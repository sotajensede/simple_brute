    /*
     * Algorithm to print every possible
     * combination of characters within
     * a set length. In this case, a 2d
     * array via manipulating the y
     * coordinates.
     */
     
    #include<iostream>
    int main()
    {
        int anArray[3][4]={
            { 1, 1, 1, 1}, // row 0
            { 2, 2, 2, 2}, // row 1
            { 3, 3, 3, 3} // row 2
        };
        int mxHt=2; //highest y coordinate
        int index=3; //highest x coordinate
        int yCoords[]={0,0,0,0}; //y coords are the
                                 //only thing that change
        bool run=true; //outer loop bool
        bool exit=false; //innter loop bool
        while(run){    
            for(int i=0;i<4;i++)
                std::cout<<anArray[yCoords[i]][i];
            std::cout<<'\n';
     
            while(!exit){
                if(yCoords[index]==mxHt){
                    yCoords[index]=0;
                    if(index>0) index--;
                    else run = !run;
                }
                if(yCoords[index]<mxHt){
                    yCoords[index]++;
                    index=3;
                    exit = !exit;
                }
            } exit = !exit;
        }
        return 0;
    }
