#include <iostream>
#include <vector>

using namespace std;

int main(){
    // N, total number, M rank
    // N from 1,....,N
    // O(N)
    int N, M;
    cin >> N >> M;
    vector<int> next(N+1, 0);
    vector<int> pre(N+1, 0);
    for (int i = 1; i <= N; i++){
        next[i] = i % N + 1;
        pre[i] = (i + N - 2) % N + 1;
    }
    // number of elements deleted;
    int cnt = 0;
    // start from cur idx;
    int curIdx = 1;
    while(cnt < N -1){
        int rank = 1;
        while(rank < M){
            curIdx = next[curIdx];
            rank++;
        }
        next[pre[curIdx]] = next[curIdx];
        pre[next[curIdx]] = pre[curIdx];
        int tmp = next[curIdx];
        next[curIdx] = -1;
        curIdx = tmp;
        cnt++;
    }
    for (int i = 1; i <= N; i++){
        if(next[i] != -1){
            cout << i << endl;
            return 0;
        }
    }
}
