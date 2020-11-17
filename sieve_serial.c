#include <stdio.h>
#include <stdlib.h>

int count_primes(int *arr, int arr_size)
{
    int i = 0, n_primes = 0;


    printf("%d\n", arr_size);    
    for(i = 2; i < arr_size; i++){
        if(arr[i] == 1) {
            // printf("%d is a prime number\n", i);
            n_primes++;
        }
    }
    return n_primes;
}
int main(int argc, char *argv[])
{
    int N;
    if(argc != 2)
    {
        printf("Call the program as ./sieve N\n");
        exit(1);
    }
    N = atoi(argv[1]);

    // memory in bytes
    int *is_prime = (int *) malloc(sizeof(int) * (N+1));
   

    for(int i=0; i<=N; i++) is_prime[i] = 1;

   
    for(int i=2; i*i <= N; i++)
    {
        if(is_prime[i]){
            for(int j = i*i; j<= N; j+=i)
            {
                is_prime[j] = 0;
            }
        }
    }


    int n_primes = count_primes(is_prime, N + 1);
    printf("Total prime numbers less than the number %d : %d\n", N, n_primes); 

    
}