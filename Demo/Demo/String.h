/**************************/
// author: liushangnan
//   note: 模拟string类
//   time: 2016.10.18
//version: 1.0
/**************************/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 50
#define STRING_SIZE 2048
#define NEWSTRINGLIST (StringList *)malloc(sizeof(StringList))
#define NEWSTRING (String *)malloc(sizeof(String))

//模拟String对象
typedef struct string
{
	char str[STRING_SIZE];
	int length;
}String;


typedef struct stringList
{
	String s[MAXSIZE];//存储多个String
	int size;//String个数
}StringList;

typedef struct keydictionary
{
	char word;
	int index;
}KeyDictionary;


//相关的函数申明


/*
*切割字符串，分为好几部分存在StringList中返回
*s是需要切割的字符串，c是切割符
*切割失败返回NULL
*/
StringList* split(char *str, char c)
{
	int length = 0;
	int count = 0;
	char* del = &c;
	char s[1024];
	char* temp;
	StringList* sList = (StringList *)malloc(sizeof(StringList));
	String* line = sList->s;
	sList->size = 0;
	if (str == NULL)
	{
		return NULL;
		free(sList);
	}
	strcpy(s, str);
	temp = strtok(s, del);
	if (temp == NULL)
		return NULL;
	while (temp != NULL) {
		length = strlen(temp);
		strcpy((line + count)->str, temp);
		(line + count)->length = length;
		count++;
		temp = strtok(NULL, del);
	}
	sList->size = count;
	return sList;
}
/*
*从索引start到end截取一段字符串
*成功返回String,失败返回NULL
*/
String* subString(char* str, char start, char end)
{
	String* s = NEWSTRING;
	char* startIndex = strchr(str, start);
	char* endIndex = strrchr(str, end);
	if (str == NULL || startIndex == NULL || endIndex == NULL)
	{
		free(s);
		return NULL;
	}
	s->length = endIndex - startIndex - 1;
	int i = 0;
	while (++startIndex<endIndex)
	{
		s->str[i++] = *(startIndex);
	}
	s->str[i] = '\0';
	return s;
}
/*
*类似于SubString,但是这是从头截取到索引front处
*/
String* subFrontString(char* str, char front)
{
	String* s = NEWSTRING;
	char* startIndex = str;
	char* endIndex = strchr(str, front);
	int i = 0;
	if (str == NULL)
	{
		free(s);
		printf("subFrontString():需要截取的字符串为空，截取失败！");
		return NULL;
	}
	if (endIndex == NULL)
	{
		free(s);
		return NULL;
	}
	s->length = endIndex - startIndex;
	strncpy(s->str, str, s->length);
	s->str[s->length] = '\0';
	return s;
}
/*
*从字符串中获取qq号码或者邮箱
*/
String* getQQID(char* str)
{
	if (str == NULL || strcmp(str, "0") == 0)
		return NULL;
	//QQ号的截取符是(),邮箱的截取符是<>
	String* num = subString(str, '(', ')');
	if (num == NULL)
	{
		num = subString(str, '<', '>');
		if (num == NULL)
			return NULL;
	}
	return num;
}


