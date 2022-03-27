#include <iostream>
#include "src/Lexer.h"
#include "src/Parser.h"
#include "src/PrintVisitor.h"
#include "src/CodeGen.h"

#define p(x) std::cout<<x<<std::endl

using namespace royc;

const char* code = " 5+1- 3 *  4 /2";
void test_lexer() {
    royc::Lexer lexer(code);
    do {
        lexer.GetNextToken();
        p(lexer.CurrentToken->Content);

    } while (lexer.CurrentToken->Kind != royc::TokenKind::Eof);
}

void test_parser() {
    Lexer lex(code);

    Parser parser(lex);
    PrintVisitor visitor;
    auto root = parser.Parse();
    root->Accept(&visitor);
}

void test_codegen(){
    Lexer lex(code);
    Parser parser(lex);
    CodeGen cg;
    auto root = parser.Parse();
    root->Accept(&cg);
}

int main(int argc, const char *argv[]) {
    // test_lexer();
    // test_parser();
    // test_codegen();
    if (argc != 2) {
        printf("please input: ./c_compiler code.\n");
        exit(-1);
    }
    auto sourceCode = argv[1];
    Lexer lex(sourceCode);
    Parser parser(lex);
    CodeGen cg;
    auto root = parser.Parse();
    root->Accept(&cg);

    return 0;
}
