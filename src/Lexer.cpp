//
// Created by liufurui on 2022/3/26.
//

#include "Lexer.h"
#include <cstring>
#include <iostream>

void royc::Lexer::GetNextToken() {
    // 1. skip whitespace
    while (isspace(CurChar)) {
        GetNextChar();
    }
    TokenKind kind;
    int val = 0;
    int startPos = Cursor - 1;
    if (CurChar == '\0') {
        kind = TokenKind::Eof;
    } else if (CurChar == '+') {
        kind = TokenKind::Add;
        GetNextChar();
    } else if (CurChar == '-') {
        kind = TokenKind::Sub;
        GetNextChar();
    } else if (CurChar == '*') {
        kind = TokenKind::Mul;
        GetNextChar();
    } else if (CurChar == '/') {
        kind = TokenKind::Div;
        GetNextChar();
    } else if (isdigit(CurChar)) {
        val = 0;
        do {
            val = val * 10 + CurChar - '0';
            GetNextChar();
        } while (isdigit(CurChar));
        kind = TokenKind::Num;
    } else {
        printf("not support char: %c", CurChar);
    }
    CurrentToken = std::make_shared<Token>();
    CurrentToken->Kind = kind;
    CurrentToken->Value = val;
    CurrentToken->Content = SourceCode.substr(startPos, Cursor-1-startPos);

    // std::cout<< "content:"<<CurrentToken->Content<<std::endl;

}

void royc::Lexer::GetNextChar() {
   if (Cursor == SourceCode.size()) {
       CurChar = '\0';
   } else {
       CurChar = SourceCode[Cursor];
   }
   Cursor++;
}
