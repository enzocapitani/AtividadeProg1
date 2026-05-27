#include <stdio.h>

int main(){
    int tam;
    printf("Digite o tamanho do triangulo de pascal: ");
    scanf("%d", &tam);
    
    int matrizPas[tam][tam];
    
    //Essa parte do codigo, dá valor 0 a todas as posições da matriz para evitar lixo
    for(int i = 0; i <tam; i++){
        
        for(int j = 0; j < tam; j++){

            matrizPas[i][j] = 0;

        }


    }

    //Essa aqui implementa a formula do triangulo de pascal
    for(int i = 1; i < tam; i++){
        for (int j = 0; j < tam-1; j++){
            //sempre que j = 0 a pos é 1
            //se nao, soma a a linha anterior e a coluna anterior com a linha anterior e a coluna atual
            if(j == 0){
                matrizPas[i][j] = 1;
            }else{
                matrizPas[i][j] = matrizPas[i-1][j-1] + matrizPas[i-1][j];
            }
  
        }
    }

    //Essa é a parte do print, mas faz outras coisas também
    for(int i = 0; i < tam; i++){
        int qtEspacamento = 0;

        //Aqui captura a quantidade de 0 em cada linha
        //essa quantidade é igual a quantidade de espacamento
        for(int k = 0; k < tam; k++){
            if(matrizPas[i][k] == 0) qtEspacamento++;
        }

        //Printa os espacamentos
        for(int e = 0; e < qtEspacamento; e++){
            printf(" ");
        }

        //Por fim, printa os numeros do triangulo, se diferente de 0 -> print
        for (int j = 0; j < tam; j++){
            if(matrizPas[i][j] != 0)
                printf("%d ", matrizPas[i][j]);
        }

        printf("\n");
    }

    return 0;
}