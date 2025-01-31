#include <stdio.h>

extern void not_guesser();
extern void guesser();

int main(){
    int gamemode;
    printf("choose game mode (1.you guess 2. computer guesses): ");
    scanf("%d", &gamemode);
    switch(gamemode){
        case 1: not_guesser();break;
        case 2: guesser();break;
        default: printf("invalid game mode number. try again");break;
    }
    return 0;
}
