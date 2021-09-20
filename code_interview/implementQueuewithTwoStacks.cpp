#include <stack>
#include <stdexcept>
#include <stdio.h>

using namespace std;

template <typename T>
class CQueue{
public:
    CQueue(void);
    ~CQueue(void);
    void appendTail(const T &node);
    T deleteHead();
    void printStatus();

private:
    stack<T> st1;
    stack<T> st2;
};


template<typename T> CQueue<T>::CQueue(void){}

template<typename T> CQueue<T>::~CQueue(void){}

// template<typename T> ret-type cls<T>::appendTail(parameter lists)
template<typename T> void CQueue<T>::appendTail(const T & node){
    st1.push(node);
}

template<typename T> T CQueue<T>:: deleteHead(){
    if(st1.empty() && st2.empty()){
        logic_error e("queue is empty");
        throw new exception(e);
    }
    if(st2.empty()){
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
    }
    T head = st2.top();
    st2.pop();
    return head;
}

template<typename T> void CQueue<T>::printStatus(){
    printf("stack 1 size: %d \n", (int)st1.size());
    printf("stack 2 size: %d \n", (int)st2.size());
}

int main(int argc, char* argv[]){
    CQueue<char> queue;
    queue.appendTail('a');
    queue.appendTail('b');
    queue.appendTail('c');

    char head = queue.deleteHead();
    printf("poped: %c\n", head);
    queue.printStatus();

    head = queue.deleteHead();
    printf("poped: %c\n", head);
    queue.printStatus();

    queue.appendTail('d');
    queue.printStatus();

    head = queue.deleteHead();
    printf("poped: %c\n", head);
    queue.printStatus();

    head = queue.deleteHead();
    printf("poped: %c\n", head);
    queue.printStatus();
}
