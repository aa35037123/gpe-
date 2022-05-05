#include<iostream>
#include<cstdio>
using namespace std;
int T, M, N, Q;
string graph[105];
string entry;
//依序為x,y向右下左上的方向
int direction[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
bool isValid(int nowX, int nowY, int M, int N){
    if(nowX < 0 || nowX >= M || nowY < 0 || nowY >= N) return false;
    return true;
}
int FindThePath(int x, int y, int M, int N){
    //root是square中心char
    char root = graph[x][y];
    //d為邊長
    int d = 1;
    bool flag = true;
    int nowX, nowY;
    while(flag){
        d+=2;
        //從左上角開始檢查，依序由右下左上檢查一圈，若都==root，就往下一圈看
        nowX = x-(d/2), nowY = y-(d/2);
        //四個方向
        for(int i=0;i<4;i++){
            for(int j=0;j<d-1;j++){
                nowX += direction[i][0];
                nowY += direction[i][1];
                //若超出範圍，或是目前字元和root不同的話
                if(!isValid(nowX, nowY, M, N) || graph[nowX][nowY] != root){
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
    }
    return d-2;
}
int main(){
    while(scanf("%d", &T)!=EOF){
        while(T--){
            for(int i=0;i<105;i++) graph[i].clear();
            cin>>M>>N>>Q;
            for(int i=0;i<M;i++) cin>>graph[i];
            printf("%d %d %d\n", M, N, Q);
            int x, y;
            for(int i=0;i<Q;i++){
                cin>>x>>y;
                int path = FindThePath(x, y, M, N);
                printf("%d\n", path);
            }
        }
    }
}