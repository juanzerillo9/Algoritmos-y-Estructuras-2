#include <stdio.h>

// Definición de la función recursiva para calcular el factorial
int factorial(int n) {
    if (n == 0) {
        return 1;  // Caso base: el factorial de 0 es 1
    } else {
        return n * factorial(n - 1);  // Caso recursivo
    }
}

int main() {
    int num = 5;  // Cambia este número para calcular el factorial de otro valor
    printf("El factorial de %d es %d\n", num, factorial(num));
    return 0;
}