#include<iostream>
#include<cstdio>
#include<sstream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<stack>
#include<cctype>
using namespace std;
vector<long long > set, final[100];
typedef vector<long long>::iterator iter;
string entry;
const int SIZE = 31;
int ans_count;
//比較存在final_vector中的size大小，比較大的放後面(bubble sort)
void vector_compare(){
    vector<long long> temp;
    //總共重複ans_count-1輪
    for(int i=ans_count-1;i>0;i--){
        //每一輪把0到i的vector_size兩兩比較
        //每輪中最大的會沉到最後面，因此新的一輪不用考慮最後一個
        for(int j=0;j<i;j++){
            int a_size = final[j].size(),b_size = final[j+1].size();
            if(a_size>b_size){
                for(int k=0;k<a_size;k++){
                    temp.push_back(final[j][k]);
                }
                final[j].clear();
                for(int k=0;k<b_size;k++){
                    final[j].push_back(final[j+1][k]);
                }
                final[j+1].clear();
                for(int k=0;k<a_size;k++){
                    final[j+1].push_back(temp[k]);
                }
                temp.clear();
            }
        }
    }
}
//運用了stack的recursion
void subset(int sum, int set_count,bool dp[][31],stack<int> ans){
    //若叫到了sum=0的函式，代表儲存在stack內的數字就是正確答案（=原本總和的一半）
    if(sum == 0 && !ans.empty()){
        //把stack內的數字放到final_vector中，並清空stack
        while(!ans.empty()){
            int last = ans.top();
            final[ans_count].push_back(last);
            ans.pop();
        }
        ans_count++;
    }
    //若sum!=0,且set內還有東西
    else if(sum!=0 && !set.empty()){
        //從後面看回來，大的數字丟進stack
        for(int i=set_count;i>0;i--){
            //若dp為true且目前sum比目前set中數字還大，代表目前sum可以分解成subset
            if(dp[sum][i] && sum>=set[i-1]){
                ans.push(set[i-1]);
                //recursion，更新sum值（扣掉目前數字）
                //更新set_count值，因為我們希望進下個recursion時目前數字不會被算進去
                subset(sum-set[i-1],i-1,dp,ans);
                //叫完後就要把目前數字從stack內清除，尋找下一個可能
                ans.pop();
            }
        }
    }
}

//可以用recursion來寫
//先用dp建表，在用recursion
int main(){
    bool flag = false;
    while(getline(cin, entry) && entry!="."){
        if(flag) printf("\n");
        entry+=' ';
        int num = 0,len = entry.size();
        long long sum = 0;
        ans_count = 0;
        set.clear();
        for(int i=0;i<100;i++) final[i].clear();
        for(int i=0;i<len;i++){
            if(isdigit(entry[i])){
                num = num*10+entry[i]-'0';
            }
            else if(!isdigit(entry[i]) && num){
                sum+=num;
                set.push_back(num);
                num = 0;
            }
        }
        int set_count = set.size();
        sort(set.begin(),set.end());
        if(sum%2!=0){
            printf("No such subset\n");
            flag = true;
            continue;
        }
        sum/=2;
        bool dp[sum+1][SIZE];
        //建立dp表
        //sum若為0，不管數字為多少，皆為true
        for(int i=0;i<=set_count;i++){
            dp[0][i] = true;
        }
        //若set_count為0，sum!=0，則為false
        //因不可能有子集=目前sum值
        for(int i=1;i<=sum;i++){
            dp[i][0] = false;
        }
        //i是目前的sum，j是目前的子集有多少數字
        //若是子集內有子集可以=目前sum，就為true，否則繼續分解，
        //先看除掉last element後(跳過last element)
        //再看目前sum-last element後，且除掉last element後
        //若上兩者有1為true，則為true(or)
        for(int i=1;i<=sum;i++){
            for(int j=1;j<=set_count;j++){
                //先把此dp值定成去掉last element後的格子
                //數值才能被固定
                dp[i][j] = dp[i][j-1];
                if(i>=set[j-1]){
                    dp[i][j] = (dp[i][j]||dp[i-set[j-1]][j-1]);      
                }
            }
        }
        for(int i=0;i<=sum;i++){
        for(int j=0;j<=set_count;j++){
            if(j) printf(" ");
            printf("%d", dp[i][j]);
        }
        printf("\n");
        }
        stack<int> ans;
        while(!ans.empty()) ans.pop();
        subset(sum,set_count,dp,ans);
        //若有答案的話才進比較
        if(ans_count!=0){
            printf("%d subsets.\n", ans_count);
            vector_compare();
            for(int i=0;i<ans_count;i++){
                printf("{");
                for(iter it = final[i].begin();it!=final[i].end();it++){
                    cout<<*it;
                    if(it!=final[i].end()-1) cout<<" ";
                }
                printf("}\n");
            }
            flag = true;
        }
        else{
            printf("No such subset\n");
            flag = true;
        }
        

    }
}