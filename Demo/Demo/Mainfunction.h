/**************************/
// author: liushangnan
//   note: 加密解密核心算法
//   time: 2016.10.18
//version: 1.0
/**************************/

#include"String.h"

/*************声明***************/


/*加密*/
/*恺撒密码*/
char* Caesarencrypt(char* targetstring, KeyDictionary keys[]);
/*字母倒排序*/
char* Invertedencrypt(char* targetstring, KeyDictionary keys[]);
//单表置换密码
char* Singletablereplaceencrypt(char* targetstring, KeyDictionary keys[]);
//维吉利亚密码
char* Virginiaencrypt(char* targetstring, KeyDictionary keys[]);

/*解密*/
/*恺撒密码*/
char* Caesardecrypt(char* targetstring, KeyDictionary keys[]);
/*字母倒排序*/
char* Inverteddecrypt(char* targetstring, KeyDictionary keys[]);
//单表置换密码
char* Singletablereplacedecrypt(char* targetstring, KeyDictionary keys[]);
//维吉利亚密码
char* Virginiadecrypt(char* targetstring, KeyDictionary keys[]);


/*************实现***************/

/*加密*/
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

}