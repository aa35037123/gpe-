#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n, mod = pow(10,9) + 9;;
long long fastpow(int a, int n){
    long long half, ans;
    if(n == 0) return 1;
    half = fastpow(a, n/2);
    //n若為偶數
    if(n%2 == 0){
        ans = (half*half)%mod;
    }
    else{
        ans = (((half*half)%mod)*a)%mod;
    }
    return ans;
}
int main(){
    while(cin>>n){
        cout<<fastpow(3, n) - 2<<"\n";
    }
}