#include <stdio.h> 
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define MAX_DRONES 100

void gerador_posicoes(int num_drones, float x[], float y[]){
    for (int i = 0; i < num_drones; i++) {
        x[i] = ((float)rand() / RAND_MAX) * 100;
        y[i] = ((float)rand() / RAND_MAX) * 100;
    }
}



void chance_colisao(int num_drones, float x[], float y[], int distan_risco[], float distan_segura){
    for (int i = 0; i < num_drones; i++) {
        distan_risco[i] = 1; // Inicializa todos como seguros
    }

    printf("\nDrones em risco de colisao (distancia < 17.00):\n");
    for (int i = 0; i < num_drones; i++) {
        for (int j = i + 1; j < num_drones; j++) {
            float distance = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
            if (distance < distan_segura) {
                distan_risco[i] = 0;
                distan_risco[j] = 0;
                printf("Drone %d e Drone %d: Distancia: %.2f\n", i, j, distance);
            }
        }
    }
}

int main(){
    int num_drones;
    float x[MAX_DRONES];
    float y[MAX_DRONES];
    float distan_segura;
    int distan_risco[MAX_DRONES];

    srand(time(NULL));

    printf("Digite o numero de drones (ate 100): ");
    scanf("%d", &num_drones);
    if (num_drones <= 0 || num_drones > MAX_DRONES) {
        printf("Número de drones inválido. Deve estar entre 1 e %d.\n", MAX_DRONES);
        return 1;
    }

    printf("Digite a distancia minima de seguranca: ");
    scanf("%f", &distan_segura);

    gerador_posicoes(num_drones, x, y);
    printf("\nCoordenadas dos drones:\n");
    for (int i = 0; i < num_drones; i++) {
        printf("Drone %d: (%.2f, %.2f)\n", i, x[i], y[i]);
    }

    chance_colisao(num_drones, x, y, distan_risco, distan_segura);

    printf("\nDrones que precisam ajustar rota:\n");
    for (int i = 0; i < num_drones; i++) {
        if (distan_risco[i] == 0) {
            printf("Drone %d, ", i);
        }
    }

return 0;
}