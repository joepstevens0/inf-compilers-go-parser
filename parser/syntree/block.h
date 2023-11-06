#ifndef BLOCKSTM_H
#define BLOCKSTM_H
#include "syncore.h"
#include "signature.h"


class BlockStm : public Stm
{
public:
    BlockStm(Stm *stm)
        : stm{stm} {}

    std::string toString() override
    {
        return "{\n" + (stm? stm->toString(): "") + "\n}";
    }

    void setSignature(Signature* sign){
        signature = sign;
    }

    void setArgs(std::vector<ReturnValue> a){
        args = a;
    }

    void interp(Table *table) override{
        table->addScope();
        if (signature)
            signature->define(table, args);
        if (stm) stm->interp(table);
        table->removeScope();
    }

    void typeCheck(Table* t, bool skipBlocks) override{
        if (skipBlocks) return;
        
        t->addScope();
        if (signature)
            signature->define(t, {});
        stm->typeCheck(t, skipBlocks);
        t->removeScope();
    }

private:
    Stm *stm;
    Signature *signature = nullptr;
    std::vector<ReturnValue> args;
};

#endif