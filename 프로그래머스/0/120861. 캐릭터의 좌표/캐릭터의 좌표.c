#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int* solution(const char* keyinput[], size_t keyinput_len, int board[], size_t board_len) {
    int* answer = (int*)malloc(sizeof(int)*2);
    
    if(answer == NULL){
        printf("memory alloc failed");
        return NULL; 
    }
    
    memset(answer,0,sizeof(int)*2);
    
    for(int i=0; i<keyinput_len; i++){
        if(strcmp(keyinput[i],"left") == 0 && answer[0] > -board[0]/2){
            answer[0] --;
        }
        else if(strcmp(keyinput[i],"right") == 0 && answer[0] < board[0]/2){
            answer[0] ++; 
        }
        else if(strcmp(keyinput[i],"up") == 0 && answer[1] < board[1]/2){
            answer[1] ++;
        }
        else if(strcmp(keyinput[i],"down") == 0 && answer[1] > -board[1]/2){
            answer[1] --;
        }
  }

    // X 좌표 조정
/*if (answer[0] > board[0]/2) {
    answer[0] = board[0]/2;
} else if (answer[0] < -board[0]/2) {
    answer[0] = -board[0]/2;
}

// Y 좌표 조정
if (answer[1] > board[1]/2) {
    answer[1] = board[1]/2;
} else if (answer[1] < -board[1]/2) {
    answer[1] = -board[1]/2;
}*/
    return answer;
}

int main(void) {
    const char* keyinput[] = {"left", "right", "up", "right", "right"};
    size_t keyinput_len = sizeof(keyinput) / sizeof(keyinput[0]);
    int board[] = {11, 11};
    size_t board_len = sizeof(board) / sizeof(board[0]);
    int *result = solution(keyinput, keyinput_len, board, board_len);
    
    if (result == NULL) {
        printf("Memory allocation failed\n");
    } else {
        printf("[%d, %d]\n", result[0], result[1]);
        free(result);
    }
    return 0;
}
