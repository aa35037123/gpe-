#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
map<string, int> popular;
vector<string>course;
string name;
int n;
int main(){
    while(scanf("%d", &n) && n){
        popular.clear();
        for(int i=0;i<n;i++){
            string title = "";
            course.clear();
            for(int j=0;j<5;j++){
                cin>>name;
                course.push_back(name);
            }
            sort(course.begin(), course.end());
            for(int j=0;j<5;j++){
                title+=course[j];
            }
            popular[title]++;
            cout<<popular[title]<<" ";
        }
    }
}