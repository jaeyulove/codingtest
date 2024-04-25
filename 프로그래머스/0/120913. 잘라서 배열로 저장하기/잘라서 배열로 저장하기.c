#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** solution(const char* my_str, int n) {
    size_t len = strlen(my_str);
    int num_chunks = len / n; // 필요한 청크의 수 계산
    char** answer = (char**)malloc(sizeof(char*) * num_chunks);
    int index = 0;
    
    for (int i = 0; i < len; i += n) {
        int chunk_size = (i + n <= len) ? n : len - i;
        answer[index] = (char*)malloc(sizeof(char) * (chunk_size + 1));
        strncpy(answer[index], my_str + i, chunk_size);
        answer[index][chunk_size] = '\0'; 
        index++;
    }

    return answer;
}

int main(void){
    const char* my_str = "abc1Addfggg4556b";
    int n = 6;

    char** result = solution(my_str, n); 
    
    for (int i = 0; i < (strlen(my_str) + n - 1) / n; i++) {
        printf("%s\n", result[i]);
        free(result[i]); 
    }
    free(result); 
    return 0;
}
