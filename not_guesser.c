#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

static unsigned int number_to_guess;
static bool guessed = 0;

bool diff_digits_check(unsigned int num){
    bool  digits[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    while (num > 0){
        int digit;
        digit = num % 10;
        if(digits[digit] == 1){
            return 0;
        }else{
            digits[digit] = 1;
        }
        num /= 10;
    }   
    return 1;
}


unsigned int choose_num(){
    srand(time(NULL));
    while(1){
        unsigned int num;
        num = rand() % (9001) + 1000;
        if(diff_digits_check(num)){
            return num;
        }
    }
}

int bulls_and_cows(unsigned int guess, unsigned int num){
    int bulls_and_cows[2] = {4, 0};
    if(guess == num){
        guessed = 1;
        return 0;
    }

    bulls_and_cows[0] = 0;
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
    printf("bulls: %d\ncows: %d\n", bulls_and_cows[0], bulls_and_cows[1]);
    return 0;
}


void not_guesser(){
    number_to_guess = choose_num();
    ///printf("chosen number: %d\n", number_to_guess);
    while(!guessed){
        int bulls;
        int cows;
        unsigned int guess;
        printf("enter guess: ");
        scanf("%u", &guess);
        if(!diff_digits_check(guess)){
            printf("only different diggits numbers\n");
            continue;
        }
        bulls_and_cows(guess, number_to_guess);
    }
    printf("you won\n");
}