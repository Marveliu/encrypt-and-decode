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
char* Convertencrypt(char* targetstring);

/*����*/
/*��������*/
char* Caesardecrypt(char* targetstring, int m);
/*��ĸ���������*/
char* Inverteddecrypt(char* targetstring, KeyDictionary keys[]);
//�����û�����
char* Singletablereplacedecrypt(char* targetstring, KeyDictionary keys[]);
//ά�����ǽ���
char* Virginiadecrypt(char* targetstring, KeyDictionary keys[]);
//ת������
char* Convertdecrypt(char* targetstring);

/*����*/




//�˵�

void menu();
void algorithmenu();
void convertkeys(KeyDictionary* keys[]);


/*************ʵ��***************/

/*************����***************/
/*1.1 ��������*/
char* Caesarencrypt(char* targetstring, KeyDictionary keys[])
{
	int m = 0;
	int index = 0;    //targetstring index
	int length = strlen(targetstring);
	char resultstring[STRING_SIZE] = "";

	printf("������mֵ��");
	scanf("%d", &m);

	//������Կ��
	for (int i = 0; i < 26; i++)
	{
		keys[i].index = (keys[i].index + m)>122 ? (96 + keys[i].index + m - 122) : (keys[i].index + m);
		printf("%c:::%d\n", keys[i].word, keys[i].index);
	}

	//������Կ��ֵ
	for (int i = 0; i <= length; i++)
	{
		//����ط����뽨��һ��������
		int index = (int)*(targetstring + i) - 97;  //�ӿ�����ٶ�
		//todo:�����ַ��ڸ�ֵ��֪�������Բ���
		resultstring[i] = keys[index].index;
	}
	return resultstring;
}

/*2.1 ��ĸ������*/
char* Invertedencrypt(char* targetstring, KeyDictionary keys[])
{
	int i = 0;
	int length = strlen(targetstring);
	char resultstring[STRING_SIZE] = "";

	//������Կ��
	for (int i = 0; i < 26; i++)
	{
		//ǰ���ֵ�Ѿ������˸ı�
		keys[i].index = 219 - keys[i].index;
		printf("%c:::%d\n", keys[i].word, keys[i].index);
	}

	//������Կ��ֵ
	for (int i = 0; i < length; i++)
	{
		int index = (int)*(targetstring + i) - 97;  //�ӿ�����ٶ�
		//todo:�����ַ��ڸ�ֵ��֪�������Բ���
		resultstring[i] = keys[index].index;
	}
	return resultstring;
}

//3.1 �����û�����
char* Singletablereplaceencrypt(char* targetstring, KeyDictionary keys[])
{
	int n = 0;
	int index = 0;
	int length = strlen(targetstring);
	char resultstring[STRING_SIZE] = "";
	char keystring[STRING_SIZE] = "";
	int check[25] = { 0 };  //ȫ������Ϊ0


	printf("������key\n");  //�ַ���������,
	scanf("%s", keystring);

	strcat(keystring, "abcdefghijiklmnopqrstuvwxyz");

	int length1 = strlen(keystring);
	//����keys[]
	for (int i = 0; i < length1; i++)
	{
		int index = keystring[i] - 97;
		if (check[index] == 0)
		{
			//��ĸû�г���
			check[index] = 1;
			keys[n++].index = keystring[i];
		}
	}

	//���keys
	for (int i = 0; i < 26; i++)
	{
		printf("%c:::%d\n", keys[i].word, keys[i].index);
	}

	//������Կ��ֵ
	for (int i = 0; i < length; i++)
	{
		int index = targetstring[i] - 97;  //�ӿ�����ٶ�
		//todo:�����ַ��ڸ�ֵ��֪�������Բ���
		resultstring[i] = keys[index].index;
	}
	return resultstring;
}

//4.1 ά����������
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
	for (int i = 0, n = 0; i < putwords_len; i++)
	{
		//ȡģ����
		n = i % keywords_len;
		num1 = keywords[n] - 97;
		num2 = targetstring[i] - 97;
		//���㵥���ַ�
		resultstring[i] = keys[(num1 + num2) % 26].word;
	}

	return resultstring;
}

//5.1 ת������
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


	//���Ҫ���ܵĵĵ���
	printf("��������Կ:\n");
	scanf("%s", keywords);

	keywords_len = strlen(keywords);

	//�������keywords���д����ظ����ַ����кϲ�
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


	//�������Ҫ�ȶԵ��ַ����ĳ���
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



/*************����***************/

/*1.2 ��������*/
char* Caesardecrypt(char* targetstring, KeyDictionary keys[])
{
	int m = 0;
	int index = 0;    //targetstring index
	int length = strlen(targetstring);
	char resultstring[STRING_SIZE] = "";

	printf("������mֵ��");
	scanf("%d", &m);

	//������Կ��
	for (int i = 0; i < 26; i++)
	{
		keys[i].index = 122 - i;
		printf("%c:::%d\n", keys[i].word, keys[i].index);
	}

	//������Կ��ֵ
	for (int i = 0; i <= length; i++)
	{
		int index = (int)*(targetstring + i) - 97;  //�ӿ�����ٶ�
		//todo:�����ַ��ڸ�ֵ��֪�������Բ���
		resultstring[i] = keys[index].index;
	}
	return resultstring;
}

/*2.2 ��ĸ������*/
//�ͼ��ܵĺ���һ��
char* Inverteddecrypt(char* targetstring, KeyDictionary keys[])
{
	int i = 0;
	int length = strlen(targetstring);
	char resultstring[STRING_SIZE] = "";

	//��Կ��
	for (int i = 0; i < 26; i++)
	{
		keys[i].index = 122 - i;
		printf("%c:::%d\n", keys[i].word, keys[i].index);
	}

	//������Կ��ֵ
	for (int i = 0; i < length; i++)
	{
		int index = (int)*(targetstring + i) - 97;  //�ӿ�����ٶ�
		//todo:�����ַ��ڸ�ֵ��֪�������Բ���
		resultstring[i] = keys[index].index;
	}
	return resultstring;
}

//3.2 �����û�����
char* Singletablereplacedecrypt(char* targetstring, KeyDictionary keys[])
{
	int n = 0;
	int index = 0;
	int length = sizeof(targetstring);

	char resultstring[STRING_SIZE] = "";
	char keystring[STRING_SIZE] = "";
	int check[25] = { 0 };  //ȫ������Ϊ0


	printf("������key\n");  //�ַ���������,

	getch();
	scanf("%s", keystring);

	strcat(keystring, "abcdefghijiklmnopqrstuvwxyz");

	int length1 = strlen(keystring);

	//���յ����û���ԭ�򣬸���keys[]
	for (int i = 0; i < length1; i++)
	{
		int index = keystring[i] - 97;
		if (check[index] == 0)
		{
			//��ĸû�г���
			check[index] = 1;
			keys[n++].index = keystring[i];
		}
	}
	//���keys
	for (int i = 0; i < 26; i++)
	{
		printf("%c:::%d\n", keys[i].word, keys[i].index);
	}

	convertkeys(&keys);

	//���keys
	for (int i = 0; i < 26; i++)
	{
		printf("%c:::%d\n", keys[i].word, keys[i].index);
	}

	//������Կ��ֵ
	for (int i = 0; i < length; i++)
	{
		int index = (int)*(targetstring + i) - 97;  //�ӿ�����ٶ�
		resultstring[i] = keys[index].index;
	}

	return resultstring;
}

//4.2 ά����������
char* Virginiadecrypt(char* targetstring, KeyDictionary keys[]) {
	char keywords[STRING_SIZE];
	char resultstring[STRING_SIZE] = "";
	int keywords_len = 0;
	int putwords_len = 0;
	int index = 0;
	int num1 = 0;
	int num2 = 0;

	printf("��������Կ��\n");
	scanf("%s", keywords);

	//��������ַ����ĳ���
	keywords_len = strlen(keywords);
	putwords_len = strlen(targetstring);

	//���ܵ���
	for (int i = 0, n = 0; i < putwords_len; i++)
	{
		//ȡģ����
		n = i % keywords_len;
		num1 = keywords[n] - 97;
		num2 = targetstring[i] - 97;

		//���㵥���ַ�
		resultstring[i] = keys[(num2 + 26 - num1) % 26].word;
	}

	return resultstring;
}

//5.2 ת������
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


	printf("��������Կ:\n");
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


	//��������ַ����ĳ���
	keywords_len = strlen(sortkeywords);
	putwords_len = strlen(targetstring);

	num1 = putwords_len % keywords_len;          //����
	num2 = putwords_len / keywords_len;          //��

	//����check[]�����ֵ��Ϊ����
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


	//ת��������
	count = 0;
	for (int i = 0; i < keywords_len; i++)
	{
		for (int n = 0; n < check[sortkeywords[i] - 97]; n++)
		{
			stringarrays[i][n] = targetstring[count++];
		}
	}

	count = 0;
	//Ϊ�˵õ�ȡ���Ĵ�����һ�θ���check
	//�������keywords���д����ظ����ַ����кϲ�
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


/*************����***************/
/*���ܣ�����˵�*/
void menu(){
	printf("******************************\n");
	printf("\t���ܽ����㷨ʵ��\n");
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



/*���ܣ�ת�������*/
void convertkeys(KeyDictionary* keys[])
{
	KeyDictionary result[26];
	int temp;
	int index;


	//��ת
	for (int i = 0; i < 26; i++)
	{
		temp = (keys[0] + i)->index;
		(keys[0] + i)->index = (keys[0] + i)->word;
		(keys[0] + i)->word = temp;
	}


	//test
	//���keys
	//printf("keys\n");
	//for (int i = 0; i < 26; i++)
	//{
	//	printf("%d::%c:::%d\n", i,(keys[0] + i)->word, (keys[0] + i)->index);
	//}


	//����
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

	//����keys
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
