//
// Created by liufurui on 2022/3/26.
//

#include "AstNode.h"

void royc::BinaryNode::Accept(royc::AstVisitor *visitor) {
    visitor->VisitBinaryNode(this);
}

void royc::ConstantNode::Accept(royc::AstVisitor *visitor) {
    visitor->VisitConstantNode(this);
}

void royc::ProgramNode::Accept(royc::AstVisitor *visitor) {
    visitor->VisitProgramNode(this);
}
