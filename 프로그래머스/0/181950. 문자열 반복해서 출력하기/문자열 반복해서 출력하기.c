#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // malloc, free를 사용하기 위해 추가

#define LEN_INPUT 11

int main(void) {
    char s1[LEN_INPUT];
    char *answer;  // 동적 메모리로 변경
    int a;
    int index = 0;

    // 문자열과 반복 횟수를 입력받음
    scanf("%s %d", s1, &a);

    // 필요한 메모리 크기 계산: (문자열 길이 * 반복 횟수) + 1 (널 문자용)
    int total_length = strlen(s1) * a + 1;
    
    // 동적 메모리 할당
    answer = (char *)malloc(total_length * sizeof(char));
    if (answer == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    // answer 배열 초기화
    memset(answer, 0, total_length);

    // 문자열을 n번 반복해서 answer 배열에 복사
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < strlen(s1); j++) {
            answer[index++] = s1[j];
        }
    }

    // 문자열 종료를 표시하기 위한 널 문자 추가
    answer[index] = '\0';

    // 결과 출력
    printf("%s", answer);

    // 동적 메모리 해제
    free(answer);
    
    return 0;
}
