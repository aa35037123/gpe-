#include<iostream>
#include<cstdio>
#include<string.h>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
int N, dp[1001][31],object_num,price,weight,people,people_weight;
pair<int, int> object[1001];
vector<int> person,ans;
void find_item(int item,int now_weight){
    if(dp[item][now_weight]-object[item].first == dp[item-1][now_weight-object[item].second] && item!=0 && weight!=0){
        ans.push_back(item);
        find_item(item-1,now_weight-object[item].second);
    }
    else if(dp[item][now_weight]-object[item].first != dp[item-1][now_weight-object[item].second] && item!=0 && weight!=0){
       find_item(item-1,now_weight);
    }
}
int main(){
    while(scanf("%d", &N)!=EOF){
        for(int testcase=0;testcase<N;testcase++){
            int max_value = 0;
            person.clear();
            memset(dp,0,sizeof(dp));
            scanf("%d", &object_num);
            for(int count=1;count<=object_num;count++){
                scanf("%d %d",&price,&weight);
                object[count].first = price;
                object[count].second = weight;
            }
            scanf("%d", &people);
            for(int prs_count=0;prs_count<people;prs_count++){
                scanf("%d",&people_weight);
                person.push_back(people_weight);
            }
            for(int p=0;p<people;p++){
                //當i=0(沒有可以比較的item時)或是j=0(負重不夠放入任何物品時)，value為0(base case)
                ans.clear();
                memset(dp,0,sizeof(dp));
                //i代表目前在看的item，從1開始
                for(int i=1;i<=object_num;i++){
                    //J代表目前重量
                    for(int j=0;j<=person[p];j++){
                        //j<目前item的重量，代表還不能放入此item，故只能不選擇此物品，用上面一格的value
                        if(j<object[i].second)
                            dp[i][j] = dp[i-1][j];
                        //max在algorithm中
                        //若j>=目前item重量，代表可以放入此item，此時有2種選擇：
                        //放入此物品，value為此物value+dp[row-1][column-item重]，或是不放入此item，value為[row-1][column]
                        //此格value就選擇為兩種情況的最大值
                        else   
                            dp[i][j] = max(dp[i-1][j],dp[i-1][j-object[i].second]+object[i].first);
                    }
                }
                //查看dp表
                for(int i=0;i<=object_num;i++){
                    for(int j=0;j<=person[p];j++){
                        if(j) printf(" ");
                        printf("%d", dp[i][j]);
                    }
                    printf("\n");
                }
                //此函式是用來找湊成最大值的組合為何
                find_item(object_num, person[p]);
                int ans_size = ans.size();
                printf("chosen items: ");
                for(int i=ans_size-1;i>=0;i--){
                    printf("%d ", ans[i]);
                    if(i) printf(" ");
                }
                printf("\n");
                //max value是每個人最大value的總和
                max_value+=dp[object_num][person[p]];
            }
            
            printf("%d\n", max_value);
        }
    }
}