#include<iostream>
#include<cstdio>
#include<sstream>
#include<vector>
#include<ctype.h>
#include<string.h>
using namespace std;
void make(string s1){
    cout<<s1;
}
int main(){
    string test = "Wesley233";
    make(&test[2]);
}