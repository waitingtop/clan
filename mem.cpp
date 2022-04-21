#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cassert>
using namespace std;

// �ڴ��������
// memecpy - �ڴ濽��  Ӧ�ÿ������ص����ڴ�
void* my_memcpy(void* dest, const void* src, size_t num)
{
	assert(dest && src);
	void* ret = dest;
	while (num--)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return ret;
}

// memmove - ���Դ����ڴ��ص������
void* my_memmove(void* dest, const void* src, size_t num)
{
	assert(dest && src);
	void* ret = dest;
	if (dest < src)
	{
		// ǰ -> ��
		while (num--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		// �� -> ǰ
		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);
		}
	}
	return ret;
}

int main()
{
	char arr1[] = { 1, 2, 3, 4 , 5};
	char arr2[6] = { 0 };
	my_memcpy(arr2, arr1, 20);
	return 0;
}
