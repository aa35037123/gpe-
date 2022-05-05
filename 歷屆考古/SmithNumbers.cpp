#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int num, prime[32000] = {0};
int digit_sum(int digit){
    int sum = 0;
    while(digit){
        sum += digit%10;
        digit/=10;
    }
    return sum;
}
int main(){
    int n;
    prime[0] = prime[1] = 1;
    //smith_number限制只能到10^9，因此質數範圍到32000就好
    for(int i=2;i<=32000;i++){
        if(!prime[i]){
            for(int j=i*i;j<=32000;j+=i){
                prime[j] = 1;
            }
        }
    }
    while(cin>>n){
        while(n--){
            cin>>num;
            int smith_num = num+1;
            while(true){
                int temp = smith_num, left_sum = 0, right_sum = 0;
                int sqrt_temp = sqrt(temp);
                //一個數一定有一個小於或等於sqrt(此數)的因數，把這些質因數找出來除掉
                //temp最後的結果只可能是1或是比sqrt(此數)大的質數
                //要有temp是因為要持續更新除掉質因數後，smith_number的值，不能直接拿smith_number除
                for(int i=2;i<=sqrt_temp && temp > 1;i++){
                    if(!prime[i]){
                        //除果temp可以被i(質因數)整除，就一直除，直到不行為止
                        while(temp % i == 0){
                            right_sum += digit_sum(i);
                            temp /= i;
                        }
                    }
                }
                //若有比sqrt_smith還大的質數
                //若上面迴圈結束後，temp還是等於smith_num的話，就代表此數是質數，不算smith_number
                if(temp != smith_num){
                    if(temp > 1) right_sum += digit_sum(temp);
                    left_sum = digit_sum(smith_num);
                    if(left_sum == right_sum) break;
                }
                //若這輪結果不合，就讓smith_num+1再跑一次
                smith_num++;
            }
            cout<<smith_num<<"\n";
        }
    }
}