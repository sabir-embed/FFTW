#include <stdio.h>

int sum(int a, int b){
    return (a+b);
}

int diff(int a, int b){
    if(a>b){
        return (a-b);
    }else{

        return (b-a)*(-1);
    }
}