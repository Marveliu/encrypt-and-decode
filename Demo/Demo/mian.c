/**************************/
// author: liushangnan
//   note: ���ܽ���������
//         �ٶ����ܻ��ܵ��ַ���ΪСд
//   time: 2016.10.18
//version: 1.0
/**************************/

#include"Mainfunction.h"


//��������
void main(int argc, char const *argv[])
{
	int flag = 1;   //�����˵�ѭ��
	int category = 0; //ѡ���������
	int choice = 0;   //���ܽ�������

	char targetstring[STRING_SIZE] = "";
	char resultstring[STRING_SIZE] = "";

	KeyDictionary keys[26];//��Сд������

	//��ʼ����Կ�ֵ�
	for (int i = 0; i < 26; i++)
	{
		keys[i].word = i + 97;
		keys[i].index = i + 97;
	}

	//�˵�
	menu();
	while (flag)
	{

		printf("��ѡ��������ͣ�\n��������1����������2\n");
		//ѡ����ܻ��߽���
		scanf("%d", &category);
		if (category == 1)
		{
			//����
			//��������ַ���

			printf("��������Ҫ���ܵ��ַ�����\n");
			scanf("%s", targetstring);
			//ѡ����ܵķ�ʽ
			printf("��ѡ��������ͣ�\n");
			algorithmenu();
			scanf("%d", &choice);
			switch (choice)
			{
			case 1:
				strcpy(resultstring, Caesarencrypt(targetstring, keys));
				break;
			case 2:
				strcpy(resultstring, Invertedencrypt(targetstring, keys));
				break;
			case 3:
				strcpy(resultstring, Singletablereplaceencrypt(targetstring, keys));
				break;
			case 4:
				strcpy(resultstring, Virginiaencrypt(targetstring, keys));
				break;
			case 5:
				break;
			default:
				break;
			}
			printf("�����ַ�Ϊ��\n");
			printf("%s\n", resultstring);

			//else
			//{
			//	printf("�ַ��������������\n");
			//	break;
			//}
			//�Ƿ񱣴�
		}
		else if (category == 2)
		{
			printf("��������Ҫ���ܵ����ģ�\n");
			scanf("%s", targetstring);
			//ѡ����ܵķ�ʽ
			printf("��ѡ��ѡ����ܵķ�ʽ��\n");
			algorithmenu();
			scanf("%d", &choice);
			int confrim = 1;
			switch (choice)
			{
			case 1:
				//��ʾ���ܽ��
				while (confrim)
				{
					strcpy(resultstring, Caesardecrypt(targetstring, keys));
					printf("�ƽ�����%s\n", &resultstring);
					printf("�����ƽ��밴1�������˳�\n");
					scanf("%d", &confrim);
					if (confrim == 1){
						confrim = 1;
					}
					else
					{
						confrim = 0;
					}
				}
				break;
			case 2:
				//��ʾ���ܽ��
				while (confrim)
				{
					strcpy(resultstring, Inverteddecrypt(targetstring, keys));
					printf("�ƽ�����%s\n", &resultstring);
					printf("�����ƽ��밴1�������˳�\n");
					scanf("%d", &confrim);
					if (confrim == 1){
						confrim = 1;
					}
					else
					{
						confrim = 0;
					}
				}
				break;
			case 3:
				strcpy(resultstring, Singletablereplacedecrypt(targetstring, keys));
				break;
			case 4:
				strcpy(resultstring, Virginiadecrypt(targetstring, keys));
				break;
			case 5:
				break;
			default:
				break;
			}
		}
		else if (category == 0)
		{
			printf("��ѡ���˳�����\n");
			flag = 0;
		}
		else
		{
			//��������
			printf("�����ָ����������������\n");
		}
		printf("��������������˵�\n");
		getch();
		system("cls");
	}
	return 0;
}


