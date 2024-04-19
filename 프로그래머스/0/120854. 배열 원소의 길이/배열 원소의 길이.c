#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// strlist_len은 배열 strlist의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* strlist[], size_t strlist_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    
    // 동적 할당을 사용해 길이 배열을 초기화
    int* answer = (int*)malloc(sizeof(int) * strlist_len);
    
    // 각 문자열의 길이를 계산하여 answer 배열에 저장
    for(size_t i=0; i<strlist_len; i++){
        answer[i] = strlen(strlist[i]);
    }
    return answer;
}

int main(void){
    const char* strlist[]={"We","are","the","world!"};
    
    // 배열의 원소 개수 4 구하기 
    size_t strlist_len = sizeof(strlist) / sizeof(strlist[0]); 
    
    // solution 함수를 호출하여 각 문자열의 길이를 계산
    int* result = solution(strlist, strlist_len);
    
    // 결과 출력
    for(size_t i =0; i<strlist_len; i++){
        printf("%d", result[i]);
    }
    
    // 동적 할당된 메모리 해제
    free(result);
    
    return 0;
}