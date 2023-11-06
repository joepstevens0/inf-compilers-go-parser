#ifndef VARIABLE_H
#define VARIABLE_H

class VarCreateStm : public Stm{
public:
    VarCreateStm(char *id, Exp *val = nullptr)
        : id{id}, val{val}
    {
    }
    std::string toString() override
    {
        return "var " + id + " " + (val ? " = " + val->toString() : "");
    }
    void interp(Table *table) override
    {
        Type t = val->getType(table);
        if (val)
            table->createVar(id, t, val->interp(table, t).val);
        else
            throw "Error: variable needs initializer";
    }

    void typeCheck(Table* t, bool skipBlocks) override{
        val->typeCheck(t);

        Type type = val->getType(t);
        t->createVar(id, type, nullptr);
    }

private:
    Exp *val;
    std::string id;
};
class IntCreateStm : public Stm
{
public:
    IntCreateStm(char *id, Exp *val = nullptr)
        : id{id}, val{val}
    {
    }
    std::string toString() override
    {
        return "var " + id + " int" + (val ? " = " + val->toString() : "");
    }
    void interp(Table *table) override
    {
        if (val)
            table->createVar(id, Type::intType, val->interp(table, Type::intType).val);
        else
            table->createVar(id, Type::intType, &v);
    }
    
    void typeCheck(Table* t, bool skipBlocks) override{
        if (val){
            val->typeCheck(t);
            Type type = val->getType(t);
            if (type != Type::intType)
                throw TypeException{toString(), Type::intType, type};
        }
        t->createVar(id, Type::intType, &v);
    }

private:
    Exp *val;
    std::string id;
    int v = 0;
};

class BoolCreateStm : public Stm
{
public:
    BoolCreateStm(char *id, Exp *val = nullptr)
        : id{id}, val{val}
    {
    }
    std::string toString() override
    {
        return "var " + id + " bool" + (val ? " = " + val->toString() : "");
    }
    void interp(Table *table) override
    {
        if (val)
            table->createVar(id, Type::boolType, val->interp(table, Type::boolType).val);
        else
            table->createVar(id, Type::boolType, &v);
    }

    void typeCheck(Table* t, bool skipBlocks) override{
        if (val){
            val->typeCheck(t);
            Type type = val->getType(t);
            if (type != Type::boolType)
                throw TypeException{toString(), Type::boolType, type};
        }
        t->createVar(id, Type::boolType, &v);
    }

private:
    Exp *val;
    std::string id;
    bool v;
};

class RuneCreateStm : public Stm
{
public:
    RuneCreateStm(char *id, Exp *val = nullptr)
        : id{id}, val{val}
    {
    }
    std::string toString() override
    {
        return "var " + id + " rune" + (val ? " = " + val->toString() : "");
    }
    void interp(Table *table) override
    {
        if (val)
            table->createVar(id, Type::runeType, val->interp(table, Type::runeType).val);
        else
            table->createVar(id, Type::runeType, &v);
    }

    void typeCheck(Table* t, bool skipBlocks) override{
        if (val){
            val->typeCheck(t);
            Type type = val->getType(t);
            if (type != Type::runeType)
                throw TypeException{toString(), Type::runeType, type};
        }
        t->createVar(id, Type::runeType, &v);
    }

private:
    Exp *val;
    std::string id;
    char v;
};

class StringCreateStm : public Stm
{
public:
    StringCreateStm(char *id, Exp *val = nullptr)
        : id{id}, val{val}
    {
    }
    std::string toString() override
    {
        return "var " + id + " rune" + (val ? " = " + val->toString() : "");
    }
    void interp(Table *table) override
    {
        if (val)
            table->createVar(id, Type::stringType, val->interp(table, Type::stringType).val);
        else
            table->createVar(id, Type::stringType, &v);
    }

    void typeCheck(Table* t, bool skipBlocks) override{
        if (val){
            val->typeCheck(t);
            Type type = val->getType(t);
            if (type != Type::stringType)
                throw TypeException{toString(), Type::stringType, type};
        }
        t->createVar(id, Type::stringType, &v);
    }

private:
    Exp *val;
    std::string id;
    std::string v;
};

#endif