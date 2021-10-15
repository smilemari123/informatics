#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c, m[64]={};
    int i = 0, fl = 0;
    printf ("Введите число с плавающей точкой: ");
    while (((c=getchar())!='\n') && (i < 64)){
        if ((c != '.') && ((c > '9') || (c < '0'))){
            printf ("Введен неверный символ"); 
            exit (1);
        }
        if (c == '.'){
            fl = 1; 
            c = '|';
        }
        m[i++]=c;
    }
    
    if (fl == 0){
        printf ("Введенное число не содержит точки или содержит больше 64 символов"); 
        exit (1);
    }
    
    i = 0;
    while ((c = m[i]) != '\0')
        printf ("%c", m[i++]);

    return 0;
}