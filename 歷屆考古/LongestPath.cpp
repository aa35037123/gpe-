#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
using namespace std;
//此題用到SPFA：求單源最短路徑的演算法
//此題用BFS（廣度優先搜尋），要用到queue
//用DFS(深度優先搜尋)也可以，只要把queue全部換成stack就好
int findLongestPath(int n,int start,vector<int>&distance,bool map[101][101]){
    queue<int> queue;
    vector<bool> inQueue(n+1, false);
    queue.push(start);
    while(!queue.empty()){
        int current = queue.front();
        queue.pop();
        inQueue[current] = false;
        for(int i=1;i<=n;i++){
            //若從current可以走到i
            if(map[current][i] && 1+distance[current]>distance[i]){
                distance[i] = distance[current] + 1;
                //若queue裡沒有i，就把i塞進去
                //用inQueue可以防止跑不必要的回圈
                if(!inQueue[i]){
                    queue.push(i);
                    inQueue[i] = true;
                }
            }
        }
    }
    int maxIndex = 1;
    for(int i=2;i<=n;i++){
        //因為題目說：若是有多個maxLength，就選index最小的，因此才不考慮"="的情況
        if(distance[i] > distance[maxIndex]){
            maxIndex = i;
        }    
    }
    return maxIndex;
    
}
int main(){
    int n,start,p,q,final;
    int caseCounter = 0;
    while(scanf("%d", &n) && n){
        caseCounter++;
        scanf("%d", &start);
        //每次重新輸入n後，map要初始化為false
        bool map[101][101] = {false};
        //map是看可不可以從p走到q
        while(scanf("%d %d",&p,&q)&& p && q){
           map[p][q] = true;
        }
        //設定distance長度為n+1，每個值皆為0
        vector<int> distance(n+1, 0);
        final = findLongestPath(n, start, distance, map);
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n"
            , caseCounter, start, distance[final], final);
    }
}