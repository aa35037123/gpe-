#include<iostream>
#include<cstdio>
using namespace std;
bool FindSudoAns(int sudo[][9], bool row[][10], bool column[][10], bool box[][10], int index){
    int row_num = index/9, col_num = index%9;
    if(index == 81) return true;
    if(sudo[row_num][col_num]!=0)   return FindSudoAns(sudo,row,column,box,index+1);    
    for(int i=1;i<=9;i++){
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
int n;
int main(){
    while(scanf("%d", &n)!=EOF && n){
        for(int k=0;k<n;k++){
            int sudo[9][9] = {0};
            bool row[9][10] = {false}, column[9][10] = {false}, 
                box[9][10] = {false}, hasSolution = true;
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    scanf("%d", &sudo[i][j]);
                    if(sudo[i][j]!=0){
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
            if(!hasSolution)
                printf("NO\n");
            if(FindSudoAns(sudo,row,column,box,0)){
                for(int i=0;i<9;i++){
                    for(int j=0;j<9;j++){
                        if(j) printf(" ");
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