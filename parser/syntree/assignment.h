
#include "syncore.h"

class VarAssignStm: public Stm{
public:
    VarAssignStm(char* id, Exp* val)
    : id{id}, val{val}{
    }

    std::string toString() override{
        return id + " = " + val->toString();
    }

    void interp(Table* table) override{
        Type t = val->getType(table);
        v = val->interp(table, t);
        table->setVar(id,t, v.val);
    }

    void typeCheck(Table* t, bool skipBlocks) override{
        val->typeCheck(t);
        Type expected = t->getVarType(id);
        Type received = val->getType(t);
        if (received != expected){
            throw TypeException{toString(), expected, received};
        }
    }

private:
    std::string id;
    Exp* val;
    ReturnValue v;
};



class PlusAssignStm: public Stm{
public:
    PlusAssignStm(char* id, Exp* val)
    : id{id}, val{val}{
    }

    std::string toString() override{
        return id + " += " + val->toString();
    }

    void interp(Table* table) override{
        ReturnValue v2 = val->interp(table);
        ReturnValue v1 = table->getVar(id);
        if (v1.type == Type::intType && v2.type == Type::intType){
            v = *((int*)v1.val) + *((int*)v2.val);
            table->setVar(id,Type::intType, &v);
        } else if (v1.type == Type::stringType && v2.type == Type::stringType){
            s = *((std::string*)v1.val) + *((std::string*)v2.val);
            table->setVar(id,Type::stringType, &s);
        }
    }

    void typeCheck(Table* t, bool skipBlocks) override{
        val->typeCheck(t);
        Type vartype = t->getVarType(id);
        if (vartype != Type::intType && vartype != Type::stringType){
            throw TypeException{toString(), Type::intType, vartype};
        }
        Type valtype = val->getType(t);
        if (valtype != vartype){
            throw TypeException{toString(), vartype, valtype};
        }
    }

private:
    std::string id;
    Exp* val;
    int v;
    std::string s;
};


class IntMinAssignStm: public Stm{
public:
    IntMinAssignStm(char* id, Exp* val)
    : id{id}, val{val}{
    }

    std::string toString() override{
        return id + " -= " + val->toString();
    }

    void interp(Table* table) override{
        ReturnValue v2 = val->interp(table, Type::intType);
        ReturnValue v1 = table->getVar(id, Type::intType);
        v = *((int*)v1.val) - *((int*)v2.val);
        table->setVar(id,Type::intType, &v);
    }

    void typeCheck(Table* t, bool skipBlocks) override{
        val->typeCheck(t);
        Type vartype = t->getVarType(id);
        if (vartype != Type::intType){
            throw TypeException{toString(), Type::intType, vartype};
        }
        Type valtype = val->getType(t);
        if (valtype != Type::intType){
            throw TypeException{toString(), Type::intType, valtype};
        }
    }

private:
    std::string id;
    Exp* val;
    int v;
};


class IntMulAssignStm: public Stm{
public:
    IntMulAssignStm(char* id, Exp* val)
    : id{id}, val{val}{
    }

    std::string toString() override{
        return id + " *= " + val->toString();
    }

    void interp(Table* table) override{
        ReturnValue v2 = val->interp(table, Type::intType);
        ReturnValue v1 = table->getVar(id, Type::intType);
        v = *((int*)v1.val) * *((int*)v2.val);
        table->setVar(id,Type::intType, &v);
    }

    void typeCheck(Table* t, bool skipBlocks) override{
        val->typeCheck(t);
        Type vartype = t->getVarType(id);
        if (vartype != Type::intType){
            throw TypeException{toString(), Type::intType, vartype};
        }
        Type valtype = val->getType(t);
        if (valtype != Type::intType){
            throw TypeException{toString(), Type::intType, valtype};
        }
    }

private:
    std::string id;
    Exp* val;
    int v;
};


class IntDivAssignStm: public Stm{
public:
    IntDivAssignStm(char* id, Exp* val)
    : id{id}, val{val}{
    }

    std::string toString() override{
        return id + " /= " + val->toString();
    }

    void interp(Table* table) override{
        ReturnValue v2 = val->interp(table, Type::intType);
        ReturnValue v1 = table->getVar(id, Type::intType);

        int divisor = *((int*)v2.val);
        if (divisor == 0){
            std::cout << "Error: devision by zero\n";
            throw -1;
        }
        v = *((int*)v1.val) / divisor;
        table->setVar(id,Type::intType, &v);
    }

    void typeCheck(Table* t, bool skipBlocks) override{
        val->typeCheck(t);
        Type vartype = t->getVarType(id);
        if (vartype != Type::intType){
            throw TypeException{toString(), Type::intType, vartype};
        }
        Type valtype = val->getType(t);
        if (valtype != Type::intType){
            throw TypeException{toString(), Type::intType, valtype};
        }
    }

private:
    std::string id;
    Exp* val;
    int v;
};