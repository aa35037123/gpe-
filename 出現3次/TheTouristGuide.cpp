#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N, R, S, D, T, C1, C2, P;
int main(){
    int capacity[105][105], testcase = 0;
    while(scanf("%d %d", &N, &R)!=EOF && (N||R)){
        memset(capacity, 0, sizeof(capacity));
        while(R--){
            scanf("%d %d %d", &C1, &C2, &P);
            capacity[C1][C2] = P;
            capacity[C2][C1] = P;
        }
        //k是選擇的中繼站
        for(int k=1;k<=N;k++){
            for(int i=1;i<=N;i++){
                for(int j=1;j<=N;j++){
                    //找到最大可容納單位
                    capacity[i][j] = max(capacity[i][j], min(capacity[i][k], capacity[k][j]));
                }
            }
        }
        scanf("%d %d %d", &S, &D, &T);
        printf("Scenario #%d\n", ++testcase);
        //算出來的capacity要-1，因為包含導遊，問句式好用，要記清楚(判斷內容)？(true要怎麼樣):(false要怎麼樣)
        printf("Minimum Number of Trips = %d\n\n", T/(capacity[S][D]-1) + ((T%(capacity[S][D]-1)>0) ? 1:0));
    }
}