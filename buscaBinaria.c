#include <stdio.h>
#include <stdlib.h>

//função recursiva para realizar a busca no vetor
int buscaBinaria(int *vet, int key, int inicio, int fim, int cont)
{
    cont++;
    int meio;
    if(inicio <= fim) {
        meio = (inicio + fim) / 2;
        if(key == vet[meio]){
            printf("Comparacoes: %d", cont-1);
            return meio;
        }else{
            if(key < vet[meio]) {   
                //chama a função recursivamente diminuindo o numero de valores a serem comparados  
                return buscaBinaria(vet, key, inicio, meio - 1, cont);
            }else{     
                //chama a função recursivamente diminuindo o numero de valores a serem comparados      
                return buscaBinaria(vet, key, meio + 1, fim, cont);
            }               
        }
    }
    printf("Comparacoes: %d\n", cont-1);
    return -1;
}

int main() 
{
    //int vet[10] = {13, 14, 19, 43, 47, 52, 65, 82, 89, 91};
    int valor, op, quantidade, i;
    int cont = 0;
    
    printf("Criacao de vetor atraves de numeros recebidos. Esses numeros serao organizados em ordem\n");
    printf("Quantos numeros deseja adicionar? ");
    scanf("%d", &quantidade);

    int vet[quantidade];

    for(i = 0; i < quantidade; i++)
    {
        printf("digite o numero: ");
        scanf("%d", &valor);
        vet[i] = valor;
    }

//colocando em ordem usando bubble sort
  int aux, j;

    for(i=quantidade-2; i>=0; i--)
        {
            for(j=0; j<=i; j++)
            {
                if(vet[j] > vet[j+1])
                {
                    aux = vet[j];
                    vet[j] = vet[j+1];
                    vet[j+1] = aux;
                }
            }
        } 

      for(i = 0; i < quantidade; i++)
    {
        printf(" %d ", vet[i]);
    }  


    //buscar valores com loop para seguir buscando ou encerrar o programa
     do {
        printf("\nDigite um valor a ser buscado: ");
        scanf("%d", &valor);
        printf("\nIndice do valor buscado: %d\n", buscaBinaria(vet, valor, 0, 9, cont));
            if (buscaBinaria(vet, valor, 0, 9, cont) == -1)
            {
                printf("Numero nao encontrado\n");
            }

    
        printf("\n0 - Sair\n1 - Nova busca\n");
        scanf("%d", &op); 
    } while(op != 0);
}
