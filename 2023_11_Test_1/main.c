#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "MyString.h"

void Test_26()
{
	printf("TEST_26\n");

}

void Test_25()
{
	printf("TEST_25\n");

}

void Test_24()
{
	printf("TEST_24\n");

}

int IfRotateStr(const char* str1, const char* str2)
{
	//�ж�һ���ַ����Ƿ�Ϊ��һ���ַ�������ת���
	assert(str1);
	assert(str2);

	size_t ln = 0;
	if (ln = strlen(str1) != strlen(str2))
		return 0;

	int point = 0;
	while (*str1 != str2[point] && str2[point])
		point++;

	if (!str2[point])
		return 0;

	int i = 0;
	for (i = 0; i < ln; i++)
	{
		if (str1[i] != str2[(point + i) % (int)ln])
			return 0;
	}

	return 1;
}

void Test_23()
{
	printf("TEST_23\n");

	char str1[] = "abcdd";
	char str2[] = "ddabc";
	char str3[] = "ABCDD";

	printf("%s\n", IfRotateStr(str1, str2) ? "��" : "��");
	printf("%s\n", IfRotateStr(str1, str3) ? "��" : "��");
}

int findValue(int arr[], int col, int row, int k)
{
	int i = 0;
	for (i = 0; i < col; i++)
	{
		//��ÿһ�е�������β��Ѱ����ֵ������ֵ�������������������Ѱ����ֵ
		if (arr[i * row + 0] < k && arr[i * row + row] > k)
		{
			int j = 0;
			for (j = 0; i < row; j++)
			{
				if (arr[i * row + j] == k)
				{
					return 1;
				}
			}
		}
		else if (arr[i * row + 0] == k || arr[i * row + row] == k)
		{
			return 1;
		}
	}

	//����ȫ�������޽���򷵻�false
	return 0;
}

void Test_22()
{
	printf("TEST_22\n");
	//���Ͼ��������ֵ�Ƿ����
	int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	printf("%s\n", findValue(arr, 3, 3, 7) ? "����" : "������");
}

int GetPointValue(int x, int y)
{
/*
 * 1
 * 1  1
 * 1  2  1
 * 1  3  3  1
 * 1  4  6  4  1
 * 1  5 10 10  5  1
 */
	assert(x <= y);
	assert(0 <= x || 0 <= y);

	//1,1 = 1
	//2,1 = 1;
	//3,2 = 2,1 + 2,2


	if (x == 1 || x == y)
		return 1;
	else
		return GetPointValue(x - 1, y - 1) + GetPointValue(x, y - 1);
}

void PrintTriangle(int count)
{
	int i = 0;
	for (i = 0; i < count; i++)
	{
		int j = 0;
		for (j = 0; j <= i; j++)
		{
			printf("%d ", GetPointValue(j + 1, i + 1));
		}
		printf("\n");
	}

}

void Test_21()
{
	printf("TEST_21\n");
	//�������
	/* 
	 * 1
	 * 1  1
	 * 1  2  1
	 * 1  3  3  1
	 * 1  4  6  4  1
	 * 1  5 10 10  5  1
	 */

	PrintTriangle(10);
}

void Test_20()
{
	printf("TEST_20\n");

		//A˵�������ҡ�
		//B˵����C��
		//C˵����D��
		//D˵��C�ں�˵
		//��֪3����˵���滰��1����˵���Ǽٻ���
		//ͶƱ
	
	//abcd����ͶƱ����
	int arr[4] = { 0, 0, 1, 1 };

	//d��ͶƱ
	arr[3] -= 1;

	int i = 0;
	int maxScript = 0;
	for (i = 0; i < _countof(arr); i++)
	{
		if (arr[maxScript] < arr[i])
			maxScript = i;
	}

	switch (maxScript)
	{
	case 0:
		printf("a\n");
		break;
	case 1:
		printf("b\n");
		break;
	case 2:
		printf("c\n");
		break;
	case 3:
		printf("d\n");
		break;
	}
}

void Test_19()
{
	printf("TEST_19\n");

	//printf("%zd\n", MyStrlen("Hello World!"));
	//char szBuffer[1024] = "abcdef\0**********";
	//char szSrc[] = "abdcefgh";

	//MyStrcpy(szBuffer, szSrc);

	//printf("%s\n", szBuffer);

	//char szCh1[] = "abcde";
	//char szCh2[] = "abcdf";

	//printf("%d\n", MyStrcmp(szCh1, szCh2));

	//char szBuffer[1024] = "abc";
	//char szCh1[] = "def";

	//printf("%s\n", MyStrcat(szBuffer, szCh1));

	char str[] = "this is a string";

	char CHs[] = " ";
	
	char* ret = MyStrstr(str, CHs);
	if (ret)
		printf("%s\n", ret);
	while (ret = MyStrstr(NULL, CHs))
		printf("%s\n", ret);

}

void SngDobSet(int arr[], size_t sz)
{
	assert(arr);
	assert(sz);

	//˫ָ��

	size_t begin = 0;
	size_t end = sz - 1;

	int cur = begin;

	while (begin < end)
	{

		//˫ָ���ƶ�
		if (0 == arr[begin] % 2)
		{
			int temp = arr[begin];
			arr[begin] = arr[end];
			arr[end] = temp;
			end--;
			continue;
		}
		if (1 == arr[end] % 2)
		{
			int temp = arr[begin];
			arr[begin] = arr[end];
			arr[end] = temp;
			begin++;
			continue;
		}
		
		begin++;
		end--;
	}


}

void Test_18()
{
	printf("TEST_18\n");

	//����һ���������飬ʵ��һ��������
	//	�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
	//	����ż��λ������ĺ�벿�֡�

	int arr[] = { 2, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int i = 0;

	for (i = 0; i < _countof(arr); i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');

	SngDobSet(arr, _countof(arr));
	
	for (i = 0; i < _countof(arr); i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');
}

void myBubbleSort(int arr[], size_t sz)
{
	assert(arr);
	assert(sz);
	size_t end = sz;

	while (end > 0)
	{
		int i = 0;
		for (i = 0; i < end - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				int temp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = temp;
			}
		}
		end--;
	}
}

void Test_17()
{
	//ʵ��һ�������ε�ð������
	printf("TEST_17\n");
	
	int arr[] = { 7, 6, 5, 4, 3, 2, 1 };
	int i = 0;

	for (i = 0; i < _countof(arr); i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');

	myBubbleSort(arr, _countof(arr));

	for (i = 0; i < _countof(arr); i++)
	{
		printf("%d ", arr[i]);
	}
	putchar('\n');
}

void Test_16()
{
	printf("TEST_16\n");
	//�����±��������
	int i = 0;
	int arr[10] = { 0 };
	for (i = 0; i < 10; i++)
	{
		*(arr + i) = i + 1;
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d ", *(arr + i));
	}
}

void Test_15()
{
	printf("TEST_15\n");
	//�ַ�������
	char ch[] = "ABCDEFG";

	printf("%s\n", ch);

	//����
	const int count = 2;	//��������
	char szBuffer[512] = { 0 };
	strcpy(szBuffer, ch);

	size_t length = strlen(ch);

	int i = 0;
	for (i = 0; i < length; i++)
	{
		ch[(i + count) % (int)length] = szBuffer[i];
	}

	printf("%s\n", ch);

}

//void ExChange(char* c1, char* c2)
//{
//	char temp = *c2;
//	*c2 = *c1;
//	*c1 = temp;
//}
//
//int main() {
//	char szBuffer[1024] = { 0 };
//	while (gets_s)
//	{
//		int left = 0;
//		int right = strlen(szBuffer) - 1;
//		while (left < right)
//		{
//			ExChange((char*)szBuffer + left, (char*)szBuffer + right);
//			left++;
//			right--;
//		}
//		printf("%s\n", szBuffer);
//	}
//
//	return 0;
//}

size_t myStrlen(char* str)
{
	assert(str);

	char* begin = str;
	while (*str)
		str++;
	return str - begin;
}

void Test_14()
{
	printf("TEST_14\n");

	printf("%zd\n", myStrlen("Hello world"));
}

int compareFunc(void* c1, void* c2)
{
	return (*(int*)c1) - (*(int*)c2);
}

void Test_13()
{
	printf("TEST_13\n");

	//��һ�����������У�ֻ��һ�����ֳ���һ�Σ��������鶼�ǳɶԳ��ֵģ����ҳ��Ǹ�ֻ����һ�ε����֡�
	//	���磺
	//	�������У�1 2 3 4 5 1 2 3 4��ֻ��5����һ�Σ��������ֶ�����2�Σ��ҳ�5

	int arr[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4 };
	
	int findValueSubscript = -1;
	int i = 0;
	qsort(arr, _countof(arr), sizeof(int), compareFunc);

	int c = _countof(arr);

	for (i = 1; i < _countof(arr); i++)
	{
		if (i % 2 == 1 && arr[i] != arr[i - 1])
		{
			findValueSubscript = i - 1;
			break;
		}

	}
	//���������Сĩλ�ж�
	if (0 > findValueSubscript && _countof(arr) % 2 == 1)
	{
		findValueSubscript = _countof(arr) - 1;
	}


	findValueSubscript >= 0 ? printf("%d\n", arr[findValueSubscript]) : printf("Not single value\n");
}

//��ӡ���������е�����λ��ż��λ
//��ȡһ���������������������е�ż��λ������λ���ֱ��ӡ������������

void Test_12()
{
	printf("TEST_12\n");

	char szBuffer1[512] = { 0 };
	char szBuffer2[512] = { 0 };

	char bSequence[] = "1010010110100101";

	int i = 0;
	int PointBuff = 0;
	int b1Index = 0;
	int b2Index = 0;

	printf("%s\n", bSequence);	//��ӡδ�ָ������

	//�ָ�
	for (i = 0; i < _countof(bSequence); i++)
	{
		//�ָ�Ϊ����
		switch (PointBuff)
		{
		case 0:
			szBuffer1[b1Index] = bSequence[i];
			b1Index++;
			break;
		case 1:
			szBuffer2[b2Index] = bSequence[i];
			b2Index++;
			break;
		}

		PointBuff++;
		if (PointBuff > 1)
		{
			PointBuff = 0;
		}
	}
	//ĩβ��0
	szBuffer1[b1Index] = 0;
	szBuffer2[b2Index] = 0;

	//��ӡЧ��
	printf("%s\n%s\n", szBuffer1, szBuffer2);
}

void Exchange(int* x, int* y)
{
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}

void Test_11()
{
	printf("TEST_11\n");

	int a = 3;
	int b = 5;

	printf("%d, %d\n", a, b);
	
	Exchange(&a, &b);

	printf("%d, %d\n", a, b);

}

//��Sn = a + aa + aaa + aaaa + aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
//
//���磺2 + 22 + 222 + 2222 + 22222
void Test_10()
{
	printf("TEST_10\n");


	int Sn = 0;
	int sValue = 2;
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		int temp = sValue % 10;


		Sn += sValue;
		sValue += sValue * 10 + temp;
	}
	printf("%d\n", Sn);
}

//�ݹ��ӡһ������ÿһλ
void PutDigit(int x)
{
	if (x / 10 > 0)
	{
		PutDigit(x / 10);
	}
	printf("%d ", x % 10);
}

void Test_09()
{
	printf("TEST_09\n");
	PutDigit(1234);
	printf("\n");
}

long long factorial1(int n)
{
	return n * (n > 2 ? factorial1(n - 1) : 1);
}

long long factorial2(int n)
{
	long long sum = 0;


	int i = 0;
	for (i = 2; i <= n; i++)
	{
		if (i == 2)
			sum = 1;
		sum *= i;
	}


	return sum;
}

//�õݹ���ǵݹ�ʵ�ֽ׳�
void Test_08()
{
	printf("TEST_08\n");


	printf("%lld\n", factorial1(0));
	printf("%lld\n", factorial2(0));
}

//дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮��
int DigitSum(int x)
{
	return x > 10 ? x % 10 + DigitSum(x / 10) : x;
}

void Test_07()
{
	printf("TEST_07\n");

	printf("%d\n", DigitSum(1729));
	printf("%d\n", DigitSum(12345));
}

//����n��k�η�
int N_SToK(int n, int k)
{
	return k > 1 ? n * N_SToK(n, k - 1) : n;
}

void Test_06()
{
	printf("TEST_06\n");


	int n = 10;
	int k = 3;


	printf("%d\n", N_SToK(10, 3));
}

//쳲��������У�Fibonacci sequence�����ֳƻƽ�ָ����У�����ѧ�������ɶࡤ쳲�������Leonardo Fibonacci�������ӷ�ֳΪ���Ӷ����룬���ֳơ��������С���
//����ֵΪ��1��1��2��3��5��8��13��21��34��������ѧ�ϣ���һ���������µ��Ƶķ������壺F(0) = 1��F(1) = 1, F(n) = F(n - 1) + F(n - 2)

int febNumN_1(int n)
{
	//�ݹ鷨
	int ret = 1;


	if (n >= 3)
	{
		//�ݹ��ۼ�
		ret = febNumN_1(n - 1) + febNumN_1(n - 2);
	}


	return ret;
}

int febNumN_2(int n)
{
	//ѭ����
	int n_1 = 1;
	int n_2 = 1;


	int ret = 1;


	int i = 3;
	for (i = 3; i <= n; i++)
	{
		//��ֵλ��������ƶ�
		ret = n_1 + n_2;
		n_2 = n_1;
		n_1 = ret;
	}
	return ret;
}

void Test_05()
{
	printf("TEST_05\n");


	int n = 10;


	printf("%d\n", febNumN_1(n));
	printf("%d\n", febNumN_2(n));
}

long GetNN(int x, int count)
{
	long ret = x;
	int i = 0;
	for (i = 1; i < count; i++)
	{
		ret *= x;
	}
	return ret;
}

//��ӡˮ�ɻ���
void Test_04()
{
	printf("TEST_04\n");


	//������ֵ
	long long i = 0;
	for (i = 0; i <= 100000; i++)
	{
		int temp = i;
		int sum = 0;


		int count = 0;
		do {
			temp /= 10;
			count++;
		} while (temp > 0);


		temp = i;


		do {
			//ÿһλ�Ļ�ȡ
			int tempBaseNum = temp % 10;


			//ÿһλ��n�η���
			sum += GetNN(tempBaseNum, count);


			//λ�ƶ�
			temp /= 10;
		} while (0 < temp);
		if (sum == i)
		{
			printf("%lld ", i);
		}
	}


}

//��ӡ����
void Test_03()
{
	printf("TEST_03\n");


	const signed int cLineCount = 13;
	int i = 0;
	int ctrl = cLineCount / 2;
	int flag = -1;
	for (i = 0; i < cLineCount; i++)
	{
		int j = 0;
		for (j = 0; j < cLineCount; j++)
		{
			//                  *
			//                 ***
			//                *****
			//                 ***
			//                  *
			if (j >= ctrl && j < cLineCount - ctrl)
			{
				putchar('*');
			}
			else
			{
				putchar(' ');
			}
		}
		putchar('\n');


		if (ctrl == 0)
		{
			//�ֱ��ӡ����������
			flag = 1;
		}


		ctrl += flag;
	}
	putchar('\n');
}

//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Ժȶ�����ˮ�����ʵ�֣���
void Test_02()
{
	printf("TEST_02\n");


	const int nPrice = 1;


	int money = 20;
	int count = 0;
	int cEmptyBottle = 0;


	for (money = 20; money; money--)
	{
		cEmptyBottle++;
		count++;


		//���ĵ����п������ĵĿ�ƿ
		while (cEmptyBottle >= 2)
		{
			//��ƿ�滻�ٺȵ������Ŀ�ƿ����
			int temp = cEmptyBottle / 2;
			//�ȵ�����ˮ����������
			count += temp;


			//��ƿ��������
			cEmptyBottle %= 2;
			cEmptyBottle += temp;
		}
	}


	printf("���Ժ� %d ƿ��ˮ\n", count);
}

void Test_01()
{
	printf("TEST_01\n");
	int a = 0, b = 0;
	for (a = 1, b = 1; a <= 100; a++)
	{
		if (b >= 20) break;
		if (b % 3 == 1)
		{
			b = b + 3;
			continue;
		}
		b = b - 5;
	}
	printf("%d\n", a);
}

int main()
{
	//Test_01();
	//Test_02();
	//Test_03();
	//Test_04();
	//Test_05();
	//Test_06();
	//Test_07();
	//Test_08();
	//Test_09();
	//Test_10();
	//Test_11();
	//Test_12();
	//Test_13();
	//Test_14();
	//Test_15();
	//Test_16();
	//Test_17();
	//Test_18();
	//Test_19();
	//Test_20();
	//Test_21();
	//Test_22();
	Test_23();
	//Test_24();
	//Test_25();
	//Test_26();
	//Test_27();


	return 0;
}