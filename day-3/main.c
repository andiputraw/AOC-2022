#include <stdio.h>
#include <string.h>


#define INPUT_PATH "./input-1.txt"
#define MAX_BUFFER 2048

//for debugging purpose
void print_string(char str[], int len){
    for(int i = 0; i < len; i++){
        printf("%c", str[i]);
    }
    printf("\n");   
}
//for debugging purpose
void print_c_string(char *str){
    if (str == NULL) {
        return;
    }
    int i = 0;
    while(str[i] != '\0' && i < 100){
        printf("%c", str[i]);
        i++;
    }
    printf("\n");
}

int include(char str[],int len, char target){
    for(int i = 0; i < len; i++){
        if(str[i] == target){
            return 0;
        }
    }
    return -1;
}

int get_priorty(char chars){
    if(chars < 'a'){
        return (int)chars - (int)'A' + 27;    
    }else {
        return (int)chars - (int)'a' + 1;
    }
}

// ${check_error} THIS IS NOT FOR CHECKING APP ERROR
int check_error(char first_half[],char second_half[], int len){
    char error[MAX_BUFFER] = {0};
    int len_err = 0;
    for(int i = 0; i < len; i++){
        for (int j = 0; j < len; j++)
        {
            if (first_half[i] == second_half[j]){
                if(!(include(error, len_err, first_half[i]) == 0)){
                error[len_err] = first_half[i];
                len_err++;
                }
            }
        }
    }
    int point = 1;
    for(int i = 0; i < len_err; i++){
        point += get_priorty(error[i]);
    }
    return point;
}

int check_badge(char first_elf[], char second_elf[], char third_elf[]){
    int count[MAX_BUFFER] = {0};
    int i = 0;
    while(first_elf[i] != '\0'){
        if(count[(int)first_elf[i]] == 0){
            count[(int)first_elf[i]] = 1;
        }
        i++;
    }
    i = 0;
    while(second_elf[i] != '\0'){
        if(count[(int)second_elf[i]] == 1){
            count[(int)second_elf[i]] += 1;
        }
        i++;
    }
    i= 0;
    while(third_elf[i] != '\0'){
        if(count[(int)third_elf[i]] == 2){
            count[(int)third_elf[i]] += 1;
        }
        i++;
    }
    
    char badge = 0;
    for(int i = (int)'a'; i <= (int)'z'; i++ ){
        if(count[i] == 3) {
            badge = (char)i;
        } 
    }
    if(badge == 0){
     for(int i = (int)'A'; i <= (int)'Z'; i++ ){
        if(count[i] == 3) {
            badge = (char)i;
        } 
    }   
    }
    int result =  get_priorty(badge);
    return result;
}

int main(void){
    FILE *input = fopen(INPUT_PATH, "r");
    if(input == NULL){
        printf("cannot open %s", INPUT_PATH);
        return 1;
    }
    
    #if 0
    char buff[MAX_BUFFER] = {0};
    char first_half[MAX_BUFFER] = {0};
    char second_half[MAX_BUFFER] = {0};
    int point = 0;
    while(fgets(buff, MAX_BUFFER, input) != NULL){
        size_t half = strlen(buff) / 2;
        strncpy(first_half, buff+(1 - 1), half);
        strncpy(second_half, buff+(half), half);
        
        point += check_error(first_half, second_half, half);
        memset(first_half, '\0', sizeof(first_half));
        memset(second_half, '\0', sizeof(second_half));
    }
    printf("sum of priorty = %d", point);
    #else 
    char first_elf[MAX_BUFFER] = {0};
    char second_elf[MAX_BUFFER] = {0};
    char third_elf[MAX_BUFFER] = {0};
    int point = 0;
    while(fgets(first_elf, MAX_BUFFER, input) != NULL){
        fgets(second_elf, MAX_BUFFER, input);
        fgets(third_elf, MAX_BUFFER, input);
        point += check_badge(first_elf,second_elf,third_elf);
    }
    printf("%d", point);
    #endif
    fclose(input);
    return 0;
}


