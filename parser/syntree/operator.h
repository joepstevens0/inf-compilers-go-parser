#ifndef OPERATOR_H
#define OPERATOR_H
#include "syncore.h"

enum Operator
{
    And,Or,Not,
    Plus, Minus, Mul, Div,
    Greater,GreaterOrEqual,Lesser,LesserOrEqual,Equal,NotEqual
};

inline std::string opToString(Operator op)
{
    switch (op)
    {
    case And:
        return "&&";
    case Or:
        return "||";
    case Not:
        return "!";
    case Plus:
        return "+";
    case Minus:
        return "-";
    case Mul:
        return "*";
    case Div:
        return "/";
    case Greater:
        return ">";
    case GreaterOrEqual:
        return ">=";
    case Lesser:
        return "<";
    case LesserOrEqual:
        return "<=";
    case Equal:
        return "==";
    case NotEqual:
        return "!=";
    default:
        return "<unkown operator>";
    }
}

class OpExp : public Exp
{
public:
    OpExp(Exp *exp1, Operator op, Exp *exp2)
        :Exp{opType(op)},exp1{exp1}, op{op}, exp2{exp2}
    {
    }

    std::string toString() override
    {
        return "(" + (exp1 ? exp1->toString() : "") + " " + opToString(op) + " " + exp2->toString() + ")";
    }

    ReturnValue interp(Table* table) override{
        switch (op)
        {
        case And:
            return boolInterp(table);
        case Or:
            return boolInterp(table);
        case Not:
            return boolInterp(table);
        case Plus:
            if (exp2 && exp2->getType(table) == Type::stringType)
                return stringInterp(table);
            return intInterp(table);
        case Minus:
            return intInterp(table);
        case Mul:
            return intInterp(table);
        case Div:
            return intInterp(table);
        case Greater:
            return cmpInterp(table);
        case GreaterOrEqual:
            return cmpInterp(table);
        case Lesser:
            return cmpInterp(table);
        case LesserOrEqual:
            return cmpInterp(table);
        case Equal:
            return equalInterp(table);
        case NotEqual:
            return equalInterp(table);
        default:
            return {Type::unknown, nullptr};
        }
    }

    void typeCheck(Table* t) override{
        Type type1 = Type::voidType;
        if (exp1){
            exp1->typeCheck(t);
            type1 = exp1->getType(t);
        }
        Type type2 = Type::voidType;
        if (exp2){
            exp2->typeCheck(t);
            type2 = exp2->getType(t);
        }
        if (!opParaTypeCheck(type1, op, type2)){
            throw "Invalid types for operation " + opToString(op) + " in " + toString();
        }
    }

private:

    ReturnValue stringInterp(Table* table){
        std::string val1;
        if (exp1)
            val1 = *(std::string*)exp1->interp(table, Type::stringType).val;
        std::string val2;
        if (exp2)
            val2 = *(std::string*)exp2->interp(table, Type::stringType).val;

        switch (op)
        {
        case Plus:
            stringResult = val1 + val2;
            break;
        default:
            stringResult = val1;
            break;
        }
        return {Type::stringType, &stringResult};
    }

    ReturnValue boolInterp(Table* table){
        bool val1;
        if (exp1)
            val1 = *(bool*)exp1->interp(table, Type::boolType).val;
        bool val2;
        if (exp2)
            val2 = *(bool*)exp2->interp(table, Type::boolType).val;

        switch (op)
        {
        case And:
            boolResult = val1 && val2;
            break;
        case Or:
            boolResult =  val1 || val2;
            break;
        case Not:
            boolResult = !val2;
            break;
        default:
            boolResult = val2;
            break;
        }

        return {Type::boolType, &boolResult};
    }

    ReturnValue intInterp(Table* table){
        int val1 = 0;
        if (exp1)
            val1 = *(int*)exp1->interp(table, Type::intType).val;
        int val2 = *(int*)exp2->interp(table, Type::intType).val;
    
        switch (op)
        {
        case Plus:
            intResult = val1 + val2;
            break;
        case Minus:
            intResult = val1 - val2;
            break;
        case Mul:
            intResult = val1 * val2;
            break;
        case Div:
            if (val2 == 0){
                std::cout << "Error: devision by zero\n";
                throw -1;
            }
            intResult = val1 / val2;
            break;
        default:
            intResult = val1;
        }

        return {Type::intType, &intResult};
    }

    ReturnValue cmpInterp(Table* t){
        int val1 = *(int*)exp1->interp(t, Type::intType).val;
        int val2 = *(int*)exp2->interp(t, Type::intType).val;
        switch (op)
        {
        case Greater:
            boolResult = val1 > val2;
            break;
        case GreaterOrEqual:
            boolResult = val1 >= val2;
            break;
        case Lesser:
            boolResult = val1 < val2;
            break;
        case LesserOrEqual:
            boolResult = val1 <= val2;
            break;
        default:
            boolResult = val1 > 0;
        }
        return {Type::boolType, &boolResult};
    }
    ReturnValue equalInterp(Table* t){

        ReturnValue v1 = exp1->interp(t);
        ReturnValue v2 = exp2->interp(t);
        if (op == Operator::Equal){
            switch (v1.type){
            case intType:
                boolResult = *(int*)v1.val == *(int*)v2.val;
                break;
            case boolType:
                boolResult = *(bool*)v1.val == *(bool*)v2.val;
                break;
            case runeType:
                boolResult = *(char*)v1.val == *(char*)v2.val;
                break;
            case stringType:
                boolResult = *(std::string*)v1.val == *(std::string*)v2.val;
                break;
            default:
                boolResult = false;
            }
        }else if (op == Operator::NotEqual){
            switch (v1.type){
            case intType:
                boolResult = *(int*)v1.val != *(int*)v2.val;
                break;
            case boolType:
                boolResult = *(bool*)v1.val != *(bool*)v2.val;
                break;
            case runeType:
                boolResult = *(char*)v1.val != *(char*)v2.val;
                break;
            case stringType:
                boolResult = *(std::string*)v1.val == *(std::string*)v2.val;
                break;
            default:
                boolResult = true;
            }
        }
        return {Type::boolType, &boolResult};
    }

    Type opType(Operator op){
        switch (op){
        case And:
            return Type::boolType;
        case Or:
            return Type::boolType;
        case Not:
            return Type::boolType;
        case Plus:
            return Type::intType;
        case Minus:
            return Type::intType;
        case Mul:
            return Type::intType;
        case Div:
            return Type::intType;
        case Greater:
            return Type::boolType;
        case GreaterOrEqual:
            return Type::boolType;
        case Lesser:
            return Type::boolType;
        case LesserOrEqual:
            return Type::boolType;
        case Equal:
            return Type::boolType;
        case NotEqual:
            return Type::boolType;
        default:
            return Type::unknown;
        }
    }

    bool opParaTypeCheck(Type t1 ,Operator op, Type t2){
        if (t1 == Type::unknown || t2 == Type::unknown) return true;
        switch (op){
        case And:
            return t1 == Type::boolType && t2 == Type::boolType;
        case Or:
            return t1 == Type::boolType && t2 == Type::boolType;
        case Not:
            return t1 == Type::voidType && t2 == Type::boolType;
        case Plus:
            return (t1 == Type::intType && t2 == Type::intType) 
            || (t1 == Type::stringType && t2 == Type::stringType)
            || (t1 == Type::voidType && t2 == Type::intType);;
        case Minus:
            return (t1 == Type::intType && t2 == Type::intType)
            || (t1 == Type::voidType && t2 == Type::intType);
        case Mul:
            return t1 == Type::intType && t2 == Type::intType;
        case Div:
            return t1 == Type::intType && t2 == Type::intType;
        case Greater:
            return t1 == Type::intType && t2 == Type::intType;
        case GreaterOrEqual:
            return t1 == Type::intType && t2 == Type::intType;
        case Lesser:
            return t1 == Type::intType && t2 == Type::intType;
        case LesserOrEqual:
            return t1 == Type::intType && t2 == Type::intType;
        case Equal:
            return (t1 == Type::intType && t2 == Type::intType)
                || (t1 == Type::boolType && t2 == Type::boolType)
                || (t1 == Type::runeType && t2 == Type::runeType)
                || (t1 == Type::stringType && t2 == Type::stringType);
        case NotEqual:
            return (t1 == Type::intType && t2 == Type::intType)
                || (t1 == Type::boolType && t2 == Type::boolType)
                || (t1 == Type::runeType && t2 == Type::runeType)
                || (t1 == Type::stringType && t2 == Type::stringType);
        default:
            return true;
        }
    }

    Exp *exp1;
    Operator op;
    Exp *exp2;
    bool boolResult;
    int intResult;
    std::string stringResult;
};

#endif