#include <stdio.h>

int main(){
    int base, larguraT, alturaT, soma;
    
    //Esse loop captura os valores necessário para a questão
    //Usa um sistema de parada que a cada valor adcionado, ele soma + 1, se ao final a soma for 3, o loop encerra
    //Se algum dos inputs for incorreto, ele vai ao final e verifica que a soma é != de 3 e refaz os inputs
    do{
        soma = 0;
        printf("============================ | Insira os valores | ============================\n");
        printf("Digite o tamanho da base, deve ser impar e maior ou igual a 3 : ");
        scanf("%d", &base);
        if(base < 3 || base % 2 == 0){
            printf("DIGITO ERRADO! NUMERO PAR OU MENOR QUE 3\n");
            printf("Retornando...\n");
            continue;
        }
        soma++;

        printf("===============================================================================\n");
        printf("Digite a largura do tronco\ndeve ser impar, maior ou igual a 1 e menor que a metade da base (Metade da base atual -> %d): ", base/2);
        scanf("%d", &larguraT);
        if(larguraT < 1 || larguraT % 2 == 0 || larguraT > base/2){
            printf("DIGITO ERRADO! NUMERO PAR OU MENOR QUE 1 OU MAIOR QUE BASE/2\n");
            printf("Retornando...\n");
            continue;
        }
        soma++;
        printf("===============================================================================\n");
        printf("Digite a altura do tronco\ndeve ser maior ou igual a 2 e menor que a metade da base (Metade da base atual -> %d): ", base/2);
        scanf("%d", &alturaT);
        if(alturaT < 2 || alturaT > base/2){
            printf("DIGITO ERRADO! NUMERO MENOR QUE 2 OU MAIOR QUE BASE/2\n");
            printf("Retornando...\n");
            continue;
        }
        soma++;
        printf("===============================================================================\n");

    }while(soma != 3);
    
    int quantidadeX = 1;
    int altura = base/2 + 1;

    //Esse trecho faz a parte do triangulo da árvore, que a cada linha a quantidade aumenta em 2 asteristicos
    //e calcula a quantidade de espacamento conforme a formula -> base/2 - i
    for(int i = 0; i < altura; i++){
        for(int g = 0; g < base/2 - i; g++){
            printf(" ");
        }

        for(int t = 0; t < quantidadeX; t++){
            printf("*");
        }

        quantidadeX+=2;
        printf("\n");
    }

    //Aqui calulca a quantidade de espacamento no tronco
    //ex: se base for 13 e largura for 3, o C calcula assim -> 5 = 13/2 - 3/2
    //como é valor em int, ele arredonda pra cima e fica assim -> 5 = 7 - 2
    int espacamentoTronco = base/2 - larguraT/2;

    //Por fim, esse trecho desenha o tronco, o primeiro loop itera a altura,
    //o segundo desenha o espacamento conforme a variável explicada acima,
    //o terceiro desenha a quantidade de * conforme o tamanho da largura
    for(int i = 0; i < alturaT; i++){
        for(int g = 0; g < espacamentoTronco; g++){
            printf(" ");
        }

        for(int l = 0; l < larguraT; l++){
            printf("*");
        }

        printf("\n");
    }

    return 0;
}