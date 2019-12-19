#include <stdio.h>
#include <stdlib.h>
#include <cuda_runtime.h>

#define CHECK(cmd) \
{\
    cudaError_t error  = cmd;\
    if (error != cudaSuccess) { \
        fprintf(stderr, "error: '%s'(%d) at %s:%d\n", cudaGetErrorString(error), error,__FILE__, __LINE__); \
        exit(EXIT_FAILURE);\
          }\
}

int main(){
        int flag = 0;
        int *pointer1 = NULL;
        int *pointer2 = NULL;
        int size1 = sizeof(int) * 1024;
        int size2 = sizeof(int) * 2048;
        CHECK(cudaMalloc((void**)&pointer1, size1));
        CHECK(cudaMalloc((void**)&pointer2, size2));
        if(flag == 0){
        	CHECK(cudaFree(pointer1));
        }
        CHECK(cudaFree(pointer2));
        return 0;
}