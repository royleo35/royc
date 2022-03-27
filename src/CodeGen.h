//
// Created by liufurui on 2022/3/26.
//

#ifndef C_COMPILER_CODEGEN_H
#define C_COMPILER_CODEGEN_H
#include "AstNode.h"

// 代码生成

namespace royc{
    class CodeGen: public AstVisitor {
    private:
        int StackLevel{0};
    public:
        CodeGen() {}
        void VisitProgramNode(ProgramNode* node) override;
    private:
        void VisitBinaryNode(BinaryNode* node) override;
        void VisitConstantNode(ConstantNode* node) override;


        void Push();
        void Pop(const char* reg);


    };
}



#endif //C_COMPILER_CODEGEN_H
