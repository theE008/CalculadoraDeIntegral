////////////////////////////////////////////////
// COMPILAÇÃO

// rodarC

////////////////////////////////////////////////
// BIBLIOTECAS

#include <stdio.h>
#include <math.h>

////////////////////////////////////////////////
// DEFINIÇÕES

#define pi 3.14159265358979323846264338327950
typedef double (*funcao) (double);

////////////////////////////////////////////////
// POTÊNCIA (desnecessário, só para deixar a chamada mais bonita)

int potencia (int a, int b)
{
    int resp = 1;

    for (int x = 0; x < b; x ++) resp *= a;

    return resp;
}

////////////////////////////////////////////////
// INTEGRAR

double integrar (funcao f, int nivelDePrecisao, double a, double b)
{
    long long N = 100000000; // 10000000

    double deltaX = (b - a) / N; // Largura que será usada nos retângulos

    double soma = 0; // Soma total da área

    for (int i = 1; i < N; i ++) // Anda por todo o gráfico
    {
        double x = a + i * deltaX; // Pega a posição X do termo atual
        
        soma += f (x) * deltaX; // Base * Altura do retângulo
    }

    return soma;
}

double imprimirIntegral (funcao f, double a, double b)
{
    static int q = 1;
    printf ("Integral de %g ate %g da questao %d: %lf\n", a, b, q++, integrar (f, 0, a, b));
}

////////////////////////////////////////////////
// FUNÇÕES

double funcao_1 (double x) { return (4 * sqrt (36 - x * x)) ;} 
double funcao_2 (double x) { return (2 * pi * (9  - x * x)) ;} 
double funcao_3 (double x) { return (16/(sqrt (16 - x * x)));} 

////////////////////////////////////////////////
// MAIN

int main (void)
{
    imprimirIntegral (funcao_1, 0, 6);
    imprimirIntegral (funcao_2, 0, 3);
    imprimirIntegral (funcao_3, 0, 4);

    return 0;
}