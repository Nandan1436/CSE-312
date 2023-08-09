#include <bits/stdc++.h>

using namespace std;

char transition[100][100][100];
int numOfStates,numOfSymbols;

void nfa(char startState,char finalState,string inputString,int curr,char *symbols,char *states){
    if(startState=='X'){
        return;
    }
    int i,j,k,x;
    for(i=curr;inputString[i];i++){
        for(j=0;j<numOfStates;j++){
            if(startState==states[j])break;
        }
        for(k=0;k<numOfSymbols;k++){
            if(inputString[i]==symbols[k])break;
        }
        for(x=0;transition[j][k][x];x++){
            nfa(states[j],finalState,inputString,i+1,symbols,states);
        }

    }

}

int main()
{
    int numOfTransitions,i,j,k;
    char startState,finalState;
    string inputString;
    cin>>numOfStates>>numOfSymbols;

    char states[numOfStates],symbols[numOfSymbols];
    for(i=0;i<numOfStates;i++)cin>>states[i];
    for(i=0;i<numOfSymbols;i++)cin>>symbols[i];

    for(i=0;i<numOfStates;i++){
        for(j=0;j<numOfSymbols;j++){
            cin>>numOfTransitions;
            for(k=0;k<numOfTransitions;k++){
                cin>>transition[i][j][k];
            }
            transition[i][j][k]='X';
        }
    }
    cin>>startState>>finalState;
    cin>>inputString;


    return 0;
}
