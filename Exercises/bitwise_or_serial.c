#include <stdio.h>
#include <mpich/mpi.h>

const int N = 5;
int my_array[] = {13, 2243, 64, 99};

int main(int argc, char *argv[])
{
    int i;
    int res = 0;
    int p_size = 2;

    for(i = 0; i < N; i+=1){
        res = res | my_array[i];
    }

    printf("%d\n", res);
    return 0;
}