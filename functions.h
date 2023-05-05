#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    unsigned char** matrix;
    int value;
} Solution;
/* Representação de uma solução. */

typedef struct List {
    Solution solution;
    struct List* next;
} List;
/* Representação da lista tabu. */

int* get_data_from_file(char* file_name);
/* Lê um arquivo .dat e retorna os valores em um vetor de dados. */

int** build_task_matrix(int* parameters, int number_of_tasks);
/* Constrói uma matriz de tarefas, onde a quantidade de linhas é a quantidade de tarfas e a quantidade de colunas é 4, onde
 * a primeira coluna representa o índice da tarefa, a segunda representa o tempo de início, a terceira representa o tempo de fim
 * e por último, a quarta que representa a quantidade de cores que a tarefa exige. */

int search_bigger_time(int** matriz_of_parameters, int number_of_tasks);
/* Procura o maior tempo na matriz de parametros. */

unsigned char** create_solution_matrix(int number_of_tasks);
/* Cria uma matriz identidade binária que representa a solução, cada linha representa uma máquina e cada coluna representa 
 * o índice da tarefa. O número 1 representa que a tarefa 'x' está na máquina 'y'. */

void print_solution_matrix(Solution solution, int number_of_tasks);
/* Função que imprime na tela em formato de tabela a matriz de solução. */

int calculate_solution_value(Solution solution, int number_of_tasks);
/* Calcula o valor da solução. */

Solution build_initial_solution(int number_of_tasks);
/* Constrói a solução inicial. */

List* initialize_list();
/* Inicializa a lista. */

int is_empty_list(List* list);
/* Verifica se a lista é vazia. */

List* insert_solution_in_list(Solution solution, List* list);
/* Insere um novo elemento na lista. A inserção é feita no final da lista. */