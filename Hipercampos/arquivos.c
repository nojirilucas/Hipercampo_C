#include "header.h"

// Essa função faz a abertura dos arquivos de entrada e saída
int File(int argc, char **argv, char *input, char *output){
    int opt;
    // Faz a leitura da entrada digitada até -o
    while((opt = getopt(argc, argv, "i:o:")) > 0){
        switch (opt) {
            case 'i':
                strcpy(input, optarg);
                break;
            case 'o':
                strcpy(output, optarg);
                break;
            default:
                fprintf(stderr, "ENTRADA INCORRETA! Digite Novamente...\n");
                return -1; 
        }
    }
    return 0;
}

// Faz a leitura das entradas e verifica se os valores são aceitos
void Leitura_input(char *input) {
    int i = 0;
    FILE *entrada = fopen(input, "r");
    
    fscanf(entrada, "%d %f %f\n", &num_pontos, &A, &B);
    if(num_pontos >1000000){
        printf("Entrada excede o limite de pontos...\n");
        exit(0);
    }else if(A >= B){
        printf("Erro na entrada, A maior que B...\n");
        exit(0);
    }else if(B >10000){
        printf("Erro na entrada, B excede o limite...\n");
        exit(0);
    }else if(A < 0){
        printf("Erro na entrada, A menor que o valor 0...\n");
        exit(0);
    }
    pontos = (Ponto *)calloc(num_pontos, sizeof(Ponto));
    // Percorre as linhas do arquivo de entrada informado e faz a leitura dos valores
    while(i < num_pontos){
        fscanf(entrada, "%f %f\n", &(pontos[i].x), &(pontos[i]).y);
        i++;
    }
    fclose(entrada);
}
