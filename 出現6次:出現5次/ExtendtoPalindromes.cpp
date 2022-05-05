#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int SIZE = 100001;
char S[SIZE];
char P[SIZE];
int Next[SIZE];
void GetNext(char P[]){
    int i = 0, j = -1;
    Next[0] = -1;
    while(P[i]){
        if(j==-1 || P[i] == P[j]){
            i++;
            j++;
            //優化版KMP演算法，若在index為i時匹配失敗，先檢查P[i]和P[j]是否一樣
            //若一樣，那麼換匹配字串的index後，還是匹配不上，因此就要找原對應LPS的下一個LPS
            if(P[i]!=P[j])
                Next[i] = j;
            else    
                Next[i] = Next[j];
            /*
            沒優化版：直接寫Next[i] = j;
            */
         }
        else{
            j = Next[j];
        }
    }
} 
int KMP(char S[], char P[]){
    int i =0,j=0;
    while(S[i]){
        if(j == -1 || S[i] == P[j]){
            i++;
            j++;
        }
        else{
            j = Next[j];
        }
    }
    return j;
}
int main(){
    while(scanf("%s", S)!=EOF){
        int len = strlen(S);
        for(int i=0; i<len;i++){
            P[i] = S[len-1-i];
        }
        P[len] = '\0';
        GetNext(P);
        int cut = KMP(S,P);
        printf("%s%s\n", S,&P[cut]);
    }
    return 0;
}