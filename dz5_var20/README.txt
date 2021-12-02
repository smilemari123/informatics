Используемые функции:
void new_string (int n, FILE *file, int i, int j)
	Создание новой строки в файле file. Описывает n ребер между вершинами i и j

int matr_size (FILE *file) 
	Считает размер матрицы, содержащейся в файле file по первой строке

int** file_to_matr (int n, FILE *file)
	Преобразует файл file в матрицу размером n на n

void matr_to_graph (int** matr, FILE *file, int n) 
	Преобразует матрицу размером n на n в file, описывающий граф

void str_delete (int** matr, int m, int n)
	Удаляет вершину m в матрице смежности matr размером n на n

void pr(int** matr, int n)
	Выводит матрицу matr размера n на n

int** sort(int** matr, int n)
	Сортирует по возрастанию степени вершины графа, описанного в матрице смежности matr размера n на n