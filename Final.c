#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 200

void startdomain(int domain[n][n]){
    int i, j;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            *(*(domain +i) +j) = 0;
        }   
    }
    *(*(domain +(n/2)) +(n/2)) =1;
    *(*(domain +(n/2)+1) +(n/2)) =1;
    *(*(domain +(n/2)) +(n/2)+1) =1;
    *(*(domain +(n/2)-1) +(n/2)) =1;
    *(*(domain +(n/2)) +(n/2)-1) =1;
}

void passo(int domain[n][n],int x, int y){
    
    int dir;
    
    sorteio1: 
    dir = rand()%4;  //Sorteia a direção que a particula anda;

    switch (dir)
    {
    case 0:                             //Particula anda para cima (x constante e y varia +)
        if(y>1){
            y = y-1;
            if(*(*(domain + x ) +y-1)==1||*(*(domain + x+1 ) +y)==1||*(*(domain + x-1 ) +y)==1){
                *(*(domain + x) +y) = 1;
            }
            else
                goto sorteio1;
        }
        else
            break;
        break;
    case 1:                             //Particula anda para direita (x varia + e y constante)
        if(x<(n-2)){
            x = x+1;
            if(*(*(domain + x+1 ) +y)==1||*(*(domain + x ) +y+1)==1||*(*(domain + x ) +y-1)==1){
                *(*(domain + x ) +y)=1;
            }
            else
                goto sorteio1;
        }
        else
            break;
        break;
    case 2:                             //Particula anda para esquerda (x varia - e y constante)
        if(x>1){
            x = x-1;
            if(*(*(domain + x-1 ) +y)==1||*(*(domain + x ) +y+1)==1||*(*(domain + x ) +y-1)==1){
                *(*(domain + x ) +y)=1;
            }
            else
                goto sorteio1;
        }
        else
            break;
        break;
    case 3:                             //Particula anda para baixo (x constante e y varia -)
        if(y<(n-2)){
            y = y+1;
            if(*(*(domain + x ) +y+1)==1||*(*(domain + x+1 ) +y)==1||*(*(domain + x-1 ) +y)==1){
            *(*(domain + x ) + y) = 1;
            }
            else
                goto sorteio1;
        }
        else        
            break;
        break;
    default:
        break;
    }
}

void newpoint(int domain[n][n]){
    int xs;
    int ys;

    sorteio:
    xs = rand()%(n+1);   //Gera a posição inicial x
    ys = rand()%(n+1);   //Gera a posição inicial y
    
    int i,j;

    if(*(*(domain + xs ) +ys)==0 && (*(*(domain+ xs +1) +ys)!=1||*(*(domain + xs -1) +ys)!=1||*(*(domain + xs) +ys+1)!=1||*(*(domain + xs) +ys-1)!=1)){
        passo(domain, xs, ys);
    }
    else
        goto sorteio;
}

void printdomain(int domain[n][n]){
    int i, j;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",domain[i][j]);
            }
        printf("\n");
    }
}

void save(int domain[n][n]){
    FILE *arq;
    int i, j;

    arq = fopen("dla.txt","w");

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            fprintf(arq,"%d    ", domain[i][j]);
        }
        fprintf(arq,"\n");
    }

    fclose(arq);

}

int main(void){
    int domain[n][n];  
    int i, j;
   
    srand(time(NULL));

    startdomain(domain);

    for(i=0;i<150*n/4;i++){
        newpoint(domain);
    }

    save(domain);

    return 0;
}