//
// Created by liufurui on 2022/3/26.
//

#include "CodeGen.h"
#include <cassert>

void royc::CodeGen::VisitBinaryNode(royc::BinaryNode *node) {
    node->Rhs->Accept(this);
    Push();
    node->Lhs->Accept(this);
    Pop("%rdi");
    switch (node->BinOp) {
        case BinaryOperator::Add:
            printf("\tadd %%rdi, %%rax\n");
            break;
        case BinaryOperator::Sub:
            printf("\tsub %%rdi, %%rax\n");
            break;
        case BinaryOperator::Mul:
            printf("\timul %%rdi, %%rax\n");
            break;
        case BinaryOperator::Div:
            printf("\tcqo\n");
            printf("\tidiv %%rdi\n");
            break;
        default:
            assert(0);
    }
}

void royc::CodeGen::VisitConstantNode(royc::ConstantNode *node) {
    printf("\tmov $%d, %%rax\n", node->Value);
}

void royc::CodeGen::VisitProgramNode(royc::ProgramNode *node) {
    printf("\t.text\n");
#ifdef __linux__
    printf("\t .globl prog\n");
    printf("\tprog:\n");
#else
    // macos
    printf("\t.globl _prog\n");
    printf("\t_prog:\n");
#endif

    printf("\tpush %%rbp\n");
    printf("\tmov %%rsp, %%rbp\n");
    printf("\tsub $32, %%rsp\n");

    node->Lhs->Accept(this);
    assert(StackLevel == 0);

    printf("\tmov %%rbp, %%rsp\n");
    printf("\tpop %%rbp\n");
    printf("\tret\n");

}

void royc::CodeGen::Push() {
    printf("\tpush %%rax\n");

}

void royc::CodeGen::Pop(const char *reg) {
    printf("\tpop %s\n", reg);
}
