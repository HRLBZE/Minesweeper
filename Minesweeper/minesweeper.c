#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
void input_length(int* length)
{
	puts("please input the length of rectangle,and the length shouldn't beyond 120");
	do
	{
		scanf_s("%d", length);
		if (*length > 120)
			puts("please repeat your input");
	} while (*length > 120);
}

void input_width(int* width)
{
	puts("please input the width of rectangle,and the length shouldn't beyond 120");
	do
	{
		scanf_s("%d", width);
		if (*width > 120)
			puts("please repeat your input");
	} while (*width > 120);
}


void input_bomb(int* bomb, int length, int width)
{
	do
	{
		puts("please input the number of bombs,and the number shouldn't beyond the multiplication of the length and the width");
		scanf_s("%d", bomb);
		if (*bomb > (length * width))
			puts("please repeat your input");
	} while (*bomb > (length * width));
}

void Mine_sweeper_str(char str[][128], int length, int width, int bomb)
{
	//num=a+(b-a+1)*rand()/(RAND-MAX+1.0)£»
	for (; bomb > 0; bomb--)
	{
		int lon_str = 0 + ((length - 1) - 0 + 1) * rand() / (RAND_MAX + 1.0);
		int wid_str = 0 + ((width - 1) - 0 + 1) * rand() / (RAND_MAX + 1.0);
		int num = 1 + (9 - 1 + 1) * rand() / (RAND_MAX + 1.0);
		if (isprint(str[lon_str][wid_str]))
		{
			bomb++;
			continue;
		}
		else
		{
			str[lon_str][wid_str] = num + '0';
		}
	}
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (isprint(str[i][j]))
			{
				continue;
			}
			else
			{
				str[i][j] = '0';
			}
		}
	}
}
int main()
{
	int bomb, length, width;
	char str[128][128] = { 0 };
	input_length(&length);
	input_width(&width);
	input_bomb(&bomb, length, width);
	Mine_sweeper_str(str, length, width, bomb);
	//printf("%d %d %d", length, width, bomb);
	printf("%c %c %c %c", str[0][0], str[0][1], str[1][0], str[1][1]);
	return 0;
}