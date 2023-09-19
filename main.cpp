#include <bits/stdc++.h>

using namespace std;

int findindex(char x,char states[],int n)
{
    int pos;
    for(int i=0; i<n; i++)
    {
        if(states[i]==x)
        {
            pos=i;
            break;
        }
    }
    return pos;
}

int main()
{
    freopen("mini.txt","r",stdin);

    int numOfStates,numOfSymbols,i,j,k;
    cin>>numOfStates>>numOfSymbols;

    char states[numOfStates],symbols[numOfSymbols],dfa[numOfStates][numOfSymbols],startState,endState;
    for(i=0; i<numOfStates; i++)cin>>states[i];
    for(i=0; i<numOfSymbols; i++)cin>>symbols[i];
    for(i=0; i<numOfStates; i++)
    {
        for(j=0; j<numOfSymbols; j++)
        {
            cin>>dfa[i][j];
        }
    }
    cin>>startState>>endState;

    char table[numOfStates][numOfStates];
    for(i=0; i<numOfStates; i++)
    {
        for(j=0; states[i]!=states[j]; j++)
        {
            table[i][j]=' ';
            if(states[j]==endState || states[i]==endState)
            {
                table[i][j]='X';
            }
        }
    }

    for(int z=0; z<2; z++)
    {
        for(i=0; i<numOfStates; i++)
        {
            for(j=0; states[i]!=states[j]; j++)
            {
                for(k=0; k<numOfSymbols; k++)
                {
                    char u=dfa[i][k],v=dfa[j][k];
                    int x=findindex(u,states,numOfStates),y=findindex(v,states,numOfStates);
                    if(table[x][y]=='X' || table[y][x]=='X')
                    {
                        table[i][j]='X';
                        break;
                    }
                }
            }
        }
    }

    for(i=1; i<numOfStates; i++)
    {
        for(j=0; states[i]!=states[j]; j++)
        {
            if(table[i][j]!='X')table[i][j]='=';
        }
    }

    for(i=1; i<numOfStates; i++)
    {
        for(j=0; states[i]!=states[j]; j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }

    vector<set<char>>tempStates;
    vector<vector<char>>transition;
    vector<char>newStates;
    for(i=0;i<numOfStates-1;i++)
    {
        set<char>temp;
        for(j=numOfStates-1;j>0;j--){
            if(table[j][i]=='='){
                temp.insert(states[i]);
                temp.insert(states[j]);
            }
        }
        tempStates.push_back(temp);
    }

    for(i=0;i<tempStates.size();i++){
        vector<char>temp1;
        int pos1,pos2;
        auto x=tempStates[i].begin();
        for(j=0;j<numOfStates;j++){
            if(states[j]==*x){
                pos1=j;
                x++;
            }
            if(states[j]==*x){
                pos2=j;
                break;
            }
        }
        for(j=0;j<numOfSymbols;j++){
            temp1.push_back(dfa[pos1][j]);
        }
        transition.push_back(temp1);
        states[pos1]=states[pos2]='X';
    }

    for(i=0;i<numOfStates;i++){
        vector<char>temp1;
        if(states[i]!='X'){
            for(j=0;j<numOfSymbols;j++){
                temp1.push_back(dfa[i][j]);
            }
        }
        transition.push_back(temp1);
    }

    char ch='A';
    for(i=0;i<transition.size();i++){
        newStates.push_back(ch++);
    }
    cout<<"New States: ";
    for(i=0;i<transition.size();i++){
        cout<<newStates[i]<<" ";
    }
    cout<<endl;
    cout<<"Symbols: ";
    for(i=0;i<numOfSymbols;i++){
        cout<<symbols[i]<<" ";
    }
    cout<<endl;
    cout<<"Transition table: "<<endl;

    for(i=0;i<transition.size();i++){
        for(j=0;j<numOfSymbols;j++){
            cout<<transition[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
