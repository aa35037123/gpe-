#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n, mod = pow(10,9) + 9;;
long long fastpow(int a, int n){
    long long half;
    //base case
    if(n == 0) return 1;
    half = fastpow(a, n/2);
    //n若為偶數
    if(n%2 == 0){
        return (half*half)%mod;
    }
    else{
        return (((half*half)%mod)*a)%mod;
    }
}
int main(){
    while(cin>>n){
        cout<<fastpow(3, n) - 2<<"\n";
    }
}