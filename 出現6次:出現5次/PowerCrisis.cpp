#include<iostream>
using namespace std;
int N,last,m;
int main(){
    while(cin>>N && N){
        for(m=1;m<N;m++){
            //最後存活的人index為0，因此換m後就要更新一次
            last = 0;
            //为什么不是j<=n 因为第一个人直接走了。所以只有n-1个人 
			//为什么j=2开始，因为只有一个人(j=1)时，循环一次结果也不会变。
            //從結果（只剩1人）反推回2人,3人...到N-2個人時last的編號
            for(int j=2;j<N;j++){
                last = (last+m)%j;
            }
            //等于11是因为13是从0-12，去掉首个(第一个电站直接没了)就变成了0-11。  
            if(last == 11) break;
        }
        cout<<m<<"\n";
    }
}