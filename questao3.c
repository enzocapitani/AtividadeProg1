#include <stdio.h>

int main(){

    int altura = 0, fill = 0;

    printf("Digite a altura do triangulo: ");
    scanf("%d", &altura);

    printf("Preenchido = 1 , Nao preenchido = 0 : ");
    scanf("%d", &fill);

    if(fill == 1){
        for(int i = 1; i <= altura; i++){
            for(int j = 1; j <= i; j++){
                printf("* ");
            }
            printf("\n");
        }
    }else{
        for(int i = 1; i <= altura; i++){

            for(int j = 1; j <= i; j++){

                if(j == 1 || j == i || i == altura){
                    printf("* ");
                }else{
                    printf("  ");
                }
            
            }
            
            printf("\n");
        }
    }
    

    return 0;
}