#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int N, testcase, H, W;
char map[25][25];
int visited[25][25];
//把區域一樣的都挖出來，visited改成1
void DFS(int x, int y, int H, int W){
    visited[x][y] = 1;
    if(map[x+1][y] == map[x][y] && !visited[x+1][y] && x >= 0 && x < H) DFS(x+1, y, H, W);
    if(map[x-1][y] == map[x][y] && !visited[x-1][y] && x >= 0 && x < H) DFS(x-1, y, H, W);
    if(map[x][y+1] == map[x][y] && !visited[x][y+1] && y >= 0 && y < W) DFS(x, y+1, H, W);
    if(map[x][y-1] == map[x][y] && !visited[x][y-1] && y >= 0 && y < W) DFS(x, y-1, H, W);
}

int main(){
    while(scanf("%d", &N)!=EOF){
        testcase = 0;
        while(N--){
            memset(visited, 0, sizeof(visited));
            testcase++;
            scanf("%d %d", &H, &W);
            getchar();
            for(int i=0;i<H;i++){
                for(int j=0;j<W;j++){
                    scanf("%c", &map[i][j]);
                }
                getchar();
            }
            int maxArea = 0, letters[30] = {0};
            for(int i=0;i<H;i++){
                for(int j=0;j<W;j++){
                    //若沒有來過這個點的話
                    if(!visited[i][j]){
                        letters[map[i][j]-'a']++;
                        maxArea = max(letters[map[i][j]-'a'], maxArea);
                        //DFS目的為找到相連的同樣字母的區域，把經過的所有字母都改成visited
                        DFS(i, j, H, W);
                    }
                }
            }
            printf("World #%d\n", testcase);
            //順序：第一個比area，第二個比字母順序
            for(int j=maxArea;j>0;j--){
                for(int i=0;i<26;i++){
                    if(letters[i] == j){
                        printf("%c: %d\n", char('a'+i), j);
                    }
                }
            }
        }
    }
}