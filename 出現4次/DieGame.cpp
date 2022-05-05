#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int total;
vector<string>direction;
string input;
int main(){
    while(cin>>total && total){
        direction.clear();
        for(int i=0;i<total;i++){
            cin>>input;
            direction.push_back(input);
        }
        int dire_size = direction.size();
        int top = 1,bottom = 6,north = 2,east = 4, south = 5, west = 3;
        for(int i=0;i<dire_size;i++){
            //west和east不變
            if(direction[i] == "north"){
                north = top;
                top = south;
                south = 7 - north;
                bottom = 7 - top;
            }
            //west和east不變
            if(direction[i] == "south"){
                south = top;
                top = north;
                north = 7 - south;
                bottom = 7 - top;
            }
            //north和south不變
            if(direction[i] == "east"){
                east = top;
                top = west;
                west = 7 - east;
                bottom = 7 - top;
            }
            //north和south不變
            if(direction[i] == "west"){
                west = top;
                top = east;
                east = 7 - west;
                bottom = 7 - top;
            }
        }
        cout<<top<<"\n";
    }
}