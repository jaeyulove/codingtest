#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* my_string) {
    size_t len = strlen(my_string); 
    char* answer = (char*)malloc(sizeof(char) * (len + 1));
    
    // 대문자를 소문자로 변환하면서 answer에 복사
    for (int i = 0; i < len; i++) {
        if (my_string[i] >= 'A' && my_string[i] <= 'Z') {
            answer[i] = my_string[i] + 32;
        } else {
            answer[i] = my_string[i];
        }
    }
    answer[len] = '\0';  
    
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (answer[j] > answer[j + 1]) {
                char temp = answer[j];
                answer[j] = answer[j + 1];
                answer[j + 1] = temp;
            }
        }
    }

    return answer;
}

int main(void) {
    const char* my_string = "Bcad";
    char* result = solution(my_string);
    printf("%s\n", result);
    free(result);  
    return 0;
}
