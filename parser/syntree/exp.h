#ifndef EXP_H
#define EXP_H

#include "syncore.h"

class IntLiteralExp: public Exp{
public:
    IntLiteralExp(int i)
    :Exp{Type::intType}, number{i}{
    }
    std::string toString() override{
        return std::to_string(number);
    }

    ReturnValue interp(Table* table) override{
        ReturnValue r;
        r.type = Type::intType;
        r.val = &number;
        return r;
    }

private:
    int number;
};

class BoolLiteralExp: public Exp{
public:
    BoolLiteralExp(bool i)
    :Exp{Type::boolType}, value{i}{
    }
    std::string toString() override{
        if (value)
            return "true";
        return "false";
    }

    ReturnValue interp(Table* table) override{
        ReturnValue r;
        r.type = Type::boolType;
        r.val = &value;
        return r;
    }

private:
    bool value;
};

class RuneLiteralExp: public Exp{
public:
    RuneLiteralExp(char i)
    :Exp{Type::runeType}, value{i}{
    }
    std::string toString() override{
        return std::string("'") + value + "'";
    }

    ReturnValue interp(Table* table) override{
        ReturnValue r;
        r.type = Type::runeType;
        r.val = &value;
        return r;
    }

private:
    char value;
};
class StringLiteralExp: public Exp{
public:
    StringLiteralExp(char* i)
    :Exp{Type::stringType}, value{i}{
    }
    std::string toString() override{
        return std::string("\"") + value + '"';
    }

    ReturnValue interp(Table* table) override{
        ReturnValue r;
        r.type = Type::stringType;
        r.val = &value;
        return r;
    }

private:
    std::string value;
};

class IdExp: public Exp{
public:
    IdExp(std::string id)
    :Exp{Type::unknown},id{id}{
    }

    std::string toString() override{
        return id;
    }

    Type getType(Table* t) override{
        return t->getVarType(id);
    }
    ReturnValue interp(Table *table) override{
        return table->getVar(id);
    }

private:

    std::string id;
};

class IndexExp: public Exp{
public:
    IndexExp(Exp* exp, Exp* index)
    :Exp{Type::runeType}, exp{exp},index{index}{
    }

    std::string toString() override{
        return exp->toString() + "[" + index->toString() + "]";
    }

    ReturnValue interp(Table *table) override{
        ReturnValue v = exp->interp(table);
        ReturnValue i = index->interp(table);
        int strIndex = *(int*)i.val;
        std::string string = *(std::string*)v.val;
        if (strIndex < 0 || strIndex >= string.size()){
            throw "Index out of range for " + toString();
        }
        rval = string[strIndex];
        return {Type::runeType, &rval};
    }

    void typeCheck(Table* t) override{
        exp->typeCheck(t);
        index->typeCheck(t);
        Type vtype = exp->getType(t);
        if (vtype != Type::stringType)
            throw TypeException{toString(), Type::stringType, vtype};
        Type itype = index->getType(t);
        if (itype != Type::intType)
            throw TypeException{toString(), Type::intType, itype};
    }

private:
    Exp* exp;
    Exp* index;
    char rval;
};

#endif