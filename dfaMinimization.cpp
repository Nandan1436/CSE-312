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

    vector< set<char> >tempStates;
    vector< vector<char> >transition;
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
        if(temp.size()>0)tempStates.push_back(temp);
    }
    cout<<tempStates.size()<<endl;

    for(i=0;i<tempStates.size();i++){
        vector<char>temp1;
        int pos=-1;
        set<char>::iterator x = tempStates[i].begin();
        for(;x!=tempStates[i].end();x++){
            for(j=0;j<numOfStates;j++){
                if(states[j]==*x){
                    if(pos==-1)pos=j;
                    states[j]='X';
                }
            }
        }

        for(j=0;j<numOfSymbols;j++){
            temp1.push_back(dfa[pos][j]);
        }
        transition.push_back(temp1);
    }
    cout<<transition.size()<<endl;

    for(i=0;i<transition.size();i++){
        for(j=0;j<numOfSymbols;j++){
            cout<<transition[i][j]<<" ";
        }
        cout<<endl;
    }

    for(i=0;i<numOfStates;i++){
        if(states[i]!='X'){
            vector<char>temp1;
            for(j=0;j<numOfSymbols;j++){
                int pos = findindex(dfa[i][j],states,numOfStates);
                if(pos<numOfStates && states[pos]!='X'){
                    cout<<dfa[i][j]<<endl;
                    temp1.push_back(dfa[i][j]);
                }
                else {
                    for(k=0;k<tempStates.size();k++){
                        set<char>::iterator itr=tempStates[k].find(dfa[i][j]);
                        if(itr!=tempStates[k].end()){
                            itr=tempStates[k].begin();
                            cout<<*itr<<endl;
                            char ch=*itr;
                            temp1.push_back(ch);
                            break;
                        }
                    }
                    if(k==tempStates.size())temp1.push_back(dfa[i][j]);
                }
            }
            transition.push_back(temp1);
            states[i]='X';
        }
    }
    cout<<transition.size()<<endl;

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
