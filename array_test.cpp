/*
 * Algorithm to print every possible
 * combination of characters within
 * a length range. In this case, a 2d
 * array via manipulating the y
 * coordinates.
 */
 
#include<iostream>
int main()
{
    int anArray[3][4]={
        {1, 1, 1, 1},
        {2, 2, 2, 2},
        {3, 3, 3, 3}};

    int minLen=2;
    int maxLen=4;
    int cut=0; //how much is cut from output
    int mxHt=2; //highest y coordinate
    int index=3; //highest x coordinate
    int x=index;
    int yCoords[]={0,0,0,0}; //y coords are the
                             //only thing that change
    bool run=true; //outer loop bool
    while(true){    
        for(int i=cut;i<4;i++)
            std::cout<<anArray[yCoords[i]][i];
        std::cout<<'\n';
 
        while(true){
            if(yCoords[index]==mxHt){
                yCoords[index]=0;
                if(index>0) index--;
                else if(cut<maxLen-minLen) cut++;
                else goto end;
            }
            if(yCoords[index]<mxHt){
                yCoords[index]++;
                index=3;
                break;
            }
        }
    }
    end:
    return 0;
}
