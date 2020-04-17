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


int main()
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

    }
    return 0;
}
