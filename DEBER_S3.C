/* 
Nombre:Matias Rojas
Fecha:13/4/2026
Descripcion:Sacar el promedio por estudiantes y asignatura usando matrizes
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    float notas[5][3];
    float promE[5], promA[3];
    float maxE[5], minE[5], maxA[3], minA[3];
    int aprobA[3] = {0,0,0}, reproA[3] = {0,0,0};
    int i, j, ok;
    float x;

    /* Ingreso y validación */
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 3; j++) {
            do {
                printf("Nota (0-10) Estudiante %d Asignatura %d: ", i+1, j+1);
                ok = scanf("%f", &x);

                /* Si no es número, limpiar buffer */
                if (ok != 1) {
                    printf("Entrada invalida.\n");
                    while (getchar() != '\n'); /* limpia hasta fin de línea */
                    x = -1; /* fuerza repetir */
                    continue;
                }

                if (x < 0 || x > 10) {
                    printf("Fuera del rango.\n");
                }
            } while (x < 0 || x > 10);

            notas[i][j] = x;
        }
    }

    /* Inicializaciones */
    for (i = 0; i < 5; i++) {
        promE[i] = 0;
        maxE[i] = notas[i][0];
        minE[i] = notas[i][0];
    }
    for (j = 0; j < 3; j++) {
        promA[j] = 0;
        maxA[j] = notas[0][j];
        minA[j] = notas[0][j];
    }

    /* Cálculos */
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 3; j++) {
            float n = notas[i][j];

            promE[i] += n;
            promA[j] += n;

            if (n > maxE[i]) maxE[i] = n;
            if (n < minE[i]) minE[i] = n;

            if (n > maxA[j]) maxA[j] = n;
            if (n < minA[j]) minA[j] = n;

            if (n >= 6) aprobA[j]++;
            else reproA[j]++;
        }
        promE[i] /= 3.0f;
    }
    for (j = 0; j < 3; j++) promA[j] /= 5.0f;

    /* Salidas */
    printf("\n--- Promedio por estudiante ---\n");
    for (i = 0; i < 5; i++)
        printf("Estudiante %d: %.2f\n", i+1, promE[i]);

    printf("\n--- Promedio por asignatura ---\n");
    for (j = 0; j < 3; j++)
        printf("Asignatura %d: %.2f\n", j+1, promA[j]);

    printf("\n--- Nota alta/baja por estudiante ---\n");
    for (i = 0; i < 5; i++)
        printf("Estudiante %d -> Alta: %.2f | Baja: %.2f\n", i+1, maxE[i], minE[i]);

    printf("\n--- Nota alta/baja por asignatura ---\n");
    for (j = 0; j < 3; j++)
        printf("Asignatura %d -> Alta: %.2f | Baja: %.2f\n", j+1, maxA[j], minA[j]);

    printf("\n--- Aprobados/Reprobados por asignatura (>=6) ---\n");
    for (j = 0; j < 3; j++)
        printf("Asignatura %d -> Aprobados: %d | Reprobados: %d\n", j+1, aprobA[j], reproA[j]);

    return 0;
}