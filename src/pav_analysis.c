#include <math.h>
#include "pav_analysis.h"

double PI = 3.14159265358979323846;

float compute_power(const float *x, unsigned int N) {
    float sumatorio = 1e-4;
    int i;

    for(i=0; i < N; i++){
        sumatorio += (x[i] * x[i]);
    }

    return 10*log10(sumatorio/N);
}

float compute_am(const float *x, unsigned int N) {
    float sumatorio = 0;
    int i;

    for(i=0; i < N; i++){
        if(x[i] < 0){
            sumatorio += (x[i] * (-1.0));            
        }else{
            sumatorio += (x[i]);
        }
    }

    return sumatorio/N;
}

float compute_zcr(const float *x, unsigned int N, float fm) {
    int sumatorio = 0;
    int i;

    for(i=1; i < N; i++){
        if(x[i-1] * x[i] < 0){
            sumatorio += 1;
        }
    }

    return (fm/(2*(N-1))) * sumatorio;
}

float Hamming(int n, int N){
    if(n >= 0 && n < N){
        return 0.53836 - 0.46164 * cos((2*PI*n)/(N-1));
    }
    return 0;
}

float compute_power_windowed_Hamming(const float *x, unsigned int N, unsigned int fm) {
    float N_Tlong = fm * 0.02;
    float M = fm * 0.01;
    float res_interior_log = 0;
    float w = 0;
    int n = 0, inicio = 0, count = 0;

    while(n < N){
        inicio = count * M;

        for(n = inicio; n < (inicio + N_Tlong); n++){
            w = Hamming(n - inicio, N_Tlong);
            if(w && n < N){
                res_interior_log += (x[n]*w)*(x[n]*w)/(w*w);
            }
        }
        count++;
    }
    return 10*log10(res_interior_log);
}

float compute_init_power(float p) 
{ 
  return pow(10, (p / 10));
}
