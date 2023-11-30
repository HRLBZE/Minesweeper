#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include<windows.h> 
#include<conio.h>
#include<graphics.h>
#include<ctime>

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

void Derm(int length, int width, char str[][128], char str1[][128])
{
	int length1, width1;
	for (length1 = 0; length1 < length; length1++)
	{
		for (width1 = 0; width1 < width; width1++)
		{
			str1[length1][width1] = str[length1][width1];
			if (str[length1][width1] == '1')
				str1[length1][width1] = str1[length1][width1] - '1' + 'a';
		}
	}
	for (length1 = 0; length1 < length; length1++)
	{
		for (width1 = 0; width1 < width; width1++)
		{
			if (str[length1][width1] == '0')
			{
				if (length1 == 0 && width1 == 0)//左上
				{
					if (str[length1][width1 + 1] == '1')
						str1[length1][width1]++;
					if (str[length1 + 1][width1] == '1')
						str1[length1][width1]++;
					if (str[length1 + 1][width1 + 1] == '1')
						str1[length1][width1]++;
				}
				if (length1 == 0 && (width1 != 0 && width1 != width - 1))//上
				{
					if (str[length1][width1 - 1] == '1')
						str1[length1][width1]++;
					if (str[length1 + 1][width1] == '1')
						str1[length1][width1]++;
					if (str[length1][width1 + 1] == '1')
						str1[length1][width1]++;
					if (str[length1 + 1][width1 + 1] == '1')
						str1[length1][width1]++;
					if (str[length1 + 1][width1 - 1] == '1')
						str1[length1][width1]++;
				}
				if (length1 == 0 && width1 == width - 1) //右上
				{
					if (str[length1][width1 - 1] == '1')
						str1[length1][width1]++;
					if (str[length1 + 1][width1] == '1')
						str1[length1][width1]++;
					if (str[length1 + 1][width1 - 1] == '1')
						str1[length1][width1]++;
				}
				if ((length1 != 0 && length1 != length - 1) && width1 == width - 1)//右
				{
					if (str[length1 - 1][width1] == '1')
						str1[length1][width1]++;
					if (str[length1 + 1][width1] == '1')
						str1[length1][width1]++;
					if (str[length1][width1 - 1] == '1')
						str1[length1][width1]++;
					if (str[length1 - 1][width1 - 1] == '1')
						str1[length1][width1]++;
					if (str[length1 + 1][width1 - 1] == '1')
						str1[length1][width1]++;
				}
				if (length1 == length - 1 && width1 == 0) //左下
				{
					if (str[length1 - 1][width1] == '1')
						str1[length1][width1]++;
					if (str[length1 - 1][width1 + 1] == '1')
						str1[length1][width1]++;
					if (str[length1][width1 + 1] == '1')
						str1[length1][width1]++;
				}
				if ((length1 != 0 && length1 != length - 1) && width1 == 0)//左
				{
					if (str[length1 - 1][width1] == '1')
						str1[length1][width1]++;
					if (str[length1 + 1][width1] == '1')
						str1[length1][width1]++;
					if (str[length1][width1 + 1] == '1')
						str1[length1][width1]++;
					if (str[length1 - 1][width1 + 1] == '1')
						str1[length1][width1]++;
					if (str[length1 + 1][width1 + 1] == '1')
						str1[length1][width1]++;
				}
				if (length1 == length - 1 && width1 == width - 1) //右下
				{
					if (str[length1 - 1][width1] == '1')
						str1[length1][width1]++;
					if (str[length1 - 1][width1 - 1] == '1')
						str1[length1][width1]++;
					if (str[length1][width1 - 1] == '1')
						str1[length1][width1]++;
				}
				if (length1 == length - 1 && (width1 != 0 && width1 != width - 1))//下
				{
					if (str[length1][width1 - 1] == '1')
						str1[length1][width1]++;
					if (str[length1][width1 + 1] == '1')
						str1[length1][width1]++;
					if (str[length1 - 1][width1] == '1')
						str1[length1][width1]++;
					if (str[length1 - 1][width1 - 1] == '1')
						str1[length1][width1]++;
					if (str[length1 - 1][width1 + 1] == '1')
						str1[length1][width1]++;
				}
				if (length1 != 0 && length1 != length - 1 && width1 != 0 && width1 != width - 1)
				{
					if (str[length1 - 1][width1 - 1] == '1')//左上
						str1[length1][width1]++;
					if (str[length1 - 1][width1] == '1')//上
						str1[length1][width1]++;
					if (str[length1 - 1][width1 + 1] == '1')//右上
						str1[length1][width1]++;
					if (str[length1][width1 - 1] == '1')//左
						str1[length1][width1]++;
					if (str[length1][width1 + 1] == '1')//右
						str1[length1][width1]++;
					if (str[length1 + 1][width1 + 1] == '1')//右下
						str1[length1][width1]++;
					if (str[length1 + 1][width1 - 1] == '1')//左下
						str1[length1][width1]++;
					if (str[length1 + 1][width1] == '1')//下
						str1[length1][width1]++;
				}
			}
		}
	}
}

void Mine_sweeper_str(char str[][128], int length, int width, int bomb, char str1[][128])//分配1-9
{
	int length1 = 0;
	int width1 = 0;
	srand(time(NULL));
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
	for (; length1 < length; length1++)
	{
		for (width1 = 0; width1 < width; width1++)
		{
			if (str[length1][width1] != '0')
				str[length1][width1] = '1';
			else
				continue;
		}

	}
	Derm(length, width, str, str1);
}

void load_photo(IMAGE* A, int i, int width, int height)	//载入图片
{
	char name[64];
	sprintf(name, "picture/%d.png", i);
	if (i != 12 && i != 14)
		loadimage(A, name, 50, 50);
	else
		loadimage(A, name, width * 50, height * 50);
}

void put_photo(IMAGE A, int i, int weight_w, int height_h)	//放出图片
{
	putimage(weight_w, height_h, &A);
}

void init(int width, int length)
{
	initgraph(width * 50, length * 50, NULL);
}

void Recursive_0(char str[][128], int x, int y, int width, int length, IMAGE A[14])
{
	if (x + 1 < width)//向右
	{
		if (str[y][x + 1] == '0')
		{
			put_photo(A[0], 0, (x + 1) * 50, y * 50);
			str[y][x + 1] += '0';
			Recursive_0(str, x + 1, y, width, length, A);
		}
		else
		{
			if (str[y][x + 1] >= '1' && str[y][x + 1] <= '9')
			{
				int i = str[y][x + 1] - '0';
				put_photo(A[i], i, (x + 1) * 50, y * 50);
			}
		}
	}
	if (x - 1 >= 0)//左
	{
		if (str[y][x - 1] == '0')
		{
			put_photo(A[0], 0, (x - 1) * 50, (y) * 50);
			str[y][x - 1] += '0';
			Recursive_0(str, x - 1, y, width, length, A);
		}
		else
		{
			if (str[y][x - 1] >= '1' && str[y][x - 1] <= '9')
			{
				int i = str[y][x - 1] - '0';
				put_photo(A[i], i, (x - 1) * 50, (y) * 50);

			}
		}
	}
	if (y + 1 < length)//下
	{
		if (str[y + 1][x] == '0')
		{
			put_photo(A[0], 0, (x) * 50, (y + 1) * 50);
			str[y + 1][x] += '0';
			Recursive_0(str, x, y + 1, width, length, A);
		}
		else
		{
			if (str[y + 1][x] >= '0' && str[y + 1][x] <= '9')
			{
				int i = str[y + 1][x] - '0';
				put_photo(A[i], i, (x) * 50, (y + 1) * 50);
			}
		}
	}
	if (y - 1 >= 0)//上
	{
		if (str[y - 1][x] == '0')
		{
			put_photo(A[0], 0, (x) * 50, (y - 1) * 50);
			str[y - 1][x] += '0';
			Recursive_0(str, x, y - 1, width, length, A);
		}
		else
		{
			if (str[y - 1][x] >= '0' && str[y - 1][x] <= '9')
			{
				int i = str[y - 1][x] - '0';
				put_photo(A[i], i, (x) * 50, (y - 1) * 50);
			}
		}
	}
}


void Mouse(ExMessage& m, ExMessage& n, char str[128][128], IMAGE A[14], int width, int length, char str2[][128], int bomb)
{
	int der = 0;
	int der1 = 0;
	printf("if you want to exit,please click the mbuttondown\n");
	printf("and when you are sure you are right,you also need to click the mbuttondown");
	do
	{
		m = n;
		getmessage(&m, EM_MOUSE);
		if (m.message == WM_LBUTTONDOWN)
		{
			int c;
			int m_x1;
			int m_y1;
			m_x1 = m.x / 50;
			m_y1 = m.y / 50;
			c = str[m_y1][m_x1] - '0';
			str2[m_y1][m_x1] = str[m_y1][m_x1];
			if (c == 'a' - '0')
			{
				put_photo(A[10], 10, m_x1 * 50, m_y1 * 50);
				der = 1;
				break;
			}
			else
			{
				if (c == 0)
				{
					put_photo(A[c], c, m_x1 * 50, m_y1 * 50);
					Recursive_0(str, m_x1, m_y1, width, length, A);
				}
				else
				{
					put_photo(A[c], c, m_x1 * 50, m_y1 * 50);
				}
			}
		}
		if (m.message == WM_RBUTTONDOWN)
		{
			int c;
			int m_x1;
			int m_y1;
			m_x1 = m.x / 50;
			m_y1 = m.y / 50;
			put_photo(A[11], 11, m_x1 * 50, m_y1 * 50);
			str2[m_y1][m_x1] = 'a';
		}
	} while (m.message != WM_MBUTTONDOWN);

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (str[i][j] == 'a' && (str[i][j] == str2[i][j]))
			{
				der1++;
			}
		}
	}

	if (der == 1)
	{
		float sec = 1;
		clock_t delay = sec * CLOCKS_PER_SEC;
		clock_t start = clock();
		while (clock() - start < delay / 2)
			;
		put_photo(A[12], 12, 0, 0);
		while (clock() - start < delay * 3)
			;
	}
	if (der1 == bomb && der != 1)
	{
		float sec = 1;
		clock_t delay = sec * CLOCKS_PER_SEC;
		clock_t start = clock();
		while (clock() - start < delay / 2)
			;
		put_photo(A[14], 14, 0, 0);
		while (clock() - start < delay * 3)
			;
	}
}

int main()
{
	printf("将所有的雷排出后，需要按中键确认，如果中途出错，则游戏直接失败\n");
	ExMessage m;
	ExMessage n = { 0 };
	int m_x;
	int m_y;
	int bomb, length, width;
	int photo = 0;
	int weight_w = 0;
	int height_h = 0;
	char str[128][128] = { 0 };
	char str1[128][128] = { 0 };
	char str2[128][128] = { 0 };
	input_length(&length);
	input_width(&width);
	input_bomb(&bomb, length, width);
	Mine_sweeper_str(str, length, width, bomb, str1);
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			printf("%c", str1[i][j]);
		}
		putchar('\n');
	}
	IMAGE A[15];
	for (int i = 0; i < 15; i++)
	{
		load_photo(&A[i], i, width, length);
	}
	init(width, length);
	for (int i = 0; i < length; i++)//i is h,j is w
	{
		for (int j = 0; j < width; j++)
		{
			put_photo(A[13], 13, weight_w, height_h);
			weight_w += 50;
		}
		height_h += 50;
		weight_w = 0;
	}
	Mouse(m, n, str1, A, width, length, str2, bomb);
	closegraph();
	return 0;
}