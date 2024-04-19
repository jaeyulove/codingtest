#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int* solution(int num_list[], size_t num_list_len) {
    int* answer = (int*)malloc(sizeof(int)*2);
    if (answer == NULL) {
        return NULL;
    }
    
    int i;
    int odd = 0;
    int even = 0; 
    
    for(i=0; i<num_list_len; i++){
        if(num_list[i] % 2 == 0){
            even ++; 
        }
        else {
            odd ++;
        }
    }
    answer[0] = even; 
    answer[1] = odd;  
    
    return answer;
}
    
int main(void) {
    int num_list[] = {1, 2, 3, 4, 5};
    size_t num_list_len = sizeof(num_list) / sizeof(num_list[0]);
    int* result = solution(num_list, num_list_len);

    if (result != NULL) {
        printf("Even: %d, Odd: %d\n", result[0], result[1]);
        free(result); // 동적 할당한 메모리 해제
    }

    return 0;
}
