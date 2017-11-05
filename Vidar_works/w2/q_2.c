#include <stdio.h>

#define NAME_LEN 100
#define ARTICAL_LEN 10000

int main(int argc, char const *argv[]) {
    char fname[NAME_LEN];
    char artical[ARTICAL_LEN];
    int i = 0;
    char ch;
    int word_num = 0,char_num = 0,space_num = 0;
    _Bool in_word = 0,status = 0;

    printf("File name?");
    scanf("%s",fname);//no check
    FILE * fp = fopen(fname,"r");
    ch = fgetc(fp);
    while(ch != EOF && i < ARTICAL_LEN){
        if((ch > 'a' && ch < 'z') || (ch > 'A' && ch < 'Z')){
            in_word = 1;
        }else if(ch == ' '){
            space_num ++;
            in_word = 0;
        }else{
            char_num ++;
            in_word = 0;
        }
        if(in_word){
            status = 1;
        }else if(status){
            word_num ++;
            status = 0;
        }
        artical[i] = ch;
        ch = fgetc(fp);
        i ++;
    }
    artical[i] = '\0';
    fclose(fp);
    printf("Words:%d\nChars:%d\nSpaces:%d\n",word_num,char_num,space_num);
    return 0;
}
