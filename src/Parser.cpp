//
// Created by liufurui on 2022/3/26.
//

#include "Parser.h"
using namespace royc;

// PrimaryExpr := Num
std::shared_ptr<AstNode> royc::Parser::ParsePrimaryExpr() {
    auto node = std::make_shared<ConstantNode>();
    node->Value = Lex.CurrentToken->Value;
    Lex.GetNextToken();
    return node;
}

// 加法
// AddExpr := MulExpr | AddExpr + MulExpr | AddExpr - MulExpr
std::shared_ptr<AstNode> Parser::ParseAddExpr() {
    auto left = ParseMulExpr();
    while(Lex.CurrentToken->Kind == TokenKind::Add || Lex.CurrentToken->Kind == TokenKind::Sub) {
        auto op = Lex.CurrentToken->Kind == TokenKind::Add? BinaryOperator::Add: BinaryOperator::Sub;
        Lex.GetNextToken();
        auto node = std::make_shared<BinaryNode>();
        node->BinOp = op;
        node->Lhs = left;
        node->Rhs = ParseMulExpr();
        left = node;
    }
    return left;
}


// MulExpr := PrimaryExpr | MulExpr*PrimaryExpr | MulExpr/PrimaryExpr
std::shared_ptr<AstNode> Parser::ParseMulExpr() {
    auto left = ParsePrimaryExpr();
    while(Lex.CurrentToken->Kind == TokenKind::Mul || Lex.CurrentToken->Kind == TokenKind::Div) {
        auto op = Lex.CurrentToken->Kind == TokenKind::Mul? BinaryOperator::Mul: BinaryOperator::Div;
        Lex.GetNextToken();
        auto node = std::make_shared<BinaryNode>();
        node->BinOp = op;
        node->Lhs = left;
        node->Rhs = ParsePrimaryExpr();
        left = node;
    }
    return left;
}

// 表达式由加法表达式组成
std::shared_ptr<AstNode> Parser::ParseExpr() {
    return ParseAddExpr();
}

// 程序由表达式组成
std::shared_ptr<ProgramNode> Parser::Parse() {
    Lex.GetNextToken();
    auto node = std::make_shared<ProgramNode>();
    node->Lhs = ParseExpr();
    return node;
}
