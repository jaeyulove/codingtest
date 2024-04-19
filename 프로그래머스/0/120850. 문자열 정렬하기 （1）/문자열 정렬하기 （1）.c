#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 주어진 문자열에서 숫자만 추출하여 정수 배열로 반환
int* solution(const char* my_string) {
    size_t len = strlen(my_string); 
    int* answer = (int*)malloc(sizeof(int) * len); // 숫자가 모두 있을 최대 길이
    int count = 0;

    if (answer == NULL) {
        printf("메모리 할당 실패\n");
        return NULL;
    }
    
    for (int i = 0; i < len; i++) {
        if (my_string[i] >= '0' && my_string[i] <= '9') { // 문자가 숫자인지 확인
            answer[count++] = my_string[i] - '0'; // 문자를 숫자로 변환
        }
    }

    // 버블 정렬 로직 수정
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (answer[j] > answer[j + 1]) {
                int temp = answer[j];
                answer[j] = answer[j + 1];
                answer[j + 1] = temp;
            }
        }
    }

    if (count > 0) {
        // 실제 숫자 개수만큼 메모리 크기 조정
        int* resized = realloc(answer, sizeof(int) * count);
        if (resized != NULL) {
            answer = resized;
        } else {
            free(answer);
            return NULL;
        }
    } else {
        // 숫자가 없는 경우
        free(answer);
        return NULL;
    }

    return answer;
}

int main(void) {
    const char* my_string = "hi12392";
    int* result = solution(my_string);
        int count = 0; 
    
    if (result != NULL) {
        // 결과 출력
        int i = 0;
        while (i < count) {  // 수정된 조건
            printf("%d", result[i]);
            if (i < count - 1) printf(", ");
            i++;
        }
        free(result); // 메모리 해제
    } else {
        printf("결과 없음 또는 메모리 할당 실패\n");
    }
    
    return 0;
}
