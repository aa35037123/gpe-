/*
解題思路：找一个节点，例如节点i进行搜索找到一条最远的路径，这条路径现在记为Aroad，
然后回溯搜索从i出发的另外一条离i最远的路径，记为Broad。答案就是相当于以i节点为中介，找到的两条路的和。
*/
#include <cstdio>
#include<iostream>
#include <vector>
#include<sstream>
#include<utility>
using namespace std;
const int SIZE = 10001;
pair<int,int> p;
//map為adjList
vector<pair<int,int> >map[SIZE];
int ans;
//使用recursion而不是stack的原因是需要更新prev_node和current的值
//所以寫成函數會較方便
int DFS(int current, int prev_point){
    //A_road是從currentNode可以走到的最長路徑
    //temp為目前的路徑再加上走到下個Node的距離
    int A_road = 0,temp;
    //vector.size()是看裡面有多少元素
    int map_size = map[current].size();
    for(int i=0;i<map_size;i++){
        int next = map[current][i].first;
        //recursion的exit condition
        if(next != prev_point){
            //temp是從目前vertex可能走的距離
            temp = DFS(next, current) + map[current][i].second; 
            ans = max(ans, temp+A_road);
            A_road = max(temp,A_road);
        }
    }
    
    return A_road;
}
int main(){
    int v1,v2,len;
    string entry;
    //用來讓字串變成int的語法
    stringstream ss;
    //表示輸入尚未結束
    while(!cin.eof()){
        for(int i=0;i<SIZE;i++){
            map[i].clear();
        }
        ans = 0;
        while(getline(cin, entry) && entry!=""){
            //要先清空ss
            ss.str("");
            ss.clear();
            //把s輸入進ss中
            ss.str(entry);
            //類似cin，把ss輸入到v1,v2,len
            ss>>v1>>v2>>len;
            //路是雙向的，所以push兩次
            map[v1].push_back(make_pair(v2,len));
            map[v2].push_back(make_pair(v1,len));
        }   
        DFS(1,0);
        printf("%d\n", ans);
    }
}