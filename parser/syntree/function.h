#ifndef FUNCTION_H
#define FUNCTION_H

#include "syncore.h"
#include "block.h"
#include "table/table.h"
#include "signature.h"

class Arguments
{
public:
    virtual std::string toString(){
        return "<argument list>";
    }

    virtual std::vector<ReturnValue> interp(Table *table) {return {};}

    virtual std::vector<Type> getTypes(Table* t){ return {};}

    virtual void typeCheck(Table* t) {}
};

class ArgumentsList : public Arguments
{
public:
    ArgumentsList(Exp *head, Arguments *tail)
        : head{head}, tail{tail}
    {
    }

    std::string toString() override{
        return head->toString() + ", " + tail->toString();
    }

    std::vector<ReturnValue> interp(Table *table) override
    {   
        std::vector<ReturnValue> r = tail->interp(table);
        r.insert(r.begin(),head->interp(table));
        return r;
    }

    std::vector<Type> getTypes(Table* t) override{
        std::vector<Type> r = tail->getTypes(t);
        r.insert(r.begin(),head->getType(t));
        return r;
    }

    void typeCheck(Table* t) override{
        head->typeCheck(t);
        tail->typeCheck(t);
    }

private:
    Exp *head;
    Arguments *tail;
};
class ArgumentsLast : public Arguments
{
public:
    ArgumentsLast(Exp *lastEl) : lastEl{lastEl} {}

    std::string toString() override{
        return lastEl->toString();
    }

    std::vector<ReturnValue> interp(Table *table) override
    {   
        return {lastEl->interp(table)};
    }

    std::vector<Type> getTypes(Table* t) override{
        return {lastEl->getType(t)};
    }

    void typeCheck(Table* t) override{
        lastEl->typeCheck(t);
    }

private:
    Exp *lastEl;
};

class FunctionStm : public Stm, Function
{
public:
    FunctionStm(char *funcName, Signature *signature, BlockStm *block)
        :Function{signature} ,funcName{funcName}, signature{signature}, block{block}
    {
        block->setSignature(signature);
    }

    std::string toString() override
    {
        return "func " + funcName  + signature->toString() + block->toString();
    }
    void interp(Table *table) override
    {   
        table->addFunction(funcName, this);
    }

    void call(Table* t, std::vector<ReturnValue> args) override {
        block->setArgs(args);
        block->interp(t);
    }
    Type returnType() const override{
        return signature->returnType();
    }

    void typeCheck(Table* t, bool skipBlocks) override{
        if (skipBlocks)
           t->addFunction(funcName, this);
        block->typeCheck(t, skipBlocks);
    }

private:
    std::string funcName;
    Signature *signature;
    BlockStm *block;
};

class CallStm : public Stm
{
public:
    CallStm(char *funcName, Arguments *args = nullptr)
        : funcName{funcName}, args{args}
    {
    }

    std::string toString() override
    {
        return funcName + "(" + (args ? args->toString(): "") + ")";
    }

    void interp(Table *table) override
    {
        #ifndef NDEBUG
            std::cout << "DEBUG| Function call: " << funcName << "\n";
        #endif

        // interpret arguments
        std::vector<ReturnValue> para;
        if (args)
            para = args->interp(table);

        Function* func = table->getFunction(funcName);

        // keep only global scope for function and add a new one for it
        std::vector<Scope> scopesStackBefore = table->getScopeStack();
        table->setScopeStack({scopesStackBefore[0], Scope()});

        ReturnValue r;
        try{
            func->call(table, para);
            r = {Type::voidType};
        } catch(ReturnException& e){
            r = e.r;
        }
        #ifndef NDEBUG
            std::cout << "DEBUG| Function: " << funcName << " return with type: " << typeToString(r.type) << "\n";
        #endif

        if (func->returnType() != r.type){
            std::cout << "Invalid return type '" << typeToString(r.type) << "', expected '" << 
            typeToString(func->returnType()) << "'\n";
            throw -1;
        }

        // return scopes from before
        table->setScopeStack(scopesStackBefore);
    }

    void typeCheck(Table* t, bool skipBlocks) override{
        if (args)
            args->typeCheck(t);

        Function* f = t->getFunction(funcName);
        Signature* sign = f->getSign();
        std::vector<Type> expected = sign->getParaTypes();
        if (expected.size() > 0){
            if (expected[0] == Type::unknown){
                // any type or list of types is correct
                return;
            }
        }
        if (!args){
            if (expected.size() > 0){
                std::cerr << "Invalid number of arguments\n";
                throw -1;
            }
            return;
        }
        std::vector<Type> received = args->getTypes(t);
        for (int i = 0; i < expected.size();++i){
            if (expected[i] != received[i]){
                throw TypeException{ toString() + ", argument " + std::to_string(i+1), expected[i], received[i]};
            }
        }
    }

private:
    std::string funcName;
    Arguments *args;
};

class CallExp: public Exp
{
public:
    CallExp(char *funcName, Arguments *args = nullptr)
        :Exp{Type::unknown},funcName{funcName}, args{args}
    {
    }

    std::string toString() override
    {
        return funcName + "(" + (args ? args->toString(): "") + ")";
    }

    ReturnValue interp(Table* table) override{

        #ifndef NDEBUG
            std::cout << "DEBUG| Function call: " << funcName << "\n";
        #endif

        // interpret arguments
        std::vector<ReturnValue> para;
        if (args)
            para = args->interp(table);

        Function* func = table->getFunction(funcName);

        // keep only global scope for function and add a new one for it
        std::vector<Scope> scopesStackBefore = table->getScopeStack();
        table->setScopeStack({scopesStackBefore[0], Scope()});

        ReturnValue r;
        try{
            func->call(table, para);
            r = {Type::voidType};
        } catch(ReturnException& e){
            r = e.r;
        }
        #ifndef NDEBUG
            std::cout << "DEBUG| Function: " << funcName << " return with type: " << typeToString(r.type) << "\n";
        #endif

        if (func->returnType() != r.type){
            std::cout << "Invalid return type '" << typeToString(r.type) << "', expected '" << 
            typeToString(func->returnType()) << "'\n";
            throw -1;
        }

        // return scopes from before
        table->setScopeStack(scopesStackBefore);
        return r;
    }

    void typeCheck(Table* t) override{
        if (args)
            args->typeCheck(t);
        
        Function* f = t->getFunction(funcName);
        Signature* sign = f->getSign();
        std::vector<Type> expected = sign->getParaTypes();
        if (expected.size() > 0){
            if (expected[0] == Type::unknown){
                // any type or list of types is correct
                return;
            }
        }
        if (!args){
            if (expected.size() > 0){
                std::cerr << "Invalid number of arguments\n";
                throw -1;
            }
            return;
        }

        std::vector<Type> received = args->getTypes(t);
        for (int i = 0; i < expected.size();++i){
            if (expected[i] != received[i])
                throw TypeException{ toString() + ", argument " + std::to_string(i+1), expected[i], received[i]};
        }
    }

private:
    std::string funcName;
    Arguments *args;
};

#endif