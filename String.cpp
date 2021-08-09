//
// Created by RUIPENG on 2021/8/7.
//

#include "String.h"

String::String(int sz) {
    maxSize = sz;
    length = 0;
    ch = new char[sz+1];
    ch[0] = '\0';
}

String::String(const char *str) {
    maxSize = defaultSize;
    length = strlen(str);
    ch = new char[defaultSize+1];
    strcpy(ch, str);
}

String::String(const String &str) {
    maxSize = str.maxSize;
    length = str.length;
    ch = new char[str.maxSize+1];
    strcpy(ch, str.ch);
}

String &String::operator=(const String &str) {
    maxSize = str.maxSize;
    length = str.length;
    delete[]ch;
    ch = new char[maxSize+1];
    strcpy(ch, str.ch);
    return *this;
}

String &String::operator=(const char *str) {
    if(strlen(str)>maxSize){
        cout << "Error! String length exceeded. Assignment terminated\n";
        return *this;
    }
    length = strlen(str);
    strcpy(ch, str);
    return *this;
}

String &String::operator+=(const String &str) {
    if(length + str.length > maxSize) {
        cout << "Error! String length exceeded. Append terminated.\n";
        return *this;
    }
    length += str.length;
    strcat(ch, str.ch);
    return *this;
}

String &String::operator+=(const char *str) {
    if(length + strlen(str) > maxSize) {
        cout << "Error! String length exceeded. Append terminated.\n";
        return *this;
    }
    length += strlen(str);
    strcat(ch, str);
    return *this;
}

String String::operator+(const String &str) {
    int new_sz = (length+str.length)>max(maxSize,str.maxSize)? maxSize+str.maxSize:max(maxSize, str.maxSize);
    String res(new_sz);
    strcpy(res.ch, ch);
    strcat(res.ch, str.ch);
    return res;
}

String String::operator+(const char *str) {
    int new_sz = (length+strlen(str))>maxSize? maxSize+strlen(str):maxSize;
    String res(new_sz);
    strcpy(res.ch, ch);
    strcat(res.ch, str);
    return res;
}

bool String::operator==(const String &str) {
    return strcmp(ch, str.ch)==0;
}

bool String::operator==(const char *str) {
    return strcmp(ch, str)==0;
}

bool String::operator!=(const String &str) {
    return strcmp(ch, str.ch)!=0;
}

bool String::operator!=(const char *str) {
    return strcmp(ch, str)!=0;
}

bool String::operator<(const String &str) {
    return strcmp(ch, str.ch)<0;
}

bool String::operator<(const char *str) {
    return strcmp(ch, str)<0;
}

bool String::operator>(const String &str) {
    return strcmp(ch, str.ch)>0;
}

bool String::operator>(const char *str) {
    return strcmp(ch, str)>0;
}

String String::operator()(int start, int size) {
    String res(maxSize);
    if(start<0 || start >=length) {
        cout << "Error! invalid index.\n";
        return res;
    }
    if(size < 0) {
        res.length = length - start;
    }
    else {
        res.length = min(length-start, size);
    }
    for(int i = 0; i <= res.length; i++){
        res.ch[i] = ch[i+start];
    }
    return res;
}

char String::operator[](int idx) {
    if(idx<0 || idx>=length){
        cout << "Error! invalid index.\n";
        return '\0';
    }
    return ch[idx];
}

ostream &operator<<(ostream &out, String &str) {
    out<<str.ch;
    return out;
}

int String::find(char *pattern) {
    //KMP algorithm
    int plen = strlen(pattern);
    //get next[] for pattern
    int j = 0, k = -1;
    int* next = new int[plen];
    next[0] = -1;
    while(j < plen) {
        if(k == -1 || pattern[j] == pattern[k]) {
            j++;
            k++;
            next[j] = k;
        }
        else{
            k = next[k];
        }
    }
    //find pattern
    int posT = 0;
    int posP = 0;
    while(posP < plen && posT < length) {
        if(posP == -1 || ch[posT] == pattern[posP]) {
            posT++;
            posP++;
        }
        else{
            posP = next[posP];
        }
    }
    delete[]next;
    if(posP < plen) return -1;
    else return posT-plen;
}

int String::find(String &pattern) {
    return find(pattern.ch);
}














