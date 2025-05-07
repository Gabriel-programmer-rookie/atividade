#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NOTAS 100


void ordenar(float notas[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (notas[j] > notas[j+1]) {
                float temp = notas[j];
                notas[j] = notas[j+1];
                notas[j+1] = temp;
            }
}


float calcular_media(float notas[], int n) {
    float soma = 0;
    for (int i = 0; i < n; i++) {
        soma += notas[i];
    }
    return soma / n;
}


float calcular_mediana(float notas[], int n) {
    ordenar(notas, n);
    if (n % 2 == 0)
        return (notas[n/2 - 1] + notas[n/2]) / 2.0;
    else
        return notas[n/2];
}


float calcular_desvio_padrao(float notas[], int n, float media) {
    float soma = 0;
    for (int i = 0; i < n; i++) {
        soma += pow(notas[i] - media, 2);
    }
    return sqrt(soma / n);
}

int main() {
    float notas[MAX_NOTAS];
    int totalNotas = 0;
    float nota1, nota2;

    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);
    notas[totalNotas++] = nota1;

    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);
    notas[totalNotas++] = nota2;

    float media = (nota1 + nota2) / 2.0;
    int tentativasExtras = 0;

    while (media < 6.0) {
        float novaNota;
        printf("Média atual: %.2f (menor que 6.0). Digite nova tentativa: ", media);
        scanf("%f", &novaNota);

      
        if (nota1 < nota2)
            nota1 = novaNota;
        else
            nota2 = novaNota;

        notas[totalNotas++] = novaNota;
        media = (nota1 + nota2) / 2.0;
        tentativasExtras++;
    }

    printf("\nParabéns! Média final: %.2f\n", media);
    printf("Total de tentativas extras: %d\n", tentativasExtras);

   
    float mediaTodas = calcular_media(notas, totalNotas);
    float medianaTodas = calcular_mediana(notas, totalNotas);
    float desvio = calcular_desvio_padrao(notas, totalNotas, mediaTodas);

    printf("\nEstatísticas das notas:\n");
    printf("Média das notas: %.2f\n", mediaTodas);
    printf("Mediana das notas: %.2f\n", medianaTodas);
    printf("Desvio padrão das notas: %.2f\n", desvio);

    return 0;
}

