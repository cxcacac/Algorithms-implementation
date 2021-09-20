#include <queue>
#include <stdexcept>
#include <stdio.h>

using namespace std;

template <typename T>
class CStack{
public:
    CStack(void);
    ~CStack(void);
    void append(const T &node);
    void pop();

private:
    queue<T> qt1;
    queue<T> qt2;
};

template <typename T> CStack<T>::CStack(void){}

template <typename T> CStack<T>::~CStack(void){}

template <typename T> void CStack<T>::append(const T &node){
    if(!qt2.empty()){
        qt2.push(node);
    }
    else{
        qt1.push(node);
    }
}

template <typename T> void CStack<T>::pop(){
    if(qt1.empty() && qt2.empty()){
        logic_error e("stack is empty");
        throw new exception(e);
    }
    if(qt1.empty()){
        while(qt2.size>1){
            qt1.push(qt2.front());
            qt2.pop();
        }
        qt2.pop();
    }
    else{
        while(qt1.size>1){
            qt2.push(qt1.front());
            qt1.pop();
        }
        qt1.pop();
    }
}
