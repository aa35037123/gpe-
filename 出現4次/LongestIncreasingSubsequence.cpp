#include<iostream>
#include<cstdio>
#include<sstream>
#include<vector>
using namespace std;
int n, dp[65535],num;
vector<int> sequence;
string entry;
int main(){
    stringstream ss;
    while(scanf("%d", &n)!=EOF){
        getchar();
        //清空ss，初始化要用.str和.clear，缺一不可
        ss.str("");
        ss.clear();
        //初始化vector
        sequence.clear();
        getline(cin,entry);
        ss.str(entry);
        while(ss>>num){
            sequence.push_back(num);
        }
        //初始化dp為1，1代表最小的LIS(Longest Increasing Subsequence)
        for(int i=0;i<65535;i++){
            dp[i] = 1;
        }
        for(int j=1;j<n;j++){
            for(int i=0;i<j;i++){
                if(sequence[j]>sequence[i]){
                    dp[j] = max(dp[j],dp[i]+1);
                }
            }
        }
        int max = 1;
        for(int i=0;i<n;i++){
            if(dp[i]>max) max = dp[i];
        }
        for(int i =0;i<n;i++){
            if(i) printf(" ");
            printf("%d",dp[i]);
        }
        printf("\n");
        printf("%d", max);
    }
}