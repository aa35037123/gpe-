#include<iostream>
#include<stdio.h>
#include<sstream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
string entry;
int v1,v2,dis;
vector<pair<int, int> > path[10001];
int ans;
int DFS(int start, int prev_node){
    int A_road = 0, temp;
    int size = path[start].size();
    for(int i=0;i<size;i++){
        if(path[start][i].first!=prev_node){
            temp = DFS(path[start][i].first, start) + path[start][i].second;
            ans = max(temp + A_road, ans);
            A_road = max(temp, A_road);
        }
    }
    return A_road;
}
int main(){
    stringstream ss;
    while(!cin.eof()){
        ans = 0;
        for(int i=0;i<10001;i++){
            path[i].clear();
        }
        while(getline(cin, entry) && entry!=""){
            ss.str("");
            ss.clear();
            ss.str(entry);
            ss>>v1>>v2>>dis;
            path[v1].push_back(make_pair(v2, dis));
            path[v2].push_back(make_pair(v1,dis));
        }
        DFS(1,0);
        printf("%d\n", ans);
    }
}