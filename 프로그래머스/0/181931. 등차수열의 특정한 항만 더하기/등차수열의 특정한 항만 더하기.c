#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// included_len은 배열 included의 길이입니다.
int solution(int a, int d, bool included[], size_t included_len) {
    int answer = 0;
    
    for(int i=0; i<included_len; i++) {
        if(included[i] == true) {
            answer += a+d*(i);
        }
    }
    return answer;
}

int main(void) {
    int a = 3;
    int d = 4;
    bool included[] = {true, false, false, true, true};
    size_t included_len = sizeof(included)/sizeof(included[0]); 
    
    int result = solution(a,d,included,included_len);
    printf("%d", result); 
    return 0; 
}