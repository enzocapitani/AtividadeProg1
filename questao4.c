#include <stdio.h>

int main(){
    int base;
    printf("Digite o tamanho do centro do losango, funciona melhor se for impar: ");
    scanf("%d", &base);

    //Altura achei pela formula : base = altura*2 - 1
    int altura = (base+1)/2, meio = base/2;
    // Essa variavel eu criei quando cheguei a conclusao que a cada linha que passa
    // a quantidade de X aumenta em 2
    int quantidadeX = 1;

    //Triangulo superior, aqui ele faz o triangulo superior
    for(int i = 1; i <= altura; i++){
        //Nesse trecho, ele printa o espacamento conforme a minha altura atual,
        //que no caso seria o i
        for(int j = 1; j <= meio - i; j++){
            printf(" ");
        }

        //Aqui ele printa a quantidade de X atual, que ao final do loop de indice i
        //aumenta dois
        for(int j = 0; j < quantidadeX; j++){
            printf("X");
        }

        quantidadeX+= 2;

        printf("\n");
    }

    //Parte inferior, ou triangulo invertido inferior
    for(int i = 1; i < altura; i++){
        //Essa parte printa os espacamentos, conforme o valor de i
        for(int j = 1; j <= i; j++){
            printf(" ");
        }

        //Como a piramide decresce sempre de 2 em 2, entao a quantidade de "X" sempre vai
        //seguir essa formula -> QT DE X = base - (i * 2)
        for(int j = 0; j < base - i*2; j++){
            printf("X");
        }

        printf("\n");

    }

    return 0;
}