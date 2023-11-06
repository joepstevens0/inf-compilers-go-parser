#ifndef SCOPE_H
#define SCOPE_H

#include "../syncore.h"

struct VarValue
{
    Type type;
    void *valuePtr;
};

class Scope
{
public:

    bool hasVar(std::string id){
        return vars.count(id) > 0;
    }
    VarValue* getVar(std::string id){
        return &vars[id];
    }
    void addVar(std::string id, VarValue v){
        vars[id] = v;
    }

private:

    std::map<std::string, VarValue> vars;
    Type returntype = Type::voidType;
};


#endif