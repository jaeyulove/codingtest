#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> 

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* myString, const char* pat) {
    int answer = 0;
    size_t myString_len = strlen(myString);
    char myString_cpy[myString_len];
    strcpy(myString_cpy, myString); 
    
    for(int i=0; i<myString_len; i++){
        if(myString_cpy[i] == 'A'){
            myString_cpy[i] = 'B';
        }
        else if(myString_cpy[i] == 'B'){
            myString_cpy[i] = 'A'; 
        }
    }
    return strstr(myString_cpy,pat)?1:0; 
}

int main(void){
    const char* myString = "ABBAA";
    const char* pat = "AABB"	;
    
    int result = solution(myString,pat);
    printf("%d", result);
    return 0; 
}