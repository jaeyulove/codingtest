#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char* morse;
    char alphabet; 
} morseCode; 

morseCode MorseCode[] = {
    {".-", 'a'}, {"-...", 'b'}, {"-.-.", 'c'}, {"-..", 'd'},
    {".", 'e'}, {"..-.", 'f'}, {"--.", 'g'}, {"....", 'h'},
    {"..", 'i'}, {".---", 'j'}, {"-.-", 'k'}, {".-..", 'l'},
    {"--", 'm'}, {"-.", 'n'}, {"---", 'o'}, {".--.", 'p'},
    {"--.-", 'q'}, {".-.", 'r'}, {"...", 's'}, {"-", 't'},
    {"..-", 'u'}, {"...-", 'v'}, {".--", 'w'}, {"-..-", 'x'},
    {"-.--", 'y'}, {"--..", 'z'}
};

char* solution(const char* letter) {
    size_t len = strlen(letter);
    char* answer = (char*)malloc(sizeof(char) * (len + 1)); // 널 문자를 위한 공간 추가
    if(answer == NULL){
        printf("메모리 할당 실패\n");
        return NULL;
    }

    const char* ptr = letter;
    char morse[5];
    int idx = 0;
    int answerIdx = 0;
    // 포인터 ptr가 가리키는 문자가 널 문자('\0')가 아닐 때까지 루프를 계속 실행
    while(*ptr) {  
        if(*ptr == ' '){
            morse[idx] = '\0';  //C 스타일의 문자열로 만들어야 함 
            for(int i = 0; i < sizeof(MorseCode) / sizeof(MorseCode[0]); i++){
                if(strcmp(MorseCode[i].morse, morse) == 0){
                    answer[answerIdx++] = MorseCode[i].alphabet;
                    break;
                }
            }
            idx = 0;
        } else {
            morse[idx++] = *ptr;
        }
        ptr++;
    }

    // 마지막 모스부호 처리
    morse[idx] = '\0';
    for (int i = 0; i < sizeof(MorseCode) / sizeof(MorseCode[0]); i++) {
        if (strcmp(MorseCode[i].morse, morse) == 0) {
            answer[answerIdx++] = MorseCode[i].alphabet;
            break;
        }
    }

    answer[answerIdx] = '\0';
    return answer;
}

int main(void){
    // 예시 테스트 케이스
    const char* letter = ".... . .-.. .-.. ---";

    char* result = solution(letter);
    if(result != NULL){
        printf("%s\n", result); // hello
        free(result);
    }
    else{
        printf("메모리 할당 실패\n");
    }
    return 0;
}
