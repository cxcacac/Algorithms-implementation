/*
    Reference1: https://github.com/zhulintao/CodingInterviewChinese2/blob/master/01_AssignmentOperator/AssignmentOperator.cpp
    Reference2: <剑指offer>
*/

#include <iostream>
#include <cstring>
#include <cstdio>

class CMyString{
public:
    // 构造函数原型声明
    CMyString(char* pData=nullptr);
    ~CMyString(void);
    // 复制构造函数
    CMyString(const CMyString &str);
    // 赋值构造函数
    CMyString &operator=(const CMyString &str);
    void print();

private:
    char* m_pdata;
};

CMyString::CMyString(char* pData){
    if(pData==nullptr){
        m_pdata = new char[1];
        m_pdata[0] = '\0';
    }
    else{
        int length = strlen(pData);
        m_pdata = new char[length + 1];
        strcpy(m_pdata, pData);
        // strncpy(m_pdata, pData, length+1);
    }
}

CMyString::~CMyString(){
    // 注意是delete[]
    delete[] m_pdata;
}

CMyString::CMyString(const CMyString& str){
    int length = strlen(str.m_pdata);
    m_pdata = new char[length + 1];
    strcpy(m_pdata, str.m_pdata);
}

CMyString& CMyString::operator=(const CMyString& str){
    // #####version 1#####
    // 不考虑异常安全问题
    if(this == &str){
        return *this;
    }
    delete[] m_pdata;
    m_pdata = nullptr;

    m_pdata = new char[strlen(str.m_pdata) + 1];
    strcpy(m_pdata, str.m_pdata);
    return *this;

    // #####version 2#####
    // 考虑异常安全问题
    // if(this != &str){
    //     // 栈上申请的内存，利用构造函数初始化创造新的对象
    //     CMyString strTemp(str);
    //     char *pTemp = strTemp.m_pdata;
    //     strTemp.m_pdata = m_pdata;
    //     m_pdata = pTemp;
    // }
    // return *this;
}

void CMyString::print(){
    printf("%s", m_pdata);
}

void Test1(){
    printf("test1 begins: \n");
    char *text = "hello world";
    CMyString str1(text);
    CMyString str2;

    str2 = str1;

    printf("expected result: %s \n", text);
    printf("actual result: ");
    str2.print();
    printf("\n");
}

void Test2(){
    // 自身赋值。
    printf("test2 begins: \n");
    char *text = "hello world";
    CMyString str1(text);
    str1 = str1;
    printf("self copy, done \n");
}

void Test3(){
    printf("test3 begins: \n");
    char *text = "hello world";
    CMyString str1(text);
    CMyString str2, str3;
    str3 = str2 = str1;
    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str2.print();
    printf(".\n");

    printf("The expected result is: %s.\n", text);

    printf("The actual result is: ");
    str3.print();
    printf(".\n");
}

int main(int argc, char* argv[]){
    Test1();
    Test2();
    Test3();
    return 0;
}
