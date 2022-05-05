#include <iostream>
#include<sstream>
#include<vector>
#include<cstring>
using namespace std;
int coins[11] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
int num1, num2, total;
int main(){
	long long dp[12][30005] = {0};
	//若目前錢為0，方法就=1(不用給零錢)
	for(int i=0;i<=11;i++) dp[i][0] = 1;
	//範圍要控制好，不能超出coins的範圍
	for(int i=1;i<=11;i++){
		for(int j=1;j<30005;j++){
			if(j>=coins[i-1]){
				dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	while(scanf("%d.%d", &num1, &num2) && (num1 || num2)){
		//因為浮點數轉成整數是避不開誤差的，因此要用兩個整數來存值
		total = num1*100+num2;
		// for(int i=1;i<=11;i++){
		// 	for(int j=1;j<=total;j++){
		// 		if(j-1) printf(" ");
		// 		cout<<dp[i][j];
		// 	}
		// 	printf("\n");
		// }
		//%_d,_內填入-是靠左對齊，+是靠右對齊
        //數字則表示print下一個數字前要流多少空位（包含此數字）
        //%_ _d,第一個_放0，代表把空位都補0
		printf("%3d.%02d%17lld\n", num1, num2, dp[11][total]);
	}
}