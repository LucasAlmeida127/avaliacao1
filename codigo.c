#include<stdlib.h>
#include<stdio.h>

int Adicao(int num1, int num2) //Função que realiza adição
{
    return num1+num2;
}

int Subtracao(int num1, int num2) //Função que realiza subtração
{
    return num1-num2;
}

int Multiplicacao(int num1, int num2) //Função que realiza multiplicação
{
    return num1*num2;
}

int Divisao(int num1, int num2) //Função que realiza divisão
{
    return num1/num2;
}

int Resto(int num1, int num2) //Função que calcula o resto
{
    return num1%num2;
}

int Potencia(int base, int expoente) //Função recursiva que realiza potenciação sem o uso de bibliotecas externas
{
    if(expoente == 0)
        return 1;
    else
        return (base * Potencia(base, expoente-1));
}

int RetornaBin(int decimal) //Função que recebe decimal e retorna binário
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

int TransformaDec(int binario) //Função que recebe binário e retorna decimal
{
    int decimal = 0, i;
    for(i = 0; binario > 0; i++)
    {
        decimal += Potencia(2,i) * (binario % 10);
        binario /= 10;
    }
    return decimal;
}

int main(void) //Função main
{
    int bin1, bin2, resultado_bin;
    int dec1=0, dec2=0, resultado_dec=0;
    char operacao;
    scanf("%c", &operacao); //Entrada
    scanf("%d", &bin1);
    scanf("%d", &bin2);
    dec1 = TransformaDec(bin1);
    dec2 = TransformaDec(bin2);

    // Verificando a operação escolhida pelo usuário
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
    
    // Saída
    printf("--------\n");
    if (resultado_dec > 255){ //Verificando a quantidade de bits
        printf("Total de bits excedido");
    } else {
        resultado_bin = RetornaBin(resultado_dec);
    }
    return 0;
}