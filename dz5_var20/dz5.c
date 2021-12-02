#include <stdio.h>
#include <stdlib.h>

void new_string (int n, FILE *file, int i, int j){
    while (n--)
        fprintf(file, "%d -- %d\n", i, j);
}

int matr_size (FILE *file) {
    int n = 0;
    char c;
    while (((c = fgetc(file)) != '\n') && (c != EOF)) 
        if (c == ' ')
            n++;
    n++;
    return n;
}

int** file_to_matr (int n, FILE *file){
    int** matr;
    int i = 0, x = 0;
    char c;

    matr = (int**)malloc(n * sizeof(int*));
    for (int k = 0; k < n; k++){
        matr[k] = (int*)malloc(n * sizeof(int));
        if (matr[k] == NULL)
            printf("Error\n");
    }

    for (int j = 0; j < n; j++){
        while (((c = fgetc(file)) != '\n') && (c != EOF)){
            if ((c != ' ') && ((c > '9') || (c < '0'))){
                printf ("Wrong sign\n"); 
                exit (1);
            }
            else{
                if (c == ' ') {
                    matr[i][j] = x;
                    x = 0;
                    i++;
                }
                else {
                    x = x*10 + (c - '0');
                }
            }
        }
        matr[i][j] = x;
        x = 0;
        if (i >= n){
            printf ("Matrix not sqare\n"); 
            exit (1);
        }
        i = 0;
    }
    return matr;
}

void matr_to_graph (int** matr, FILE *file, int n) {
    int sum = 0;

    fprintf(file, "graph G{\n");

    for (int j = 0; j < n; j++){
        for (int i = 0; i < n; i++) {
            if ((matr[i][j] != 0) && (i >= j))
                new_string (matr[i][j], file, i, j);
            sum += matr[i][j];
        }
        if (sum == 0) 
            fprintf(file, "%d\n", j);
        sum = 0;
    }

    fprintf(file, "}");
}

void str_delete (int** matr, int m, int n){ 
    if (m >= n){
        printf("Nhere is no this node");
        exit(1);
    }
    for (int j = m; j <= (n-2); j++)
        for (int i = 0; i < n; i++)
            matr[i][j] = matr[i][j + 1];

    for (int i = m; i <= (n - 2); i++)
        for (int j = 0; j < n; j++)
            matr[i][j] = matr[i + 1][j];
}

void pr(int** matr, int n){
    for (int j = 0; j < n; j++){
        for (int i = 0; i < n; i++)
            printf("%d ", matr[i][j]);
        printf("\n");
    }   
}

int** sort(int** matr, int n){
    int** a;
    int* tmp;
    int sum = 0, min;
    a = (int**)malloc(n * sizeof(int*));
    for (int k = 0; k < n; k++){
        a[k] = (int*)malloc(2 * sizeof(int));
        if (a[k] == NULL) 
            printf("Error\n");
    }
    for (int j = 0; j < n; j++) {
        a[j][0] = j;
        for (int i = 0; i < n; i++)
            sum += matr[i][j];
        a[j][1] = sum;
        sum = 0;
    }
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
            if (a[min][1] < a[j][1])
                min = j;
        tmp = a[min];
        a[min] = a[i];
        a[i] = tmp;
    } 
    return a;  
}

int main(void)
{
    int n, i, m;
    int** matr;
    int** a;
    FILE *input;
    FILE *graph_data_1;
    FILE *graph_data_2;

    input = fopen("input.txt", "r");
    graph_data_1 = fopen("graph_data_1.txt", "w");
    graph_data_2 = fopen("graph_data_2.txt", "w");

    n = matr_size(input);
    fclose(input);
    input = fopen("input.txt", "r");

    matr = file_to_matr(n, input);
    pr(matr, n);

    matr_to_graph (matr, graph_data_1, n); 
    printf("Select a node to delete (starting from 0): ");
    scanf("%d", &m);

    if (m != (n - 1))
        str_delete(matr, m, n);
    pr(matr, n - 1);

    matr_to_graph (matr, graph_data_2, --n);

    fclose(graph_data_1);
    fclose(graph_data_2);
    fclose(input);


    a = sort(matr, n);
    printf("Nodes in descending order: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i][0]);

    printf ("\n");
    system ("dot -T png graph_data_1.txt -o graph1.png && sxiv graph1.png");
    system ("dot -T png graph_data_2.txt -o graph2.png && sxiv graph2.png");
    
    return 0;
}
