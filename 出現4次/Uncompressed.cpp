#include<iostream>
#include<cstdio>
#include<vector>
#include<ctype.h>
using namespace std;
vector<string> list;
string entry,word;
void make_list(int pos){
    string temp = list[pos-1];
    for(int i=pos-1;i>0;i--){
        list[i] = list[i-1];
    }
    list[0] = temp;
}
void add_list(string word){
    list.push_back(word);
    int size = list.size();
    for(int i = size-1;i>0;i--){
        list[i] = list[i-1];
    }
    list[0] = word;
}
int main(){
    while(getline(cin,entry) && entry!="0"){
        word = "";
        entry+='\n';
        int len = entry.size();
        int num = 0;
        for(int i=0;i<len;i++){
            if((entry[i]>='a' && entry[i]<='z')||(entry[i]>='A' && entry[i]<='Z')){
                word+=entry[i];
            }
            else if(isdigit(entry[i])){
                num = num*10 + (entry[i] - '0');
            }
            else{
                if(word!=""){
                    add_list(word);
                    cout<<word;
                    word = "";
                }
                if(num!=0){
                    cout<<list[num-1];
                    make_list(num);
                }
                num = 0;
                printf("%c", entry[i]);
                
            }
        }
    }
}