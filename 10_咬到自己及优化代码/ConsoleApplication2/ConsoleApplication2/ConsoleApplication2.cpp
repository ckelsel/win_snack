//
//  ConsoleApplication2.cpp
//
//  Created by XieKunming on 2020/04/17
//  Copyright (C) 2020 谢昆明——编程一学就会 All rights reserved.
//
// 谢昆明——编程一学就会
// QQ群：1054773066
// 邮箱：124116614@qq.com
//

#include <stdio.h>
#include <Windows.h>
#include<conio.h>
#include <time.h>
#define MAP_WIDTH 60
#define MAP_HEIGHT 20
struct object
{
    // x坐标
    int x; 

    // y 坐标
    int y;

    // *或者@或者#
    char ch;
};

// 结构体数组，代表蛇
struct object g_snack[MAP_WIDTH * MAP_HEIGHT];

// 蛇实际的长度
int g_snack_length = 5; 

// 食物
struct object g_food;

void SetPos(int x, int y)
{
    COORD point = { x, y };
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, point);
}


void DrawFood()
{
    // 设置光标到位置
    SetPos(g_food.x, g_food.y);

    // 绘制#
    printf("%c", g_food.ch);
}

void DrawSnack()
{
    for (int i = 0; i < g_snack_length; i++)
    {
        // 设置光标到位置
        SetPos(g_snack[i].x, g_snack[i].y);

        // 绘制贪吃蛇  *****
        printf("%c", g_snack[i].ch);
    }
    
}


void HideCursor()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
    CursorInfo.bVisible = false; //隐藏控制台光标
    SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态

}

// 绘制地图
void DrawMap()
{
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
}

// 初始化地图和食物
void InitFoodAndSnack()
{

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

    // 绘制食物
    g_food.x = 10;
    g_food.y = 0;
    g_food.ch = '#';

    DrawFood();
}


void EatFood(int x, int y)
{
    if ((g_snack[g_snack_length - 1].x == g_food.x) &&
        (g_snack[g_snack_length - 1].y == g_food.y))
    {
        // (0,0) (1,0), (2,0), (3,0), (4,0)@ (5, 0)#
        //       (1,0), (2,0), (3,0), (4,0), (5,0), (6,0)@,蛇的头部添加节点，错误
        //  0     1      2      3       4    5
        // (0,0) (1,0), (2,0), (3,0), (4,0), (5,0)@ 蛇的尾部添加节点
        //       0       1     2      3      4     5
        //      (1,0), (2,0), (3,0), (4,0), (5,0)  (x,x)
        g_snack_length++;
        for (int i = g_snack_length - 1; i > 0; i--)
        {
            // 移动数组元素
            g_snack[i].x = g_snack[i - 1].x;
            g_snack[i].y = g_snack[i - 1].y;
            g_snack[i].ch = g_snack[i - 1].ch;

        }
        // 尾坐标
        g_snack[0].x = x;
        g_snack[0].y = y;
        g_snack[0].ch = '*';

        // 随机生成新的食物
        g_food.x = rand() % MAP_WIDTH;
        g_food.y = rand() % MAP_HEIGHT;

        DrawFood();
    }
}

int EatSelf()
{
    for (int i = 0; i < g_snack_length - 1; i++)
    {
        if ((g_snack[g_snack_length - 1].x == g_snack[i].x) &&
            (g_snack[g_snack_length - 1].y == g_snack[i].y))
        {
            // 咬到自己
            return -1;
        }
    }
    return 0;
}

void PlayGame()
{
    // 主循环
    while (1)
    {
        // 向右移动一格
        // (0,0) (1,0), (2,0), (3,0), (4,0)@
        //       (1,0), (2,0), (3,0), (4,0), (5,0)@

        int tail_x = g_snack[0].x;
        int tail_y = g_snack[0].y;

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

        // 清除尾坐标
        SetPos(tail_x, tail_y);
        putchar(' ');

        // 绘制贪吃蛇  *****
        DrawSnack();


        // 贪吃蛇撞墙
        if ((g_snack[g_snack_length - 1].x == MAP_WIDTH) ||
            (g_snack[g_snack_length - 1].x < 0) ||
            (g_snack[g_snack_length - 1].y < 0) ||
            (g_snack[g_snack_length - 1].y == MAP_HEIGHT))
        {
            // 退出while循环，游戏结束
            break;
        }


        // 贪吃蛇吃食物
        EatFood(tail_x, tail_y);

        // 贪吃蛇咬到自己gg
        if (EatSelf() < 0)
        {
            // 退出while循环，游戏结束
            break;
        }
    }
}

int main()
{
    // 初始化随机数种子
    srand((unsigned int)time(NULL));

    // 隐藏光标
    HideCursor();

    // 绘制地图
    DrawMap();
    
    // 在地图上显示贪吃蛇和食物
    InitFoodAndSnack();
    
    // 开始游戏
    PlayGame();

    return 0;
}












