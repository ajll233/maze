#include <stdio.h>
#include <getch.h>
#include <stdlib.h>
#include <time.h>
time_t  t1=0,t2=0;
int main(int argc,const char* argv[])
{
    char maze[10][10]={
    {'#','#','#','#','#','#','#','#','#','#'},
    {'#','#',' ','#','#','#','#','#','#','#'},
    {'#','#',' ','#','#','#','#','#','#','#'},
    {'#',' ',' ',' ',' ','#','#','#','#','#'},
    {'#',' ','#','#',' ','#','#','#','#','#'},
    {'#',' ','#','#',' ','#','#','#','#','#'},
    {'#',' ','#','#',' ',' ',' ',' ',' ',' '},
    {'#',' ','@','#','#','#','#','#','#','#'},
    {'#','#','#','#','#','#','#','#','#','#'},
    {'#','#','#','#','#','#','#','#','#','#'},
    };  
    //记录游戏开始时间
    t1=time(NULL);
    //记录角色的位置坐标
    char man_x=7,man_y=2;
     for(;;)
    {
        //清理屏幕
        system("clear");
        //显示地图
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                printf("%c ",maze[i][j]);
            }
            printf("\n");
        }
        //获取方向键
        switch(getch())
        {
            case 183:            //向上
                if(' '== maze[man_x-1][man_y])
                {
                    maze[man_x][man_y]=' ';
                    maze[--man_x][man_y]='@';
                }
                break;
            case 184:           //向下
                if(' '== maze[man_x+1][man_y])
                {
                    maze[man_x][man_y]=' ';
                    maze[++man_x][man_y]='@';
                }
                break;
            case 185:           //右
                if(' '== maze[man_x][man_y+1])
                {
                    maze[man_x][man_y]=' ';
                    maze[man_x][++man_y]='@';
                }
                break;
            case 186:           //左
                if(' '== maze[man_x][man_y-1])
                {
                    maze[man_x][man_y]=' ';
           }
                break;
        }
        //判断是否到达出口
        if(man_x==6 && man_y==9)
        {
            t2=time(NULL);
            system("clear");

            for(int i=0;i<10;i++)
            {
                for(int j=0;j<10;j++)
                {
                    printf("%c ",maze[i][j]);
                }
                printf("\n");
            }

            break;
        }
    }
    printf("游戏胜利！总共用时%lus\n",t2-t1);
}
                                          