#include <stdio.h>

void pyramid(int h);

int main(){

    int ask;

    do{
        printf("Set the pyramid height (1 - 8): ");
        scanf("%i", &ask);
    }while(ask < 1 || ask > 8);

    pyramid(ask);
}

void pyramid(int h){
    int c = h - 1;
    int c2 = 1;

    for (int i = 0; i < h; i++)
    {
        for(int k = 0; k < c;k++){
            printf(" ");
        }
        for(int l = 0; l < c2; l++){
            printf("#");
        } 
        for(int m = 0; m < 2; m++){
            printf(" ");
        }
        for(int n = 0; n < c2; n++){
            printf("#");
        }
        printf("\n");
        c--;
        c2++;
        }
    }
