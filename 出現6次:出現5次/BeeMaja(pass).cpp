#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

const int SIZE = 100000;

struct point
{
    int x, y;
};
point p[SIZE + 1];
void create()
{
    p[1].x = 0, p[1].y = 0;
    int index = 2;
    int nowI = 0, nowJ = 0, count, num;
    for (num = 1; index <= SIZE; num ++)
    {
        for (count = 0; count < num && index <= SIZE; count ++, index ++)
            p[index].x = nowI, p[index].y = ++ nowJ;
        for (count = 0; count < num - 1 && index <= SIZE; count ++, index ++)
            p[index].x = -- nowI, p[index].y = ++ nowJ;
        for (count = 0; count < num && index <= SIZE; count ++, index ++)
            p[index].x = -- nowI, p[index].y = nowJ;
        for (count = 0; count < num && index <= SIZE; count ++, index ++)
            p[index].x = nowI, p[index].y = -- nowJ;
        for (count = 0; count < num && index <= SIZE; count ++, index ++)
            p[index].x = ++ nowI, p[index].y = -- nowJ;
        for (count = 0; count < num && index <= SIZE; count ++, index ++)
            p[index].x = ++ nowI, p[index].y = nowJ;
    }
}

int main(){
    create();
    int n;
    
    while (scanf("%d", &n) == 1){
        printf("%d %d\n", p[n].x, p[n].y);
    }
}