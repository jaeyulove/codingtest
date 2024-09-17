#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// slicer_len은 배열 slicer의 길이입니다.
// num_list_len은 배열 num_list의 길이입니다.
int* solution(int n, int slicer[], size_t slicer_len, int num_list[], size_t num_list_len, int result_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*num_list_len);
    memset(answer,0, sizeof(int)*num_list_len); 
    
    int a = slicer[0];
    int b = slicer[1];
    int c = slicer[2];
    
    int index = 0; 
    
    if ( n == 1) {
        for(int i=0; i <= b; i++){
            answer[index++] = num_list[i];
        }
    }
    else if ( n == 2 ) {
        for(int i=a; i<num_list_len; i++){
            answer[index++] = num_list[i];
        }
    }
    else if (n == 3) {
        for(int i = a; i <= b; i++) {
            answer[index++] = num_list[i]; 
        }
    }
    else if ( n == 4) {
        for(int i=a; i<= b; i+=c) {
            answer[index++] = num_list[i]; 
        }
      }
      result_len = index;  
      return answer;
    }

int main(void) {
    int n = 3;
    int slicer[] = {1,5,2}; 
    size_t slicer_len = sizeof(slicer)/sizeof(slicer[0]); 
    int num_list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t num_list_len = sizeof(num_list)/sizeof(num_list[0]); 
    int result_len = 0; 
    
    int* result = solution(n, slicer, slicer_len, num_list, num_list_len, &result_len); 
    
    if(result != NULL) {
        for(int i = 0 ; i<result_len; i++) {
            printf("%d", result[i]);
        }
        free(result);
    }
    return 0; 
}