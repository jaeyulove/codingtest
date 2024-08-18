#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_rows는 2차원 배열 arr의 행 길이, arr_cols는 2차원 배열 arr의 열 길이입니다.
int solution(int** arr, size_t arr_rows, size_t arr_cols) {
    int answer = 1;
    bool compare = true;  
    
    for(size_t i=0; i<arr_rows; i++){
        for(size_t j=i; j<arr_cols; j++){
            if(arr[i][j] != arr[j][i]){
                return 0; 
            }
        }
    }
    return answer;
    }

int main(void){
    size_t arr_rows, arr_cols;
    
    printf("행렬의 행 개수를 입력하세요: ");
    scanf("%zu", &arr_rows);
    printf("행렬의 열 개수를 입력하세요: ");
    scanf("%zu", &arr_cols);
    
     // 행렬 동적 할당
    int** arr = (int**)malloc(arr_rows * sizeof(int*));
    for (size_t i = 0; i < arr_rows; i++) {
        arr[i] = (int*)malloc(arr_cols * sizeof(int));
    }
    
    // 행렬 값 입력
    printf("행렬 값을 입력하세요:\n");
    for (size_t i = 0; i < arr_rows; i++) {
        for (size_t j = 0; j < arr_cols; j++) {
            printf("%zu행 %zu열의 값 입력:",i,j);
            scanf("%d", &arr[i][j]);
        }
    }
    
    int result = solution(arr,arr_rows,arr_cols);
    printf("%d\n", result);
    
    // arr 동적 메모리 해제
    for (size_t i = 0; i < arr_rows; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}