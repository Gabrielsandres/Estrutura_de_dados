#include <math.h>
#include "dados.h"

float calcularArea(Ponto *vertices, int numVertices) {
    float area = 0.0;

    for (int i = 0; i < numVertices; i++) {
        int nextIndex = (i + 1) % numVertices;
        area += (vertices[i].X * vertices[nextIndex].Y - vertices[nextIndex].X * vertices[i].Y);
    }

    area = 0.5 * fabs(area);

    return area;
}
