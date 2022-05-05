#include <iostream>
#include<vector>
#include<math.h>
using namespace std;
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
int main() {
    cout<<change("10011");
    
}