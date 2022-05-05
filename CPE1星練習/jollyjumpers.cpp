#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
vector<int> seq;
vector<int> jolly;
int progression(int n){
    int val = 0;
    for(int i=1;i<=n;i++){
        val+=i;
    }
    return val;
}
int main(){
    int N;
    while(scanf("%d",&N)!=EOF){
        int num;
        int val=progression(N-1);
        int total_jolly = 0;
        int diff = 0;
        //要輸入新的一組數字前要clear vector
        seq.clear();
        for(int i=0;i<N;i++){
            scanf("%d",&num);
            seq.push_back(num);
        }
        for(int i=0;i<N-1;i++){
            diff = abs(seq[i+1]-seq[i]);
            //要控制diff值在[1,N-1]
            if(diff<1||diff>N-1) break;
            total_jolly += diff;
        }
        if(total_jolly==val)
            cout<<"Jolly"<<endl;
        else
            cout<<"Not jolly"<<endl;
        
     }
}