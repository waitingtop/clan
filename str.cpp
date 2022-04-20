#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstring>
#include <cassert>
#include <cstring>
using namespace std;

// 长度不受限制
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
*	字符串拷贝 
*	原字符以'\0'结束
*	目标空间足够大，并且可变
*/	
char* my_strcpy(char* dest, const char* src)	
{
	assert(src != nullptr);
	char* res = dest;
	while (*dest++ = *src++);
	return res;
}

/*
*	字符串追加
*	原字符以'\0'结束
*	目标空间足够大，并且可变
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
*	字符串比较函数
*	第一个字符串大于第二个字符串, 返回大于0的数字
*	相等, 返回0
*	小于, 返回小于0的数字
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

// 长度受限制的字符串函数

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
		cout << "找到了" << ret << endl;
	else cout << "没找到" << endl;
	return 0;
}