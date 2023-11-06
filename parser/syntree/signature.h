#ifndef SIGNATURE_H
#define SIGNATURE_H

#include "syncore.h"
#include "table/table.h"

class Parameter
{
public:
    Parameter(const char *id, Type type) : id{id}, type{type} {
    }

    virtual std::string toString()
    {
        return id + " " + typeToString(type);
    }

    void define(Table* t, ReturnValue arg){
        if (arg.type != type){
            throw TypeException{"Invalid argument type  for '" + id + "'\n", type, arg.type};
        }
        t->createVar(id, type, arg.val);
    }
    void define(Table* t){
        t->createVar(id, type, nullptr);
    }

    Type getType(){
        return type;
    }

private:
    std::string id;
    Type type;
};

class Parameters
{
public:
    virtual std::string toString()
    {
        return "<parameter list>";
    }

    virtual void define(Table* t, std::vector<ReturnValue> args) = 0;

    virtual std::vector<Type> getTypes(){ return {};}

private:
};

class ParametersList : public Parameters
{
public:
    ParametersList(Parameter *head, Parameters *tail)
        : head{head}, tail{tail}
    {
    }

    std::string toString() override
    {
        return head->toString() + ", " + tail->toString();
    }

    void define(Table* t, std::vector<ReturnValue> args) override{
        if (args.size() > 0){
            head->define(t, args[0]);
            args.erase(args.begin());
        } else{
            head->define(t);
        }
        tail->define(t, args);
    }

    std::vector<Type> getTypes() override{
        std::vector<Type> r = tail->getTypes();
        r.insert(r.begin(),head->getType());
        return r;
    }

private:
    Parameter *head;
    Parameters *tail;
};

class ParametersLast: public Parameters
{
public:
    ParametersLast(Parameter *lastEl)
        : lastEl{lastEl}
    {
    }

    std::string toString() override
    {
        return lastEl->toString();
    }
    void define(Table* t, std::vector<ReturnValue> args) override{
        if (args.size() > 0){
            lastEl->define(t, args[0]);
        } else{
            lastEl->define(t);
        }
    }

    std::vector<Type> getTypes() override{
        return {lastEl->getType()};
    }

private:
    Parameter *lastEl;
};

class Signature
{
public:
    Signature(Parameters *paras, Type returntype)
        : paras{paras}, _returnType{returntype}
    {
    }

    std::string toString()
    {
        return "(" + (paras? paras->toString():"") + ") " + (_returnType != voidType? typeToString(_returnType): "");
    }

    void define(Table* t, std::vector<ReturnValue> args){
        if (paras)
            paras->define(t, args);
    }
    Type returnType() const {
        return _returnType;
    }

    std::vector<Type> getParaTypes(){
        if (paras)
            return paras->getTypes();
        return {};
    }

private:
    Parameters *paras;
    Type _returnType;
};

#endif