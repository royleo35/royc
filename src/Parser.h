//
// Created by liufurui on 2022/3/26.
//

#ifndef C_COMPILER_PASER_H
#define C_COMPILER_PASER_H
#include "Lexer.h"
#include "AstNode.h"
// 语法分析
// Parser的输入是Lexer，利用Lexer解析一个个token，从而解析一个个表达式，最终构成抽象语法树
// 每个表达式由一些节点构成，一次需要给出一个抽象节点AstNode，其他的节点都继承它
//
namespace royc{
    class Parser {
    private:
        Lexer &Lex;
        std::shared_ptr<AstNode> ParseExpr();
        std::shared_ptr<AstNode> ParseAddExpr();
        std::shared_ptr<AstNode> ParseMulExpr();
        std::shared_ptr<AstNode> ParsePrimaryExpr();
    public:
    Parser(Lexer& lexer): Lex(lexer) { }
    std::shared_ptr<ProgramNode> Parse();

    };

}



#endif //C_COMPILER_PASER_H
