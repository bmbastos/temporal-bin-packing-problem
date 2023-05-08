#include "functions.h"

int main(int argc, char const *argv[])
{
    FILE *file;
    char path[256] = "";
    char file_name[] = "instancia_5_5.dat";

    if (getcwd(path, sizeof(path)) == NULL){
        perror("getcwd() error\n");
    }
    else {
        strcat(path, "\\instancias\\");
        strcat(path, file_name);
        int *vector_of_parameters;
        int **matrix_of_tasks;

        vector_of_parameters = get_data_from_file(path);

        int n_tasks = vector_of_parameters[0];
        int n_cores = vector_of_parameters[1];

        matrix_of_tasks = build_task_matrix(vector_of_parameters, n_tasks);
        free(vector_of_parameters);
        Solution initial_solution = build_initial_solution(n_tasks);
        printf("Jobs: %d = Valor: %d\n", n_tasks, initial_solution.value);
        print_solution_matrix(initial_solution, n_tasks);
    }



    return 0;
}
