#include<iostream>
#include<cstdio>
using namespace std;
int B, P, M;
long long fastpow(int B, int P, int M){
    if(P == 0) return 1;
    long long half = (fastpow(B, P/2, M))%M;
    if(P%2 == 0){
        return (half*half)%M;
    }
    else{
        return (((half*half)%M)*B)%M;
    }
}
int main(){
    while(cin>>B>>P>>M){
        cout<<fastpow(B, P, M)<<"\n";
    }
}