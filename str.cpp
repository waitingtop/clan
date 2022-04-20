#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
#include <cassert>
#include <cstring>
using namespace std;

// ���Ȳ�������
/*int my_strlen(const char* str)
{
	assert(str != nullptr);
	int cnt = 0;
	while (*str)
	{
		++cnt, ++str;
	}
	return cnt;
}*/

/*int my_strlen(const char* str)
{
	assert(str != nullptr);
	if (*str) return 1 + my_strlen(str + 1);
	else return 0;
}*/

int my_strlen(const char* str)
{
	assert(str != nullptr);
	const char* end = str;
	while (*end) ++end;
	return end - str;
}

/* 
*	�ַ������� 
*	ԭ�ַ���'\0'����
*	Ŀ��ռ��㹻�󣬲��ҿɱ�
*/	
char* my_strcpy(char* dest, const char* src)	
{
	assert(src != nullptr);
	char* res = dest;
	while (*dest++ = *src++);
	return res;
}

/*
*	�ַ���׷��
*	ԭ�ַ���'\0'����
*	Ŀ��ռ��㹻�󣬲��ҿɱ�
*/
char* my_strcat(char* dest, const char* src)
{
	assert(dest && src);
	char* res = dest;
	while (*dest) ++dest;
	while (*dest++ = *src++);
	return res;
}

/*
*	�ַ����ȽϺ���
*	��һ���ַ������ڵڶ����ַ���, ���ش���0������
*	���, ����0
*	С��, ����С��0������
*/

int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1 == *str2)
	{
		if (*str1 == '\0') return 0;
		++str1;
		++str2;
	}
	return *str1 - *str2;
}

// ���������Ƶ��ַ�������

char* my_strncpy(char* dest, const char* src, size_t count)
{
	assert(dest && src);
	char* start = dest;
	while (count && (*dest++ = *src++))
		--count;
	if (count)
		while (count--)
			*dest++ = '\0';
	return start;
}

char* my_strncat(char* front, const char* back, size_t count)
{
	assert(front && back);
	char* start = front;
	while (*front) ++front;
	while (count--)
	{
		if ((*front++ = *back++) == 0) return start;
	}
	*front = '\0';
	return start;
}

int my_strncmp(const char* str1, const char* str2, size_t num)
{
	assert(str1 && str2);
	while (num && (*str1 == *str2))
	{
		if (*str1 == '\0') return 0;
		--num;
		++str1, ++str2;
	}
	if (*str1 == *str2) return 0;
	return *str1 - *str2 < 0 ? -1 : 1;
}

char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	if (*str2 == '\0') return (char*)str1;
	const char* s1 = nullptr;
	const char* s2 = nullptr;
	const char* cp = str1;
	while (*cp)
	{
		s1 = cp;
		s2 = str2;
		while (*s1 && *s2 && (*s1 == *s2))
		{
			++s1, ++s2;
		}
		if (*s2 == '\0') return (char*)cp;
		++cp;
	}
	return nullptr;
}



int main()
{
	char arr1[] = "abcdf";
	char arr2[] = "df";
	auto ret = my_strstr(arr1, arr2);
	if (ret)
		cout << "�ҵ���" << ret << endl;
	else cout << "û�ҵ�" << endl;
	return 0;
}