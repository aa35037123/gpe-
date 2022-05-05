#include<iostream>
#include<cstdio>
#include<sstream>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
string entry;
int casecount,com_count,comI,comJ;
char type;
int main(){
    stringstream ss;
    //如果是scanf下面要接getline就要用getchar(把\n吃掉)
    //不然getline就會少吃到一行
    //但若是scanf接scanf，不管中間有多少\n都沒關係
    //scanf會自己找到input
    while(scanf("%d", &casecount)!=EOF){
       
        for(int i=0;i<casecount;i++){
            int RightAns = 0, WrongAns = 0;
            if(i) printf("\n");
            scanf("%d", &com_count);
            getchar();
            //connected用來確認兩數字是否相連（在同一組）
            vector<int> connected(com_count+1);
            //初始化connected,index = value
            for(int j=1;j<=com_count;j++){
                connected[j] = j;
            }
            while(getline(cin,entry) && entry!=""){
                ss.clear();
                ss.str(entry);
                ss>>type>>comI>>comJ;
                //此回圈會讓connected的value變成相連的最小電腦編號，藉此判斷是否為同一組
                int groupI = connected[comI], groupJ = connected[comJ];
                if(type == 'c'){
                    for(int j=1;j<=com_count;j++){
                        //因為回圈跑完後comI會和comJ相連，因此這裡connected不管=groupI或是groupJ都可以
                        //value就選最小的group
                        if(connected[j] == groupI || connected[j] == groupJ){
                            connected[j] = min(groupI,groupJ);
                        }
                    }
                }
                if(type == 'q'){
                    //若value一樣，代表comI和comJ是同組的
                    if(connected[comI] != connected[comJ])
                        WrongAns++;
                    else
                        RightAns++;
                }
            }
            printf("%d,%d\n", RightAns, WrongAns);
        }
    }
}