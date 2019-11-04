#include<graphics.h>
#include<time.h>
int main()
{
    int gd,gm;
    gd=DETECT;
    initgraph(&gd,&gm,"");

    //used for getting graph height and width
    int midx=getmaxx()/4;
    int midy=getmaxy()/4;
    //used for taking current time
    time_t t1;
    struct tm *data;
    char str[100];
    // loop will be run untill we press keyboard
    while(!kbhit())
    {
        line(0,midy-20,midx*4,midy-20);
        line(0,midy*2,midx*4,midy*2);
        //storing local time in data
        t1=time(NULL);
        data=localtime(&t1);

        //used for convert different value to string
        strftime(str,100,"%I : %M : %S",data);
        //color set
        setcolor(14);
        //changing font and it's size
        settextstyle(SANS_SERIF_FONT,0,7);
        //printing str in graph
        outtextxy(midx,midy,str);
        //used for convert different value to string
        strftime(str,100,"%p",data);
        //changing font and it's size
        settextstyle(SANS_SERIF_FONT,0,2);
        //printing str in graph
        outtextxy(midx+315,midy+10,str);
        //converting date to string
        strftime(str,100,"%a , %d %b 20%y",data);
        //changing font and it's size
        setcolor(11);
        settextstyle(SANS_SERIF_FONT,0,4);
        //printing str in graph
        outtextxy(midx+10,midy*1.5,str);
        //timer for 1 second
        Sleep(1000);
        //clearing screen
        cleardevice();
    }
    getch();
    closegraph();

    return 0;
}

