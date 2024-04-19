#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value; // 응급도
    int originalIndex; // 원래 배열에서의 인덱스
} Emergency;

// 구조체를 응급도에 따라 내림차순으로 정렬하기 위한 비교 함수
int compareEmergency(const void* a, const void* b) {
    Emergency* emergencyA = (Emergency*)a;
    Emergency* emergencyB = (Emergency*)b;
    return emergencyB->value - emergencyA->value; // 내림차순 정렬
}

int* solution(int emergency[], size_t emergency_len) {
    Emergency emergencies[emergency_len]; // 구조체 배열 선언
    int* answer = (int*)malloc(sizeof(int) * emergency_len); // 결과 배열 할당
    
    // 메모리 할당 검사
    if (answer == NULL) {
        printf("메모리 할당 실패\n");
        return NULL;
    }
    
    // 구조체 배열 초기화
    for (int i = 0; i < emergency_len; i++) {
        emergencies[i].value = emergency[i];
        emergencies[i].originalIndex = i; // 원래 인덱스 저장
    }

    // 구조체 배열을 응급도에 따라 내림차순으로 정렬
    qsort(emergencies, emergency_len, sizeof(Emergency), compareEmergency);
    
    // 각 원소의 원래 인덱스(1을 더해 1부터 시작하는 순서로)에 대한 순위를 answer 배열에 저장
    for (int i = 0; i < emergency_len; i++) {
        answer[emergencies[i].originalIndex] = i + 1;
    }
    
    return answer;
}

int main(void) {
    int emergency[] = {3, 76, 24};
    size_t emergency_len = sizeof(emergency) / sizeof(emergency[0]);
    int* result = solution(emergency, emergency_len);
    
    // 결과 출력
    if (result != NULL) {
        for (int i = 0; i < emergency_len; i++) {
            printf("%d ", result[i]);
        }
        free(result); // 할당된 메모리 해제
    } else {
        printf("메모리 할당 실패\n");
    }
    return 0;
}
