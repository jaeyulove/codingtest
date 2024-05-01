#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 순열 생성 함수
void permute(const char *str, int l, int r, char** dic, int dic_len, bool *found) {
    if (l == r) {
        for (int i = 0; i < dic_len; i++) {
            if (strcmp(str, dic[i]) == 0) {
                *found = true;
                return;
            }
        }
    } else {
        for (int i = l; i <= r; i++) {
            // 문자 교환
            char temp = ((char*)str)[l];
            ((char*)str)[l] = ((char*)str)[i];
            ((char*)str)[i] = temp;

            // 재귀적 순열 생성
            permute(str, l + 1, r, dic, dic_len, found);

            // 원래 문자로 되돌림
            temp = ((char*)str)[l];
            ((char*)str)[l] = ((char*)str)[i];
            ((char*)str)[i] = temp;

            // 이미 단어를 찾았다면 중단
            if (*found) return;
        }
    }
}

// 주 함수
int solution(const char* spell[], size_t spell_len, const char* dic[], size_t dic_len) {
    char word[11] = {0}; // 최대 길이 + 1
    for (int i = 0; i < spell_len; i++) {
        word[i] = spell[i][0];
    }
    
    bool found = false;
    permute(word, 0, spell_len - 1, dic, dic_len, &found);
    
    return found ? 1 : 2;
}

int main() {
    const char* spell2[] = {"z", "d", "x"};
    const char* dic2[] = {"def", "dww", "dzx", "loveaw"};
    printf("Test 2: %d\n", solution(spell2, 3, dic2, 4));

    return 0;
}
