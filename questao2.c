#include <stdio.h>

int main(){

    int num;
    printf("Digite a quantidade de linhas do triangulo: ");
    scanf("%d", &num);

    for (int i = 1; i <= num; i++) {
        //Para j = 1, imprima espaço vazio enquanto j <= num - 1
        //No caso num = 3, esse loop só para se : num - i = 2, 1, 0 
        for(int j = 1; j <= num - i; j++){
            printf("  ");
        }

        //Para J = 1, imprima j enquanto j menor ou igual a i
        for(int j = 1; j <= i; j++){
            printf("%d ", j);
        }

        for (int j = i - 1;j >= 1; j--){
            printf("%d ", j);
        }
        

        printf("\n");
    }

    return 0;
}