#include <stdio.h>
#include <math.h>
#include "fftw3.h"



int main(){

    fftw_complex ar[10] = { 0,0,0,0,1,0,0,0,0,1};

    fftw_plan plan_for , plan_rev;

    //plan_for =     

    int count =0;
    while(count<10){
        double ff[2] = (double[]) *(ar[count]);
        printf(" %f", ff[0]);
        count++;
    }    


    return 0;
}