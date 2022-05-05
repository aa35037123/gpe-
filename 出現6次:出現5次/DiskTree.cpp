#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 50005;
//iter是自創的structer，代表iterator
typedef map<string, int>::iterator iter;
struct Trie{
  int counter;
  //sting表示資料夾名稱，filepath[0]代表在最上層檔案
  //map會按照key來做排序(key的首字母)
  map<string,int> filepath[MAXN];
  void init();
  void insert(string path);
  void print(int level, int blank);
  
}tree;
void Trie::init(){
    filepath[0].clear();
    //counter代表filename被存入map的順序
    counter=1;
}
//此函數會建立很多個以資料夾為名的map，若此資料夾底下還有子資料夾
//則map->second會和子資料夾map[i]的i一致，藉此判斷
//共通點：第一層的資料夾index皆為0
void Trie::insert(string path){
    //level表示此word會在資料夾的第幾層
    int level = 0;
    //建立空字串
    string word = "";
    for(int i=0;i<path.size();i++){
        //代表word已經為一個資料夾的完整名字
        if(path[i]=='\\'){
            //若map中還尚未有名為word的資料夾
            //filepath中有些空間會被浪費，可能會跳過幾個index
            if(!filepath[level].count(word)){
                //counter會領先level，counter=目前資料夾總量
                filepath[counter].clear();
                //filepath的value意義為：可以指向此資料夾的紫資料夾（下一level）
                filepath[level][word] = counter;
                counter++;
            }
            //level就會帶到filepath的下一個map 
            level = filepath[level][word];
            word = "";
            
        }else{
            word+=path[i];
        }
        
    }
}
//用到recursion的概念，recursion其實和stack很像，先進先出
//很像DFS的概念，會先印出第一個主資料夾的所有子資料夾，才會印第二個主資料夾
void Trie::print(int current, int blank){
    for(iter it=filepath[current].begin();it!=filepath[current].end();it++){
        for(int i=0;i<blank;i++)
            printf(" ");
        cout<<it->first<<endl;
        print(it->second, blank+1);
    }
}
int main(){
    int n;
    string path;
    while(scanf("%d", &n) && n){
        tree.init();
        for(int i=0;i<n;i++){
            cin>>path;
            path+='\\';
            tree.insert(path);
        }
        tree.print(0,0);
        
    }
 }
