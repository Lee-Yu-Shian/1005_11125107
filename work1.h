#include <iostream>
#include<cstdlib> 
#include<cstring>
#include <typeinfo>
#include <stdlib.h> /* 亂數相關函數 */
#include <time.h>   /* 時間相關函數 */
using namespace std;
#pragma once

class StringClassd{
private://私有
    char* data;//字串內容
    unsigned int len;//字串長度
public://公有
    StringClassd();//建構子
    ~StringClassd();//解構子
    void strCPY(char*);//複製s
    void strCAT(char*);//串接
    unsigned int  strLEN();//回傳字串長度
    char *GetString();//取得字串
    int FindString(char*);//搜尋字串
    int PrintString();//輸出
    void operator=(StringClassd src);//等號(class=class)
    StringClassd operator+(StringClassd src);

};

