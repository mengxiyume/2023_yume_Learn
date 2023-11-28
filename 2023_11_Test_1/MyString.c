#define _CRT_SECURE_NO_WARNINGS 1

#include <stdlib.h>
#include <assert.h>

size_t MyStrlen(const char* src)
{
	assert(src);
	char* end = src;

	while (*end++);
	return end - src - 1;
}

char* MyStrcpy(char* destination, const char* source)
{
	assert(destination);
	assert(source);

	char* d = destination;
	char* s = source;

	while (*s)
	{
		*d++ = *s++;
	}
	*d = '\0';

	return destination;
}

int MyStrcmp(const char* str1, const char* str2)
{
	assert(str1);
	assert(str2);

	while (*str1 && *str2)
	{
		if (*str1++ != *str2++)
			return *(str1 - 1) - *(str2 - 1);
	}

	return *str1 - *str2;
}

char* MyStrcat(char* destination, const char* source)
{
	assert(destination);
	assert(source);
	//Æ´½Ó×Ö·û´®
	char* retBegin = destination;

	while (*destination++);
	destination--;

	while (*destination++ = *source++);
	*destination = '\0';

	return retBegin;
}

char* MyStrstr(char* str1, const char* str2)
{
	assert(str2);
	static char* begin = NULL;

	if (str1)
		begin = str1;
	if (NULL == begin)
		return NULL;

	char* tempBegin = begin;
	while (*tempBegin)
	{
		char* tempStr2 = str2;
		while (*tempStr2)
		{
			if (*tempBegin == *tempStr2)
			{
				*tempBegin++ = '\0';
				char* ret = begin;
				begin = tempBegin;
				return ret;
			}
			tempStr2++;
		}
		tempBegin++;
	}
	if (begin)
	{
		char* ret = begin;
		begin = NULL;
		return ret;
	}
	else
	{
		return NULL;
	}

}