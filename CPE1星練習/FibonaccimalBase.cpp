#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX =1000000000;
vector<int> fib;
string s;
int main(){
    int index = 2,N,num;
    //初始化費氏數列
    fib.push_back(1);
    fib.push_back(2);
    while(fib.back()<=MAX){
        fib.push_back(fib[index-1]+fib[index-2]);
        index++;
    }
    while(scanf("%d", &N)!=EOF){
       for(int i=0;i<N;i++){
           s.clear();
           scanf("%d",&num);
           int maxIndex=0,tmp = num;
           //maxIndex代表費式數列中大於num的最小值（因為跑完後還會+1）
            while(fib[maxIndex]<=num){
               maxIndex++;
            }
            //fibIndex代表費式數列中小於num的最大值
            int fibIndex = maxIndex-1;
            //tmp為num-費式數列中的值後的值
            //若fibIndex<0就跳出迴圈
            //每跑一次while迴圈，fibIndex都要-1
            while(tmp){
                if(s==""&&fibIndex>=0){
                    tmp-=fib[fibIndex];
                    s+='1';
                    fibIndex--;
                }
                else if(s.back()!='1'&&tmp-fib[fibIndex]>=0&&fibIndex>=0){
                    tmp-=fib[fibIndex];
                    s+='1';
                    fibIndex--;
                }
                else if(s.back()!='1'&&tmp-fib[fibIndex]<0&&fibIndex>=0){
                    s+='0';
                    fibIndex--;
                }
                else if(s.back()=='1'&&fibIndex>=0){
                    s+='0';
                    fibIndex--;
                }
                
            }
            //若s長度不足就補0
            int jug=s.size();
            while(jug<maxIndex){
                s+='0';
                jug++;
            }
            printf("%d = %s (fib)\n",num,s.c_str());
       }
    }
}