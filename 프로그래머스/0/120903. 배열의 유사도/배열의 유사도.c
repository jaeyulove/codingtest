#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// s1_len은 배열 s1의 길이입니다.
// s2_len은 배열 s2의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s1[], size_t s1_len, const char* s2[], size_t s2_len){

    int answer=0;
    for(int i=0; i<s1_len; i++){
        for(int j=0; j<s2_len; j++){
            if(strcmp(s1[i],s2[j]) == 0){
                answer++;
            }
        }
    }
    return answer;
}

int main(void){
   const char* s1[] = {"a","b","c"};
   const char* s2[] = {"n","omg"};
    size_t s1_len = sizeof(s1)/sizeof(s1[0]);
    size_t s2_len = sizeof(s2)/sizeof(s2[0]);
    
   int result = solution(s1,s1_len,s2,s2_len); 
    printf("%d", result);
    return 0; 
}