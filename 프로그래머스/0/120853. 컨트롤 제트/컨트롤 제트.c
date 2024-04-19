#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 0;
    int n = 0;
    char* p;
    int len = strlen(s);
    int* num = (int*)malloc(sizeof(int)*len);
    
    p=strtok(s," ");
    while(p!=NULL){
        if(*p == 'Z'){
            answer -= num[n-1]; // num 배열의 마지막 원소를 answer에서 빼준다. 
        }
        else {
            num[n]=atoi(p); //p가 가리키는 문자열을 정수로 변환한다 
            answer += num[n++]; //  변환된 정수를 answer에 더하고 n을 증가시킨다. 
        }
        p=strtok(NULL," "); // 다음 토큰을 찾는다.  
    }
    return answer;
}
