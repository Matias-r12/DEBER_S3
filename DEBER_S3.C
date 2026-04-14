/* 
Nombre:Matias Rojas
Fecha:13/4/2026
Descripcion:Sacar el promedio por estudiantes y asignatura usando matrizes
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{

 float notas[5][3], promE[5] = {0}, promA[3] = {0};
    float maxE[5], minE[5], maxA[3], minA[3];
    int aprobA[3] = {0,0,0}, reproA[3] = {0,0,0};
    int i, j;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 3; j++) {
            do {
                printf("Nota (0-10) Est%d Asig%d: ", i+1, j+1);
                scanf("%f", &notas[i][j]);
                if (notas[i][j] < 0 || notas[i][j] > 10)
                    printf("Fuera del rango.\n");
            } while (notas[i][j] < 0 || notas[i][j] > 10);
        }
    }
    for (i = 0; i < 5; i++) maxE[i] = minE[i] = notas[i][0];
    for (j = 0; j < 3; j++) maxA[j] = minA[j] = notas[0][j];

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 3; j++) {
            promE[i] += notas[i][j];
            promA[j] += notas[i][j];

            if (notas[i][j] > maxE[i]) maxE[i] = notas[i][j];
            if (notas[i][j] < minE[i]) minE[i] = notas[i][j];

            if (notas[i][j] > maxA[j]) maxA[j] = notas[i][j];
            if (notas[i][j] < minA[j]) minA[j] = notas[i][j];

            if (notas[i][j] >= 6) aprobA[j]++; else reproA[j]++;
        }
        promE[i] /= 3.0f;
    }
    for (j = 0; j < 3; j++) promA[j] /= 5.0f;


    return 0;
}