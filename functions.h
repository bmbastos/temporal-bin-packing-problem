#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int* get_data_from_file(char* file_name);
/* Lê um arquivo .dat e retorna os valores em um vetor de dados. */

int** build_task_matrix(int* parameters, int number_of_tasks);
/* Constrói uma matriz de tarefas, onde a quantidade de linhas é a quantidade de tarfas e a quantidade de colunas é 4, onde
*  a primeira coluna representa o índice da tarefa, a segunda representa o tempo de início, a terceira representa o tempo de fim
*  e por último, a quarta que representa a quantidade de cores que a tarefa exige. */

