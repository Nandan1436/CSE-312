#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int findLength(char *binString){
    int length=0;
    for(int i=0;binString[i]!='\0';i++){
        length++;
    }
    return length;
}

int main()
{
    srand(time(0));
    int i,j,numOfStrings=5,strLen,check;
    char binString[numOfStrings][51],userString[50],userString1[50],userString2[50],answer[110];

    for(i=0;i<numOfStrings;i++){
        strLen=rand()%50+1;
        for(j=0;j<strLen;j++){
            binString[i][j]=rand()%2+'0';
        }
        binString[i][j]='\0';
    }
    printf("The %d strings with their length are: \n",numOfStrings);
    for(i=0;i<numOfStrings;i++){
        printf("String: %s , length: %d\n",binString[i],findLength(binString[i]));
    }

    check=1;
    printf("Enter string : ");
    scanf("%s",userString);
    for(i=0;i<findLength(userString);i++){
        if(userString[i]!='0' && userString[i]!='1'){
            printf("The given string is not from the alphabet.\n");
            check=0;
            break;
        }
    }
    if(check)printf("The given string is from the alphabet.\n");


    printf("Enter the two strings: ");
    scanf("%s %s",userString1,userString2);
    j=findLength(userString1);
    for(i=0;i<findLength(userString1);i++){
        answer[i]=userString1[i];
    }
    j=findLength(userString1);
    for(i=0;i<findLength(userString2);i++){
        answer[j++]=userString2[i];
    }
    answer[findLength(userString1) + findLength(userString2)]='\0';
    printf("The concatenated string is: %s\n",answer);


    return 0;
}
