#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
// intervals_rows는 2차원 배열 intervals의 행 길이, intervals_cols는 2차원 배열 intervals의 열 길이입니다.
int* solution(int arr[], size_t arr_len, int** intervals, size_t intervals_rows) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    size_t result_len = 0; 
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            result_len += intervals[i][j];
        }
    }
    
    int* answer = (int*)malloc(sizeof(int)*result_len);
    int index = 0;
    
    for(size_t i=0; i<intervals_rows; i++){
            for(size_t j=intervals[i][0]; j <= intervals[i][1]; j++){
                answer[index++] = arr[j];
            }    
    }
    return answer;
}

int main(void){
    int arr[] = {1,2,3,4,5};
    size_t arr_len = sizeof(arr)/sizeof(arr[0]);
    
    size_t intervals_rows = 3;
    size_t intervals_cols = 3;
    
    int** intervals = (int**)malloc(sizeof(int*)*intervals_rows);
    for(size_t i=0; i<intervals_rows; i++){
        intervals[i] = (int*)malloc(sizeof(int)*intervals_cols);
    }
    
    printf("행렬의 값을 입력하시오:");
    for(int i=0; i<intervals_rows; i++){
        for(int j=0; j<intervals_cols; j++){
        printf("%d행 %d열의 값 입력:", i,j);
        scanf("%d", &intervals[i][j]);
        }
    }
    
    int* result = solution(arr,arr_len,intervals,intervals_rows);
        
    if(result != NULL){
        for(int i=0; result[i] != 0; i++){
            printf("%d", result[i]);
        }
        }
        free(result);
        return 0; 
    }
    