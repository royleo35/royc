//
// Created by liufurui on 2022/3/27.
//

#ifndef C_COMPILER_PRINTVISITOR_H
#define C_COMPILER_PRINTVISITOR_H
#include "AstNode.h"

namespace royc {
    class PrintVisitor: public AstVisitor {
    public:
        void VisitBinaryNode(BinaryNode* node) override;
        void VisitConstantNode(ConstantNode* node) override;
        void VisitProgramNode(ProgramNode* node) override;

    };

}



#endif //C_COMPILER_PRINTVISITOR_H
