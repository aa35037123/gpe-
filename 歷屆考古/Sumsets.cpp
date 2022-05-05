#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
vector<int> set;
int N,sum,len;
bool isfound;
int main(){
     while(cin>>N && N){
        sum = 0; isfound = false;
        //是string.h內的函式
        set.clear();
        int num;
        for(int i=0;i<N;i++){
            scanf("%d", &num);
            set.push_back(num);
        }
        //在algorithm裡，由小到大排列
        //若想改變規則，可以自己寫一個函式放在第3個argument
        sort(set.begin(),set.end());
        int set_size = set.size();
        for(int d=set_size-1;d>=0&&!isfound;d--){
            for(int a=0;a<set_size&&!isfound;a++){
            //continue是跳過當前循環體中的當次迴圈(i)
            //進入下一次迴圈(i+1)，並回上一層繼續執行下面未執行的程式
                if(a==d) continue;
                for(int b=a+1;b<set_size&&!isfound;b++){
                    if(b==d) continue;
                    for(int c=b+1;c<set_size&&!isfound;c++){
                        if(c==d) continue;
                        if(set[a]+set[b]+set[c] == set[d]){
                            isfound = true;
                            cout<<set[d]<<"\n";
                            //break是出去此break所在的回圈（1個）
                            break;
                        }
                       
                    }       
                }
            }
        }
       if(!isfound){
            cout<<"no solution\n";
        }
    }
    
}