#ifndef TABLE_H
#define TABLE_H

#include "../syncore.h"
#include "scope.h"
#include <exception>

class Signature;

struct ReturnException: public std::exception
{
    ReturnValue r;
};
struct TypeException: public std::exception
{
    TypeException(std::string code, Type expected, Type received){
        this->m = "Type error in:\n'" + code + "'";
        this->expected = expected;
        this->received = received;
    }
    std::string m;
    Type expected;
    Type received;
};


class Function
{
public:
    Function(Signature* sign):sign{sign}{}
    virtual void call(Table *t, std::vector<ReturnValue> args) = 0;
    virtual Type returnType() const = 0;

    Signature* getSign() const { return sign;}
private:
    Signature* sign;
};

class Table
{
public:
    Table()
    {
        scopestack.push_back(Scope());
    }
    void setVar(std::string id, Type type, void* val)
    {
        VarValue *valuePtr = findVar(id);
        if (!valuePtr)
        {
            std::cout << "\nError: variable '" << id << "' undefined\n";
            throw -1;
        }
        else if (valuePtr->type != type)
        {
            std::cout << "\nError: assignment failed, variable '" << id << "' is not of type" << typeToString(type) << "\n";
            throw -1;
        }
        else
        {
            valuePtr->valuePtr = val;
        }
    }
    ReturnValue getVar(std::string id, Type expectedType = Type::unknown)
    { 
        VarValue *valuePtr = findVar(id);
        if (!valuePtr)
        {
            std::cout << "\nError: variable '" << id << "' undefined\n";
            throw -1;
        }
        if (expectedType != Type::unknown && valuePtr->type != expectedType)
        {
            std::cout << "\nError: variable '" << id << "' is not of type " << typeToString(expectedType) << "\n";
            throw -1;
        }
        else
        {
            ReturnValue r;
            r.type = valuePtr->type;
            r.val = valuePtr->valuePtr;
            return r;
        }
    }
    void createVar(std::string id, Type type, void* value)
    {
        #ifndef NDEBUG
            std::cout << "DEBUG| Create var: " << id << "\n";
        #endif

        if (!scopestack[scopestack.size()-1].hasVar(id))
        {
            VarValue v{type, value};
            scopestack[scopestack.size() - 1].addVar(id, v);
        }
        else
        {
            std::cout << "\nError: redefinition of variable " << id << "\n";
            throw -1;
        }
    }

    void addScope()
    {
        scopestack.push_back(Scope());
    }
    void removeScope()
    {
        scopestack.pop_back();
    }

    void addFunction(std::string id, Function *func)
    {
        if (!functions.count(id))
            functions[id] = func;
        else{
            std::cout << "\nError: function redefinition: " << id << "\n";
            throw -1;
        }
    }

    Type getVarType(std::string id){
        VarValue* v = findVar(id);

        if (v){
            return v->type;
        }
        std::cout << "\nError: variable '" << id << "' is undefined\n";
        throw -1;
    }

    Function* getFunction(std::string id){
        // test if function defined, give error if not
        testFunctionDefined(id);

        return functions[id];
    }

    std::vector<Scope> getScopeStack(){
        return scopestack;
    }
    void setScopeStack(std::vector<Scope> stack){
        scopestack = stack;
    }

private:

    void testFunctionDefined(std::string id){
        if (functions.count(id)){
            return;
        }else{
            std::cout << "\nError: function '" << id << "' is undefined\n";
            throw -1;
        }
    }

    VarValue *findVar(std::string id)
    {
        for (int i = scopestack.size() - 1; i >= 0; --i)
        {
            Scope &scope = scopestack[i];
            if (scope.hasVar(id))
            {
                return scope.getVar(id);
            }
        }
        return nullptr;
    }

    std::vector<Scope> scopestack;
    std::map<std::string, Function *> functions;
    ReturnValue returnVal = {Type::voidType};
};

#endif