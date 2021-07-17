#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int Func(int(*arr)[4], int target)
{
	int i = 0, j = 3;
	while (i < 4 && j >= 0)
	{
		if (target < arr[i][j])
			j--;
		if (target > arr[i][j])
			i++;
		if (target == arr[i][j])
			return 1;
	}
	return 0;
}

int main(void)
{
	int arr[4][4] = {1,2,8,9,
					 2,4,9,12,
					 4,7,10,13,
					 6,8,11,15};
	int target = 0;
	printf("请输入一个整数：\n");
	scanf("%d", &target);
	int ret = Func(arr, target);
	if (ret)
	{
		printf("找到了！");
	}
	else
	{
		printf("没找到");
	}
	return 0;
}