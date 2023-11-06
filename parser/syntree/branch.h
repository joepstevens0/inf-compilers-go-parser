#include "block.h"

class IfStm: public Stm{
public:
    IfStm(Exp* exp, BlockStm *block, Stm* preStm = nullptr, Stm* elseBlock = nullptr)
    :exp{exp}, block{block}, preStm{preStm}, elseBlock{elseBlock}{}

    std::string toString() override
    {
        return "if " + (preStm? preStm->toString() + "; " : "") + exp->toString() + block->toString() + (elseBlock? "else " + elseBlock->toString() : "");
    }
    void interp(Table *table) override
    {   
        if (preStm)
            preStm->interp(table);
        if (*(bool*)exp->interp(table, Type::boolType).val){
            block->interp(table);
        } else if (elseBlock){
            elseBlock->interp(table);
        }
    }

    void typeCheck(Table* t, bool skipBlocks) override{
        if (preStm)
            preStm->typeCheck(t, skipBlocks);
        exp->typeCheck(t);
        Type type = exp->getType(t);
        if (type != Type::boolType)
            throw TypeException{toString(), Type::boolType, type};

        if (block)
            block->typeCheck(t, skipBlocks);
        if (elseBlock)
            elseBlock->typeCheck(t, skipBlocks);
    }

private:
    Exp* exp;
    BlockStm* block;
    Stm* preStm;
    Stm* elseBlock;
};

class ForStm: public Stm{
public:
    ForStm(Exp* condition, BlockStm* block, Stm* preStm = nullptr, Stm* post = nullptr)
    :condition{condition}, block{block}, preStm{preStm}, post{post} {}

    std::string toString() override
    {
        return "for " + 
        (preStm? preStm->toString() + "; " : "") 
        + condition->toString() +
        (post? "; " + post->toString() : "") + 
        block->toString();
    }
    void interp(Table *table) override
    {   
        table->addScope();
        if (preStm)
            preStm->interp(table);
        while(*((bool*)condition->interp(table, Type::boolType).val)){
            block->interp(table);
            if (post)
                post->interp(table);
        }
        table->removeScope();
    }

    void typeCheck(Table* t, bool skipBlocks) override{
        t->addScope();
        if (preStm)
            preStm->typeCheck(t, skipBlocks);
        condition->typeCheck(t);
        Type type = condition->getType(t);
        if (type != Type::boolType)
            throw TypeException{toString(), Type::boolType, type};
        if (post)
            post->typeCheck(t, skipBlocks);
        block->typeCheck(t, skipBlocks);
        t->removeScope();
    }

private:
    Exp* condition;
    BlockStm* block;
    Stm* preStm; 
    Stm* post;
};