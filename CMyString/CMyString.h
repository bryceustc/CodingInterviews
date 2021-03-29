//
// Created by Bryce on 2021/3/29.
//

#ifndef INC_1_CMYSTRING_H
#define INC_1_CMYSTRING_H

#include <string.h>
#include <iostream>

class CMyString {
public:
    CMyString(char *pData = nullptr);
    CMyString(const CMyString &);
    ~CMyString();
    CMyString &operator = (const CMyString &str);
    char *getData();
private:
    char *m_pData;
};

CMyString::CMyString(char *pData){
    m_pData = new char[strlen(pData) + 1];
    strcpy(m_pData, pData);
}

CMyString::~CMyString() {
    if (m_pData) {
        delete[] m_pData;
        m_pData = nullptr;
    }
}

//拷贝构造函数
CMyString::CMyString(const CMyString &str) {
    std::cout << "这是拷贝构造函数！" << std::endl;
    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);
}

//赋值运算符函数
CMyString &CMyString::operator=(const CMyString &str) {
    std::cout << "这是拷贝赋值运算符！" << std::endl;
    if (this == &str) {
        //检查自赋值的情况
        return *this;
    }

    //释放原本的内存
    if (m_pData) {
        delete[] m_pData;
        m_pData = nullptr;
    }

    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);

    return *this;
}

char *CMyString::getData() {
    return m_pData;
}

#endif //INC_1_CMYSTRING_H
