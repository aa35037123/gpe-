#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
#include<sstream>
#include<vector>
using namespace std;
string entry;
stack<int> input, operand;
vector<int> temp;
int charToint,num;
int main(){
    //+, -, *, /, and %
    stringstream ss;
    while(getline(cin, entry) && entry!="."){
        int len = entry.size(), operand_count = 0,ans = 0;
        while(!operand.empty()){
            operand.pop();
        }
        for(int i=len-1;i>=0;i--){
            if(entry[i]>='0' && entry[i]<='9'){
                num = entry[i] - '0';
                input.push(num);
            }
            else if(entry[i] == ' ' && !input.empty()){
                charToint = input.top();
                input.pop();
                while(!input.empty()){
                    charToint = charToint*10 + input.top();
                    input.pop();
                }
                operand.push(charToint);
            }
            else if(entry[i] == '+'){
                while(!operand.empty()){
                    temp.push_back(operand.top());
                    operand.pop();
                    operand_count++;
                    if(operand_count == 2) break;
                    
                }
                if(operand_count<2) printf("illegal\n");
                else{
                    ans = temp[0] + temp[1];
                    operand.push(ans);
                    temp.clear();
                    operand_count = 0;
                }
            }
            else if(entry[i] == '-'){
                while(!operand.empty()){
                    temp.push_back(operand.top());
                    operand.pop();
                    operand_count++;
                    if(operand_count == 2) break;
                }
                if(operand_count<2) printf("illegal\n");
                else{
                    ans = temp[0] - temp[1];
                    operand.push(ans);
                    temp.clear();
                    operand_count = 0;
                }
            }
            else if(entry[i] == '*'){
                while(!operand.empty()){
                    temp.push_back(operand.top());
                    operand.pop();
                    operand_count++;
                    if(operand_count == 2) break;
                    
                }
                if(operand_count<2) printf("illegal\n");
                else{
                    ans = temp[0] * temp[1];
                    operand.push(ans);
                    temp.clear();
                    operand_count = 0;
                }
            }
            else if(entry[i] == '/'){
                while(!operand.empty()){
                    temp.push_back(operand.top());
                    operand.pop();
                    operand_count++;
                    if(operand_count == 2) break;
                    
                }
                if(operand_count<2) printf("illegal\n");
                else{
                    ans = temp[0] / temp[1];
                    operand.push(ans);
                    temp.clear();
                    operand_count = 0;
                }
            }
            else if(entry[i] == '%'){
                while(!operand.empty()){
                    temp.push_back(operand.top());
                    operand.pop();
                    operand_count++;
                    if(operand_count == 2) break;
                    
                }
                if(operand_count<2) printf("illegal\n");
                else{
                    ans = temp[0] % temp[1];
                    operand.push(ans);
                    temp.clear();
                    operand_count = 0;
                }
            }
        }
        if(!operand.empty()) printf("%d\n", operand.top());
        else printf("illegal\n");
    }
}