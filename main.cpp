#include <iostream>
#include "parser/syntaxtree.h"
#include "parser/parser_build/parser.hpp"
#include "parser/lexer.h"
#include "parser/printfunc.h"

extern Stm* syntree;
extern bool parseSuccess;

const char* filename = "test.go";

int main(int argc,const char** argv){
    if (argc < 2){
        std::cerr << "Missing argument file name\n";
        return -1;
    }
    const char* filename = argv[1];
    std::cout << "Started interpreter for file " << filename << "\n\n";

    yyin = fopen(filename, "r");

    try{
        yyparse();
        if (!parseSuccess)
            throw "unable to parse code";
        if (syntree){
            #ifndef NDEBUG
                std::cout << "\n-------------------------------------------------------\n";
                std::cout << syntree->toString();
                std::cout << "\n-------------------------------------------------------\n\n";
            #endif

            Table typechecktable;
            typechecktable.addFunction("print", new Print());
            syntree->typeCheck(&typechecktable, true);
            syntree->typeCheck(&typechecktable, false);
            #ifndef NDEBUG
                std::cout << "----- typecheck done\n";
            #endif

            Table t;
            t.addFunction("print", new Print());
            syntree->interp(&t);
            
            Function* main = t.getFunction("main");
            main->call(&t, {});

            std::cout << "\nFinished interpreting code\n";
        } else {
            std::cout << "Failed to interpret code\n";
        }
    } catch(TypeException e){
        std::cout << "Error: " << e.m << "\n expected: " << typeToString(e.expected) << "\n received: " << typeToString(e.received) << "\n";
    } catch(const char* e){
        std::cout << "Error: " << e << "\n";
    } catch(std::string e){
        std::cout << "Error: " << e << "\n";
    } catch(...){

    }
    return 0;
}