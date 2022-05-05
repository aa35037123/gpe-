#include <iostream>
using namespace std;
void travel(string &preord,string &inord,string &postord)
{
    if(preord.size())
    {
        string PreLeft,PreRight,InLeft,InRight;
        char root=preord[0];
        int FindRootInord=inord.find(root);

        InLeft=inord.substr(0,FindRootInord);
        InRight=inord.substr(FindRootInord+1);
        PreLeft=preord.substr(1,InLeft.size());
        PreRight=preord.substr(InLeft.size()+1);

        travel(PreLeft,InLeft,postord);//left
        travel(PreRight,InRight,postord);//right
        postord+=root;
    }
}
int main()
{
    string preord,inord;
    while(cin>>preord>>inord)
    {
        string postord="";
        travel(preord,inord,postord);
        cout<<postord<<endl;
    }
    return 0;
}