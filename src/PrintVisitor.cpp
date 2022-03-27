//
// Created by liufurui on 2022/3/27.
//

#include "PrintVisitor.h"
#include <cstdio>

void royc::PrintVisitor::VisitBinaryNode(royc::BinaryNode *node) {
    node->Rhs->Accept(this);
    node->Lhs->Accept(this);
    switch (node->BinOp) {
        case BinaryOperator::Add:
            printf(" + ");
            break;
        case BinaryOperator::Sub:
            printf(" - ");
            break;
        case BinaryOperator::Mul:
            printf(" * ");
            break;
        case BinaryOperator::Div:
            printf(" / ");
            break;
        default:
            assert(0);
    }
}

void royc::PrintVisitor::VisitConstantNode(royc::ConstantNode *node) {
    printf(" %d ", node->Value);
}

void royc::PrintVisitor::VisitProgramNode(royc::ProgramNode *node) {
    node->Lhs->Accept(this);
}
