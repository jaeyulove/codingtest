#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* polynomial) {
    char* buffer = strdup(polynomial);  // polynomial을 수정 가능한 문자열로 복사
    char* token;
    int sum_x = 0;
    int sum_num = 0;

    token = strtok(buffer," ");
    
    while(token != NULL){
    if (strstr(token, "x")){
        if (strlen(token) == 1){
            sum_x += 1; 
        }
        else {
            token[strlen(token)-1] = '\0';  //strlen 은 NULL 값 들어가있음 
            sum_x += atoi(token);
        }
    } else {
        sum_num += atoi(token); 
    }
        token = strtok(NULL," "); //strtok 연솔 호출 시 인자에 NULL을 넣음 
    }
    
    char* answer = malloc(50);
    if(sum_x != 0) {
        if(sum_x == 1){
            sprintf(answer,"x");
        } else {
            sprintf(answer,"%dx", sum_x); 
        }
        if (sum_num != 0) {
            sprintf(answer + strlen(answer)," + %d", sum_num); 
        }
    } else {
        sprintf(answer,"%d", sum_num); 
    }
    
    free(buffer);
    return answer; 
}

int main(void) {
    const char* polynomial = "3x + 7 + x";
    char* result = solution(polynomial);
    if (result != NULL) {
        printf("%s\n", result);
        free(result);
    } else {
        printf("memory alloc failed");
    }
    return 0;
}
