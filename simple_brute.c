/*
 * Jesse Deaton
 *
 * String generation program
 * for possible use with brute
 * force attack.
 *
 * December, 2014
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

//sets parameters by given arguments
int set_params(int argc, char *argv[]);
//outputs based on given parameters
void build_output(int height);
//return give char as upper case


int minLen,maxLen;
bool params[4]; //letters, caps, numbers, special

void main(int argc, char *argv[])
{
    if(argc<4)//needs at least one letter argument for now
        printf("Usage: ssg [min_length] [max_length] "
               "arg1 arg2 arg3...\n\n"
               "l - letters\nc - caps\nn - numbers\n"
               "s - special characters\n");
    else build_output(set_params(argc,argv)); //setParams() sends the height
											//of the 2d output array to
											//buildOutput()
}

int set_params(int argc, char *argv[])
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

//This will be pruned. It build the 2d output array from
//the given parameters
void build_output(int height)
{
    char output[height][maxLen]; //the whole point of this
    int fill=0; //keep up with how full output arr is
    //alphabet array(s)
    if(params[0]||params[1]){
        char alphabet[26];
        alphabet[0]='a';
        for(char c='a';c<='z';c++) alphabet[c-'a'] = c;
		if(params[0]){
			for(int y=fill;y<26+fill;y++)//alphabet is added to 2d output array
				for(int x=0;x<maxLen;x++) output[y][x]=alphabet[y-fill];
			fill+=26;
		}
        if(params[1]){
            char caps[26];
            for(int i=0;i<26;i++) caps[i]=toupper(alphabet[i]);               
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
    //special characters
    if(params[3]){
        char specials[]={'?', '!', '@', '#', '$', '%', '^', '&',
                         '*', '(', ')', '{', '}', '|', '\\', '/',
                         '_', '-', '=', '+', '~', '`', '\'', '\"',
                         ':', ';', '<', '>', ',', '.', };
		for(int y=fill;y<30+fill;y++)
			for(int x=0;x<maxLen;x++) output[y][x]=specials[y-fill];
		fill+=30;
    }
	//output array is ready for printing
    int cut=0;
    int mxHt=height-1;
    int index=maxLen-1;
    int yCrd[maxLen];
    for(int i=0;i<maxLen;i++) yCrd[i]=0;
	//main output loop
    while(true){
		//printed by row
		for(int i=cut;i<maxLen;i++) printf("%c",output[yCrd[i]][i]);
        printf("\n");
		//counting loop
        while(true){
			//if column height has been reached,
            if(yCrd[index]==mxHt){
                yCrd[index]=0;//reset column
                if(index>0) index--;// move left, if possible
				//shrink output length
                else if(cut<maxLen-minLen) cut++;
				//if minimum length is reached, end
                else goto end;
            }
			//if column height hasn't been reached,
            if(yCrd[index]<mxHt){
                yCrd[index]++;//go to next row in column
                index=maxLen-1;//move to far right
                break;//break from counting loop to print
            }
        }
    }
    end:;
}
