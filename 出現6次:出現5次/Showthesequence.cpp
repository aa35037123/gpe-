//https://morris821028.github.io/2014/07/31/oj/uva/uva-997/
#include<iostream>
#include<vector>
#include<stack>
#include<ctype.h>
#include<string.h>
using namespace std;
const int MAX = 50;
char s[1024];
//因為a的value有可能會到很大，所以要用long long
long long a[MAX];
int n;
//要用char字串的形式，recursion時才能決定字串要從哪開始
void parsing(char s[],int n){
    //sign判斷數字正負，m是紀錄[]內數字為何
    int sign = 1,m = 0,i;
    char opr;
    //i從1開始，因為0一定是'['
    //判斷此for迴圈要不要繼續的因素不在這，因此第二項敘述可以空著
    for(i=1; ;i++){
        //要能判斷數字的正負 
        if(s[i] == '-'){
            sign = -1;
        }
        //因數字不一定只有個位數，因此需要跑多遍迴圈
        else if(s[i]>='0' && s[i]<='9'){
            //s[i]-'0'可以把char變成int
            m = m*10+(s[i]-'0');
        }
        else{
            //若遇到符號，就出迴圈
            opr = s[i];
            break;
        }
    }
    m *=sign;
    if(opr=='+'){
        //因s為array，被函數call時會傳送index0的地址
        //所以可以+上數字改變想傳送的字串(擷取原本字串)
        //有'+'和'*'就代表後面還有東西，所以近recursion
        //直到數字後的符號不是'+'or'*'
        parsing(s+i+1, n);
        long long d = a[0],t;
        a[0] = m;
        for(int j=1;j<n;j++){
            t = a[j];
            a[j] = a[j-1] + d;
            d = t;
        }
    }
    else if(opr=='*'){
        parsing(s+i+1, n);
        a[0] *= m;
        for(int j=1;j<n;j++){
            a[j] *= a[j-1];
        }
    }
    else{
        for(int j=0;j<n;j++){
            a[j] = m;
        }
    }
}
int main(){
    //scanf char字串時不用＆，因為array本身就類似指標，會回傳index0的地址
    while(scanf("%s %d", s, &n)!=EOF){
        memset(a,0,sizeof(a));
        parsing(s,n);
        for(int i=0;i<n;i++)
            printf("%lld%c", a[i],i==n-1? '\n':' ');
      
    }
}