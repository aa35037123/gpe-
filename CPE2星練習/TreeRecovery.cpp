//uva 536
//此題考BinaryTree的traversal方式：
//preorder：中左右，inorder：左中右，postorder：左右中
#include<iostream>
#include<cstdio>
//find和substr都在string函式庫中
#include<string>
using namespace std;
//postord要用"&"確保改到真實的值，因為postord需要保存更新後的結果
void recover(string &preord, string &inord, string &postord){
    if(preord.size()){
        string PreLeft, PreRight, InLeft, InRight;
        char root = preord[0];
        //find會找出字串裡面最先出現()中字元(或字串)的index
        int FindRootIndex = inord.find(root);
        //substr可以裁切原本的字串，()中兩個argument分別是：
        //1.從string的多少index開始切 2.要找多少個字元
        //若只有放一個argument代表從那個index一路切到最後
        InLeft = inord.substr(0, FindRootIndex);
        InRight = inord.substr(FindRootIndex+1);
        int len = InLeft.size();
        //postorder的方式：左右中
        PreLeft = preord.substr(1, len);
        PreRight = preord.substr(len+1);
        //按照左右中的順序traversal
        recover(PreLeft, InLeft, postord);
        recover(PreRight, InRight, postord);
        postord+=root;
    }
}
int main(){
    string preord, inord, postord;
    while(cin>>preord>>inord && !cin.eof()){
        postord = "";
        recover(preord, inord, postord);
        cout<<postord<<"\n";
    }
}