#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char map[25][25];
int N, H, W, visited[25][25], letters[30], max_Area;
void DFS(int x, int y){
    visited[x][y] = 1;
    if(!visited[x+1][y] && map[x+1][y] == map[x][y])    DFS(x+1, y);
    if(!visited[x-1][y] && map[x-1][y] == map[x][y])    DFS(x-1, y);
    if(!visited[x][y+1] && map[x][y+1] == map[x][y])    DFS(x, y+1);
    if(!visited[x][y-1] && map[x][y-1] == map[x][y])    DFS(x, y-1);
}
int main(){
    while(cin>>N){
        for(int testcase=1;testcase<=N;testcase++){
            cin>>H>>W;
            getchar();
            for(int i=0;i<H;i++){
                for(int j=0;j<W;j++){
                    scanf("%c", &map[i][j]);
                }
                getchar();
            }
            memset(visited, 0, sizeof(visited));
            memset(letters, 0, sizeof(letters));
            max_Area = 0;
            for(int i=0;i<H;i++){
                for(int j=0;j<W;j++){
                    if(!visited[i][j]){
                        letters[map[i][j]-'a']++;
                        max_Area = max(letters[map[i][j] - 'a'], max_Area);
                        DFS(i, j);
                    }
                }
            }
            printf("World #%d\n", testcase);
            for(int i=max_Area; i>0;i--){
                for(int j=0;j<26;j++){
                    if(letters[j] == i){
                        printf("%c: %d\n", char(j+'a'), i);
                    }
                }
            }
        }
    }
    
}