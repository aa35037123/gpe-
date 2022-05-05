#include<iostream>
#include<climits>
#include<algorithm>
#include<cstring>
using namespace std;
int table[55], dp[55][55], l, n;
int main(){
    while(cin>>l && l){
        cin>>n;
        memset(dp, 0, sizeof(dp));
        for(int i=1;i<=n;i++){
            cin>>table[i];
        }
        n++;
        table[0] = 0, table[n] = l;
        int end, temp;
        //range為切割隔幾個切割點
        //range從2開始是因為若range=1就不需要切割
        for(int range=2;range<=n;range++){
            //begin為從哪個切割點開始切割
            for(int begin=0;begin<n;begin++){
                //end是最後的切割點
                end = begin + range;
                if(end > n) break;
                //先把這格設為最大值，接下來不管什麼數一定比他小
                dp[begin][end] = INT_MAX;
                //c為中繼的切割點
                for(int c=begin+1;c<end;c++){
                    temp = dp[begin][c] + dp[c][end] + table[end] - table[begin];
                    //dp每個意義為：從切割點begin到切割點end所花的最小花費
                    dp[begin][end] = min(temp, dp[begin][end]);
                }
            }
        }
        printf("The minimum cutting is %d.\n", dp[0][n]);
    }
}