#include<iostream>
#include<cstdio>
using namespace std;
//程式會把“”裡面的視為字串，因此要多加一個\n的位置
char kind[11][3][6] = {
    {"10000",
     "11110",
     "10000"},
    {"10000",
     "11110",
     "01000"},
    {"10000",
     "11110",
     "00100"},
    {"10000",
     "11110",
     "00010"},
    {"01000",
     "11110",
     "01000"},
    {"01000",
     "11110",
     "00100"},
    {"11000",
     "01110",
     "01000"},
    {"11100",
     "00111",
     "00000"},
    {"11000",
     "01110",
     "00100"},
    {"11000",
     "01110",
     "00010"},
    {"11000",
     "01100",
     "00110"}
};
int testcase, graph[6][6];
//順時針轉動
void rotate(){
    int temp[6][6];
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            //若t[i][j] = g[j][i]，那麼t是g的行列互換版
            //但無法規律轉動，只會在兩個形狀互換
            //這裡特地用5-j，所以t的左右會再反過來，變順時針轉90度
            temp[i][j] = graph[5-j][i];
        }
    }
    //這裡是把temp值傳回去g
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            graph[i][j] = temp[i][j];
        }
    }
}
//鏡像對稱
void mirrorFlip(){
    int temp[6][6];
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            //t會是g矩陣的鏡像對稱（列相同，行鏡像對稱）
            temp[i][j] = graph[i][5-j];
        }
    }
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            graph[i][j] = temp[i][j];
        }
    }
}
bool check(){
    int i,j,k,p,q;
    //i是題目給的形狀的列
    for(i=0;i<6;i++){
        //j是題目給的形狀的行
        for(j=0;j<6;j++){
            //k是第幾個形狀
            for(k=0;k<11;k++){
                //p是已定好形狀的列
                for(p=0;p<3;p++){
                    //q是已定好形狀的行
                    for(q=0;q<5;q++){
                        //=0就不需要比較，直接出回圈就好
                        if(kind[k][p][q] == '0')
                            continue;
                        //若i+p or j+q超過範圍6，就出這兩個回圈（讓p跟q超過範圍）
                        if(i+p>=6 || j+q>=6 || 
                            graph[i+p][j+q] != kind[k][p][q])
                            p = 10, q = 10;
                    }
                }
                //若把定好形狀的3列都跑完，就是全部符合的意思
                if(p == 3)
                    return true;
            }
        }
    }
    return false;
}
bool solution(){
    //左右顛倒只要1次就夠了
    for(int i=0;i<2;i++){
        //因為一次是逆時針轉90度，所以要轉4次，才能涵蓋所有形狀
        for(int j=0;j<4;j++){
            if(check())
                return true;
            rotate();
        }
        mirrorFlip();
    }
    return false;
}
int main(){
    while(scanf("%d", &testcase)!=EOF){
        for(int i=0;i<testcase;i++){
            if(i) printf("\n");
            for(int j=0;j<6;j++){
                for(int k=0;k<6;k++){
                    scanf("%d", &graph[j][k]);
                    //把g變成char，比較好跟範例比較
                    graph[j][k] += '0';
                }
            }
            if(solution())
                printf("correct\n");
            else
                printf("incorrect\n");
        }
    }
}