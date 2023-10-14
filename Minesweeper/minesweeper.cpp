#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include<windows.h> 
#include<conio.h>
#include<graphics.h>

void input_length(int* length)//输入长
{
	puts("please input the length of rectangle,and the length shouldn't beyond 120,and you'd better input a number bigger than 2");
	do
	{
		scanf_s("%d", length);
		if (*length > 120)
			puts("please repeat your input");
	} while (*length > 120);
}

void input_width(int* width)//输入宽
{
	puts("please input the width of rectangle,and the length shouldn't beyond 120,and you'd better input a number bigger than 2");
	do
	{
		scanf_s("%d", width);
		if (*width > 120)
			puts("please repeat your input");
	} while (*width > 120);
}

void input_bomb(int* bomb, int length, int width)//输入炸弹
{
	do
	{
		puts("please input the number of bombs,and the number shouldn't beyond the multiplication of the length and the width");
		scanf_s("%d", bomb);
		if (*bomb > (length * width))
			puts("please repeat your input");
	} while (*bomb > (length * width));
}

void Mine_sweeper_str(char str[][128], int length, int width, int bomb)//分配1-9
{
	srand(time(NULL));
	//num=a+(b-a+1)*rand()/(RAND-MAX+1.0)；
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

typedef struct
{
	IMAGE picture;
	double x;
	double y;
}photos;

void loadphoto(photos* a, int i)//载入图画
{
	char name[64];
	sprintf(name, "picture/%d.png", i);
	loadimage(&a->picture, name, 50, 50);
}

void putphoto(photos* a, int weight, int height)//放出图画
{
	putimage(weight, height, &a->picture);
}

void init(int width, int length)
{
	initgraph(width * 50, length * 50, NULL);
}

int main()
{
	int bomb, length, width;
	int photo = 0;
	int weight_w = 0;
	int height_h = 0;
	char str[128][128] = { 0 };
	input_length(&length);
	input_width(&width);
	input_bomb(&bomb, length, width);
	Mine_sweeper_str(str, length, width, bomb);
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			printf("%c", str[i][j]);
		}
		putchar('\n');
	}
	photos* pho[10];
	for (int i = 0; i < 10; i++)
	{
		pho[i] = new photos;
		loadphoto(pho[i], i);
	}
	init(width, length);

	for (int i = 0; i < length; i++)//i is weight,j is height
	{
		for (int j = 0; j < width; j++)
		{
			int c = str[i][j] - '0';
			putphoto(pho[c], weight_w, height_h);
			weight_w += 50;
		}
		height_h += 50;
		weight_w = 0;
	}
	system("pause");
	getchar();
	closegraph();
	return 0;
}