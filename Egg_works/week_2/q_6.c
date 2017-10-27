/*--------------------------------------------------------------------------
拼不出的单词

Copyright (c) 2017 HDU_Microchip_Lab Co., Ltd.

2017-08-24

--------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>


#define LENGTH_OF_LIB   3                                                                  //词库中词的数量
const char Library[LENGTH_OF_LIB][10] = { "microchip","microwave","microsoft" }; /* use string.h(strlen) must make sure the last ele is '\0' 9 -> 10 */                        //词库
/* 20 -> 10 */
int searchWord(char Input_Word[], const char Library[][10]);                               //搜索单词函数


int main(int argc, const char * argv[])
{
	int i = searchWord("microwave", Library);

	if (-1 != i)
	{
		printf("%s\n", Library[i]);
	}
	else
	{
		printf("Word not found!\n");
	}
	getchar();/*getch -> getchar , getch is not in head file stdio.h */
	return 0;
}
/* 20 -> 9 */
int searchWord(char Input_Word[], const char Library[][10])
{

	int Num_Of_Word;                                                                    //词库索引
	int CNT_Same_Char = 0;                                                              //相同字符计数
	int Length_Of_Word = strlen(Input_Word);  /* strlen recall value is an interge,drop (int) */                                     //当前单词长度
	char Index[20] = { 0 };                                                               //用于输入字符串操作
	int i, j = 0;

	for (i = 0; i<Length_Of_Word; i++)                                                     //将输入字符串保存到操作数组中
	{
		Index[i] = Input_Word[i];
	}

	for (Num_Of_Word = 0; Num_Of_Word<LENGTH_OF_LIB; Num_Of_Word++)                        //遍历词库中所有单词
	{

		for (; Num_Of_Word<LENGTH_OF_LIB && Length_Of_Word != strlen(Library[Num_Of_Word]); Num_Of_Word++);      //如果字符串长度不同，直接进入下一次查找
		if (Num_Of_Word >= LENGTH_OF_LIB)
		{
			return -1;
		}

		for (i = 0; i<Length_Of_Word; i++)                                                //遍历一个单词中的所有字符
		{                                         /*Index[j] i -> j */
			for (j = 0; j<Length_Of_Word && Index[j] != Library[Num_Of_Word][i]; j++);      //j不停计数，直到操作数组的当前字符与库中当前单词中的某一个字符相同

			if (j < Length_Of_Word)
			{
				for (; j<Length_Of_Word; j++)                                           //将相同的字符从操作数组中移除
				{
					Index[j] = Index[j + 1];
				}
				CNT_Same_Char++;                                                        //相同字符计数增加
			}

			if (CNT_Same_Char == Length_Of_Word)                                        //如果所有字符都与当前字库中的单词相同
			{
				return Num_Of_Word;
			}

		}

	}

	return -1;                                                                          //如果匹配结束仍未找到相同单词，返回-1表示未找到

}
