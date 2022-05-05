#include<iostream>
#include<cstdio>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
int n,start,v1,v2;
int map[101][101];
int FindLongestPath(int n,int start, vector<int> &distance){
    stack<int> stack;
    bool inQueue[101] = {false};
    stack.push(start);
    while(!stack.empty()){
        int current = stack.top();
        stack.pop();
        inQueue[current] = false;
        for(int i=1;i<=n;i++){
            if(map[current][i] && distance[current]+1>distance[i]){
                distance[i] = distance[current] + 1;
                if(!inQueue[i]){
                    stack.push(i);
                    inQueue[i] = true;
                }
            }
        }
    }
    int maxIndex = 1;
    for(int i=2;i<=n;i++){
        if(distance[i] > distance[maxIndex])
            maxIndex = i;
    }
    return maxIndex;
    
}
int main(){
    int casecount = 0;
    while(scanf("%d", &n)!=EOF && n){
        memset(map,0,sizeof(map));
        vector<int> distance(n+1,0);
        casecount++;
        scanf("%d",&start);
        while(scanf("%d %d",&v1,&v2)!=EOF && v1 && v2){
            map[v1][v2] = 1;
        }
        int ans = FindLongestPath(n,start,distance);
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n"
            ,casecount,start,distance[ans],ans);
        printf("\n");

    }
}