/**************************/
// author: liushangnan
//   note: 加密解密主程序
//         假定加密机密的字符均为小写
//   time: 2016.10.18
//version: 1.0
/**************************/

#include"Mainfunction.h"
#define STRING_SIZE 1024


//函数主体
void main(int argc, char const *argv[])
{
	int flag = 1;   //结束菜单循环
	int category = 0; //选择程序类型

	char targetstring[STRING_SIZE] = "";
	char resultstring[STRING_SIZE] = "";

	KeyDictionary keys[26];//大小写的问题

	//初始化密钥字典
	for (int i = 0; i < 26; i++)
	{
		keys[i].word = i + 97;
		keys[i].index = i;
	}

	//菜单
	menu();
	while (flag)
	{
		printf("请选择程序类型：/n加密请输1，解密请输2/n");
		//选择加密或者解密
		if (category == 1)
		{
			//加密
			//输入或导入字符串

			printf("请输入你要加密的字符串：/n");
			getch();
			if (getch(targetstring) != -1){
				//选择加密的方式
				printf("请选择加密类型：/n");
				algorithmenu();
				scanf("%d", &category);
				switch (category)
				{
				case 1:
					strcpy(resultstring,*(Caesarencrypt(targetstring,keys)));
					break;
				case 2:
					strcpy(resultstring, *(Invertedencrypt(targetstring,keys)));
					break;
				case 3:
					strcpy(resultstring, *(Singletablereplaceencrypt(targetstring,keys)));
					break;
				case 4:
					strcpy(resultstring, *(Virginiaencrypt(targetstring,keys)));
					break;
				case 5:
					break;
				default:
					break;
				}
			}
			else
			{
				printf("字符串输入出现问题");
				break;
			}
			//是否保存
		}
		else if (category == 2)
		{
			printf("请输入你要解密的密文：/n");
			getch();
			if (getch(targetstring) != -1){
				//选择加密的方式
				printf("请选择选择解密的方式：/n");
				algorithmenu();
				scanf("%d", &category);
				int confrim = 1;
				switch (category)
				{
				case 1:
					////显示解密结果
					//while (confrim)
					//{
					//	strcpy(resultstring, *(Caesardecrypt(targetstring,keys)));
					//	printf("破解结果：%s/n", &resultstring);
					//	printf("继续破解请按1，否则退出\n");
					//	scanf("%d", &confrim);
					//	if (confrim == 1){
					//		confrim = 0;
					//	}
					//	else
					//	{
					//		confrim = 1;
					//	}
					//}
					break;
				case 2:
					//strcpy(resultstring, *(Inverteddecrypt(targetstring, keys)));
					break;
				case 3:
					//strcpy(resultstring, *(Singletablereplacedecrypt(targetstring, keys)));
					break;
				case 4:
					//strcpy(resultstring, *(Virginiadecrypt(targetstring, keys)));
					break;
				case 5:
					break;
				default:
					break;
				}

			}
			else if (category == 0);
			else
			{
				printf("字符串输入出现问题");
				break;
			}
			//解密
			//导入密文
			//暴力破解模式
			//循环输出破解密文
			//是否保存   
		}
		else
		{
			//输入有误
			printf("输入的指令有误，请重新输入/n");
			System("cls");
		}
	}
	return 0;
}

