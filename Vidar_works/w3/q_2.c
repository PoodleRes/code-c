#include <stdio.h>
#define MAX_LEN 10000

char * encode(const char *,int);
char to_char(const _Bool *);
_Bool * to_binary(char);

char * decode(const char *,int);
char to_char_de(const _Bool *);
_Bool * to_binary_de(char);

int pow_2(int);
int get_str(char *,int);


char * base = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";


int main(int argc, char const *argv[]) {
    char str[MAX_LEN];
    int len;
    puts("Encode str:");
    len = get_str(str,MAX_LEN);
    puts(encode(str,len));
    puts("Decode str:");
    len = get_str(str,MAX_LEN);
    puts(decode(str,len));
    return 0;
}


char * encode(const char * str,int len){
    _Bool * cp,temp[8 * 3];
    static char res[MAX_LEN * 4 / 3 + 4];
    int i,j,k,rec,res_rec,times = len / 3;
    rec = 0;
    res_rec = 0;
    for(i = 0;i < times;i ++){
        for(j = 0;j < 3;j ++){
            cp = to_binary(str[rec]);
            rec ++;
            for(k = 7;k >= 0;k --)
                temp[j * 8 + k] = cp[k];
        }
        for(j = 0;j < 4;j ++){
            res[res_rec] = base[to_char(temp + j * 6)];
            res_rec ++;
        }
    }
    i = len % 3;
    if(i){
        for(j = 0;j < i;j ++){
            cp = to_binary(str[rec]);
            rec ++;
            for(k = 7;k >= 0;k --)
                temp[j * 8 + k] = cp[k];
        }
        for(j = i * 8;j < 3 * 6;j ++)
            temp[j] = 0;
        for(j = 0;j < i + 1;j ++){
            res[res_rec] = base[to_char(temp + j * 6)];
            res_rec ++;
        }
        for(j = 0;j < 3 - i;j ++){
            res[res_rec] = '=';
            res_rec ++;
        }
    }
    res[res_rec] = '\0';
    return res;
}


char to_char(const _Bool * str_6){
    int i;
    char res = 0;
    for(i = 0;i < 6;i ++)
        res += str_6[i] * pow_2(5 - i);
    return res;
}


_Bool * to_binary(char ch){
    int i;
    static _Bool temp[8];
    for(i = 7;i >= 0;i --){
        temp[i] = ch % 2;
        ch >>= 1;
    }
    return temp;
}


char * decode(const char * str,int len){
    _Bool * cp,temp[8 * 3];
    static char res[MAX_LEN];
    int i,j,k,rec,res_rec,times = len / 4;
    rec = 0;
    res_rec = 0;
    for(i = 0;i < times - 1;i ++){
        for(j = 0;j < 4;j ++){
            cp = to_binary_de(str[rec]);
            rec ++;
            for(k = 5;k >= 0;k --)
                temp[j * 6 + k] = cp[k];
        }
        for(j = 0;j < 3;j ++){
            res[res_rec] = to_char_de(temp + j * 8);
            res_rec ++;
        }
    }
    for(i = 2;i < 4;i ++){
        if(str[rec + i] == '=')
            break;
    }
    for(j = 0;j < i;j ++){
        cp = to_binary_de(str[rec]);
        rec ++;
        for(k = 5;k >= 0;k --)
            temp[j * 6 + k] = cp[k];
    }
    for(j = 0;j < i - 1;j ++){
        res[res_rec] = to_char_de(temp + j * 8);
        res_rec ++;
    }
    res[res_rec] = '\0';
    return res;
}


char to_char_de(const _Bool * str_8){
    int i,res = 0;
    for(i = 0;i < 8;i ++)
        res += str_8[i] * pow_2(7 - i);
    return res;
}


_Bool * to_binary_de(char ch){
    int i,j;
    static _Bool temp[6];
    for(i = 0;i < 64;i ++)
        if(ch == base[i])
            break;
    for(j = 5;j >= 0;j --){
        temp[j] = i % 2;
        i >>= 1;
    }
    return temp;
}


int pow_2(int n){
    int i,res = 1;
    for(i = 0;i < n;i ++)
        res *= 2;
    return res;
}


int get_str(char * str,int len){
    int get_len = 0;
    char * sp = fgets(str,len,stdin);
    while(*sp != '\0' && *sp!='\n'){
        get_len ++;
        sp ++;
    }
    if(*sp == '\0')
        while(getchar() != '\n')
            continue;
    else
        *sp = '\0';
    return get_len;
}
