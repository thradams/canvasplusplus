// Generated by tkgen - Version Apr 28 2011
// tkgen was developed by Thiago Adams
// www.thradams.com
//
// Copyright (C) 2009, Thiago Adams (thiago.adams@gmail.com)
// http://www.thradams.com/
// Permission to copy, use, modify, sell and distribute this software
// is granted provided this copyright notice appears in all copies.
// This software is provided "as is" without express or implied
// warranty, and with no claim as to its suitability for any purpose.
//

#ifndef __CANVASPARSERDFA_H__
#define __CANVASPARSERDFA_H__

namespace CanvasParser
{

enum Tokens
{
    TokenTKOPENP,
    TokenTKCLOSEP,
    TokenTKCOMA,
    TokenTKRGB,
    TokenTKRGBA,
    TokenTKNUMBER,
    TokenTKFNUMBER,
    TokenBLANKS,
};

inline const wchar_t* TokensToString(Tokens e)
{
    switch(e)
    {
    case TokenTKOPENP: return L"TKOPENP";
    case TokenTKCLOSEP: return L"TKCLOSEP";
    case TokenTKCOMA: return L"TKCOMA";
    case TokenTKRGB: return L"TKRGB";
    case TokenTKRGBA: return L"TKRGBA";
    case TokenTKNUMBER: return L"TKNUMBER";
    case TokenTKFNUMBER: return L"TKFNUMBER";
    case TokenBLANKS: return L"BLANKS";
    default:break;
    }
    return L"";
}

struct DFA
{
    typedef Tokens TokenType;

    static int GetNext(int state, wchar_t ch)
    {
        switch (state)
        {
            case 0:
        if (ch >= L'\t' && ch <= L'\n')
          return 1;
            else if (ch == L'\r')
                return 1;
            else if (ch == L' ')
                return 1;
            else if (ch == L'(')
                return 2;
            else if (ch == L')')
                return 3;
            else if (ch == L',')
                return 4;
        else if (ch >= L'0' && ch <= L'9')
          return 5;
        else if (ch == L'r')
          return 6;
    break; // 
            case 1:
        if (ch >= L'\t' && ch <= L'\n')
          return 1;
            else if (ch == L'\r')
                return 1;
            else if (ch == L' ')
                return 1;
        //TokenBLANKS
    break; // 
            case 2:
        //TokenTKOPENP
    break; // 
            case 3:
        //TokenTKCLOSEP
    break; // 
            case 4:
        //TokenTKCOMA
    break; // 
            case 5:
            if (ch == L'.')
                return 8;
        else if (ch >= L'0' && ch <= L'9')
          return 5;
        //TokenTKNUMBER
    break; // 
            case 6:
        if (ch == L'g')
          return 9;
    break; // 
            case 7:
  return -1;
    break; // 
            case 8:
       if (ch >= L'0' && ch <= L'9')
           return 10;
    break; // 
            case 9:
        if (ch == L'b')
          return 11;
    break; // 
            case 10:
        if (ch >= L'0' && ch <= L'9')
          return 10;
        //TokenTKFNUMBER
    break; // 
            case 11:
            if (ch == L'a')
                return 12;
        //TokenTKRGB
    break; // 
            case 12:
        //TokenTKRGBA
    break; // 
        } //switch
        return -1;
    }

    static bool IsInterleave(Tokens tk)
    {
        return tk == TokenBLANKS;
    }

    static bool GetTokenFromState(int state, Tokens& tk)
    {
        switch(state)
        {
            case 1: tk = TokenBLANKS; break;
            case 2: tk = TokenTKOPENP; break;
            case 3: tk = TokenTKCLOSEP; break;
            case 4: tk = TokenTKCOMA; break;
            case 5: tk = TokenTKNUMBER; break;
            case 10: tk = TokenTKFNUMBER; break;
            case 11: tk = TokenTKRGB; break;
            case 12: tk = TokenTKRGBA; break;
            default:
                return false;
        }
        return true;
    }
};
} //namespace
#endif //header
