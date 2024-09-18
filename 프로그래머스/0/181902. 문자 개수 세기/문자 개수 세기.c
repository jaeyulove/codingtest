#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* my_string) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*52);
    size_t my_string_len = strlen(my_string); 

    const char alphabet[] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
    };
    for(int i=0; i<52; i++){
        answer[i] = 0; 
    }

    for (int i = 0; i < 52; i++) {
        for(int j=0; j<my_string_len; j++) {
            if(alphabet[i] == my_string[j]){
                answer[i] ++; 
            }
        }
    }    
    return answer;
}

int main(void) {
    const char* my_string = "Programmers"; 
    int* result = solution(my_string);

    if(result != NULL) {
        for(int i=0; i<52; i++) {
            printf("%d", result[i]); 
        }
        free(result);
    }
    return 0; 
}