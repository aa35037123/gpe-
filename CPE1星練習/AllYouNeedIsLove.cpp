#include<iostream>
#include<vector>
#include<math.h>
#include<cstdlib>
using namespace std;
const int MAX = 20000;
vector<int> str[MAX];
int change(string s){
    int counter = 0,ans = 0;
    while(s!=""){
        if(s.back()=='1'){
            ans += pow(2,counter);
            counter++;
            s.erase(s.size()-1,1);
        }
        else{
            counter++;
            s.erase(s.size()-1,1);
        }
            
    }
    return ans;
}
//利用輾轉相除法找最大公因數
//用遞迴讓每次都是大除小
int factor(int a, int b){
    if(b==0) return a;
    return factor(b,a%b);
}
int main(){
    int N,ans1,ans2,fac;
    long long int num1,num2;
    string s1,s2;
    while(cin>>N){
        //清空vector
        for(int i=0;i<2*N;i++)
            str[i].clear();
        for(int i=0;i<N;i++){
            cin >> s1>>s2;
            ans1 = change(s1);
            ans2 = change(s2);
            fac = factor(max(ans1,ans2),min(ans1,ans2));
            if(fac == 1)
                printf("Pair #%d: Love is not all you need!\n",i+1);  
            else    
                printf("Pair #%d: All you need is love!\n",i+1);               
        }
        
        
        
    }
    
}