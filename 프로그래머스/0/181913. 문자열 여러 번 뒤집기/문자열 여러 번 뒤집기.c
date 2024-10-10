#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> 

// queries_rows는 2차원 배열 queries의 행 길이, queries_cols는 2차원 배열 queries의 열 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, int** queries, size_t queries_rows, size_t queries_cols) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
size_t my_string_len = strlen(my_string); 
char* answer = (char*)malloc((sizeof(char)*my_string_len+1));
strcpy(answer,my_string); 
char temp; 
int i,j; 

 // 쿼리를 처리하여 문자를 범위 내에서 뒤집기
    for (size_t i = 0; i < queries_rows; i++) {
        // 쿼리에서 시작과 끝 인덱스
        int start = queries[i][0];
        int end = queries[i][1];
        
        // 범위 내 문자를 뒤집기
        while (start < end) {
            char temp = answer[start];
            answer[start] = answer[end];
            answer[end] = temp;
            start++;
            end--;
        }
    }
                                                     
return answer;           
}

int main() {
    // 쿼리 배열의 크기
    int query_count = 4; 
    int column_count = 2; 

    // 2차원 배열 동적 할당
    int** queries = (int**)malloc(query_count * sizeof(int*));
    for (int i = 0; i < query_count; i++) {
        queries[i] = (int*)malloc(column_count * sizeof(int));
    }

    // 값 초기화
    queries[0][0] = 2; queries[0][1] = 3;
    queries[1][0] = 0; queries[1][1] = 7;
    queries[2][0] = 5; queries[2][1] = 9;
    queries[3][0] = 6; queries[3][1] = 10;

    // 값 출력
    for (int i = 0; i < query_count; i++) {
        printf("{%d, %d}\n", queries[i][0], queries[i][1]);
    }

    // 동적 할당 메모리 해제
    for (int i = 0; i < query_count; i++) {
        free(queries[i]);
    }
    free(queries);

    return 0;
}