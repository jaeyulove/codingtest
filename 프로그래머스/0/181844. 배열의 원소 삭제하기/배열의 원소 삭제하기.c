#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
// delete_list_len은 배열 delete_list의 길이입니다.
int* solution(int arr[], size_t arr_len, int delete_list[], size_t delete_list_len, int result_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*arr_len);
    int index=0;
    bool delete; 
    
    for(size_t i=0; i<arr_len; i++){
        delete = false; 
        for(size_t j=0; j<delete_list_len; j++){
            if(arr[i] == delete_list[j]){
                delete = true;
                break;
            }
        }
        if(!delete){
          answer[index++] = arr[i];    
        }
    }
    result_len = index; 
    return answer;
}

int main(void) {
    
    int arr[]={293, 1000, 395, 678, 94};
    size_t arr_len = sizeof(arr)/sizeof(arr[0]); // 20/4 = 5
    int delete_list[]= {94, 777, 104, 1000, 1, 12};
    size_t delete_list_len = sizeof(delete_list)/sizeof(delete_list[0]); 
    int result_len;
    
    int* result = solution(arr,arr_len,delete_list,delete_list_len,&result_len);
     
    if(result != NULL){
        for(size_t i=0; i<result_len; i++){
            printf("%d", result[i]);
            free(result[i]);
        }
        free(result);
    }
    return 0; 
}