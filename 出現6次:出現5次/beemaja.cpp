#include<iostream>
#include<utility>
using namespace std;
const int SIZE = 100001;
pair<int,int> coord[SIZE];
int n;
int main(){
    coord[1].first = 0, coord[1].second = 0;
    int counter = 2, nowI = 0, nowJ = 0 ,i;
    //初始化Willi的座標(index)對應到的Maja座標(value)
    //round是第幾輪，決定要重複下,左下,左上,上,右上,右下幾遍
    for(int round=1;counter<SIZE;round++){
        //counter(蜂窩數量)不能大於SIZE,所有for回圈都要check
        //下
        for(i=0;i<round && counter<SIZE;i++,counter++){
            coord[counter].first = nowI;
            coord[counter].second = ++nowJ;
        }
        //左下，第一輪沒有左下，因此判斷式為round-1
        for(i=0;i<round-1 && counter<SIZE;i++, counter++){
            coord[counter].first = --nowI;
            coord[counter].second = ++nowJ;
        }
        //左上
        for(i=0;i<round && counter<SIZE;i++,counter++){
            coord[counter].first = --nowI;
            coord[counter].second = nowJ;
        }
        //上
        for(i=0;i<round && counter<SIZE;i++,counter++){
            coord[counter].first = nowI;
            coord[counter].second = --nowJ;
        }
        //右上
        for(i=0;i<round && counter<SIZE;i++, counter++){
            coord[counter].first = ++nowI;
            coord[counter].second = --nowJ;
           
        }
        //右下
        for(i=0;i<round && counter<SIZE;i++,counter++){
            coord[counter].first = ++nowI;
            coord[counter].second = nowJ;
        }
        
    }
    while(scanf("%d", &n)!=EOF && n){
        printf("%d %d\n", coord[n].first,coord[n].second);
    }
}