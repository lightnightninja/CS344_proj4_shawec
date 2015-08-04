//
//  threadedhappyprimes.c
//  CS344_proj4_shawec
//
//  Created by Cierra Shawe on 8/1/15.
//  Copyright (c) 2015 Cierra Shawe. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>

struct sieved{

    unsigned int num;
    unsigned int count;
    unsigned int *array;
    unsigned int *primearray;

};
typedef struct sieved sieved;
struct happies{

    unsigned int *array;
    unsigned int num;

};
typedef struct happies happies;

unsigned int *init(unsigned int num){

    unsigned int i;
    unsigned int *array = malloc(sizeof(unsigned int)*num);
    for (i = 1; i < num; i++) {
        array[i] = 1;
    }
    return array;
}
void print(unsigned int *array, unsigned int num){

    unsigned int i;
    for (i = 0; i < num; i++) {
        printf("%i ", array[i]);
    }

}
void menu(sieved *primes){

    printf("Please Enter a number: ");
    scanf("%i", &primes->num);

}

int doMath(sieved *primes, int i){

    unsigned int num = primes->primearray[i];
    unsigned int sum = 0;
    int rem;

    while(1){

        while (num != 0){
            rem = num % 10;
            sum += rem * rem;
            num /= 10;
        }

        if (sum == 1){
            return 1;
        }
        else if (sum == 0  || sum == 37 || sum == 4  ||
                 sum == 43 || sum == 16 || sum == 58 ||
                 sum == 89 || sum == 20 || sum == 145 )
            return 0;
        num = sum;
        sum = 0;
    }

    return 0;
}
void happy(sieved *primes, happies *hap){

    int hpc = 0; //happy prime count

    for (int i = 0; i < primes->count; i++) {
        if(doMath(primes, i) == 1)
            hap->num++;
        else
            primes->primearray[i] = 0;
    }

    hap->array = init(hap->num);

    for (unsigned int i = 0; i < primes->count; i++) {
        if (primes->primearray[i] != 0){
            hap->array[hpc] = primes->primearray[i];
            hpc++;
        }

    }

}
unsigned int *sieve(sieved *primes){

    unsigned int k = 0;
    unsigned int m = 0;
    unsigned int i = 0;
    unsigned int c = 0;
    unsigned int *primearray;
    primes->array[0] = 2;

    for (k = 1; (k+1)*(k+1) <= primes->num; k++) {
        if (primes->array[k] != 0) {
            m = k;
        }
        for (i = 2; (m+1)*i <= primes->num; i++) {
            primes->array[((m+1)*i)-1] = 0;
        }
    }

    for(k = 0; k < primes->num; k++) {
        if (primes->array[k] == 1) {
            primes->count++;
        }
    }


    primearray = init(primes->count);

    for (i = 0; i < primes->num; i++) {
        if (primes->array[i] == 1) {
            primes->primearray[c] = i+1;
            c++;
        }
    }

    return primes->primearray;
}

int main() {
    //system("clear");
    sieved *primes = (sieved *)malloc(sizeof(sieved));
    happies *hap = (happies *)malloc(sizeof(happies));
    menu(primes);
    primes->array = init(primes->num);

    primes->primearray = sieve(primes);
    happy(primes, hap);
    printf("There are %i prime numbers under %i, and they include:\n", hap->num, primes->num);
    print(hap->array, hap->num);
    
    free(primes->array);
    free(primes);
    
    return 0;
}