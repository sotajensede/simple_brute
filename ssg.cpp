/*
 * Jesse Deaton
 *
 * String generation program
 * for possible use with brute
 * force attack.
 *
 * December, 2014
 */

#include <iostream>
#include <string>
#include <locale>
#include <stdlib.h>

using namespace std;

//sets parameters by given args
void setParams(int argc, char *argv[]);
//outputs based on givem parameters
void buildOutput();

int minLen,maxLen;
bool params[4]; //letters, caps, numbers, special

int main(int argc, char *argv[])
{
    if(argc<3)
        cout<<"Usage: ssg [min_length] [max_length] "
            <<"arg1 arg2 arg3...\n\n"
            <<"l - letters\nc - caps\nn - numbers\n"
            <<"s - special characters\n";
    else{
        setParams(argc,argv);
        buildOutput();
    }
    return 0;
}

void setParams(int argc, char *argv[])
{
    //capture max and min length
    minLen = atoi(argv[1]);
    maxLen = atoi(argv[2]);
    //clear parameters before setting them
    for(int i=0;i<4;i++)
        params[i]=false;
    //set parameter array based on args
    for(int i=3;i<argc;i++){
        if(*argv[i]=='l') params[0]=true;
        if(*argv[i]=='c') params[1]=true;
        if(*argv[i]=='n') params[2]=true;
        if(*argv[i]=='s') params[3]=true;
    }
}

void buildOutput()
{
    //create and fill alphabet array(s)
    if(params[0]||params[1]){
        char *alphabet[26];
        *alphabet[0]='a';
        for(char c='a';c<='z';c++)
            *alphabet[c-'a'] = c;
        if(params[1]){
            locale loc;
            char *caps[26];
            for(int i=0;i<26;i++)
                *caps[i]=toupper(*alphabet[i],loc);               
        }
    }
    //special characters array
    if(params[3]){
        char specials[]={'?', '!', '@', '#', '$', '%', '^', '&',
                         '*', '(', ')', '{', '}', '|', '\\', '/',
                         '_', '-', '=', '+', '~', '`'};
    }
}
