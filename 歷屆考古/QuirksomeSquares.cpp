//重點想法：枚舉 把可能的情況通通列出來，再取可能的情況
//有許多vector, string用法，盡量多學點
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector <string> res;
string num2str(int num, int N){
    //ret為空string
    string ret = "";
    //若num變為0，則離開loop
    while(num){
        //每次把num的個位數加進retstring中
        //要在前面放一個'0'，才能夠做為char放入string中
        ret += '0' + (num%10);
        //每次loop結束後，num的個位數都會被去掉
        //因為num是int，若/10後為小數，則會自動變為0
        num /= 10;
    }
    //把ret反過來，因為數字放進ret時是反的
    reverse(ret.begin(), ret.end());
    while(ret.length()< N){
        //若ret長度比N小，則在前面補0
        ret = '0' + ret;
    }
    return ret;
}
int main(void){
    int digit;
    //若有持續輸入數字，while迴圈就會繼續進行
    while(cin>>digit){
        //在開頭要清空上一次放進去的數字
        res.clear();
        //mx為前段數字要乘的倍數(10的倍數)
        int mx = 1;
        digit/=2;
        for(int i=0;i<digit;i++){
            mx *= 10;
        }
        for(int i=0;i<mx;i++){
            for(int j=0;j<mx;j++){
                //表示此數字為quirkNumber
                if((i+j)*(i+j) == (i*mx+j)){
                    res.push_back(num2str(i, digit)+num2str(j, digit));
                }
            }
        }
        
        vector<string>::iterator it_i;
        for(it_i = res.begin(); it_i!=res.end(); it_i++){
            //這裡的*注意要和<<分開，不然會錯誤
            cout<< *it_i <<endl;
        }       
       
    }

}