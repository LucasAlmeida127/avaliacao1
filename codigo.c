#include<stdlib.h>
#include<stdio.h>

int Potencia(int base, int expoente)
{
    if(expoente == 0)
        return 1;
    else
        return (base * Potencia(base, expoente-1));
}

int main(void)
{
    int bin1, bin2, dec=0;
    char operacao;
    scanf("%c", &operacao);
    scanf("%d", &bin1);
    scanf("%d", &bin2);

    return 0;
}