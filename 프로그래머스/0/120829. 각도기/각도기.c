#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int angle) {

    if (angle >= 0  && angle < 90) return 1 ; //예각
    else if (angle == 90) return 2; // 직각 
    else if (angle >= 91 && angle < 180) return 3; //둔각
    else if (angle == 180) return 4; // 평각 
    else return 0; 
}

int main(void){
    int angle, result; 
    
    angle = 70; 
    result = solution(angle);
    printf("%d", result);
    
    angle = 91; 
    result = solution(angle);
    printf("%d", result);
    
    angle = 180; 
    result = solution(angle);
    printf("%d", result);
    
    return 0;
}