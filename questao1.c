#include <stdio.h>

int main(){
    //Se fill = 1 é preenchido, se 0 é vazio
    int altura = 0, fill = 0, largura = 8;
    
    printf("Digite a altura do quadrado: ");
    scanf("%d", &altura);

    printf("Preenchido = 1 , Não preenchido = 0 : ");
    scanf("%d", &fill);

    //Preenchido
    if(fill == 1){
        for(int i = 1; i <= altura * largura; i++){
            
            if(i % largura == 0){
                printf("\n");
                continue;
            }
            printf("*  ");
    
        }
    //Vazio
    }else{

        //Linhas
        for(int i = 1; i <= altura; i++){

            //Colunas
            for(int j = 1; j <= largura; j++){

                //Se for as laterais, print
                if(i == 1 || i == altura){
                    printf("*  ");

                // se for a parte superior e inferior, print
                }else if(j == 1 || j == largura){
                    printf("*  ");
                }else{
                    printf("   ");
                }

            }

            printf("\n");
        }

    }

    return 0;
}