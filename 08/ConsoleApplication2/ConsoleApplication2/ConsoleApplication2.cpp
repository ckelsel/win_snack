// ConsoleApplication2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <Windows.h>
#include<conio.h>
#define MAP_WIDTH 60
#define MAP_HEIGHT 20
struct snack
{
    // x坐标
    int x; 

    // y 坐标
    int y;

    // *或者@
    char ch;
};

// 结构体数组，代表蛇
struct snack g_snack[MAP_WIDTH * MAP_HEIGHT];

// 蛇实际的长度
int g_snack_length = 5; 


void SetPos(int x, int y)
{
    COORD point = { x, y };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, point);
}

void DrawSnack()
{
    for (int i = 0; i < g_snack_length; i++)
    {
        // 设置光标到(0,0)位置
        SetPos(g_snack[i].x, g_snack[i].y);

        // 绘制贪吃蛇  *****
        printf("%c", g_snack[i].ch);
    }
    
}


void HiddenCursor()
{
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    GetConsoleCursorInfo(hout, &info);
    info.bVisible = FALSE;
    SetConsoleCursorInfo(hout, &info);
}

int main()
{
    // 隐藏光标

    HiddenCursor();

    //[0,21)
    for (int j = 0; j < MAP_HEIGHT + 1; j++)
    {
        if (j == MAP_HEIGHT)
        {
            // 绘制一行
            for (int i = 0; i < MAP_WIDTH; i++)
            {
                printf("-");
            }
            printf("\n");

        }
        else
        {
            // 绘制空行
            for (int i = 0; i < MAP_WIDTH; i++)
            {
                printf(" ");
            }
            printf("|");
            printf("\n");
        }
        
    }
    
    g_snack_length = 5;

    g_snack[0].x = 0;
    g_snack[0].y = 0;
    g_snack[0].ch = '*';
    
    g_snack[1].x = 1;
    g_snack[1].y = 0;
    g_snack[1].ch = '*';

    g_snack[2].x = 2;
    g_snack[2].y = 0;
    g_snack[2].ch = '*';

    g_snack[3].x = 3;
    g_snack[3].y = 0;
    g_snack[3].ch = '*';

    g_snack[4].x = 4;
    g_snack[4].y = 0;
    g_snack[4].ch = '@';
    
    // 绘制贪吃蛇  *****
    DrawSnack();

   

    

    while (1)
    {
        // 向右移动一格
        // (0,0) (1,0), (2,0), (3,0), (4,0)@
        //       (1,0), (2,0), (3,0), (4,0), (5,0)@

        // 清除尾坐标
        SetPos(g_snack[0].x, g_snack[0].y);
        putchar(' ');

        // [0,5)
        for (int i = 0; i < g_snack_length - 1; i++)
        {
            g_snack[i].x = g_snack[i + 1].x;
            g_snack[i].y = g_snack[i + 1].y;
        }

        int key = _getch();
        switch (key)
        {
        case 'w':// 上
            //printf("上");
            g_snack[g_snack_length - 1].y -= 1;

            break;
        case 'a':// 左
            //printf("左");
            g_snack[g_snack_length - 1].x -= 1;

            break;
        case 's':// 下
            // printf("下");
            g_snack[g_snack_length - 1].y += 1;

            break;
        case 'd':// 右
            //printf("右");
            g_snack[g_snack_length - 1].x += 1;
            break;
        }


        // 绘制贪吃蛇  *****
        DrawSnack();


        // 判断是否撞墙
        if ((g_snack[g_snack_length - 1].x == MAP_WIDTH) ||
            (g_snack[g_snack_length - 1].y == MAP_HEIGHT) ||
            (g_snack[g_snack_length - 1].x < 0) ||
            (g_snack[g_snack_length - 1].y < 0))
        {
            // 退出while循环
            break;
        }
    }
    return 0;
}
