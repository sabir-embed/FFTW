#include <stdio.h>
#include "fftw3.h"
#include <math.h>
#define N 100
float get_abs(float real, float img);




   
  

  fftw_complex arr[10][10] = {{0,0,0,0,0,0,0,0,0,0},
                    {0,0,0,1,1,0,0,0,0,0},
                    {0,0,1,1,1,1,0,0,0,0},
                    {0,0,1,0,0,1,0,0,0,0},
                    {0,1,1,0,0,1,1,0,0,0},
                    {0,1,1,1,1,1,1,0,0,0},
                    {0,1,1,0,0,1,1,0,0,0},
                    {0,1,1,0,0,1,1,0,0,0},
                    {0,1,1,0,0,1,1,0,0,0},
                    {0,1,1,0,0,1,1,0,0,0}};

    int arr_full[N] = {             0,0,0,0,0,0,0,0,0,0,  
                                    0,0,0,1,1,0,0,0,0,0,
                                    0,0,1,1,1,1,0,0,0,0,
                                    0,0,1,0,0,1,0,0,0,0,
                                    0,1,1,0,0,1,1,0,0,0,
                                    0,1,1,1,1,1,1,0,0,0,
                                    0,1,1,0,0,1,1,0,0,0,
                                    0,1,1,0,0,1,1,0,0,0,
                                    0,1,1,0,0,1,1,0,0,0,
                                    0,1,1,0,0,1,1,0,0,0 };     

     
    fftw_plan plan ,plan_rev ;           

int main(){
    fftw_complex res[10][10], res_full[N], res_full_trunk[N] , rev_res[N];   


    fftw_complex in_full[N];


    for(int i=0; i<N; i++){
      in_full[i][0] = arr_full[i];
      in_full[i][1] = 0;
    }

    plan = fftw_plan_dft_1d(N, in_full, res_full ,FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(plan);

    for(int i=0; i<N; i++){
      printf("%f ",res_full[i][0]);
    }

    plan_rev = fftw_plan_dft_1d(N,  res_full, rev_res ,FFTW_BACKWARD, FFTW_ESTIMATE);
    fftw_execute(plan_rev);
    printf("orignal\n");
    
   for(int i=0; i<N; i++){
      printf("%f ",rev_res[i][0]);
    }
    return 0;
}

float get_abs(float real, float img){


      return sqrt(pow(real,2)+pow(img,2));

}