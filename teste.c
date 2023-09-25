#include <stdio.h>
#include <stdlib.h>
#include "dados.h"
#include "calculo.c"

int main()
{

    FILE *file;
    int numVertices;
    Ponto *vertices;
    float area = 0.0;

    file = fopen("vertices.txt", "r");

    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }

    fscanf(file, "%d", &numVertices);

    if (numVertices < 3)
    {
        printf("O poligono deve ter pelo menos 3 vertices.\n");
        fclose(file);
        return 1;
    }

    vertices = (Ponto *)malloc(numVertices * sizeof(Ponto));
    if (vertices == NULL)
    {
        printf("Erro ao alocar memoria para os vertices.\n");
        fclose(file);
        return 1;
    }

    for (int i = 0; i < numVertices; i++)
    {
        fscanf(file, "%f %f", &(vertices[i].X), &(vertices[i].Y));
    }

    for (int i = 0; i < numVertices; i++)
    {
        printf("%.2f %.2f\n", vertices[i].X, vertices[i].Y);
    }

    fclose(file);

    return 0;
}
