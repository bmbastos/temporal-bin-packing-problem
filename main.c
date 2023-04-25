#include "functions.h"

int main(int argc, char const *argv[])
{
    FILE *file;
    char path[200] = "C:/Users/Bruno/Desktop/CProjects/otimizacao/instancias/";
    char file_name[] = "instancia_5_5.dat";
    strcat(path, file_name);
    int *vector_of_parameters;
    int **matrix_of_tasks;

    vector_of_parameters = get_data_from_file(path);

    int n_tasks = vector_of_parameters[0];
    int n_cores = vector_of_parameters[1];

    matrix_of_tasks = build_task_matrix(vector_of_parameters, n_tasks);
    free(vector_of_parameters);



    return 0;
}