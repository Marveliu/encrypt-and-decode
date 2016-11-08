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



