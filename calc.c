////////////////////////////////////////////////
// COMPILAÇÃO

// rodarC

////////////////////////////////////////////////
// BIBLIOTECAS

#include <stdio.h>

////////////////////////////////////////////////
// DEFINIÇÕES

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
    int N = potencia (10, nivelDePrecisao);

    double deltaX = (b - a) / N; // Largura que será usada nos retângulos

    double soma = 0; // Soma total da área

    for (int i = 1; i <= N; i ++) // Anda por todo o gráfico
    {
        double x = a + i * deltaX; // Pega a posição X do termo atual
        
        soma += f (x) * deltaX; // Base * Altura do retângulo
    }

    return soma;
}

////////////////////////////////////////////////
// FUNÇÕES

double funcao_1 (double x) { return (x + x*x);}   
double funcao_2 (double x) { return (x);}   
double funcao_3 (double x) { return (x*x);}   

////////////////////////////////////////////////
// MAIN

int main (void)
{
    double a = 0, b = 1;

    double resposta = integrar (funcao_3, 7, a, b);

    printf ("\nIntegral da funcao entre '%g' e '%g': %g\n", a, b, resposta);

    return 0;
}