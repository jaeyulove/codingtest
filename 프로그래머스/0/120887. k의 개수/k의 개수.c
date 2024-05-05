#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int i, int j, int k) {
    
int answer = 0;
char ck = k + 48; // k에 0을 더해서 문자로 변환 
char ci[3]; //숫자 3자리

for(; i<=j; i++) 
{
    sprintf(ci, "%d", i); // ci에 i~j까지 i값을 문자로 저장 
    for(int o = 0; o<strlen(ci); o++){ // ci 문자열 검색 
        if(ci[o] == ck){ //i에 k값이 있다면 answer++
            answer++;
        }
    }
 }
return answer;
}