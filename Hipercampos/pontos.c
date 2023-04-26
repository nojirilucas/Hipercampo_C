#include "header.h"

// Faz a operação de encontrar o coeficiente da reta entre 2 pontos, usando a fórmula coef = y2 - y1 / x2 - x1
float Coeficiente_Reta(float x2, float y2, float x1, float y1){
    float coef = (y2-y1) / (x2-x1);
    return coef;
}

// Essa função resolve todos os coeficientes possiveis
float Resolve_coef(Ponto points[4]){
    Ponto xa = points[0];
    Ponto ya = points[1];
    Ponto xb = points[2];
    Ponto yb = points[3];
    float coef_a_menor_b = (ya.y - yb.y) / (xa.x - xb.x);
    float coef_b_menor_a = (yb.y - ya.y) / (xb.x - xa.x);
    float coef_menor_a = (ya.y - yb.y) / (xa.x - xb.x);
    float coef_maior_b = (yb.y - ya.y) / (xb.x - xa.x);
    // Retorna o coeficiente de acordo com a orientação dos pontos
    if(xa.x < xb.x){
        if(ya.y < yb.y){
            return coef_a_menor_b; // xa < xb, ya < yb
        }else{
            return coef_menor_a; // xa < xb, ya > yb
        }
    }else{
        if(ya.y < yb.y){
            return coef_maior_b; // xa > xb, ya < yb
        }else{
            return coef_b_menor_a; // xa > xb, ya > yb
        }
    }
}

// Função que faz a verificação das interceptações entre o maior de i e o maior de n
int Interceptacao(float coef_a, float coef_b, float xa, float ya, float xb, float yb){ 
float coef;
    switch (coef_a < 0) { // Verifica se xa > A, xa < xb
        case 1:
            coef = Coeficiente_Reta(xb, yb, xa, ya); // Coeficiente de xa < xb     
            if (xa < xb && coef < coef_b && coef > coef_a)
                return 1;
            return 0;
        default:
            switch (coef_b > 0) { // Verifica se xa > B, xa > xb
                case 1:
                    coef = Coeficiente_Reta(xa, ya, xb, yb); // Coeficiente de xa > xb
                    if (xa > xb && coef < coef_b && coef > coef_a)
                        return 1;
                    return 0;
                default:
                    switch (xa > xb) { // Caso ponto esteja entre A e B
                    // Ou seja, o coeficiente coef poderá ser coef > coef_a ou coef < coef_b
                        case 1:
                            coef = Coeficiente_Reta(xa, ya, xb, yb);
                            if (coef > coef_a)
                                return 1;
                            return 0;
                        default:
                            coef = Coeficiente_Reta(xb, yb, xa, ya);
                            if (coef < coef_b)
                                return 1;
                            return 0;
                    }
            }
    }
}

// Essa função faz a busca do maior ponto ou ponto "mais alto" do Hipercampo
int Busca_Maior(int *pt_alto){
    Maior = 1;
    int n = 0;
    while(n <= num_pontos){ // Percorre todos os pontos em ordem crescente
        float coef_a = Coeficiente_Reta(A, 0, pontos[n].x, pontos[n].y);
        float coef_b = Coeficiente_Reta(B, 0, pontos[n].x, pontos[n].y);
        int i = n - 1;
        while(i >= 0){ // Percorre tudo abaixo do maior ponto n
            if(pt_alto[i] >= pt_alto[n]){
                if(Interceptacao(coef_a, coef_b, pontos[n].x, pontos[n].y, pontos[i].x, pontos[i].y)){
                    pt_alto[n] = pt_alto[i] + 1;
                    if(pt_alto[n] > Maior){
                        Maior = pt_alto[n];
                        break;
                    }
                }
            }
            i--;
        }
        n++;
    }
    return Maior;
}

// Função de ordenação dos pontos 
void selectionSort(Ponto *arr, int n){
int i, j, min;
for(i = 0; i < n-1; i++) {
    min = i;
    for(j = i+1; j < n; j++){
        if(arr[j].y < arr[min].y)
            min = j;
    }
    Ponto temp = arr[i];
    arr[i] = arr[min];
    arr[min] = temp;
    }
}

// Descobre o maior ponto após a ordenação
void Solucao(){
    selectionSort(pontos, num_pontos);
    int *pt_alto = calloc(num_pontos + 1, sizeof(int));
    int j = 0;
    while(j < num_pontos){
        pt_alto[j] = 1;
        j++;
    }
    Busca_Maior(pt_alto);
}

// Função de plotagem do ponto no hipercampo
int plot(){
    char * commandsForGnuplot[] = {"set title \"plot\"", "plot 'data.temp' using 1:2:xticlabels(1)", "plot 'data.temp' using 3:2:xticlabels(1)"};
    double xvals[NUM_POINTS]    = {A, Maior, B};
    double xvals2[NUM_POINTS]   = {A, Maior, B};
    double yvals[NUM_POINTS]    = {A, Maior, B};
    
    FILE * temp = fopen("data.temp", "w");
    FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
    int i;
    for (i=0; i < NUM_POINTS; i++){
        fprintf(temp, "%.0f %.0f %.0f \n", xvals[i], yvals[i], xvals2[i]); // Escreve os dados em um arquivo temporário
    }
    for (i=0; i < NUM_COMMANDS; i++){
        fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[i]); // Envia os comandos para o GNUPLOT
    }
    return 0;
}
