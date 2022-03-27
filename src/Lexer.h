//
// Created by liufurui on 2022/3/26.
//

#ifndef C_COMPILER_LEXER_H
#define C_COMPILER_LEXER_H

#include <string_view>

namespace royc {
    // token 枚举
    enum class TokenKind{
        Eof,
        Add,
        Sub,
        Mul,
        Div,
        Num,
    };
    // token 类
    class Token{
    public:
        TokenKind Kind;
        int Value;
        std::string_view Content;
    };
    // 词法分析类
    class Lexer {
    private:
        std::string_view SourceCode;
        char CurChar{' '};
        int Cursor{0};

    public:
        std::shared_ptr<Token> CurrentToken;
        Lexer(const char* code){
            SourceCode = code;
        }
        void GetNextToken();
        void GetNextChar();

    };
}


#endif //C_COMPILER_LEXER_H
