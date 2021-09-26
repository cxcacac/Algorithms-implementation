// Reference: https://leetcode-cn.com/leetbook/read/cpp-interview-highlights/e4u9z3/
#include <iostream>
#include <cstring>

using namespace std;

// Not thread safe
class A{
private:
    char *p;
    unsigned int p_size;
    int *p_count; // counter
public:
    A(unsigned int n = 1){
        p = new char[n];
        p_size = n;
        p_count = new int; // multiple instances will use same momory
        *p_count = 1;
        cout << "count is:" << *p_count << endl;
    }
    A(const A& tmp){
        p = tmp.p;
        p_size = tmp.p_size;
        p_count = tmp.p_count;
        (*p_count)++;
        cout << "count is:" << *p_count << endl;
    }
    ~A(){
        (*p_count)--;
        cout << "count is:" << *p_count << endl;
        if(*p_count==0){
            cout << "buffer is deleted" << endl;
            delete[] p;
            p = nullptr;
            if(p_count != nullptr){
                delete p_count;
                p_count = nullptr;
            }
        }
    }

    char* getPointer(){
        return p;
    }
};

void fun(){
    A ex(100);
    char *p = ex.getPointer();
    strcpy(p, "test");
    cout << p << endl;

    A ex1 = ex;
    cout << "ex1.p==" << ex1.getPointer() << endl;
}

int main(){
    fun();
    return 0;
}
