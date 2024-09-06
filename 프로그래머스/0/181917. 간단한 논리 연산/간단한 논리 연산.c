#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(bool x1, bool x2, bool x3, bool x4) {
    bool answer = true;
    
    answer =  (x1 || x2) && (x3 || x4);
    return answer;
}

int main(void){
    bool x1 = false;
    bool x2 = true;
    bool x3 = true;
    bool x4 = true;
    
    bool result = solution(x1,x2,x3,x4);
    
    printf("%s\n", result);
    return 0;
}