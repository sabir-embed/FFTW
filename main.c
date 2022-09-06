#include <stdio.h>
#include "fftw3.h"
#include <math.h>

float my_abs(float real, float img);

// PF: 0.8 Leg , Frequency: 50Hz , Vr: 3rd harmonics - 5%
signed int Vr_sample[130] = 
{
323     ,
679     ,
1032    ,
1380    ,
1720    ,
2049    ,
2380    ,
2679    ,
3003    ,
3271    ,
3572    ,
3844    ,
4041    ,
4524    ,
4594    ,
4577    ,
4640    ,
4918    ,
5161    ,
5308    ,
5429    ,
5536    ,
5632    ,
5714    ,
5784    ,
5846    ,
5893    ,
5936    ,
5961    ,
5990    ,
5993    ,
6007    ,
5991    ,
5991    ,
5957    ,
5945    ,
5888    ,
5881    ,
5772    ,
5822    ,
5730    ,
5540    ,
5368    ,
5204    ,
5116    ,
5021    ,
4869    ,
4689    ,
4496    ,
4285    ,
4060    ,
3822    ,
3566    ,
3296    ,
3013    ,
2713    ,
2402    ,
2078    ,
1750    ,
1411    ,
1066    ,
715     ,
361     ,
3       ,
-355    ,
-709    ,
-1060   ,
-1406   ,
-1751   ,
-2079   ,
-2415   ,
-2708   ,
-3036   ,
-3294   ,
-3603   ,
-3866   ,
-4076   ,
-4555   ,
-4618   ,
-4600   ,
-4666   ,
-4943   ,
-5189   ,
-5334   ,
-5454   ,
-5563   ,
-5654   ,
-5739   ,
-5808   ,
-5872   ,
-5915   ,
-5961   ,
-5984   ,
-6013   ,
-6017   ,
-6030   ,
-6013   ,
-6014   ,
-5979   ,
-5968   ,
-5910   ,
-5902   ,
-5794   ,
-5846   ,
-5754   ,
-5561   ,
-5387   ,
-5225   ,
-5137   ,
-5043   ,
-4888   ,
-4710   ,
-4518   ,
-4310   ,
-4084   ,
-3843   ,
-3587   ,
-3315   ,
-3030   ,
-2733   ,
-2424   ,
-2103   ,
-1774   ,
-1433   ,
-1090   ,
-737    ,
-384    ,
-28     
//329     ,
//685 
};

signed int Vy_sample[130] = 
{
659     ,
1334    ,
1931    ,
2433    ,
2820    ,
3087    ,
3240    ,
3305    ,
3300    ,
3279    ,
3247    ,
3285    ,
3355    ,
3555    ,
3791    ,
4160    ,
4547    ,
4977    ,
5515    ,
5844    ,
6058    ,
6208    ,
6282    ,
6334    ,
6236    ,
6020    ,
5730    ,
5423    ,
5122    ,
4883    ,
4711    ,
4657    ,
4689    ,
4853    ,
5067    ,
5377    ,
5661    ,
5982    ,
6191    ,
6379    ,
6382    ,
6368    ,
6100    ,
5926    ,
5535    ,
4953    ,
4502    ,
4170    ,
3840    ,
3568    ,
3383    ,
3280    ,
3250    ,
3262    ,
3293    ,
3299    ,
3254    ,
3118    ,
2873    ,
2505    ,
2016    ,
1430    ,
764     ,
52      ,
-656    ,
-1331   ,
-1934   ,
-2439   ,
-2823   ,
-3092   ,
-3244   ,
-3310   ,
-3306   ,
-3285   ,
-3254   ,
-3289   ,
-3359   ,
-3559   ,
-3792   ,
-4168   ,
-4555   ,
-4986   ,
-5521   ,
-5848   ,
-6061   ,
-6213   ,
-6287   ,
-6339   ,
-6241   ,
-6025   ,
-5734   ,
-5430   ,
-5127   ,
-4890   ,
-4718   ,
-4665   ,
-4698   ,
-4861   ,
-5074   ,
-5383   ,
-5667   ,
-5988   ,
-6195   ,
-6386   ,
-6387   ,
-6376   ,
-6103   ,
-5928   ,
-5541   ,
-4961   ,
-4509   ,
-4181   ,
-3849   ,
-3579   ,
-3389   ,
-3288   ,
-3253   ,
-3270   ,
-3296   ,
-3306   ,
-3254   ,
-3121   ,
-2873   ,
-2510   ,
-2025   ,
-1433   ,
-765    ,
-60     
//652     ,
//1327    
};

// PF: 0.8 Leg , Frequency: 50Hz , Vb: 11th harmonics - 20%
signed int Vb_sample[130] = 
{
912     ,
1688    ,
2154    ,
2257    ,
2055    ,
1689    ,
1347    ,
1204    ,
1389    ,
1915    ,
2724    ,
3650    ,
4502    ,
5122    ,
5381    ,
5297    ,
4913    ,
4457    ,
4049    ,
3934    ,
4125    ,
4637    ,
5515    ,
6191    ,
6738    ,
7105    ,
7180    ,
6784    ,
6254    ,
5577    ,
5172    ,
4908    ,
5195    ,
5509    ,
6398    ,
6945    ,
7094    ,
6969    ,
6699    ,
6210    ,
5455    ,
4696    ,
4146    ,
3919    ,
4033    ,
4403    ,
4879    ,
5265    ,
5392    ,
5157    ,
4563    ,
3725    ,
2797    ,
1977    ,
1417    ,
1209    ,
1324    ,
1660    ,
2030    ,
2254    ,
2176    ,
1740    ,
980     ,
32      ,
-915    ,
-1692   ,
-2156   ,
-2261   ,
-2058   ,
-1693   ,
-1347   ,
-1210   ,
-1389   ,
-1925   ,
-2728   ,
-3654   ,
-4507   ,
-5124   ,
-5382   ,
-5295   ,
-4915   ,
-4463   ,
-4053   ,
-3939   ,
-4130   ,
-4647   ,
-5518   ,
-6188   ,
-6739   ,
-7104   ,
-7182   ,
-6785   ,
-6256   ,
-5576   ,
-5177   ,
-4908   ,
-5201   ,
-5508   ,
-6395   ,
-6946   ,
-7095   ,
-6969   ,
-6704   ,
-6210   ,
-5456   ,
-4701   ,
-4152   ,
-3922   ,
-4035   ,
-4407   ,
-4879   ,
-5265   ,
-5390   ,
-5156   ,
-4571   ,
-3727   ,
-2805   ,
-1985   ,
-1422   ,
-1208   ,
-1322   ,
-1657   ,
-2030   ,
-2255   ,
-2183   ,
-1747   ,
-990    ,
-45     
//906     ,
//1685    
};


// PF: 0.8 Leg , Frequency: 50Hz , Ir: 3rd harmonics - 10%
signed int Ir_sample[130] = 
{
8       ,
18      ,
27      ,
36      ,
44      ,
52      ,
58      ,
64      ,
68      ,
72      ,
75      ,
78      ,
80      ,
82      ,
84      ,
87      ,
89      ,   
92      ,   
96      ,
99      ,
104     ,
109     ,
115     ,
120     ,
126     ,
132     ,
137      ,
141     ,
145     ,
148     ,
150     ,
151     ,
150     ,
149     ,
146     ,
143     ,
139     ,
133     ,
128     ,
122     ,
117     ,
111     ,
106     ,
101     ,
97      ,
93      ,
91      ,
88      ,
86      ,
83      ,
82      ,
80      ,
77      ,
74      ,
70      ,
66      ,
61      ,
54      ,
47      ,   
39      ,
30      ,
21      ,
12      ,
1       ,
-9      ,
-19     ,
-28     ,
-37     ,
-45     ,
-53     ,
-59     ,
-65     ,
-70     ,   
-73     ,
-76     ,
-79     ,
-82     ,
-83     ,
-86     ,
-88     ,
-90     ,
-93     ,
-97     ,
-101    ,
-105    ,
-111    ,
-116    ,
-121    ,
-127    ,
-133    ,
-138    ,
-143    ,
-146    ,
-149    ,
-151    ,
-152    ,
-151    ,
-150    ,
-148    ,
-144    ,
-140    ,
-135    ,
-129    ,
-123    ,
-118    ,
-112    ,
-107    ,
-102    ,
-98     ,
-95     ,
-91     ,
-89     ,
-87     ,
-84     ,
-83     ,
-80     ,
-78     ,
-75     ,
-71     ,
-68     ,
-62     ,
-56     ,
-48     ,
-40     ,
-32     ,
-22     ,
-12     ,
-2      
//8       ,
//18      
};


// PF: 0.8 Leg , Frequency: 50Hz , Iy: 3rd harmonics - 5%, 7th harmonics - 20%
signed int Iy_sample[130]=
{
1       ,
17       ,
33      ,
47      ,
57      ,
64      ,
68      ,
69      ,
68      ,
65      ,
62          ,
60      ,
59      ,
61      ,
65      ,
73      ,
82      ,
94      ,
106     ,
119     ,
130     ,
139     ,
145     ,
148     ,
148     ,
144     ,   
138     ,
130     ,
121     ,
114     ,
107     ,
103     ,
102     ,
104     ,
108     ,
115     ,
123     ,
131     ,
139     ,
145     ,
148     ,
148     ,
145     ,
138     ,
129     ,
118     ,
105     ,
93      ,
81      ,   
72      ,
65      ,
61      ,
60      ,
61      ,
64      ,
67      ,
70      ,
70      ,   
68      ,   
64      ,
57      ,
45      ,
32      ,
16      ,
-1      ,
-18     ,
-33     ,
-47     ,
-57     ,
-64     ,
-68     ,
-69     ,
-68     ,
-65     ,
-63     ,
-60     ,
-59     ,
-61     ,
-65     ,
-73     ,   
-82     ,
-94     ,
-107    ,
-119    ,
-131    ,
-140    ,
-146    ,
-149    ,
-148    ,
-144    ,
-138    ,
-131    ,
-122    ,
-114    ,
-108    ,
-104    ,
-102    ,
-104    ,
-109    ,
-115    ,
-123    ,
-132    ,
-139    ,
-146    ,
-149    ,
-149    ,
-145    ,
-138    ,
-129    ,
-118    ,
-105    ,
-93     ,
-82     ,
-72     ,
-66     ,
-61     ,
-60     ,
-61     ,
-64     ,
-67     ,
-70     ,
-71      ,
-69     ,
-64     ,
-57     ,
-46     ,
-33     ,
-16     
//1       ,
//17  
};

// PF: 0.8 Leg , Frequency: 50Hz , Ib: 3rd harmonics - 10%, 7th harmonics - 15%, 7th harmonics - 35%
signed int Ib_sample[130] = 
{
25      ,
62      ,
76      ,
67      ,
43      ,
21      ,
17      ,
33      ,
64      ,
93      ,
107      ,
98      ,
72      ,
43      ,
28          ,
39      ,   
72        ,
114     ,
148     ,
160     ,
131     ,
156     ,
166     ,
152     ,
120     ,
84      ,
62      ,
63      ,    
89      ,
125     ,
156     ,
166     ,
154     ,
127     ,
102     ,
92      ,
102     ,
128     ,
152     ,
161     ,   
145     ,
109     ,
68      ,
37      ,
30      ,
47      ,
76      ,
101     ,
107     ,
91      ,
60      ,
31      ,
17      ,
24      ,
47      ,
70      ,
77      ,
59      ,
21      ,
-26     ,
-62     ,
-76     ,
-66     ,
-42     ,
-21     ,
-17     ,
-34     ,
-64     ,
-93     ,
-107    ,
-97     ,
-71     ,
-42     ,
-29     ,
-39     ,
-72     ,
-114    ,
-148    ,
-160    ,
-149    ,
-123    ,
-99     ,
-91     ,
-104    ,
-131    ,
-157    ,
-166    ,
-152    ,
-119    ,
-84     ,
-62     ,
-63     ,
-89     ,
-126    ,
-156    ,
-166    ,
-153    ,
-126    ,
-101    ,
-91     ,
-102    ,
-128    ,
-152    ,
-160    ,
-144    ,
-108    ,
-67     ,
-36     ,
-30     ,
-47     ,
-76     ,
-101    ,
-107    ,
-90     ,
-60     ,
-30     ,
-17     ,
-24     ,
-47     ,
-70     ,
-77     ,
-59     ,
-20     
//26      ,
//63  
};

signed int Vr_fft[32];

int main(void){

    int N =128;
    fftw_complex in_vr[N],out_vr[N],
                 in_vy[N],out_vy[N],
                 in_vb[N],out_vb[N],

                 in_ir[N],out_ir[N],
                 in_iy[N],out_iy[N],
                 in_ib[N],out_ib[N];
    fftw_plan p_vr,p_vy, p_vb, p_ir, p_iy, p_ib;
  

    for(int i=0; i< N ; i++){
        in_vr[i][0] = Vr_sample[i];
        in_vr[i][1] = 0;

        in_vy[i][0] = Vy_sample[i];
        in_vy[i][1] = 0;

        in_vb[i][0] = Vb_sample[i];
        in_vb[i][1] = 0;

        in_ir[i][0] = Ir_sample[i];
        in_ir[i][1] = 0;

        in_iy[i][0] = Iy_sample[i];
        in_iy[i][1] = 0;

        in_ib[i][0] = Ib_sample[i];
        in_ib[i][1] = 0;

    }
    

    p_vr = fftw_plan_dft_1d(N, in_vr, out_vr ,FFTW_FORWARD, FFTW_ESTIMATE);

    fftw_execute(p_vr);

    p_vy = fftw_plan_dft_1d(N, in_vy, out_vy ,FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(p_vy);

    p_vb = fftw_plan_dft_1d(N, in_vb, out_vb ,FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(p_vb);

    p_ir = fftw_plan_dft_1d(N, in_ir, out_ir ,FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(p_ir);

    p_iy = fftw_plan_dft_1d(N, in_iy, out_iy ,FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(p_iy);

    p_ib = fftw_plan_dft_1d(N, in_ib, out_ib ,FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(p_ib);
 

    printf("Result Vr:\n");
    float abs_vr[128], abs_vy[128] , abs_vb[128], abs_ir[128], abs_iy[128], abs_ib[128];

for(int i=0; i<64;i++){
    abs_vr[i] = my_abs(out_vr[63+i][0],out_vr[63+i][1]);
    abs_vy[i] = my_abs(out_vy[63+i][0],out_vy[63+i][1]);
    abs_vb[i] = my_abs(out_vb[63+i][0],out_vb[63+i][1]);

    abs_ir[i] = my_abs(out_ir[63+i][0],out_ir[63+i][1]);
    abs_iy[i] = my_abs(out_iy[63+i][0],out_iy[63+i][1]);
    abs_ib[i] = my_abs(out_ib[63+i][0],out_ib[63+i][1]);
 

}
for(int i=64; i<128; i++){
    
    abs_vr[i] = my_abs(out_vr[i][0],out_vr[i][1]);
    abs_vy[i] = my_abs(out_vy[i][0],out_vy[i][1]);
    abs_vb[i] = my_abs(out_vb[i][0],out_vb[i][1]);

    abs_ir[i] = my_abs(out_ir[i][0],out_ir[i][1]);
    abs_iy[i] = my_abs(out_iy[i][0],out_iy[i][1]);
    abs_ib[i] = my_abs(out_ib[i][0],out_ib[i][1]);

}

for(int i=0; i< 128;i++)
    printf("Abs value vr[%d]: %f\n",i+1, abs_vr[i]);

float sum_vr , sum_vy, sum_vb, sum_ir, sum_ib, sum_iy;
  
for(int i=0; i<65;i=i+2  ){   // 65 128

        sum_vr += pow(abs_vr[i],2); 
        sum_vy += pow(abs_vy[i],2); 
        sum_vb += pow(abs_vb[i],2); 

        sum_ir += pow(abs_ir[i],2); 
        sum_iy += pow(abs_iy[i],2); 
        sum_ib += pow(abs_ib[i],2); 

}

  printf("summned %f %f %f %f %f %f: ",sum_vr,sum_vy,sum_vb,sum_ir,sum_iy,sum_ib);
 

float thd_vr = sqrt(sum_vr)/my_abs(out_vr[127][0],out_vr[127][1]); 
float thd_vy = sqrt(sum_vy)/my_abs(out_vy[127][0],out_vy[127][1]); 
float thd_vb = sqrt(sum_vb)/my_abs(out_vb[127][0],out_vb[127][1]); 
printf(" ##### Why %f\n",my_abs(out_ir[127][0],out_ir[127][1]));
float thd_ir = sqrt(sum_ir)/my_abs(out_ir[127][0],out_ir[127][1]); 
float thd_iy = sqrt(sum_iy)/my_abs(out_iy[127][0],out_iy[127][1]); 
float thd_ib = sqrt(sum_ib)/my_abs(out_ib[127][0],out_ib[127][1]); 

 
printf("###### THD: %f \n%f \n%f \n%f \n%f \n%f: ",thd_vr, thd_vy, thd_vb,  thd_ir, thd_iy ,thd_ib  );

    // Vr Vy Vb Ir Iy Ib

    int pow_r[128],pow_y[128],pow_b[128];

// 1 for +ve 2 for -ve
    int flag_r=1, flag_y=1, flag_b=1;

    for(int i=0; i<127; i++){

       pow_r[i] = out_vr[i][0]*out_ir[i][0]*0.8;

        if(pow_r[i]<0){
            flag_r =2;
        }

       pow_y[i] = out_vy[i][0]*out_iy[i][0]*0.8;

        if(pow_y[i]<0){
            flag_y =2;
        }

       pow_b[i] = out_vb[i][0]*out_ib[i][0]*0.8;

        if(pow_b[i]<0){
            flag_b =2;
        }
    }


    if(flag_r==1){
        printf("R line Harmonics Power from source\n");
    }else{
                printf("R line Harmonics Power from load\n");

    }

     if(flag_b==1){
        printf("B line Harmonics Power from source\n");
    }else{
                printf("B line Harmonics Power from load\n");

    }

     if(flag_y==1){
        printf("Y line Harmonics Power from source\n");
    }else{
                printf("Y line Harmonics Power from load\n");

    }
    
    return 0;

}



float my_abs(float real, float img){

    return sqrt(pow(real,2)+pow(img,2));
} 