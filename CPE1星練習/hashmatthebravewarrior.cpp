#include<iostream>
using namespace std;
int main(){
    //遇到llint宣告方式
    long long a,b;
    //遇到ll不要用%容易錯
    while(cin>>a>>b){
        cout<<abs(a-b)<<"\n";
    }
}