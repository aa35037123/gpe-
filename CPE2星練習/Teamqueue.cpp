#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
//element代表element在哪個team中
int element[1000005];
//teamQ是queue中team的順序，element_inQ是team裡element的順序
queue<int> teamQ, element_inQ[1005];
int t, n ,num, testcase = 1;
string entry;
int main(){
    while(scanf("%d", &t)!=EOF && t){
        //initial，把資料清空
        memset(element, 0, sizeof(element));
        while(!teamQ.empty()) teamQ.pop();
        for(int i=0;i<1005;i++){
            while(!element_inQ[i].empty()) element_inQ[i].pop();
        }
        //i代表現在的team編號
        for(int i=1;i<=t;i++){
            scanf("%d", &n);
            for(int j=0;j<n;j++){
                scanf("%d", &num);
                //element中同個team的index，value會一樣
                element[num] = i;
            }
        }
        printf("Scenario #%d\n", testcase++);
        //可以分別檢查一行中的不同datatype
        while(cin>>entry && entry!="STOP"){
            int team;
            if(entry == "ENQUEUE"){
                int q_num;
                scanf("%d", &q_num);
                team = element[q_num];
                //若此team中的元素第一次出現，就把他push進queue中
                if(element_inQ[team].empty()){
                    teamQ.push(team);
                }
                element_inQ[team].push(q_num);
            }
            else if(entry == "DEQUEUE"){
                team = teamQ.front();
                int ele_now = element_inQ[team].front();
                printf("%d\n", ele_now);
                element_inQ[team].pop();
                if(element_inQ[team].empty()){
                    teamQ.pop();
                }
            }
        }
        printf("\n");
    }
}