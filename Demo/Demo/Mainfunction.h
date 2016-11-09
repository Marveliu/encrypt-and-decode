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
char* Convertencrypt(char* targetstring, KeyDictionary keys[]);

/*解密*/
/*恺撒解密*/
char* Caesardecrypt(char* targetstring, KeyDictionary keys[]);
/*字母倒排序解密*/
char* Inverteddecrypt(char* targetstring, KeyDictionary keys[]);
//单表置换解密
char* Singletablereplacedecrypt(char* targetstring, KeyDictionary keys[]);
//维吉利亚解密
char* Virginiadecrypt(char* targetstring, KeyDictionary keys[]);
//转换解密
char* Convertdecrypt(char* targetstring, KeyDictionary keys[]);

/*解密*/




//菜单

void menu();
void algorithmenu();


/*************实现***************/

/*************加密***************/
/*恺撒密码*/
char* Caesarencrypt(char* targetstring, KeyDictionary keys[])
{
	int m = 0;
	int index;    //targetstring index
	int length = sizeof(targetstring);
	char resultstring[STRING_SIZE] = "";

	printf("请输入m值：");
	scanf("%d", &m);

	//更新密钥表
	for (int i = 0; i < 26; i++)
	{
		keys[i].index = (keys[i].index + m)>122 ? (97 + 122 - keys[i].index - m) : (keys[i].index + m);
	}


	//按照密钥表赋值
	for (int i = 0; i <= length; i++)
	{
		//这个地方我想建立一个ｈａｓｈ表
		int index = (int)*(targetstring + i) - 97;  //加快计算速度
		//todo:单个字符在赋值不知道这样对不对
		resultstring[i] = keys[index].index;
	}
	return &resultstring;
}
/*字母倒排序*/
char* Invertedencrypt(char* targetstring, KeyDictionary keys[])
{
	int i = 0;
	int length = sizeof(targetstring);
	char resultstring[STRING_SIZE] = "";

	//更新密钥表
	for (int i = 0; i < 26; i++)
	{
		keys[i].index = keys[25 - i].index;
	}

	//按照密钥表赋值
	for (int i = 0; i <= length; i++)
	{
		//这个地方我想建立一个ｈａｓｈ表
		int index = (int)*(targetstring + i) - 97;  //加快计算速度
		//todo:单个字符在赋值不知道这样对不对
		resultstring[i] = keys[index].index;
	}
	return &resultstring;
}
//单表置换密码
char* Singletablereplaceencrypt(char* targetstring, KeyDictionary keys[])
{
	int n = 0;
	int index = 0;
	int length = sizeof(targetstring);

	char resultstring[STRING_SIZE] = "";
	char keystring[STRING_SIZE] = "";
	int check[25] = {0};  //全部设置为0


	printf("请输入key\n");  //字符数的限制,
	scanf("%c", keystring);

	strcat(keystring, "abcdefghijiklmnopqrstuvwxyz");

	//更新keys[]
	for (int i = 0; i < strlen(keystring); i++)
	{
		int index = keystring[i] - 97;
		if (check[i] == 0)
		{
			//字母没有出现
			check[i] = 1;
			keys[n++].index = index; 
		}
	}

	//按照密钥表赋值
	for (int i = 0; i <= length; i++)
	{
		//这个地方我想建立一个ｈａｓｈ表
		int index = (int)*(targetstring + i) - 97;  //加快计算速度
		//todo:单个字符在赋值不知道这样对不对
		resultstring[i] = keys[index].index;
	}
	return &resultstring;
}
//维吉利亚密码
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
	for (int i=0,n=0; i < putwords_len; i++)
	{
		//取模运算
		n = i%keywords_len;
		num1 = keywords[n] - 97;
		num2 = targetstring[i] - 97;
		//计算单个字符
		resultstring[i] = keys[(num1 + num1) % 26].word;
	}
}
//转换加密
char* Convertencrypt(char* targetstring, KeyDictionary keys[])
{

}


/*************解密***************/

/*恺撒密码*/
char* Caesardecrypt(char* targetstring, KeyDictionary keys[])
{

}
/*字母倒排序*/
char* Inverteddecrypt(char* targetstring, KeyDictionary keys[])
{

}
//单表置换密码
char* Singletablereplacedecrypt(char* targetstring, KeyDictionary keys[])
{

}
//维吉利亚密码
char* Virginiadecrypt(char* targetstring, KeyDictionary keys[]) {


}
//转换解密
char* Convertdecrypt(char* targetstring, KeyDictionary keys[]) {

}


/*************功能***************/
/*功能：输出菜单*/
void menu(){
	printf("******************************\n");
	printf("/t加密解密算法实现\n");
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