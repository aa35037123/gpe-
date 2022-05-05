#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n;
//function若call一個array，function可以直接修改array的真實值，不用加&or*
bool FindSudoAns(int sudo[9][9], bool row[][10], bool column[][10], bool box[][10], int index){
    //因為一row有9個數字，所以9個recursion後才會+1，用/9決定
    //但column每次都要+1，所以用%9決定
    int row_num = index/9, col_num = index%9;
    //如果能撐到最後一個index(80),此index的function會再遞迴一次，就會到index==81
    //代表所有結果皆正確，因此回傳true
    if(index == 81) return true;
    //若sudo不為零，直接叫下一個recursion(表示此格不用改)
    //每次function call, index都要+1
    if(sudo[row_num][col_num]!=0) 
        return FindSudoAns(sudo,row,column,box,index+1);
    //若sudo是零的話，就要在每格試1-9
    for(int i=1;i<=9;i++){
        //照數獨規則，若不符合就跳過
        if(!row[row_num][i] && !column[col_num][i] && !box[row_num/3*3+col_num/3][i]){
            sudo[row_num][col_num] = i;
            row[row_num][i] = true;
            column[col_num][i] = true;
            box[row_num/3*3+col_num/3][i] = true;
            if(FindSudoAns(sudo,row,column,box,index+1)) return true;
            sudo[row_num][col_num] = 0;
            row[row_num][i] = false;
            column[col_num][i] = false;
            box[row_num/3*3+col_num/3][i] = false;
        } 
    }
    return false;
    
}
int main(){
    while(scanf("%d", &n)!=EOF && n){
        for(int k=0;k<n;k++){
            int sudo[9][9] = {0};
            bool row[9][10] = {false}, column[9][10] = {false}, 
                box[9][10] = {false}, hasSolution = true;
            //i是row,j是column
            //把每個數字放進sudo中，並看數字有無在row or column中
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    scanf("%d", &sudo[i][j]);
                    //若為零就不要放進row or column or box中
                    if(sudo[i][j]!=0){
                        //若同行or同列or同box中有數字重複出現，就沒有解
                        if(row[i][sudo[i][j]] || column[j][sudo[i][j]]
                            || box[(i/3)*3+j/3][sudo[i][j]]){
                                hasSolution = false;
                            }
                        row[i][sudo[i][j]] = true;
                        column[j][sudo[i][j]] = true;
                        box[(i/3)*3+j/3][sudo[i][j]] = true;
                    }
                }
            }
            if(!hasSolution){
                printf("NO\n");
                continue;
            }
                //注意這裡function傳送array的寫法
                if(FindSudoAns(sudo,row,column,box,0)){
                    for(int i=0;i<9;i++){
                        for(int j=0;j<9;j++){
                            if(j)
                                printf(" ");
                            printf("%d", sudo[i][j]);
                        }
                        printf("\n");
                    }
                }
                else
                    printf("NO\n");
            
            
            
        }
        
    }
}