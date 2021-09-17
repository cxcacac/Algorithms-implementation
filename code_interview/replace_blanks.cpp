/*
    Reference: https://github.com/zhulintao/CodingInterviewChinese2/blob/master/05_ReplaceSpaces/ReplaceSpaces.cpp
    Reference: <剑指offer>
*/
#include <cstring>
#include <cstdio>

// 空格变成%20
void ReplaceBlank(char str[], int length){
    // 边界条件判断
    if(str==nullptr || length==0){
        return;
    }
    int originalLength = 0;
    int numberofBlanks = 0;
    int i = 0;
    while(str[i] != '\0'){
        ++originalLength;
        if(str[i] == ' '){
            ++numberofBlanks;
        }
        i++;
    }
    int newLength = originalLength + numberofBlanks * 2;
    if(newLength > length){
        return;
    }
    // 需要考虑到最后一个‘\0’的存在
    int i = newLength, j = originalLength;
    // 不能覆盖
    while(j>=0 && i > j){
        if(str[j]==' '){
            str[i--] = '0';
            str[i--] = '2';
            str[i--] = '%';
        }
        else{
            str[i--] = str[j];
        }
        j--;
    }
}

