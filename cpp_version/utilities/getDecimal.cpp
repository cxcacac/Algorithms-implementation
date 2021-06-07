#include<string>
#include<vector>
#include<iostream>

using namespace std;

int main(){
    int a, b;
    cin>>a;
    cin>>b;
    int div = a/b;
    int re = a%b;
    int pre = -1;
    string res;
    res += to_string(div);
    if(re == 0) cout<<res<<endl;
    res.push_back('.');
    while(re != 0 && re != pre){
        div = re*10/b;
        pre = re;
        re = re*10%b;
        if(re == pre){
            res.push_back('(');
            res.push_back(div+'0');
            res.push_back(')');
        }else{
            res += to_string(div);
        }
    }
    cout<<res<<endl;
}