#include<iostream>
#include<stdio.h>
#include<math.h>
const int SIZE = 1000000;
//顛倒true,false，加速初始化
int prime[SIZE] = {0};
int main(){
    int sqrt_size = sqrt(SIZE);
    int N;
    int t1, t2;
    //0和1都不是質數，且1為任何數的因數，所以排除1
    prime[0] = prime[1] = 1;
    //建立質數表
    //從2開始看
    //一個合數 x ，必定有一個小於等於 sqrt(x) 的質因數。
    //所有小於等於 sqrt(x) 的質數，刪掉這些質數的倍數，就能刪掉所有合數了。
    for(int i=2;i<=sqrt_size;i++){
        //若是質數就進if
        if(!prime[i]){
            //從i的兩倍開始,3,4...直到j超過SIZE範圍
            //把i的倍數通通從值數表去掉
            for(int j = i+i; j<SIZE;j+=i){
                prime[j] = 1;
            }
        }
    }
    scanf("%d", &N);
    //N代表要執行多少次
    while(N--){
        int counter = 0;
        scanf("%d %d", &t1, &t2);
        for(int i = t1; i <= t2; i++){
            //若為prime，再看是否為digitPrime
            if(!prime[i]){
                //注意！不能直接操作i，否則會出不了loop
                int sum = 0,k = i;
                //若i至少有1位數，就繼續迴圈
                while(k){
                    sum+=k%10;
                    k/=10;
                }
                if(!prime[sum])
                    counter++;
            }    
        }
        printf("%d\n", counter);
    }
}