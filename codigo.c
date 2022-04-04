#include<stdlib.h>
#include<stdio.h>

int Adicao(int num1, int num2)
{
    return num1+num2;
}

int Subtracao(int num1, int num2)
{
    return num1-num2;
}

int Multiplicacao(int num1, int num2)
{
    return num1*num2;
}

int Divisao(int num1, int num2)
{
    return num1/num2;
}

int Resto(int num1, int num2)
{
    return num1%num2;
}

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
    int bin1, bin2, resultado_bin;
    int dec1=0, dec2=0, resultado_dec=0;
    char operacao;
    scanf("%c", &operacao);
    scanf("%d", &bin1);
    scanf("%d", &bin2);
    dec1 = TransformaDec(bin1);
    dec2 = TransformaDec(bin2);

    if (operacao == '+'){
        resultado_dec = Adicao(dec1,dec2);
    }
    else if (operacao == '-'){
        resultado_dec = Subtracao(dec1,dec2);
    }
    else if (operacao == '*'){
        resultado_dec = Multiplicacao(dec1,dec2);
    }
    else if (operacao == '/'){
        resultado_dec = Divisao(dec1,dec2);
    }
    else if (operacao == '%'){
        resultado_dec = Resto(dec1,dec2);
    } else {
        printf("Operador nao existe");
        return 0;
    }

    printf("--------\n");
    printf("Resultado em decimal: %d\n", resultado_dec);
    printf("Resultado em binario: ");
    resultado_bin = RetornaBin(resultado_dec);
    return 0;
}