/**************************/
// author: liushangnan
//   note: ���ܽ���������
//         �ٶ����ܻ��ܵ��ַ���ΪСд
//   time: 2016.10.18
//version: 1.0
/**************************/

#include"Mainfunction.h"
#define STRING_SIZE 1024


//��������
void main(int argc, char const *argv[])
{
	int flag = 1;   //�����˵�ѭ��
	int category = 0; //ѡ���������

	char targetstring[STRING_SIZE] = "";
	char resultstring[STRING_SIZE] = "";

	KeyDictionary keys[26];//��Сд������

	//��ʼ����Կ�ֵ�
	for (int i = 0; i < 26; i++)
	{
		keys[i].word = i + 97;
		keys[i].index = i;
	}

	//�˵�
	menu();
	while (flag)
	{
		printf("��ѡ��������ͣ�/n��������1����������2/n");
		//ѡ����ܻ��߽���
		if (category == 1)
		{
			//����
			//��������ַ���

			printf("��������Ҫ���ܵ��ַ�����/n");
			getch();
			if (getch(targetstring) != -1){
				//ѡ����ܵķ�ʽ
				printf("��ѡ��������ͣ�/n");
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
				printf("�ַ��������������");
				break;
			}
			//�Ƿ񱣴�
		}
		else if (category == 2)
		{
			printf("��������Ҫ���ܵ����ģ�/n");
			getch();
			if (getch(targetstring) != -1){
				//ѡ����ܵķ�ʽ
				printf("��ѡ��ѡ����ܵķ�ʽ��/n");
				algorithmenu();
				scanf("%d", &category);
				int confrim = 1;
				switch (category)
				{
				case 1:
					////��ʾ���ܽ��
					//while (confrim)
					//{
					//	strcpy(resultstring, *(Caesardecrypt(targetstring,keys)));
					//	printf("�ƽ�����%s/n", &resultstring);
					//	printf("�����ƽ��밴1�������˳�\n");
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
				printf("�ַ��������������");
				break;
			}
			//����
			//��������
			//�����ƽ�ģʽ
			//ѭ������ƽ�����
			//�Ƿ񱣴�   
		}
		else
		{
			//��������
			printf("�����ָ����������������/n");
			System("cls");
		}
	}
	return 0;
}

