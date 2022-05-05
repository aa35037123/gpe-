#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int L,R,C;
struct Position{   
    int l;
    int r;
    int c;
    int minute;
    //constructor:在創建struct時可以直接把相關數據放在()裡面，初始化很方便
    //:後面為<struct內的element>(讓此數值等於多少)，意思為element = x
    //constructor後面要加上{}
    Position(int l, int r, int c, int minute):l(l),r(r),c(c),minute(minute){};
};
//BFS廣度優先搜尋，利用queue先進先出的特性，可以把此格可能的選擇走過一遍後，再去下一個可能的選擇
int BFS(char dungeon[][35][35], int now_level, int now_row, int now_column){
    //設queue的datatype為自訂的struct
    queue<Position> map;
    //不用像<struct名><自訂名>創建再push，可以直接用constructor push進queue
    map.push(Position(now_level,now_row,now_column,0));
    //若queue內還有成員，就繼續loop
    while(!map.empty()){
        Position p = map.front();
        //最後把這次loop經過的p pop掉
        map.pop();
        //若此點的數值超過邊界，就移出queue，並且continue
        if(p.l >= L || p.r >= R || p.c >= C ||
            p.l < 0 || p.r < 0 || p.c < 0 || dungeon[p.l][p.r][p.c] == '#'){
            continue;
        }
        if(dungeon[p.l][p.r][p.c] == 'E'){
            return p.minute;
        }
        //若此格為'.'就用BFS找其他有可能的方向（上下東西南北），並把這格封住
        //避免BFS再找到經過的點，造成minute數不正確
        dungeon[p.l][p.r][p.c] = '#';
        //此點往上
        map.push(Position(p.l+1 , p.r , p.c, p.minute+1));
        //此點往下
        map.push(Position(p.l-1 , p.r , p.c, p.minute+1));
        //此點往北
        map.push(Position(p.l , p.r+1 , p.c, p.minute+1));
        //此點往南
        map.push(Position(p.l , p.r-1 , p.c, p.minute+1));
        //此點往東
        map.push(Position(p.l , p.r , p.c+1, p.minute+1));
        //此點往西
        map.push(Position(p.l , p.r , p.c-1, p.minute+1));
    }
    return -1;
}
int main(){
    while(scanf("%d %d %d", &L,&R,&C) && L!=0 && R!=0 && C!=0){
        int start_level, start_row, start_column;
        char dungeon[35][35][35];
        for(int k=0;k<L;k++){
            for(int i=0;i<R;i++){
                for(int j=0;j<C;j++){
                    cin>>dungeon[k][i][j];
                    if(dungeon[k][i][j] == 'S'){
                        dungeon[k][i][j] = '.';
                        start_level = k, start_row = i, start_column = j;
                    }
                }
            }
        }
        int minute = BFS(dungeon, start_level, start_row, start_column);
        if(minute == -1) printf("Trapped!\n");
        else printf("Escaped in %d minute(s).\n", minute);
    }
}