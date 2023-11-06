#ifndef STM_H
#define STM_H

#include "syncore.h"
#include "table/table.h"
#include "exp.h"

class CompoundStm : public Stm
{
public:
    CompoundStm(Stm *stm1, Stm *stm2)
        : stm1{stm1}, stm2{stm2}
    {
    }
    std::string toString() override
    {
        return stm1->toString() + ";\n" + stm2->toString();
    }

    void interp(Table *table) override
    {
        stm1->interp(table);
        stm2->interp(table);
    }

    void typeCheck(Table* t, bool skipBlocks) override{
        stm1->typeCheck(t, skipBlocks);
        stm2->typeCheck(t, skipBlocks);
    }

private:
    Stm *stm1;
    Stm *stm2;
};
class LastStm : public Stm
{
public:
    LastStm(Stm *stm)
        : stm{stm}
    {
    }
    std::string toString() override
    {
        return stm->toString() + ";";
    }

    void interp(Table *table) override
    {
        stm->interp(table);
    }

    void typeCheck(Table* t, bool skipBlocks) override{
        stm->typeCheck(t, skipBlocks);
    }
private:
    Stm *stm;
};

class IncrementStm : public Stm
{
public:
    IncrementStm(char *id)
        : id{id}
    {
    }
    std::string toString() override
    {
        return id + "++";
    }

    void interp(Table* t) override{
        *(int*)t->getVar(id, Type::intType).val += 1;
    }

    void typeCheck(Table* t, bool skipBlocks) override{
        Type type = t->getVarType(id);
        if (type != Type::intType)
            throw TypeException{toString(), Type::intType, type};
    }

private:
    std::string id;
};
class DecrementStm : public Stm
{
public:
    DecrementStm(char *id)
        : id{id}
    {
    }
    std::string toString() override
    {
        return id + "++";
    }

    void interp(Table* t) override{
        *(int*)t->getVar(id, Type::intType).val -= 1;
    }

    void typeCheck(Table* t, bool skipBlocks) override{
        Type type = t->getVarType(id);
        if (type != Type::intType)
            throw TypeException{toString(), Type::intType, type};
    }


private:
    std::string id;
};

class ReturnStm : public Stm
{
public:
    ReturnStm(Exp *result)
        : result{result}
    {
    }
    std::string toString() override
    {
        return "return" + (result ? " " + result->toString() : "");
    }

    void interp(Table* t) override{
        if (result){
            ReturnException e;
            e.r = result->interp(t);
            throw e;
        }
    }

    void typeCheck(Table* t, bool skipBlocks) override{
        result->typeCheck(t);
    }


private:
    Exp *result;
};

class PackageStm : public Stm
{
public:
    PackageStm(char *packageName)
    {
        package = packageName;
    }
    std::string toString() override
    {
        return "package " + package;
    }

private:
    std::string package;
};
class NoOpStm : public Stm
{
public:
    std::string toString() override
    {
        return "";
    }
};
class ErrorStm : public Stm
{
public:
    std::string toString() override
    {
        return "<error>";
    }
};

#endif