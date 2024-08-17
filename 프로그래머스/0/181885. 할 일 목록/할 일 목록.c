#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// todo_list_len은 배열 todo_list의 길이입니다.
// finished_len은 배열 finished의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* todo_list[], size_t todo_list_len, bool finished[], size_t finished_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char** answer = (char**)malloc(sizeof(char*)*(todo_list_len+1));
    int index = 0;
    
    for(size_t i=0; i<finished_len; i++){
        if(finished[i] == false){
            answer[index] = (char*)malloc(sizeof(char)*(strlen(todo_list[i])+1));
            strcpy(answer[index],todo_list[i]);
            index++;
        }
   }
    answer[index] = '\0';
    return answer;
}

int main(void){
    const char* todo_list[]={"problemsolving", "practiceguitar", "swim", "studygraph"};
    size_t todo_list_len = sizeof(todo_list)/sizeof(todo_list[0]);
    bool finished[]={true, false, true, false};
    size_t finished_len = sizeof(finished)/sizeof(finished[0]); 
    size_t finished_len_result = 0;
    
    for(size_t i=0; i<finished_len; i++){
        if(finished[i] == "false"){
            finished_len_result++; // 2
        }
    }
    char** result = solution(todo_list,todo_list_len,finished,finished_len);
    
    if(result != NULL){
        for(size_t j=0; j<finished_len_result; j++){
            printf("%s", result[j]);
        }
        free(result);
        return 0; 
    }
    
    
    
    
    
    
    
    
    

}