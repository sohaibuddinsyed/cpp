#include <stdio.h>
#include <omp.h>
#include <thread>
#include <chrono>

void parallel_func() {
    printf("Hello from thread: %d\n", omp_get_thread_num());
    for(int i = 0; i < 10000000000; i++);
    printf("Bye from thread: %d\n", omp_get_thread_num());
}

int main(int argc, char** argv){
    #pragma omp parallel
    {
        parallel_func();
    }
    return 0;
}