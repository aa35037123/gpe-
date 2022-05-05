#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;
int N, M;
struct rect{
    int x;
    int y;
};
int main(){
    int i, j, k, l;
    bool flag;
    rect a, b, c, d;
    while(cin>>N){
        for(int testcase=1;testcase<=N;testcase++){
            flag = false;
            cin>>M;
            cin>>a.x>>a.y>>b.x>>b.y;
            i = a.x, j = a.y, k = b.x, l = b.y;
            M--;
            while(M--){
                cin>>c.x>>c.y>>d.x>>d.y;
                i = max(a.x, c.x), j = max(a.y, c.y);
                k = min(b.x, d.x), l = min(b.y, d.y);
                //這裡不能加break，因為要把測資都輸入完
                if(i>=k || j>=l){
                    flag = true;
                }
                //一定要多一個a, b，因為若發生上面的狀況，這時的i, j, k, l就不能用
                else{
                    a.x = i, a.y = j, b.x = k, b.y = l;
                }
            }
            //這裡還要判斷一次是否倒過來，注意n=1時的狀況
            if(i>=k || j>=l) flag = true;
            printf("Case %d: ", testcase);
            if(!flag) printf("%d\n", (i-k)*(j-l));
            else printf("0\n");
        }
    }
}