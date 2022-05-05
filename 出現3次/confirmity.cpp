#include<iostream>
#include<cstdio> 
#include<vector>
#include<sstream>
#include<algorithm>
#include<map>
using namespace std;
vector<string> course;
map<string, int> popular;
map<string, int>::iterator iter;
int n,max_val,total;
string entry,line,input;
int main(){
	while(scanf("%d", &n)!=EOF && n){
		max_val = 0;
		total = 0;
		popular.clear();
		for(int testcase=0;testcase<n;testcase++){
			course.clear();
			line = "";
			//know that each line only has 5 nums 
			for(int i=0;i<5;i++){
				cin>>input;
				course.push_back(input);
			}
			sort(course.begin(), course.end());
			for(int i=0;i<5;i++){
				line+=course[i];
			}
			//map會把初始的value值設定為0
			popular[line]++;
		}
		//first for-loop:find max_val
		for(iter = popular.begin(); iter!=popular.end();iter++){
			if(iter->second > max_val){
				max_val = iter->second;
			}
		}
		//second for-loop:use max_val to sum up total
		for(iter = popular.begin(); iter!=popular.end();iter++){
			if(iter->second == max_val){
				total+=max_val;
			}
		}
		printf("%d\n", total);
//		for(int i=0;i<n;i++){
//			int len = course[i].size();
//			for(int j=0;j<len;j++){
//				if(j) printf(" ");
//				printf("%d", course[i][j]);
//			}
//			printf("\n");
//		}
	}	
}