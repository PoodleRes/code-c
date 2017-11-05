#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

int get_str(char *,int);
char * add_int_float(const char *,int,const char *,int);
char * add_int_int(const char *,int,const char *,int);
char * add_float_float(const char *,int,const char *,int);
char * add(const char *,int,const char *,int);
_Bool is_float(const char *);
_Bool is_invalid(const char *);

int main(int argc, char const *argv[]) {
    char str_a[MAX];
    char str_b[MAX];
    char * result;
    int a_len,b_len;
    puts("Enter Number A(MAX_LEN < 10000):");
    a_len = get_str(str_a,MAX);
    puts("Enter Number B(MAX_LEN < 10000):");
    b_len = get_str(str_b,MAX);
    result = add(str_a,a_len,str_b,b_len);
    if(*result = '0')
        result ++;
    printf("A+B=%s\n",result);

    return 0;
}

char * add_float_float(const char * str_a,int a_len,const char * str_b,int b_len){
    int dis_a_to_p = 0,dis_b_to_p = 0;
    int rec,i,temp_a,temp_b,add_1 = 0;
    int longer_float;
    int ip_len = 0;
    const char * bp = str_b;
    const char * ap = str_a;
    char * ip,* temp;
    char * fp;
    char float_part[MAX];
    static char res[2 * MAX + 1];
    while(*bp != '.'){
        bp ++;
        dis_b_to_p ++;
    }
    while(*ap != '.'){
        ap ++;
        dis_a_to_p ++;
    }
    longer_float = (a_len - dis_a_to_p) > (a_len - dis_a_to_p) ? (a_len - dis_a_to_p - 1):(a_len - dis_a_to_p - 1);
    for(i = longer_float;i > 0;i --){
        if(str_a[dis_a_to_p + i] == '\0')
            temp_a = 0;
        else
            temp_a = str_a[dis_a_to_p + i] - '0';
        if(str_b[dis_b_to_p + i] == '\0')
            temp_b = 0;
        else
            temp_b = str_b[dis_b_to_p + i] - '0';
        rec = temp_b + temp_a + add_1;
        float_part[i - 1] = '0' + rec % 10;
        if(rec >= 10)
            add_1 = 1;
    }

    if(add_1){
        ip = add_int_int(str_a,dis_a_to_p,"1",1);
        temp = ip;
        while(*temp != '\0'){
            ip_len ++;
            temp ++;
        }
        ip = add_int_int(str_b,dis_b_to_p,ip,ip_len);
    }else
        ip = add_int_int(str_a,dis_a_to_p,str_b,dis_b_to_p);
    for(ip_len = 0,i = 0;*ip != '\0';ip_len ++,i ++){
        res[i] = *ip;
        ip ++;
    }
    res[i] = '.';
    rec = i;
    for(i = 0;i < longer_float;i ++)
        res[rec + i + 1] = float_part[i];
    res[rec + i + 1] = '\0';
    return res;
}

char * add_int_float(const char * str_a,int a_len,const char * str_b,int b_len){
    int i = 0,rec,dis_b_to_p = 0;//distance from high stage to point
    const char * bp = str_b;
    char * ip;
    static char res[2 * MAX + 1];

    while(*bp != '.'){
        bp ++;
        dis_b_to_p ++;
    }
    ip = add_int_int(str_a,a_len,str_b,dis_b_to_p);
    while(*ip != '\0'){
        res[i] = *ip;
        ip ++;
        i ++;
    }
    rec = i;
    res[i] = '.';
    for(i = 0;i < b_len - dis_b_to_p;i ++)
        res[rec + i + 1] = str_b[dis_b_to_p + i + 1];
    res[rec + i + 1] = '\0';
    return res;
}


char * add_int_int(const char * str_a,int a_len,const char * str_b,int b_len){
    static char res[MAX + 1];
    char temp_1,temp_2;
    int i,j,record,add_1 = 0;
    int longer = a_len > b_len ? a_len:b_len;
    int shorter = a_len > b_len ? b_len:a_len;
    const char * str_longer = a_len > b_len ? str_a:str_b;
    const char * str_shorter = a_len > b_len ? str_b:str_a;
    for(i = longer - 1,j = shorter - 1;i >= 0;i --){
        if(j >= 0){
            temp_2 = str_shorter[j] - '0';
            j --;
        }
        else{
            temp_2 = 0;
        }
        temp_1 = str_longer[i] - '0';
        record = temp_1 + temp_2 + add_1;
        res[i + 1] = '0' + record % 10;
        if(record >= 10)
            add_1 = 1;
        else
            add_1 = 0;
    }
    if(add_1)
        res[0] = '1';
    else
        res[0] = '0';
    res[longer + 1] = '\0';

    return res;
}

_Bool is_invalid(const char * str){
    char ch = str[0];
    int once_point = 0;
    if(*str == '.')
        return 1;
    while(*str){
        if(ch < '0' || ch > '9'){
            if(ch == '.' && once_point < 1)
                once_point ++;
            else
                return 1;
        }
        ch = *(++ str);
    }
    if(*str == '.')
        return 1;

    return 0;
}

_Bool is_float(const char * str){
    while(*str != '\0'){
        if(*str == '.')
            return 1;
        str ++;
    }
    return 0;
}

char * add(const char * str_a,int a_len,const char * str_b,int b_len){
    if(is_invalid(str_a) || is_invalid(str_b)){
        fprintf(stderr, "Invalid String(Numbers)\n");
        exit(1);
    }
    if(is_float(str_a) && is_float(str_b))
        return add_float_float(str_a,a_len,str_b,b_len);
    else if(!is_float(str_a) && is_float(str_b))
        return add_int_float(str_a,a_len,str_b,b_len);
    else if(!is_float(str_b) && is_float(str_a))
        return add_int_float(str_b,b_len,str_a,a_len);
    else
        return add_int_int(str_a,a_len,str_b,b_len);
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
