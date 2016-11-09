/**************************/
// author: liushangnan
//   note: ���ܽ��ܺ����㷨
//   time: 2016.10.18
//version: 1.0
/**************************/

#include"String.h"

/*************����***************/


/*����*/
/*��������*/
char* Caesarencrypt(char* targetstring, KeyDictionary keys[]);
/*��ĸ���������*/
char* Invertedencrypt(char* targetstring, KeyDictionary keys[]);
//�����û�����
char* Singletablereplaceencrypt(char* targetstring, KeyDictionary keys[]);
//ά�����Ǽ���
char* Virginiaencrypt(char* targetstring, KeyDictionary keys[]);
//ת������
char* Convertencrypt(char* targetstring, KeyDictionary keys[]);

/*����*/
/*��������*/
char* Caesardecrypt(char* targetstring, KeyDictionary keys[]);
/*��ĸ���������*/
char* Inverteddecrypt(char* targetstring, KeyDictionary keys[]);
//�����û�����
char* Singletablereplacedecrypt(char* targetstring, KeyDictionary keys[]);
//ά�����ǽ���
char* Virginiadecrypt(char* targetstring, KeyDictionary keys[]);
//ת������
char* Convertdecrypt(char* targetstring, KeyDictionary keys[]);

/*����*/




//�˵�

void menu();
void algorithmenu();


/*************ʵ��***************/

/*************����***************/
/*��������*/
char* Caesarencrypt(char* targetstring, KeyDictionary keys[])
{
	int m = 0;
	int index;    //targetstring index
	int length = sizeof(targetstring);
	char resultstring[STRING_SIZE] = "";

	printf("������mֵ��");
	scanf("%d", &m);

	//������Կ��
	for (int i = 0; i < 26; i++)
	{
		keys[i].index = (keys[i].index + m)>122 ? (97 + 122 - keys[i].index - m) : (keys[i].index + m);
	}


	//������Կ��ֵ
	for (int i = 0; i <= length; i++)
	{
		//����ط����뽨��һ��������
		int index = (int)*(targetstring + i) - 97;  //�ӿ�����ٶ�
		//todo:�����ַ��ڸ�ֵ��֪�������Բ���
		resultstring[i] = keys[index].index;
	}
	return &resultstring;
}
/*��ĸ������*/
char* Invertedencrypt(char* targetstring, KeyDictionary keys[])
{
	int i = 0;
	int length = sizeof(targetstring);
	char resultstring[STRING_SIZE] = "";

	//������Կ��
	for (int i = 0; i < 26; i++)
	{
		keys[i].index = keys[25 - i].index;
	}

	//������Կ��ֵ
	for (int i = 0; i <= length; i++)
	{
		//����ط����뽨��һ��������
		int index = (int)*(targetstring + i) - 97;  //�ӿ�����ٶ�
		//todo:�����ַ��ڸ�ֵ��֪�������Բ���
		resultstring[i] = keys[index].index;
	}
	return &resultstring;
}
//�����û�����
char* Singletablereplaceencrypt(char* targetstring, KeyDictionary keys[])
{
	int n = 0;
	int index = 0;
	int length = sizeof(targetstring);

	char resultstring[STRING_SIZE] = "";
	char keystring[STRING_SIZE] = "";
	int check[25] = {0};  //ȫ������Ϊ0


	printf("������key\n");  //�ַ���������,
	scanf("%c", keystring);

	strcat(keystring, "abcdefghijiklmnopqrstuvwxyz");

	//����keys[]
	for (int i = 0; i < strlen(keystring); i++)
	{
		int index = keystring[i] - 97;
		if (check[i] == 0)
		{
			//��ĸû�г���
			check[i] = 1;
			keys[n++].index = index; 
		}
	}

	//������Կ��ֵ
	for (int i = 0; i <= length; i++)
	{
		//����ط����뽨��һ��������
		int index = (int)*(targetstring + i) - 97;  //�ӿ�����ٶ�
		//todo:�����ַ��ڸ�ֵ��֪�������Բ���
		resultstring[i] = keys[index].index;
	}
	return &resultstring;
}
//ά����������
char* Virginiaencrypt(char* targetstring, KeyDictionary keys[])
{
	char keywords[STRING_SIZE];
	char resultstring[STRING_SIZE] = "";
	int keywords_len = 0;
	int putwords_len = 0;
	int index = 0;
	int num1 = 0;
	int num2 = 0;

	//������ܵ���
	printf("��������ܵ��ʣ�\n");
	scanf("%s", keywords);

	//��������ַ����ĳ���
	keywords_len = strlen(keywords);
	putwords_len = strlen(targetstring);

	//todo:keywords_len>putwords_len...û��Ӱ�죬���Ƕ�ĵط�û�����

	//���ܵ���
	for (int i=0,n=0; i < putwords_len; i++)
	{
		//ȡģ����
		n = i%keywords_len;
		num1 = keywords[n] - 97;
		num2 = targetstring[i] - 97;
		//���㵥���ַ�
		resultstring[i] = keys[(num1 + num1) % 26].word;
	}
}
//ת������
char* Convertencrypt(char* targetstring, KeyDictionary keys[])
{

}


/*************����***************/

/*��������*/
char* Caesardecrypt(char* targetstring, KeyDictionary keys[])
{

}
/*��ĸ������*/
char* Inverteddecrypt(char* targetstring, KeyDictionary keys[])
{

}
//�����û�����
char* Singletablereplacedecrypt(char* targetstring, KeyDictionary keys[])
{

}
//ά����������
char* Virginiadecrypt(char* targetstring, KeyDictionary keys[]) {


}
//ת������
char* Convertdecrypt(char* targetstring, KeyDictionary keys[]) {

}


/*************����***************/
/*���ܣ�����˵�*/
void menu(){
	printf("******************************\n");
	printf("/t���ܽ����㷨ʵ��\n");
	printf("1. ���ܹ���\n");
	printf("2. ���ܹ���\n");
	printf("0. �˳�ϵͳ\n");
	printf("******************************\n");
}

/*���ܣ�ѡ�������ܽ�������*/
void algorithmenu(){
	printf("******************************\n");
	printf("��ѡ�������ܽ�������\n");
	printf("1. �������ܽ���\n");
	printf("2. ��ĸ��������ܽ���\n");
	printf("3. �����û����ܽ���\n");
	printf("4. ά�����Ǽ��ܽ���\n");
	printf("5. ת�����ܽ���\n");
	printf("******************************\n");
}