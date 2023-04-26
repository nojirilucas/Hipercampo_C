#include "header.h"

void main(int argc, char **argv){
    struct rusage buff;

    char *input = (char *)calloc(100, sizeof(char));
    char *output = (char *)calloc(100, sizeof(char)); 
       
    File(argc, argv, input, output);
    Leitura_input(input);
    Solucao();

    FILE *arq_output = fopen(output, "a"); // Toda vez que o algoritmo for executado o maior valor é escrito em um arquivo output
    fprintf(arq_output, "%d\n", Maior);
    fclose(arq_output);

    getrusage(RUSAGE_SELF,&buff);
    printf("|---------------------------------------|\n");
    printf("|\tMaior valor possível = %d\t|\n", Maior);
    printf("|---------------------------------------|\n");
    printf("|\tTempo = %lf segundos\t|\n", (double) buff.ru_utime.tv_sec + (double) buff.ru_utime.tv_usec / (double) 1000000);
    printf("|---------------------------------------|\n");
    printf("|\tUso de memória  = %ld Kb\t|\n", buff.ru_maxrss);
    printf("|---------------------------------------|\n\n\n");
    plot();

    free(input);
    free(output);
    free(pontos);

}
