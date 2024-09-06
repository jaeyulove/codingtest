#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// arr_len은 배열 arr의 길이입니다.
// queries_rows는 2차원 배열 queries의 행 길이, queries_cols는 2차원 배열 queries의 열 길이입니다.
int* solution(int arr[], size_t arr_len, int** queries, size_t queries_rows, size_t queries_cols) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*arr_len);
    memcpy(answer, arr, sizeof(int) * arr_len);
    int temp = 0;
    
    for(int i=0; i<queries_rows; i++){
        temp = answer[queries[i][0]];
        answer[queries[i][0]] = answer[queries[i][1]]; 
        answer[queries[i][1]] = temp; 
    }
    return answer;
}

int main(void){
    int arr[] = {0,1,2,3,4};
    size_t arr_len = sizeof(arr)/sizeof(arr[0]);
    int queries[3][2] = {{0, 3}, {1, 2}, {1, 4}};
    size_t queries_rows = sizeof(queries)/sizeof(queries[0]);
    size_t queries_cols = sizeof(queries[0])/sizeof(queries[0][0]); 
    
    int* result = solution(arr,arr_len,queries,queries_rows,queries_cols); 
    
    if(result != NULL){
        for(int i=0; i<arr_len; i++){
            printf("%d", result[i]); 
            free(result[i]);
        } 
    }
    free(result);
    return 0; 
}