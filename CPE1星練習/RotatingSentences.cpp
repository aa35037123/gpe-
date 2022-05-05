#include<iostream>
using namespace std;
const int MAX = 100;
string s[MAX];
int main(){
    int row = 0,column = 0;
    while(getline(cin,s[row])){
        //用(int)告訴編譯器size為int
        //選出最長的輸入字串作為column
        column=max(column,(int)s[row].size());
        row++;
    }
    //兩個for迴圈在做行列互換
    for(int i=0;i<column;i++){
        for(int j=row-1;j>=0;j--){  
            //若要輸出的col超過此字串的長度，就補" "
            if(i>=s[j].size()) 
                cout<<" ";
            else
                cout<<s[j][i];
         }
         cout<<endl;
    }
    
    
    
}