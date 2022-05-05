#include<iostream>
#include<vector>
using namespace std;
vector<string>list;
//要加typedef，創造iterator的library
typedef vector<string>::iterator iter;
void moveString(string front){
    list.push_back(list.back());
    for(int i=list.size()-1;i>0;i--){
        list[i] = list[i-1];
    }
    list[0] = front;

}
void printNum(int num){
    string temp = list[num-1];
    cout<<list[num-1];
    for(int i=num-1;i>0;i--){
        list[i] = list[i-1];
    }
    list[0] = temp;
    num = 0;
}
void printWord(string &word){
    cout << word;
    if(list.empty()){
        list.push_back(word);
    }
    else{
        moveString(word);
    }
    word="";
}
int main(){
    string s,word="";
    int num = 0;
    while(getline(cin,s)){
        if(s=="0") break;
        s+="\n";
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                num *= 10;
                //char之間減法可以變成int
                num += s[i]-'0';
            }
            else if(isalpha(s[i])){
                word+=s[i];
            }
            else{
                if(num){
                printNum(num);
                }
                else if(word!=""){
                    printWord(word);
                }
                cout<<s[i];
            }
            
        }
    }
}