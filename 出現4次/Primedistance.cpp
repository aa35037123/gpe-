#include<iostream>
#include<cstdio>
#include<math.h>
#include<utility>
#include<string.h>
using namespace std;
const int SIZE = 2147483647;
//visit的index是質數，value是1or0（是否為質數）
//prime的index是第幾個質數，value是質數本身
int visit[50001],prime[50001];
int L,U;
int makelist(int n){
    int counter = 0;
    memset(visit,0,sizeof(visit));
    visit[0] = visit[1] = 1;
    for(int i=2;i<n;i++){
        if(!visit[i]){
            prime[counter++] = i;
            for(int j=i+i;j<n;j+=i){
                visit[j] = 1;
            }
        }
    }
    return counter;
}
int plist[1000001], ans[1000001];
int main(){
    //一個合數 x ，必定有一個小於等於 sqrt(x) 的質因數
    //這裡在做質數表時，只要做到小於等於 sqrt(x)的質數就好
    //剩下更大的就用這些質數表再刪掉就好
    int size_sqrt = sqrt(SIZE);
    int prime_count = makelist(size_sqrt);
    while(scanf("%d %d",&L, &U)!=EOF){
        memset(plist,0,sizeof(plist));
        int ans_count = 0;
        for(int i=0;i<prime_count;i++){
            //L-1是防止L本身就是prime[i]的倍數
            int s = (L-1)/prime[i]+1;
            //最小質數要是2
            if(s<2)
                s = 2;
            //j是L~U範圍內prime[i]的最小倍數
            for(unsigned int j=s*prime[i];j<=U;j+=prime[i]){
                //j-L是看和L差了多少，因為題目有說明U-L不超過1000000
                //plist內是合數就為true
                plist[j-L] = 1;
            }
        }
        for(unsigned int i=L;i<=U;i++){
            //因為1不可能為質數，所以排除1
            if(i>1&&!plist[i-L]){
                ans[ans_count] = i;
                ans_count++;
            }
        }
        if(ans_count<2)
            printf("There are no adjacent primes.\n");
        else{
            int max = -2147483647,min = 2147483647;
            int biglong,smllong,bigshort,smlshort;
            for(int i=1;i<ans_count;i++){
                int model = ans[i] - ans[i-1];
                if(model>max){
                    max = model;
                    biglong = ans[i];
                    smllong = ans[i-1];
                }
                if(model<min){
                    min = model;
                    bigshort = ans[i];
                    smlshort = ans[i-1];
                }
            }
            printf("%d,%d are closest, %d,%d are most distant.\n", smlshort, bigshort, smllong,biglong);
        }
        
    }
}