//令牆壁的長度為n，n若等於1，就是1塊；n若等於2，就是2塊
//n若大於2，則n長度的牆壁可由n-1長度的牆壁加一塊垂直的方塊
//以及由n-2長度的牆壁加兩塊平行的方塊而得到。
#include<iostream>
using namespace std;
const int MAX = 51;
int n;
int fib[MAX];

int main(){
    fib[0]=1,fib[1]=1;
    for(int i=2;i<MAX;i++){
        fib[i] = fib[i-1]+fib[i-2];
    }
    while(scanf("%d", &n)!=EOF && n){
        cout<<fib[n]<<"\n";
    }
}