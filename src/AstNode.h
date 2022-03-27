//
// Created by liufurui on 2022/3/26.
//

#ifndef C_COMPILER_ASTNODE_H
#define C_COMPILER_ASTNODE_H
#include <memory>

namespace royc{

    class AstVisitor;
    // 节点基类
    // 含有一个Accept虚函数，所有继承它的类都需要重写
    // 这个Accept函数表示了作用于对象上的操作
    class AstNode {
    public:
        virtual ~AstNode() = default;
        virtual void Accept(AstVisitor* visitor){}
    };
    // 二元操作符枚举
    enum class BinaryOperator{
        Add,
        Sub,
        Mul,
        Div,
    };
    // 二元节点
    // 二元节点由左节点，右节点和操作类型构成
    class BinaryNode: public AstNode {
    public:
        BinaryOperator BinOp;
        std::shared_ptr<AstNode> Lhs;
        std::shared_ptr<AstNode> Rhs;
        void Accept(AstVisitor* visitor) override;

    };
    // 常量节点：由值构成
    class ConstantNode: public AstNode {
    public:
        int Value;
        void Accept(AstVisitor* visitor) override;
    };
    // 程序节点：作为根节点，他的成员是AST root
    class ProgramNode: public AstNode {
    public:
        std::shared_ptr<AstNode> Lhs;
        void Accept(AstVisitor* visitor) override;
    };

    // Visitor模式：封装所有节点的操作函数，并以该节点指针作为入参
    class AstVisitor{
    public:
        virtual ~AstVisitor()=default;
        virtual void VisitBinaryNode(BinaryNode* node){}
        virtual void VisitConstantNode(ConstantNode* node){}
        virtual void VisitProgramNode(ProgramNode* node){}
    };


}



#endif //C_COMPILER_ASTNODE_H
