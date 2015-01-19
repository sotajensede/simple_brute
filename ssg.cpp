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
		if(params[0]){
			for(int y=fill;y<26+fill;y++)
				for(int x=0;x<maxLen;x++) output[y][x]=alphabet[y-fill];
			fill+=26;
		}
        if(params[1]){
            locale loc;
            char caps[26];
            for(int i=0;i<26;i++) caps[i]=toupper(alphabet[i],loc);               
			for(int y=fill;y<26+fill;y++)
				for(int x=0;x<maxLen;x++) output[y][x]=caps[y-fill];
			fill+=26;
		}
    }
    //numbers
    if(params[2]){
        char numeros[]={'0','1','2','3','4','5','6','7','8','9'};
		for(int y=fill;y<10+fill;y++)
			for(int x=0;x<maxLen;x++) output[y][x]=numeros[y-fill];
		fill+=10;
    }
    //special characters array
    if(params[3]){
        char specials[]={'?', '!', '@', '#', '$', '%', '^', '&',
                         '*', '(', ')', '{', '}', '|', '\\', '/',
                         '_', '-', '=', '+', '~', '`', '\'', '\"',
                         ':', ';', '<', '>', ',', '.'};
		for(int y=fill;y<30+fill;y++)
			for(int x=0;x<maxLen;x++) output[y][x]=specials[y-fill];
		fill+=30;
    }
	/*
    for(int y=0;y<height;y++){
        for(int x=0;x<maxLen;x++) cout<<output[y][x];
        cout<<'\n';
    }
	*/
    //*********This will have its own function***********//
    int cut=0;
    int mxHt=height-1;
    int index=maxLen-1;
    int yCrd[maxLen];
    for(int i=0;i<maxLen;i++) yCrd[i]=0;

    while(true){
    for(int i=cut;i<4;i++)
        cout<<output[yCrd[i]][i];
    cout<<'\n';
        while(true){
            if(yCrd[index]==mxHt){
                yCrd[index]=0;
                if(index>0) index--;
                else if(cut<maxLen-minLen) cut++;
                else goto end;
            }
            if(yCrd[index]<mxHt){
                yCrd[index]++;
                index=3;
                break;
            }
        }
    }
    end:;
}

