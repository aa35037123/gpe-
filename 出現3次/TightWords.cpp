#include<iostream>
#include<cstring>
using namespace std;
int k, n;
//定義dp[i][j] = 以數字j結尾、長度為i的序列中，緊密的序列佔所有長度為i的序列之比
double dp[105][15], sum;
int main(){
    while(cin>>k>>n){
        memset(dp, 0, sizeof(dp));
        //一開始，長度為1的序列都是緊密的，dp[1][0~k] = 1 / (k+1)
        for(int j=0;j<=k;j++) dp[1][j] = (double)1/(k+1);
        //長度從2開始
        for(int i=2;i<=n;i++){
            for(int j=0;j<=k;j++){
                //dp[i][j]的意义为第i位数字填j有多少种可能
                //那么第i位填了j，第i-1必定只可能填j-1，j，j+1才能保证相邻两位差不超过1
                dp[i][j] = (double)(dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j+1])/(k+1);
            }
        }
        sum = 0;
        //sum把所有長度為n，且個位數是(0~k)的機率加起來
        for(int j=0;j<=k;j++){
            sum+=dp[n][j];
        }
        //%f：float，%lf：double
        printf("%.5lf\n", sum*100);
    }
}