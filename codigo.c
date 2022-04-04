#include<stdlib.h>
#include<stdio.h>

int Potencia(int base, int expoente)
{
    if(expoente == 0)
        return 1;
    else
        return (base * Potencia(base, expoente-1));
}

int RetornaBin(int decimal)
{
    int aux, i;
    for (i = 7 ; i>= 0 ; i--){
        aux = decimal >> i;
        if (aux & 1){
            printf("1");
        } else {
            printf("0");}
    }
}

int TransformaDec(int binario)
{
    int decimal = 0, i;
    for(i = 0; binario > 0; i++)
    {
        decimal += Potencia(2,i) * (binario % 10);
        binario /= 10;
    }
    return decimal;
}

int main(void)
{
    int bin1, bin2, dec=0;
    char operacao;
    //scanf("%c", &operacao);
    scanf("%d", &bin1);
    //scanf("%d", &bin2);
    dec = RetornaBin(bin1);
    //printf("Valor em decimal: %d",dec);

    return 0;
}