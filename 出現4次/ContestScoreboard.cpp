#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include<string.h>
using namespace std;
struct Team{
    bool ifjoin;
    int penalty;
    int problem;
    int num;
    int error[10];
};
bool compare(Team a, Team b){
    if(a.problem>b.problem)
        return true;
    if(a.problem<b.problem)
        return false;
    if(a.penalty<b.penalty)
        return true;
    if(a.penalty>b.penalty)
        return false;
    if(a.num<b.num)
        return true;
    return false;
}
int casecount,team_num,question,times;
char L;
string entry;
stringstream ss;
int main(){
    Team teams[105];
    while(scanf("%d", &casecount)!=EOF){
        getchar();
        getchar();
        for(int i=0;i<casecount;i++){
            for(int j=0;j<105;j++){
                teams[j].ifjoin = false;
                teams[j].penalty = 0;
                teams[j].problem = 0;
                teams[j].num = j;
                memset(teams[j].error,0,sizeof(teams[j].error));                
            }
            if(i) printf("\n");
            while(getline(cin, entry) && entry!=""){
                ss.clear();
                ss.str(entry);  
                ss>>team_num>>question>>times>>L;
                teams[team_num].ifjoin = true;
                if(teams[team_num].error[question] == -1)
                    continue;
                if(L=='C'){
                    teams[team_num].problem++;
                    teams[team_num].penalty+=times + teams[team_num].error[question]*20;
                    teams[team_num].error[question] = -1;
                }
                if(L=='I'){
                    teams[team_num].error[question]++;
                }
            }
            sort(teams, teams+105,compare);
            for(int k=0;k<105;k++){
                if(teams[k].ifjoin)
                    printf("%d %d %d\n", teams[k].num, teams[k].problem, teams[k].penalty);
            }
        }

    }
}