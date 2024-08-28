#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* solution(const char* intStrs[], size_t intStrs_len, int k, int s, int l, int* result_len) {
    // 결과 배열을 위한 메모리 할당
    int* answer = (int*)malloc(sizeof(int) * intStrs_len);
    int index = 0;

    for(size_t i = 0; i < intStrs_len; i++) {
        char temp[l + 1];  
        strncpy(temp, intStrs[i] + s, l);
        temp[l] = '\0'; 

        int num = atoi(temp);  

        if(num > k) {
            answer[index++] = num;  
        }
    }

    *result_len = index;  //역참조로 result_len 에 index 값을 넣는다. 
    return answer;
}

int main(void) {
    const char* intStrs[] = {"0123456789", "9876543210", "9999999999999"};
    size_t intStrs_len = sizeof(intStrs) / sizeof(intStrs[0]);
    int k = 50000; 
    int s = 5;
    int l = 5;
    int result_len = 0; 
    
    int* result = solution(intStrs, intStrs_len, k, s, l, &result_len); 
    
    if(result != NULL) {
        for(size_t i = 0; i < result_len; i++) {
            printf("%d\n", result[i]);
        }
        free(result);  
    }

    return 0; 
}
