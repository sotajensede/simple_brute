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
int setParams(int argc, char *argv[]);
//outputs based on givem parameters
void buildOutput(int height);

int minLen,maxLen;
bool params[4]; //letters, caps, numbers, special

int main(int argc, char *argv[])
{
    if(argc<3)
        cout<<"Usage: ssg [min_length] [max_length] "
            <<"arg1 arg2 arg3...\n\n"
            <<"l - letters\nc - caps\nn - numbers\n"
            <<"s - special characters\n";
    else buildOutput(setParams(argc,argv));
    return 0;
}

int setParams(int argc, char *argv[])
{
    int height=0;
    //capture max and min length
    minLen = atoi(argv[1]);
    maxLen = atoi(argv[2]);
    //clear parameters before setting them
    for(int i=0;i<4;i++) params[i]=false;
    //set parameter array based on args
    for(int i=3;i<argc;i++){
        if(*argv[i]=='l'){
            params[0]=true;
            height+=26;
        }
        if(*argv[i]=='c'){
            params[1]=true;
            height+=26;
        }
        if(*argv[i]=='n'){
            params[2]=true;
            height+=10;
        }
        if(*argv[i]=='s'){
            params[3]=true;
            height+=30;
        }
    }
    return height;
}

//I hate this entire function right now
void buildOutput(int height)
{
    char output[height][maxLen]; //the whole point of this
    int fill=0; //keep up with how full output arr is
    //create and fill alphabet array(s)
    if(params[0]||params[1]){
        char alphabet[26];
        alphabet[0]='a';
        for(char c='a';c<='z';c++) alphabet[c-'a'] = c;
        for(int i=0;i<maxLen;i++)
            for(int j=fill;j<height;j++)
                output[j][i]=alphabet[j];
        fill++;
        if(params[1]){
            locale loc;
            char caps[26];
            for(int i=0;i<26;i++)
                caps[i]=toupper(alphabet[i],loc);               
            for(int i=0;i<maxLen;i++)
                for(int j=fill;j<height;j++)
                    output[j][i]=caps[j];
            fill++;
        }
    }
    //numbers
    if(params[2]){
        char numeros[]={0,1,2,3,4,5,6,7,8,9};
        for(int i=0;i<maxLen;i++)
            for(int j=fill;j<height;j++)
                output[j][i]=numeros[j];
        fill++;
    }
    //special characters array
    if(params[3]){
        char specials[]={'?', '!', '@', '#', '$', '%', '^', '&',
                         '*', '(', ')', '{', '}', '|', '\\', '/',
                         '_', '-', '=', '+', '~', '`', '\'', '\"',
                         ':', ';', '<', '>', ',', '.'};
        for(int i=0;i<maxLen;i++)
            for(int j=fill;j<height;j++)
                output[j][i]=specials[j];
    }
}

