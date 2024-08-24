#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// date1_len은 배열 date1의 길이입니다.
// date2_len은 배열 date2의 길이입니다.
int solution(int date1[], size_t date1_len, int date2[], size_t date2_len) {
    int date1_sum = 0;
    int date2_sum = 0;
    int answer = 0;
    
    if(date1[0] < date2[0]){
        return 1; 
    }
    
    else if(date1[0] == date2[0] && date1[1] < date2[1]){
        return 1; 
    }
    
    else if (date1[1] == date2[1] && date1[2] < date2[2]){
        return 1; 
    }
    
    else {
        return 0; 
    }
}

int main(void){
int date1[] = {2021, 12, 28};
size_t date1_len = sizeof(date1)/sizeof(date1[0]);
int date2[] = {2021, 12, 29};
size_t date2_len = sizeof(date2)/sizeof(date2[0]);

int result = solution(date1,date1_len, date2, date2_len);
printf("%d\n", result);
return 0; 
}



