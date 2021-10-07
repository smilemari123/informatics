#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    char c, m[64]={};
    int i = 0, fl = 0, a = 0, b = 0, x =0, y = 0; 
    //a - число знаков до точки, b - после точки, x - число до точки, y - число после точки
    
    printf ("Введите число с плавающей точкой: ");
    while (((c=getchar())!='\n') && (i <= 64)){
        if ((c != '.') && ((c > '9') || (c < '0'))){
            printf ("Введен неверный символ"); 
            exit (1);
        }
        if (fl == 1){
            ++b;
        }
        if (c == '.'){
            fl = 1;
        }
        if (fl == 0){
            ++a;
        }
        m[i++] = c;
    }

    if (fl == 0){
        printf ("Введенное число не содержит точки или содержит больше 64 символов"); 
        exit (1);
    }
    
    //число до точки
    i = 0;
    fl = a - 1; 
    while (i < a){ 
        x += (m[i++] - '0') * pow(10, fl--);
    }
    
    //число после точки
    ++i;
    fl = b - 1;
    while (i < a + b + 1){
        y += (m[i++] - '0') * pow(10, fl--);
    }
    printf("%d | %d", x, y);
    
    return 0;
}
