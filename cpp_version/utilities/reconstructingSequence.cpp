#include <vector>
#include <iostream>
#include <deque>

using namespace std;

int main(){
    // questions:
    // given a pile of cards with a number on each card, then do following steps in turn:
    // (1) take a card from top to desk
    // (2) take a card from top to the bottom of the pile.
    // now, given a sequence on the desk, get the original order in the pile.

    deque<int> dq;
    int size;
    int n;
    cin >> size;
    for(int i = 0; i < size; i++){
        cin >> n;
        dq.emplace_back(n);
    }
    vector<int> arranged;
    vector<int> rearranged;
    while(!dq.empty()){
        arranged.emplace_back(dq.front());
        dq.pop_front();
        if(!dq.empty()){
            dq.push_back(dq.front());
            dq.pop_front();
        }
    }
    cout << "arrange:" << endl;
    for (int i = 0; i < size-1; i++){
        cout << arranged[i] << " ";
    }
    cout << arranged[size - 1] << endl;

    // we should do previous steps in reversed order.

    cout << "rearranged:" << endl;
    for (int i = size - 1; i >= 0; i--){
        if(dq.size()>0){
            dq.push_front(dq.back());
            dq.pop_back();
        }
        dq.push_front(arranged[i]);
    }
    for (int i = 0; i < size-1; i++){
        cout << dq[i] << " ";
    }
    cout << dq[size-1] << endl;
}

