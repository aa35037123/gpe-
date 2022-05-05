#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>
#include<cstring>
#include<algorithm>
using namespace std;
int T, N, P, Q, total, S, R, object;
int dp[1000][10000];
struct Vaccine{
    int num;
    int price;
}vaccine[1000];
int mini(int a, int b){
    if(b == 0) return a;
    return min(a, b);
}
int main(){
    while(cin>>T){
        while(T--){
            total = 0, object = 1;
            cin>>N;
            while(N--){
                cin>>P>>Q;
                //total為全部疫苗的數量
                total+=P;
                vaccine[object].num = P;
                vaccine[object].price = Q;
                object++;
            }
            //S是需要疫苗數量的testcase總數
            cin>>S;
            while(S--){
                memset(dp, 0, sizeof(dp));
                //R是需要疫苗總數
                cin>>R;
                if(R>total){
                    cout<<"no solution\n";
                    continue;
                }
                for(int i=1;i<object;i++){
                    for(int j=1; j<=total;j++){
                        if(j>=vaccine[i].num){
                            //因為可能碰到dp[i-1][j]為0的狀況，所以不能直接用min函數
                            dp[i][j] = mini(vaccine[i].price+dp[i-1][j-vaccine[i].num], dp[i-1][j]);
                        }
                        else{
                            dp[i][j] = dp[i-1][j];
                        }
                    }
                }
                for(int i=1;i<object;i++){
                    for(int j=1; j<=total;j++){
                        if(j-1) cout<<" ";
                        cout<<dp[i][j];
                    }
                    cout<<'\n';
                }
            }
        }
    }
}