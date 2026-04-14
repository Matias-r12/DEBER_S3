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
    return 0;
}