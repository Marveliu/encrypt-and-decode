/**************************/
// author: liushangnan
//   note: 加密解密核心算法
//   time: 2016.10.18
//version: 1.0
/**************************/

#include"String.h"

/*************声明***************/


/*加密*/
/*恺撒加密*/
char* Caesarencrypt(char* targetstring, KeyDictionary keys[]);
/*字母倒排序加密*/
char* Invertedencrypt(char* targetstring, KeyDictionary keys[]);
//单表置换加密
char* Singletablereplaceencrypt(char* targetstring, KeyDictionary keys[]);
//维吉利亚加密
char* Virginiaencrypt(char* targetstring, KeyDictionary keys[]);
//转换加密
char* Convertencrypt(char* targetstring);

/*解密*/
/*恺撒解密*/
char* Caesardecrypt(char* targetstring, int m);
/*字母倒排序解密*/
char* Inverteddecrypt(char* targetstring, KeyDictionary keys[]);
//单表置换解密
char* Singletablereplacedecrypt(char* targetstring, KeyDictionary keys[]);
//维吉利亚解密
char* Virginiadecrypt(char* targetstring, KeyDictionary keys[]);
//转换解密
char* Convertdecrypt(char* targetstring);

/*解密*/




//菜单

void menu();
void algorithmenu();
void convertkeys(KeyDictionary* keys[]);


/*************实现***************/

/*************加密***************/
/*1.1 恺撒密码*/
char* Caesarencrypt(char* targetstring, KeyDictionary keys[])
{
	int m = 0;
	int index = 0;    //targetstring index
	int length = strlen(targetstring);
	char resultstring[STRING_SIZE] = "";

	printf("请输入m值：");
	scanf("%d", &m);

	//更新密钥表
	for (int i = 0; i < 26; i++)
	{
		keys[i].index = (keys[i].index + m)>122 ? (96 + keys[i].index + m - 122) : (keys[i].index + m);
		printf("%c:::%d\n", keys[i].word, keys[i].index);
	}

	//按照密钥表赋值
	for (int i = 0; i <= length; i++)
	{
		//这个地方我想建立一个ｈａｓｈ表
		int index = (int)*(targetstring + i) - 97;  //加快计算速度
		//todo:单个字符在赋值不知道这样对不对
		resultstring[i] = keys[index].index;
	}
	return resultstring;
}

/*2.1 字母倒排序*/
char* Invertedencrypt(char* targetstring, KeyDictionary keys[])
{
	int i = 0;
	int length = strlen(targetstring);
	char resultstring[STRING_SIZE] = "";

	//更新密钥表
	for (int i = 0; i < 26; i++)
	{
		//前面的值已经发生了改变
		keys[i].index = 219 - keys[i].index;
		printf("%c:::%d\n", keys[i].word, keys[i].index);
	}

	//按照密钥表赋值
	for (int i = 0; i < length; i++)
	{
		int index = (int)*(targetstring + i) - 97;  //加快计算速度
		//todo:单个字符在赋值不知道这样对不对
		resultstring[i] = keys[index].index;
	}
	return resultstring;
}

//3.1 单表置换密码
char* Singletablereplaceencrypt(char* targetstring, KeyDictionary keys[])
{
	int n = 0;
	int index = 0;
	int length = strlen(targetstring);
	char resultstring[STRING_SIZE] = "";
	char keystring[STRING_SIZE] = "";
	int check[25] = { 0 };  //全部设置为0


	printf("请输入key\n");  //字符数的限制,
	scanf("%s", keystring);

	strcat(keystring, "abcdefghijiklmnopqrstuvwxyz");

	int length1 = strlen(keystring);
	//更新keys[]
	for (int i = 0; i < length1; i++)
	{
		int index = keystring[i] - 97;
		if (check[index] == 0)
		{
			//字母没有出现
			check[index] = 1;
			keys[n++].index = keystring[i];
		}
	}

	//输出keys
	for (int i = 0; i < 26; i++)
	{
		printf("%c:::%d\n", keys[i].word, keys[i].index);
	}

	//按照密钥表赋值
	for (int i = 0; i < length; i++)
	{
		int index = targetstring[i] - 97;  //加快计算速度
		//todo:单个字符在赋值不知道这样对不对
		resultstring[i] = keys[index].index;
	}
	return resultstring;
}

//4.1 维吉利亚密码
char* Virginiaencrypt(char* targetstring, KeyDictionary keys[])
{
	char keywords[STRING_SIZE];
	char resultstring[STRING_SIZE] = "";
	int keywords_len = 0;
	int putwords_len = 0;
	int index = 0;
	int num1 = 0;
	int num2 = 0;

	//输入加密单词
	printf("请输入加密单词：\n");
	scanf("%s", keywords);

	//获得两个字符串的长度
	keywords_len = strlen(keywords);
	putwords_len = strlen(targetstring);

	//todo:keywords_len>putwords_len...没有影响，但是多的地方没有输出

	//加密单词
	for (int i = 0, n = 0; i < putwords_len; i++)
	{
		//取模运算
		n = i % keywords_len;
		num1 = keywords[n] - 97;
		num2 = targetstring[i] - 97;
		//计算单个字符
		resultstring[i] = keys[(num1 + num2) % 26].word;
	}

	return resultstring;
}

//5.1 转换加密
char* Convertencrypt(char* targetstring)
{
	char keywords[STRING_SIZE];
	char sortkeywords[25] = "";
	char resultstring[STRING_SIZE] = "";
	char stringarrays[25][STRING_SIZE] = { "" };

	int keywords_len = 0;
	int putwords_len = 0;
	int index = 0;
	int count = 0;
	int num1 = 0;
	int num2 = 0;
	int check[26] = { 0 };


	//输出要加密的的单词
	printf("请输入密钥:\n");
	scanf("%s", keywords);

	keywords_len = strlen(keywords);

	//对输入的keywords进行处理，重复的字符进行合并
	for (int i = 0; i < keywords_len; i++)
	{
		index = keywords[i] - 97;
		if (check[index] == 0)
		{
			sortkeywords[count] = keywords[i];
			count++;
			check[index] = count;

		}
	}


	//获得两个要比对的字符串的长度
	keywords_len = strlen(sortkeywords);
	putwords_len = strlen(targetstring);

	num1 = putwords_len % keywords_len;
	num2 = putwords_len / keywords_len + 1;

	count = 0;
	for (int i = 0; i < keywords_len; i++)
	{

		for (int n = 0; n < num2; n++)
		{
			stringarrays[i][n] = targetstring[i + n*keywords_len];
		}
		count++;
	}

	//stringarrays2resultstring

	for (int i = 0; i < 25; i++)
	{

		while (check[i] != 0)
		{
			index = check[i] - 1;
			strcat(resultstring, stringarrays[index]);
			i++;
		}
	}

	return resultstring;
}



/*************解密***************/

/*1.2 恺撒密码*/
char* Caesardecrypt(char* targetstring, KeyDictionary keys[])
{
	int m = 0;
	int index = 0;    //targetstring index
	int length = strlen(targetstring);
	char resultstring[STRING_SIZE] = "";

	printf("请输入m值：");
	scanf("%d", &m);

	//更新密钥表
	for (int i = 0; i < 26; i++)
	{
		keys[i].index = 122 - i;
		printf("%c:::%d\n", keys[i].word, keys[i].index);
	}

	//按照密钥表赋值
	for (int i = 0; i <= length; i++)
	{
		int index = (int)*(targetstring + i) - 97;  //加快计算速度
		//todo:单个字符在赋值不知道这样对不对
		resultstring[i] = keys[index].index;
	}
	return resultstring;
}

/*2.2 字母倒排序*/
//和加密的函数一样
char* Inverteddecrypt(char* targetstring, KeyDictionary keys[])
{
	int i = 0;
	int length = strlen(targetstring);
	char resultstring[STRING_SIZE] = "";

	//密钥表
	for (int i = 0; i < 26; i++)
	{
		keys[i].index = 122 - i;
		printf("%c:::%d\n", keys[i].word, keys[i].index);
	}

	//按照密钥表赋值
	for (int i = 0; i < length; i++)
	{
		int index = (int)*(targetstring + i) - 97;  //加快计算速度
		//todo:单个字符在赋值不知道这样对不对
		resultstring[i] = keys[index].index;
	}
	return resultstring;
}

//3.2 单表置换密码
char* Singletablereplacedecrypt(char* targetstring, KeyDictionary keys[])
{
	int n = 0;
	int index = 0;
	int length = sizeof(targetstring);

	char resultstring[STRING_SIZE] = "";
	char keystring[STRING_SIZE] = "";
	int check[25] = { 0 };  //全部设置为0


	printf("请输入key\n");  //字符数的限制,

	getch();
	scanf("%s", keystring);

	strcat(keystring, "abcdefghijiklmnopqrstuvwxyz");

	int length1 = strlen(keystring);

	//按照单表置换的原则，更新keys[]
	for (int i = 0; i < length1; i++)
	{
		int index = keystring[i] - 97;
		if (check[index] == 0)
		{
			//字母没有出现
			check[index] = 1;
			keys[n++].index = keystring[i];
		}
	}
	//输出keys
	for (int i = 0; i < 26; i++)
	{
		printf("%c:::%d\n", keys[i].word, keys[i].index);
	}

	convertkeys(&keys);

	//输出keys
	for (int i = 0; i < 26; i++)
	{
		printf("%c:::%d\n", keys[i].word, keys[i].index);
	}

	//按照密钥表赋值
	for (int i = 0; i < length; i++)
	{
		int index = (int)*(targetstring + i) - 97;  //加快计算速度
		resultstring[i] = keys[index].index;
	}

	return resultstring;
}

//4.2 维吉利亚密码
char* Virginiadecrypt(char* targetstring, KeyDictionary keys[]) {
	char keywords[STRING_SIZE];
	char resultstring[STRING_SIZE] = "";
	int keywords_len = 0;
	int putwords_len = 0;
	int index = 0;
	int num1 = 0;
	int num2 = 0;

	printf("请输入密钥：\n");
	scanf("%s", keywords);

	//获得两个字符串的长度
	keywords_len = strlen(keywords);
	putwords_len = strlen(targetstring);

	//解密单词
	for (int i = 0, n = 0; i < putwords_len; i++)
	{
		//取模运算
		n = i % keywords_len;
		num1 = keywords[n] - 97;
		num2 = targetstring[i] - 97;

		//计算单个字符
		resultstring[i] = keys[(num2 + 26 - num1) % 26].word;
	}

	return resultstring;
}

//5.2 转换解密
char* Convertdecrypt(char* targetstring) {
	char keywords[STRING_SIZE];
	char sortkeywords[25] = "";

	char resultstring[STRING_SIZE] = "";
	char stringarrays[25][STRING_SIZE] = { "" };

	int keywords_len = 0;
	int putwords_len = 0;
	int index = 0;
	int count = 0;
	int num1 = 0;
	int num2 = 0;
	int check[25] = { 0 };


	printf("请输入密钥:\n");
	scanf("%s", keywords);
	keywords_len = strlen(keywords);

	for (int i = 0; i < keywords_len; i++)
	{
		index = keywords[i] - 97;
		if (check[index] == 0)
		{
			sortkeywords[count] = keywords[i];
			check[index] = 1;
			count++;
		}
	}


	//获得两个字符串的长度
	keywords_len = strlen(sortkeywords);
	putwords_len = strlen(targetstring);

	num1 = putwords_len % keywords_len;          //余数
	num2 = putwords_len / keywords_len;          //商

	//更新check[]里的数值作为长度
	for (int i = 0; i < keywords_len; i++)
	{
		index = sortkeywords[i] - 97;
		if (i < num1)
		{
			check[index] = num2 + 1;
		}
		else
		{
			check[index] = num1;
		}
	}


	//转化成数组
	count = 0;
	for (int i = 0; i < keywords_len; i++)
	{
		for (int n = 0; n < check[sortkeywords[i] - 97]; n++)
		{
			stringarrays[i][n] = targetstring[count++];
		}
	}

	count = 0;
	//为了得到取数的次序再一次更新check
	//对输入的keywords进行处理，重复的字符进行合并
	for (int i = 0; i < keywords_len; i++)
	{
		index = sortkeywords[i] - 97;
		count++;
		check[index] = count;
	}

	//resultstring
	count = 0;

	for (int i = 0; i < num2 + 1; i++)
	{
		for (int n = 0; n < keywords_len; n++)
		{
			index = check[sortkeywords[n] - 97]-1;
			resultstring[count] = stringarrays[index][i];
			count++;
		}
	}

	return resultstring;
}


/*************功能***************/
/*功能：输出菜单*/
void menu(){
	printf("******************************\n");
	printf("\t加密解密算法实现\n");
	printf("1. 加密功能\n");
	printf("2. 解密功能\n");
	printf("0. 退出系统\n");
	printf("******************************\n");
}

/*功能：选择具体加密解密类型*/
void algorithmenu(){
	printf("******************************\n");
	printf("请选择具体加密解密类型\n");
	printf("1. 恺撒加密解密\n");
	printf("2. 字母倒排序加密解密\n");
	printf("3. 单表置换加密解密\n");
	printf("4. 维吉利亚加密解密\n");
	printf("5. 转换加密解密\n");
	printf("******************************\n");
}



/*功能：转换密码表*/
void convertkeys(KeyDictionary* keys[])
{
	KeyDictionary result[26];
	int temp;
	int index;


	//反转
	for (int i = 0; i < 26; i++)
	{
		temp = (keys[0] + i)->index;
		(keys[0] + i)->index = (keys[0] + i)->word;
		(keys[0] + i)->word = temp;
	}


	//test
	//输出keys
	//printf("keys\n");
	//for (int i = 0; i < 26; i++)
	//{
	//	printf("%d::%c:::%d\n", i,(keys[0] + i)->word, (keys[0] + i)->index);
	//}


	//排序
	for (int i = 0; i < 26; i++)
	{
		index = (keys[0] + i)->word - 97;
		result[index].word = (keys[0] + i)->word;
		result[index].index = (keys[0] + i)->index;
	}

	//printf("result\n");
	//for (int i = 0; i < 26; i++)
	//{
	//	printf("%c:::%d\n", result[i].word, result[i].index);
	//}

	//更新keys
	for (int i = 0; i < 26; i++)
	{
		(keys[0] + i)->word = result[i].word;
		(keys[0] + i)->index = result[i].index;
	}

	/*

		test
		printf("\n");
		for (int i = 0; i < 26; i++)
		{
		printf("%c:::%d\n", (keys[0] + i)->word, (keys[0] + i)->index);
		}*/

}
