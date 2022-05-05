#include<iostream>
#include<algorithm>
#include<cstdio>
#include<sstream>
#include<cctype>
#include<vector>
#include<sstream>
using namespace std;
vector<int> seq;
int testcase;
string entry;
bool compare(int a,int b){
    if(a>b) return true;
    return false;
}
int main(){
    while(scanf("%d", &testcase)!=EOF){
        getchar();
        for(int i=0;i<testcase;i++){
            seq.clear();
            int ans = 0;
            //因題目數入int量不固定，因此直接把整行取進來
            getline(cin,entry);
            stringstream ss;
            ss.str(entry);
            int num;
            //輸入法超屌!!必會!!
            //若ss裡面還有int可以輸入，回圈就繼續
            while(ss>>num){
                seq.push_back(num);
                ans+=num;
            }
            sort(seq.begin(),seq.end(),compare);
            //若不能被2整除，代表一定不能平分
            if(ans%2!=0){
                printf("NO\n");
            }
            else{
                int seq_len = seq.size();
                int sensor = ans/2;
                //sensor是全部重量的一半
                //從大的開始減，若為負的就跳過此值（加回去）
                //若最後sensor==0，代表兩車能平均分配重量
                for(int j=0;j<seq_len;j++){
                    sensor -= seq[j];
                    if(sensor<0){
                        sensor+=seq[j];
                        continue;
                    }
                    if(sensor == 0){
                        break;
                    }
                }
                if(sensor == 0)
                    printf("YES\n");
                else    
                    printf("NO\n");
            }
        }
    }
}