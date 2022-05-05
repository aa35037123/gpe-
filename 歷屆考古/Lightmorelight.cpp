#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n;
int main(){
    while(scanf("%d", &n)!=EOF && n){
        int q = sqrt(n);
        if(q*q == n) printf("yes\n");
        else printf("no\n");
    }
}