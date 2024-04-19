#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int age) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(sizeof(char) * 5);

    if (answer == NULL) {
        printf("메모리 할당 실패!\n");
        return NULL; 
    }

    // 숫자를 아스키 값으로 변환 
    int index = 0;

    if (age == 0) {
        answer[index++] = 'a'; 
    }
    else {
        while (age > 0) {
            answer[index++] = 'a' + age % 10;
            age /= 10; 

            // 3 / 10의 계산 결과는 실제로 0.3이 아닌, 정수 부분만을 취하는 0이 됨 
        }
        answer[index]='\0'; 
    }

    // 문자열 뒤집기 
    for (int i = 0; i < index / 2; i++) {
        char temp = answer[i];
        answer[i] = answer[index - 1 - i];
        answer[index - 1 - i] = temp;
    }
    return answer;
}

int main(void) {
    int age = 32;
    char* result = solution(age);

    if (result != NULL) {
        printf("%s\n", result);
        free(result);
    } else {
        printf("메모리 할당 실패\n"); 
    }
    return 0; 
}