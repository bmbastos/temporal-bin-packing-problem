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

