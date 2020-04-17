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


#define MAP_WIDTH 60
#define MAP_HEIGHT 20

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
    
    while (1)
    {

    }
    return 0;
}
