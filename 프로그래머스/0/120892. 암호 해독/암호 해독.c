#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* cipher, int code) {
    size_t len = strlen(cipher);
    char* answer = (char*)malloc(sizeof(char) * (len / code + 1)); 
    
    if (answer == NULL) {
        printf("memory alloc failed");
        return NULL;
    }

    int index = 0;
    for (int i = 1 ; i * code < len+1; i++) {
        answer[index++] = cipher[code*i-1]; 
    }
    answer[index] = '\0'; 
    return answer;
}

int main(void) {
    const char* cipher = "dfjardstddetckdaccccdegk";
    int code = 4;
    char* result = solution(cipher, code);

    if (result != NULL) {
        printf("%s\n", result); 
        free(result);
    } else {
        printf("memory alloc failed");
    }

    return 0;
}
