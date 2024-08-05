#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// my_strings_len은 배열 my_strings의 길이입니다.
// parts_rows는 2차원 배열 parts의 행 길이, parts_cols는 2차원 배열 parts의 열 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_strings[], size_t my_strings_len, int** parts, size_t parts_rows, size_t parts_cols) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    
    //전체 문자열의 길이 구하기 
    size_t total_length = 0;
    for(int i=0; i<parts_rows; i++){
        total_length += parts[i][1] - parts[i][0] + 1; 
    }
    
    //결과 문자열 동적할당 
    char* answer = (char*)malloc(sizeof(char)*total_length + 1);
    if(answer == NULL){
        printf("memory allocation failed!");
        return NULL;
    }
    
    //부분 문자열들을 결과 문자열에 복사 
    size_t pos = 0; 
    
    for(size_t i=0; i<parts_rows; i++){
        int start = parts[i][0];
        int end = parts[i][1];
        int length = end - start + 1; 
        strncpy(answer+pos, my_strings[i]+start,length);
        pos += length;    
    }
    answer[total_length] = '\0'; 
    
    return answer;
}

int main(void){
    const char* my_strings[]={"progressive", "hamburger", "hammer", "ahocorasick"};
    size_t my_strings_len = sizeof(my_strings)/sizeof(my_strings[0]); 
    int** parts = {{0, 4}, {1, 2}, {3, 5}, {7, 7}};
    size_t parts_rows = sizeof(parts)/sizeof(parts[0]); // 32/8=4 
    size_t parts_cols = sizeof(parts[0])/sizeof(parts[0][0]); // 8/4=2
    
    char* result = solution(my_strings, my_strings_len, parts, parts_rows, parts_cols); 
    
    if(result != NULL){
        printf("%s\n", result);
        free(result);
    }
    return 0; 
}