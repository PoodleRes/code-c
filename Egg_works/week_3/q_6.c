/*--------------------------------------------------------------------------
 无法改变的字符串

 Copyright (c) 2017 HDU_Microchip_Lab Co., Ltd.

 2017-08-23

 --------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

char* Str_To_Ammend[5] ={   "//\r\n",                                                   //从文件中读取的字符串数组，以换行符结尾
                            "// My Code\r\n",
                            "// Copyright (c) 2017 Hdu-microchip-LAB Co., Ltd.\r\n",
                            "//\r\n",
                            0};

const char* Wrong_Model = "// Copyright (c) 2017 Hdu-microchip-LAB Co., Ltd.\r\n";      //错误的字符串template

#define STRING_LENGTH       strlen(Wrong_Model)                                         //错误的字符串的长度

int matchString(char* pInput_Str[], const char* pModel_Str, int Position)               //匹配字符串函数，返回匹配到的字符串数组下标
{
    int Match_Point = 0;
    int i;

    for(Match_Point=0, i=Position; i<strlen(*pInput_Str); i++)
    {
        if(!strcmp(pInput_Str[i],pModel_Str))
        {
            return Match_Point;
        }

        else
        {
            Match_Point ++;
        }
    }

    return -1;                                                                           //如果没有匹配的字符串，返回-1
}

/*Should be char * Input_Str[]*/
/*Change char * to char ** */
void ammendString(char** Input_Str)                                                      //修改字符串函数
{
    char* pCorrect_Str ="// Copyright (c) 2017 HDU_Microchip_Lab Co., Ltd.\r\n";         //定义正确的字符串
    /*Change Input_Str to *Input_Str */
    *Input_Str = pCorrect_Str;                                                           //使错误的字符串的指针指向正确的字符串

}

void dispString(char* pInput_Str[])                                                     //打印字符串数组中的所有字符串
{
    int i;

    for(i=0; i<strlen(*pInput_Str); i++)
    {
        printf("%s",pInput_Str[i]);
    }

}

int main(int argc, const char * argv[])
{
    int Position = -1;

    Position = matchString(Str_To_Ammend, Wrong_Model, 0);                              //获得与错误字符串匹配字符串的数组下标
    if(Position != -1)
    {
        /*There will not change the value of Str_To_Ammend*/
        ammendString(Str_To_Ammend + Position);                                          //修改错误字符串
    }
    else;

    dispString(Str_To_Ammend);                                                          //打印所有字符串

    return 0;
}
