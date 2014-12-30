/*
 *
 * Jesse Deaton
 *
 * String generation program
 * for possible use with brute
 * force attack.
 *
 * December 24, 2014
 *
 */

#include <iostream>
#include <string>
#include <locale>

using namespace std;

//sets parameters by given args
void setParams(int argc, char *argv[]);
//outputs based on givem parameters
void output();

// global parameters
int minLen = 0;
int maxLen = 0;
bool params[4]; //letters, caps, numbers, special

int main(int argc, char *argv[])
{

    if(argc<3)
        cout<<"Specify a min/max length respectively\n"
            <<"along with some arguments:\n\n"
            <<"l - letters\nc - caps\nn - numbers\n"
            <<"s - special characters\n";
    else{
        setParams(argc,argv);
        output();
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
        if(*argv[i]=='l') //letters
            params[0]=true;
        if(*argv[i]=='c') //caps
            params[1]=true;
        if(*argv[i]=='n') //numbers
            params[2]=true;
        if(*argv[i]=='s') //specials
            params[3]=true;
    }
    //  TEST
    /*
    cout << "min length: " << minLen << '\n';
    cout << "max length: " << maxLen << '\n';

    if(params[0])
        cout<<"letters "<< '\n';
    if(params[1])
        cout<<"capitals "<< '\n';
    if(params[2])
        cout<<"numbers "<< '\n';
    if(params[3])
        cout<<"specials "<< '\n';
    */
}

void output()
{
    //create and fill alphabet array
    if(params[0]||params[1]){
        char alphabet[26];
        alphabet[0]='a';
        for(char c='a';c<='z';c++){
            alphabet[c-'a'] = c;
            //TEST
            cout<<alphabet[c-'a']<<'\n';
        }
        if(params[1]){
            locale loc;
            char caps[26];
            for(int i=0;i<26;i++){
                caps[i]=toupper(alphabet[i],loc);               
                //TEST
                cout<<caps[i]<<'\n';
            }
        }
    }
    //special characters array
    if(params[3]){
        char specials[] {'?', '!', '@', '#', '$', '%', '^', '&',
                         '*', '(', ')', '{', '}', '|', '\\', '/',
                         '_', '-', '=', '+', '~', '`'};
        //TEST
        for(int i=0;i<22;i++)
            cout<<specials[i]<<'\n';
    }
    //current output length
    int length = minLen;
    //array to be printed.
    char output[maxLen];
    //start output
    //increment length of output
    while(length<minLen){
        //DO SHIT
        length++;
    }
}

