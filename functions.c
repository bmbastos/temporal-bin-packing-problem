#include "functions.h"

int* get_data_from_file(char* file_name){
    FILE* file;
    char line[100];
    char* word;
    int *vector;
    
    file = fopen(file_name, "r");
    if (file == NULL){
        printf("Não foi possível abrir o arquivo.\n");
    }
    else {
        int length_of_vector = 0;
        int index = 0;
        fscanf(file, "%d", &length_of_vector);
        rewind(file);
        length_of_vector = length_of_vector * 4 + 2;
        vector = (int*) malloc(length_of_vector * sizeof(int));
        while (fgets(line, 100, file) != NULL) {
            word = strtok(line, " ");
            while(word != NULL && index < length_of_vector){
                vector[index] = atoi(word);
                word = strtok(NULL, " ");
                index++;
            }
        }
    fclose(file);
    }
    return vector;
}

int** build_task_matrix(int* parameters, int number_of_tasks){
    int **matrix = (int **) malloc(number_of_tasks * sizeof(int *));
    int i, j;
    for (i = 0; i < number_of_tasks; i++) {
        matrix[i] = (int *) malloc(4 * sizeof(int));
    }
    
    int index_of_task = 2;
    for (i = 0; i < number_of_tasks; i++){
        for (j = 0; j < 4; j++){
            matrix[i][j] = parameters[index_of_task + j];
        }
        index_of_task += 4;
    }
    return matrix;
}

int search_bigger_time(int** matriz_of_parameters, int number_of_tasks){
    int bigger = 0;
    for (int i = 0; i < number_of_tasks; i++){
        if (matriz_of_parameters[i][3] > bigger){
            bigger = matriz_of_parameters[i][2];
        }
    }
    return bigger;
}

unsigned char** create_solution_matrix(int number_of_tasks){
    int i = 0;
    unsigned char** matrix;
    matrix = (unsigned char **) calloc(number_of_tasks, sizeof(unsigned char *));
    for (i = 0; i < number_of_tasks; i++){
        matrix[i] = (unsigned char *) calloc(number_of_tasks, sizeof(unsigned char));
    }
    for (i = 0; i < number_of_tasks; i++){
        matrix[i][i] = 1;
    }
    return matrix;
}

void print_solution_matrix(Solution solution, int number_of_tasks){
    int i = 0, j = 0;
    printf("    +");
    for (i = 0; i < number_of_tasks * 2 + 1; i++)
    {
        printf("-");
    }
    printf("+\n");
    for (i = 0; i < number_of_tasks; i++){
        printf("%.3d | ", i);
        for (j = 0; j < number_of_tasks; j++){
            printf("%hhu ", solution.matrix[i][j]);
        }
        printf("|\n");
    }
    printf("    +");
    for (i = 0; i < number_of_tasks * 2 + 1; i++)
    {
        printf("-");
    }
    printf("+\n");
}

int calculate_solution_value(Solution solution, int number_of_tasks){
    int value = 0;
    for (int i = 0; i < number_of_tasks; i++){
        for (int j = 0; j < number_of_tasks; j++){
            if (solution.matrix[i][j] == 1){
                value++;
                break;
            }
        }
    }
    return value;
}

Solution build_initial_solution(int number_of_tasks){
    Solution s;
    s.matrix = create_solution_matrix(number_of_tasks);
    s.value = calculate_solution_value(s, number_of_tasks);
    return s;
}

List* initialize_list(){
    List* list = NULL;
    return list;
}

int is_empty_list(List* list){
    int resp = 0;
    if (list == NULL){
        resp = 1;
    }
    return resp;
}

List* insert_solution_in_list(Solution solution, List* list){
    List* new_element = (List*) malloc(sizeof(List));
    new_element->solution.matrix = solution.matrix;
    new_element->solution.value = solution.value;
    new_element->next = NULL;

    if (is_empty_list(list)) {
        list = new_element;
    }
    else {
        List* current = list;
        while (current->next != NULL) {
            current = (List*) current->next;
        }
        current->next = (struct List*) new_element;
    }
    return list;
}
