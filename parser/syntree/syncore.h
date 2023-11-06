#ifndef SYNCORE_H
#define SYNCORE_H

#include <string>
#include <vector>
#include <map>
#include <iostream>

class Table;

enum Type
{
    voidType,
    intType,
    boolType,
    runeType,
    stringType,
    unknown
};

struct ReturnValue
{
    Type type;
    void* val;
};


inline std::string typeToString(Type t)
{
    switch (t)
    {
    case voidType:
        return "void";
    case intType:
        return "int";
    case boolType:
        return "bool";
    case runeType:
        return "rune";
    case stringType:
        return "string";
    default:
        return "<unknown type>";
    }
}

class Stm
{
public:
    Stm()
    {
    }

    virtual std::string toString()
    {
        return "<stm>";
    }

    virtual void interp(Table *table) {}

    virtual void typeCheck(Table* t, bool skipBlocks) {}
};

class Exp
{
public:
    Exp(Type type)
    :m_type{type}{
    }

    virtual std::string toString()
    {
        return "<exp>";
    }

    virtual ReturnValue interp(Table *table, Type expectedType) {
        ReturnValue r = interp(table);
        if (expectedType != Type::unknown && expectedType != r.type){
            std::cerr << "Incorrect expression type\n";
            throw -1;
        }
        return r;
    }
    virtual ReturnValue interp(Table *table) {
        return {Type::unknown}; 
    }

    virtual Type getType(Table* t){
        return m_type;
    }

    virtual void typeCheck(Table* t) {}
private:
    Type m_type;
};

#endif