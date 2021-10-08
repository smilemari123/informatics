#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char c, m[64]={};
    int i = 0, fl = 0;
    printf ("Enter a number: ");
    while (((c = getchar()) != '\n') && (i < 64)){
        if ((c != '.') && ((c > '9') || (c < '0'))){
            printf ("Invalid character entered"); 
            exit (1);
        }
        if (c == '.'){
            fl = 1; 
            c = '|';
        }
        m[i++] = c;
    }
    
    if (fl == 0){
        printf ("The entered number does not contain a dot or contains more than 64 characters"); 
        exit (1);
    }
    
    i = 0;
    while ((c = m[i]) != '\0')
        printf ("%c", m[i++]);
    return 0;
}
