//
// Created by RUIPENG on 2021/8/7.
//

#ifndef NJU_REVIEW_STRING_H
#define NJU_REVIEW_STRING_H
#include "commons.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class String {
protected:
    char* ch;
    int length;
    int maxSize;
public:
    //constructors and destructors
    String(int sz = defaultSize);
    String(const char* str);
    String(const String& str);
    ~String(){delete[]ch;}
    //GET functions
    int getLength()const{return length;}
    int getMaxSize()const{return maxSize;}
    bool empty()const{return length==0;}
    //operators
    String& operator=(const String& str);
    String& operator=(const char* str);
    String& operator+=(const String& str);
    String& operator+=(const char* str);
    String operator+(const String& str);
    String operator+(const char* str);
    bool operator==(const String& str);
    bool operator==(const char* str);
    bool operator!=(const String& str);
    bool operator!=(const char* str);
    bool operator<(const String& str);
    bool operator<(const char* str);
    bool operator>(const String& str);
    bool operator>(const char* str);
    String operator()(int start, int size);
    char operator[](int idx);
    friend ostream& operator << (ostream& out, String& str);
    //functions
    int find(char* pattern);
    int find(String& pattern);

};


#endif //NJU_REVIEW_STRING_H
