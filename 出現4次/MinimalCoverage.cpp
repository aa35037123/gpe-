#include<iostream>
#include<cstdio>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
const int SIZE = 100001;
int testcase, M, Lin, Rin;
vector<pair<int, int> > coord,ans;
typedef vector<pair<int, int> >::iterator iter;
int main(){
    while(scanf("%d", &testcase)!=EOF && testcase){
        for(int i=0;i<testcase;i++){
            coord.clear();
            ans.clear();
            if(i) printf("\n");
            scanf("%d", &M);
            while(scanf("%d %d", &Lin,&Rin) && (Lin || Rin)){
                coord.push_back(make_pair(Lin,Rin));
            }
            int pair_count = coord.size();
            sort(coord.begin(),coord.end());
            int left_bound = 0,right_bound = 0, j = 0;
            //用while迴圈為了在更新left, rightbound後繼續從segment內挑選適合的段落
            while(j<pair_count){
                //temp是跑完全部for後答案的index
                int temp = -1;
                //整個for跑完一次，選出一個最適當的ans（在左右邊界內的）
                for(;j<pair_count && coord[j].first<=left_bound;j++){
                    //右界一定會>0
                    if(coord[j].second>right_bound){
                        right_bound = coord[j].second;
                        temp = j;
                    }
                }
                //若都不在範圍內，就break
                if(temp == -1) break;
                //要記得把for跑出來的結果push進ans
                ans.push_back(coord[temp]);
                //若right超過M，就break
                if(right_bound>=M) break;
                //要再跑一次回圈找答案，把左界設為這次ans的右界
                left_bound = right_bound;
            }
            //若沒有適當答案，print0
            if(right_bound<M){
                printf("0\n");
                continue;
            }
            else{
                int ans_size = ans.size();
                printf("%d\n", ans_size);
                for(int k=0;k<ans_size;k++){
                    printf("%d %d\n", ans[k].first, ans[k].second);
                }
            }
            
        }
    }
}