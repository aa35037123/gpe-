#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//最大可輸入string為1000個字元，但表格從1開始比較明瞭
//所以要+1，而且還要含空字元，再+1，湊整數較好看，因此選1005
const int SIZE = 1005;
string str1, str2;
//把dynamicPrgramming表格的每一格都初始化為0
int dp[SIZE][SIZE] = {0};
int main(){
    while(cin>>str1>>str2){
        int ans,len1,len2;
        len1 = str1.size();
        len2 = str2.size();
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                //若字元相同，這格就填1+左上角那格(把兩字串最後char
                //刪掉後的maxLcs值)
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                //若字元不同，這格就填上面那格和左邊那格的max
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        cout<<dp[len1][len2]<<endl;
    }
}