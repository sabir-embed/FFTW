#include <stdio.h>
#include "fftw3.h"

fftw_plan plan;

void main()
{
    int N = 4;
    fftw_complex fft_in[N], fft_out[N];
    signed int data1[4] = {0, 0, 0, 0};
    signed int data2[4] = {0, 0, 0, 1};
    signed int data3[4] = {0, 0, 1, 0};
    signed int data4[4] = {0, 0, 1, 1};

    signed int data5[4] = {0, 1, 0, 0};
    signed int data6[4] = {0, 1, 0, 1};
    signed int data7[4] = {0, 1, 1, 0};
    signed int data8[4] = {0, 1, 1, 1};

    signed int data9[4] = {1, 0, 0, 0};
    signed int data10[4] = {1, 0, 0, 1};
    signed int data11[4] = {1, 0, 1, 0};
    signed int data12[4] = {1, 0, 1, 1};

    signed int data13[4] = {1, 1, 0, 0};
    signed int data14[4] = {1, 1, 0, 1};
    signed int data15[4] = {1, 1, 1, 0};
    signed int data16[4] = {1, 1, 1, 1};

    for (int i = 0; i < N; i++)
    {
        fft_in[i][0] = data1[i];
        fft_in[i][1] = 0;
    }
    
    plan = fftw_plan_dft_1d(N, fft_in, fft_out, FFTW_FORWARD, FFTW_ESTIMATE);
    
    fftw_execute(plan);
    

    printf("FFT DATA : \n");
    for (int i = 0; i < N; i++)
    {
        printf(" %f  ", fft_out[i][0]);
    }
    printf("\n");

    // for (int i = 0; i < N; i++)
    // {
    //     fft_in[i][0] = data2[i];
    //     fft_in[i][1] = 0;
    // }

    // plan = fftw_plan_dft_1d(N, fft_in, fft_out, FFTW_FORWARD, FFTW_ESTIMATE);
    // fftw_execute(plan);
    // printf("FFT DATA : \n");

    // for (int i = 0; i < N; i++)
    // {
    //     printf("  %f ", fft_out[i][0]);
    // }
    // printf("\n");

    // for (int i = 0; i < N; i++)
    // {
    //     fft_in[i][0] = data3[i];
    //     fft_in[i][1] = 0;
    // }
    // plan = fftw_plan_dft_1d(N, fft_in, fft_out, FFTW_FORWARD, FFTW_ESTIMATE);
    // fftw_execute(plan);
    // printf("FFT DATA : \n");

    // for (int i = 0; i < N; i++)
    // {
    //     printf("  %f ", fft_out[i][0]);
    // }
    // printf("  \n");

    // for (int i = 0; i < N; i++)
    // {
    //     fft_in[i][0] = data4[i];
    //     fft_in[i][1] = 0;
    // }
    // plan = fftw_plan_dft_1d(N, fft_in, fft_out, FFTW_FORWARD, FFTW_ESTIMATE);
    // fftw_execute(plan);
    // printf("FFT DATA : \n");

    // for (int i = 0; i < N; i++)
    // {
    //     printf("  %f ", fft_out[i][0]);
    // }
    // printf("  \n");

    // for (int i = 0; i < N; i++)
    // {
    //     fft_in[i][0] = data5[i];
    //     fft_in[i][1] = 0;
    // }
    // plan = fftw_plan_dft_1d(N, fft_in, fft_out, FFTW_FORWARD, FFTW_ESTIMATE);
    // fftw_execute(plan);
    // printf("FFT DATA : \n");

    // for (int i = 0; i < N; i++)
    // {
    //     printf(" %f ", fft_out[i][0]);
    // }
    // printf(" \n");

    // for (int i = 0; i < N; i++)
    // {
    //     fft_in[i][0] = data6[i];
    //     fft_in[i][1] = 0;
    // }
    // plan = fftw_plan_dft_1d(N, fft_in, fft_out, FFTW_FORWARD, FFTW_ESTIMATE);
    // fftw_execute(plan);
    // printf("FFT data : \n ");

    // for (int i = 0; i < N; i++)
    // {

    //     printf("%f ", fft_out[i][0]);
    // }
    // printf("\n");
    // for (int i = 0; i < N; i++)
    // {
    //     fft_in[i][0] = data7[i];
    //     fft_in[i][1] = 0;
    // }

    // plan = fftw_plan_dft_1d(N, fft_in, fft_out, FFTW_FORWARD, FFTW_ESTIMATE);
    // fftw_execute(plan);
    // printf("FFT data : \n ");

    // for (int i = 0; i < N; i++)
    // {

    //     printf("%f ", fft_out[i][0]);
    // }
    // printf("\n");
    // for (int i = 0; i < N; i++)
    // {
    //     fft_in[i][0] = data8[i];
    //     fft_in[i][1] = 0;
    // }

    // plan = fftw_plan_dft_1d(N, fft_in, fft_out, FFTW_FORWARD, FFTW_ESTIMATE);
    // fftw_execute(plan);
    // printf("FFT data : \n ");
    // for (int i = 0; i < N; i++)
    // {

    //     printf("%f ", fft_out[i][0]);
    // }

    // printf("\n");
    // for (int i = 0; i < N; i++)
    // {
    //     fft_in[i][0] = data9[i];
    //     fft_in[i][1] = 0;
    // }
    // plan = fftw_plan_dft_1d(N, fft_in, fft_out, FFTW_FORWARD, FFTW_ESTIMATE);
    // fftw_execute(plan);
    // printf("FFT data : \n ");
    // for (int i = 0; i < N; i++)
    // {

    //     printf("%f ", fft_out[i][0]);
    // }
    // printf("\n");
    // for (int i = 0; i < N; i++)
    // {
    //     fft_in[i][0] = data10[i];
    //     fft_in[i][1] = 0;
    // }
    // plan = fftw_plan_dft_1d(N, fft_in, fft_out, FFTW_FORWARD, FFTW_ESTIMATE);
    // fftw_execute(plan);
    // printf("FFT data : \n ");
    // for (int i = 0; i < N; i++)
    // {

    //     printf("%f ", fft_out[i][0]);
    // }
    // printf("\n");
    // for (int i = 0; i < N; i++)
    // {
    //     fft_in[i][0] = data11[i];
    //     fft_in[i][1] = 0;
    // }

    // plan = fftw_plan_dft_1d(N, fft_in, fft_out, FFTW_FORWARD, FFTW_ESTIMATE);
    // fftw_execute(plan);
    // printf("FFT data : \n ");
    // for (int i = 0; i < N; i++)
    // {

    //     printf("%f ", fft_out[i][0]);
    // }
    // printf("\n");
    // for (int i = 0; i < N; i++)
    // {
    //     fft_in[i][0] = data12[i];
    //     fft_in[i][1] = 0;
    // }

    // plan = fftw_plan_dft_1d(N, fft_in, fft_out, FFTW_FORWARD, FFTW_ESTIMATE);
    // fftw_execute(plan);
    // printf("FFT data : \n ");
    // for (int i = 0; i < N; i++)
    // {

    //     printf("%f ", fft_out[i][0]);
    // }
    // printf("\n");
    // for (int i = 0; i < N; i++)
    // {
    //     fft_in[i][0] = data13[i];
    //     fft_in[i][1] = 0;
    // }
    // plan = fftw_plan_dft_1d(N, fft_in, fft_out, FFTW_FORWARD, FFTW_ESTIMATE);
    // fftw_execute(plan);
    // printf("FFT data : \n ");
    // for (int i = 0; i < N; i++)
    // {

    //     printf("%f ", fft_out[i][0]);
    // }
    // printf("\n");

    // for (int i = 0; i < N; i++)
    // {
    //     fft_in[i][0] = data14[i];
    //     fft_in[i][1] = 0;
    // }

    // plan = fftw_plan_dft_1d(N, fft_in, fft_out, FFTW_FORWARD, FFTW_ESTIMATE);
    // fftw_execute(plan);
    // printf("FFT data : \n ");
    // for (int i = 0; i < N; i++)
    // {

    //     printf("%f ", fft_out[i][0]);
    // }
    // printf("\n");

    // for (int i = 0; i < N; i++)
    // {
    //     fft_in[i][0] = data15[i];
    //     fft_in[i][1] = 0;
    // }

    // plan = fftw_plan_dft_1d(N, fft_in, fft_out, FFTW_FORWARD, FFTW_ESTIMATE);
    // fftw_execute(plan);
    // printf("FFT data : \n ");
    // for (int i = 0; i < N; i++)
    // {

    //     printf("%f ", fft_out[i][0]);
    // }
    // printf("\n");

    // for (int i = 0; i < N; i++)
    // {
    //     fft_in[i][0] = data16[i];
    //     fft_in[i][1] = 0;
    // }

    // plan = fftw_plan_dft_1d(N, fft_in, fft_out, FFTW_FORWARD, FFTW_ESTIMATE);
    // fftw_execute(plan);
    // printf("FFT data : \n ");
    // for (int i = 0; i < N; i++)
    // {
    //     printf("%f ", fft_out[i][0]);
    // }
    // printf("\n");
}
