#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void Test_11()
{
	printf("TEST_11\n");
	//再写点测试用
	//再再写点测试用
}

//求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，
//
//例如：2 + 22 + 222 + 2222 + 22222
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

//递归打印一个数的每一位
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

//用递归与非递归实现阶乘
void Test_08()
{
	printf("TEST_08\n");


	printf("%lld\n", factorial1(0));
	printf("%lld\n", factorial2(0));
}

//写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和
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

//计算n的k次方
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

//斐波那契数列（Fibonacci sequence），又称黄金分割数列，因数学家莱昂纳多·斐波那契（Leonardo Fibonacci）以兔子繁殖为例子而引入，故又称“兔子数列”，
//其数值为：1、1、2、3、5、8、13、21、34……在数学上，这一数列以如下递推的方法定义：F(0) = 1，F(1) = 1, F(n) = F(n - 1) + F(n - 2)

int febNumN_1(int n)
{
	//递归法
	int ret = 1;


	if (n >= 3)
	{
		//递归累加
		ret = febNumN_1(n - 1) + febNumN_1(n - 2);
	}


	return ret;
}

int febNumN_2(int n)
{
	//循环法
	int n_1 = 1;
	int n_2 = 1;


	int ret = 1;


	int i = 3;
	for (i = 3; i <= n; i++)
	{
		//数值位置区域点移动
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

//打印水仙花数
void Test_04()
{
	printf("TEST_04\n");


	//产生数值
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
			//每一位的获取
			int tempBaseNum = temp % 10;


			//每一位的n次方和
			sum += GetNN(tempBaseNum, count);


			//位移动
			temp /= 10;
		} while (0 < temp);
		if (sum == i)
		{
			printf("%lld ", i);
		}
	}


}

//打印菱形
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
			//分别打印两个三角形
			flag = 1;
		}


		ctrl += flag;
	}
	putchar('\n');
}

//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以喝多少汽水（编程实现）。
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


		//消耗掉所有可以消耗的空瓶
		while (cEmptyBottle >= 2)
		{
			//空瓶替换再喝掉产生的空瓶处理
			int temp = cEmptyBottle / 2;
			//喝掉的汽水的数量增加
			count += temp;


			//空瓶数量更新
			cEmptyBottle %= 2;
			cEmptyBottle += temp;
		}
	}


	printf("可以喝 %d 瓶汽水\n", count);
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
	Test_11();
	return 0;
}