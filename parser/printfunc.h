#ifndef PRINTFUNC_H
#define PRINTFUNC_H

#include "syntree/table/table.h"

class Print : public Function
{

public:
    Print()
    :Function{new Signature(new ParametersLast(new Parameter("args", Type::unknown)), Type::voidType)}{

    }
    void call(Table *t, std::vector<ReturnValue> args) override
    {
        for (int i = 0; i < args.size(); ++i)
        {
            ReturnValue r = args[i];
            switch (r.type)
            {
            case intType:
                std::cout << *((int*)r.val);
                break;
            case boolType:
                if (*((bool*)r.val))
                    std::cout << "true";
                else
                    std::cout << "false";
                break;
            case runeType:
                std::cout << *(char*)r.val;
                break;
            case stringType:
                std::cout << *(std::string*)r.val;
                break;
            default:
                std::cerr << "Error unprintable object of type " << typeToString(r.type) << "\n";
            }
        }
    }
    Type returnType() const override{
        return Type::voidType;
    }
};

#endif