#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct Try{
    unsigned int num;
    int bulls;
    int cows;
} try_t;

static bool guessed = 0;
static try_t previous_tries[10];
static int tries = 0;

extern bool diff_digits_check(unsigned int num);

void guesser_bulls_and_cows(unsigned int guess, unsigned int num, int* bulls_and_cows){
    bulls_and_cows[0] = 0;
    bulls_and_cows[1] = 0;
    bool guess_digits[10] = {0,0,0,0,0,0,0,0,0,0}; 

    for(int guess_temp = guess; guess_temp > 0; guess_temp /= 10){
        guess_digits[(guess_temp % 10)] = 1;
    }

    for(int num_temp = num; num_temp > 0; num_temp /= 10){ 
        if(guess_digits[num_temp % 10]){
            bulls_and_cows[1]++;
        }
    }

    while(num > 0 && guess > 0){
        if((num % 10 == guess % 10)){
            bulls_and_cows[0]++;
            bulls_and_cows[1]--;
        }
        num /= 10;
        guess /= 10;
    }
}


void try(){
    srand(time(NULL));
    int guess;
    int guess_bulls_and_cows[2];
    for(bool eligible_guess = 0; !eligible_guess; ){
        guess = rand() % (9001) + 1000;
        eligible_guess = 1;
        if(!diff_digits_check(guess)){
            eligible_guess = 0;
            continue;
        }
        for(int i = 1; i <= tries; i++){
            if(guess == previous_tries[tries - i].num){
                eligible_guess = 0;
                continue;
            }
            guesser_bulls_and_cows(guess, previous_tries[tries - i].num , &guess_bulls_and_cows[0]);
            if(guess_bulls_and_cows[0] != previous_tries[tries - i].bulls || guess_bulls_and_cows[1] != previous_tries[tries - i].cows){
                eligible_guess = 0;
                break;
            }

        }
    }

    previous_tries[tries].num = guess;
    printf("%d\n", guess);
    printf("bulls: ");
    scanf("%d", &previous_tries[tries].bulls);
    printf("cows: ");
    scanf("%d", &previous_tries[tries].cows);
    if(previous_tries[tries].bulls == 4){
        guessed = 1;
    }
    tries++;
}


void guesser(){
    while (!guessed){
        try();
    }
    printf("I won\n");
}