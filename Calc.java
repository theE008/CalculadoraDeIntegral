////////////////////////////////////////////////
// COMPILAÇÃO

// rodarJava 

////////////////////////////////////////////////
// TERMOS

class Termo 
{
    // VARS
    private double multiplicativo = 1.0;
    private double potencia = 1.0;

    // CONS
    public Termo (double multi, double pot)
    {
        multiplicativo = multi;
        potencia = pot;
    }

    // GETS
    public double emX (double x)
    {
        return  multiplicativo * Math.pow (x, potencia);
    }
}

////////////////////////////////////////////////
// FUNÇÕES

class Funcao 
{
    // VARS
    private Termo termos [];

    // CONS 
    public Funcao (Termo termos [])
    {
        this.termos = termos;
    }

    // GETS
    public double emX (double x)
    {
        double resp = 0.0;

        int tam = termos.length;

        for (int i = 0; i < tam; i++)
        {
            resp += termos [i].emX (x);
        }

        return resp;
    }

    public double integrar (int nivelDePrecisao, double a, double b)
    {
        double N = Math.pow(10, nivelDePrecisao); // precisão

        double deltaX = (b - a) / N; // Largura que será usada nos retângulos

        double soma = 0; // Soma total da área

        for (int i = 1; i <= N; i ++) // Anda por todo o gráfico
        {
            double x = a + i * deltaX; // Pega a posição X do termo atual
            
            soma += emX (x) * deltaX; // Base * Altura do retângulo
        }
    
        return soma;
    }
}

////////////////////////////////////////////////
// MAIN

public class Calc 
{
    public static void main (String args [])
    {
        Funcao func = new Funcao // Função X^2
        ( new Termo [] 
            {
                new Termo(1, 2) // x^2
            }
        );

        double a = 0, b = 1;

        System.out.println
        (
            "Integral da função entre '" + a + "' e '" + b + 
            "': " + func.integrar (7, a, b)
        );
    }
}