#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** solution(const char* quiz[], size_t quiz_len) {
    char** answer = (char**)malloc(sizeof(char*) * quiz_len);
    for (size_t i = 0; i < quiz_len; i++) {
        answer[i] = (char*)malloc(sizeof(char) * 2);  // "O" 또는 "X" 저장
        int left, right, result;
        char op;
        
        if (sscanf(quiz[i], "%d %c %d = %d", &left, &op, &right, &result) == 4) {
            int calc_result = (op == '+') ? left + right : left - right;
            if (calc_result == result) {
                strcpy(answer[i], "O");
            } else {
                strcpy(answer[i], "X");
            }
        } 
    }
    return answer;
}

int main(void) {
    const char* quiz[] = {"3 - 4 = -1", "5 + 6 = 11"};
    size_t quiz_len = sizeof(quiz) / sizeof(quiz[0]);
    
    char** result = solution(quiz, quiz_len);
    
    if (result != NULL) {
        for (size_t i = 0; i < quiz_len; i++) {
            printf("%s\n", result[i]);
            free(result[i]);
        }
        free(result);
    }
    return 0;
}
