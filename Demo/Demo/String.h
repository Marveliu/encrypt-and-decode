/**************************/
// author: liushangnan
//   note: ģ��string��
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

//ģ��String����
typedef struct string
{
	char str[STRING_SIZE];
	int length;
}String;


typedef struct stringList
{
	String s[MAXSIZE];//�洢���String
	int size;//String����
}StringList;

typedef struct keydictionary
{
	char word;
	int index;
}KeyDictionary;


//��صĺ�������


/*
*�и��ַ�������Ϊ�ü����ִ���StringList�з���
*s����Ҫ�и���ַ�����c���и��
*�и�ʧ�ܷ���NULL
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
*������start��end��ȡһ���ַ���
*�ɹ�����String,ʧ�ܷ���NULL
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
*������SubString,�������Ǵ�ͷ��ȡ������front��
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
		printf("subFrontString():��Ҫ��ȡ���ַ���Ϊ�գ���ȡʧ�ܣ�");
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
*���ַ����л�ȡqq�����������
*/
String* getQQID(char* str)
{
	if (str == NULL || strcmp(str, "0") == 0)
		return NULL;
	//QQ�ŵĽ�ȡ����(),����Ľ�ȡ����<>
	String* num = subString(str, '(', ')');
	if (num == NULL)
	{
		num = subString(str, '<', '>');
		if (num == NULL)
			return NULL;
	}
	return num;
}


