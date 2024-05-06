#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// id_pw_len은 배열 id_pw의 길이입니다.
// db_rows는 2차원 배열 db의 행 길이, db_cols는 2차원 배열 db의 열 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* id_pw[], size_t id_pw_len, const char*** db, size_t db_rows, size_t db_cols) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(sizeof(char)*50);
    
    bool id_found = false;
    bool pw_found = false; 
    
    for(int i=0; i<db_rows; i++){
           if(strcmp(id_pw[0],db[i][0]) == 0 && strcmp(id_pw[1],db[i][1]) == 0 ){
               id_found = true; 
               pw_found = true; 
               
               strcpy(answer,"login");
               return answer;
           }
        
         else if(strcmp(id_pw[0],db[i][0]) == 0 && strcmp(id_pw[1],db[i][1]) != 0){
                   id_found = true;
                   pw_found = false; 
                 strcpy(answer,"wrong pw");
                 return answer;
            }
    
               else if(strcmp(id_pw[0],db[i][0]) != 0 && strcmp(id_pw[1],db[i][1]) == 0){
                   id_found = false;
                   pw_found = true; 
            }
        }
    
            for(int j=0; j<db_rows; j++){
                    if(!id_found){
                        strcpy(answer,"fail");
                }
            }
   // realloc(answer,strlen(answer));
    return answer;
}

int main(void){
    const char* id_pw[] = {"meosseugi", "1234"};
    size_t id_pw_len = sizeof(id_pw)/sizeof(id_pw[0]); // 2/1 = 2
    const char*** db[][2] = {{"rardss", "123"}, {"yyoom", "1234"}, {"meosseugi", "1234"}};
    size_t db_rows = sizeof(db)/sizeof(db[0]); // 6/2 = 3
    size_t db_cols = sizeof(db[0])/sizeof(db[0][0]); // 2/1 = 2
    
    char result = solution(id_pw, id_pw_len, db, db_rows, db_cols); 
    
    printf("%s\n", result);
    free(result);
    return 0; 
    
}