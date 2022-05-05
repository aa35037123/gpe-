#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
//此array放的是index城市的上一個(parent)
int parent[26];
//此vector放的是從rome到city(index)經過的城市名稱
vector<int> Road[26];
int t, M, N;
int main(){
    while(scanf("%d", &t)!=EOF){
        string str1, str2;
        int n1, n2;
        while(t--){
            cin>>M>>N;
            memset(parent, -1, sizeof(parent));
            for(int i=0;i<26;i++) Road[i].clear();
            for(int i=0;i<M;i++){
                cin>>str1>>str2;
                n1 = str1[0] - 'A';
                n2 = str2[0] - 'A';
                //n2的上一個城市是n1
                parent[n2] = n1;
            }
            int current;
            for(int i=0;i<26;i++){
                current = i;
                Road[i].push_back(current);
                while(parent[current] != -1){
                    Road[i].push_back(parent[current]);
                    current = parent[current];
                }
            }
            for(int i=0;i<N;i++){
                cin>>str1>>str2;
                n1 = str1[0] - 'A';
                n2 = str2[0] - 'A';
                int root, len1 = Road[n1].size(), len2 = Road[n2].size();
                for(int j=0;j<len1;j++){
                    for(int k=0;k<len2;k++){
                        if(Road[n1][j] == Road[n2][k]){
                            root = Road[n1][j];
                            break;
                        }
                    }
                    if(Road[n1][j] == root) break;
                }
                for(int j=0;j<len1;j++){
                    if(Road[n1][j] == root) break;
                    cout<<char(Road[n1][j] + 'A');
                }
                bool flag = false;
                for(int k=len2-1;k>=0;k--){
                    if(Road[n2][k] == root) flag = true;
                    if(flag) cout<<char(Road[n2][k] + 'A');
                }
                printf("\n");
            }
        }
    }
}