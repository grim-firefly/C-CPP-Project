#include<graphics.h>
#include<stdio.h>
int midx,midy;
int midx3_2,midy3_2;
void downline()
{
    setlinestyle(0,0,3);
    line(0,midy3_2,midx*2,midy3_2);
    setlinestyle(0,0,1);
}
void girl()
{
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,5);
    //woman belly
    line(midx3_2,midy3_2-20,midx3_2+20,midy3_2-20);
    line(midx3_2,midy3_2-20,midx3_2+10,midy3_2-50);
    line(midx3_2+20,midy3_2-20,midx3_2+10,midy3_2-50);
    floodfill(midx3_2+10,midy3_2-21,WHITE);
    //woman leg
    line(midx3_2+5,midy3_2-20,midx3_2+3,midy3_2);
    line(midx3_2+15,midy3_2-20,midx3_2+15,midy3_2);
    //woman chest
    line(midx3_2+10,midy3_2-70,midx3_2+10,midy3_2-50);
    line(midx3_2+10,midy3_2-50,midx3_2,midy3_2-60);
    line(midx3_2+10,midy3_2-50,midx3_2+20,midy3_2-60);
    line(midx3_2,midy3_2-60,midx3_2+10,midy3_2-70);
    line(midx3_2+20,midy3_2-60,midx3_2+10,midy3_2-70);
    //woman face
    circle(midx3_2+10,midy3_2-82,12);
    //woman eye
    circle(midx3_2+4,midy3_2-85,3);
    circle(midx3_2+15,midy3_2-85,3);
    line(midx3_2+8,midy3_2-76,midx3_2+12,midy3_2-76);
    //woman hair

    line(midx3_2-5,midy3_2-70,midx3_2+25,midy3_2-70);
    ellipse(midx3_2+10,midy3_2-80,-25,205,17,23);



}
void man(int i,int spedd)
{
// man face
    circle(20+i,midy3_2-90,12);
    //man eye
    circle(25+i,midy3_2-93,3);
    //man mouth
    line(24+i,midy3_2-86,27+i,midy3_2-86);
//        man chest
    line(20+i,midy3_2-30,20+i,midy3_2-78);
    //man hand
    line(30+i,midy3_2-60,20+i,midy3_2-78);
    line(30+i,midy3_2-60,40+i,midy3_2-68);
    line(40+i,midy3_2-68,40+i,midy3_2-78);
    //flower
    circle(40+i,midy3_2-80,3);
    circle(44+i,midy3_2-80,3);
    circle(36+i,midy3_2-80,3);
    circle(40+i,midy3_2-83,3);
//        man leg
    line(20+i,midy3_2-30,12+i+spedd,midy3_2);
    line(20+i,midy3_2-30,28+i-spedd,midy3_2);

}
void textandheart(int i)
{
    //massage
    setcolor(3);
    outtextxy(midx3_2-70,midy3_2-160,"I LOVE YOU :) ");
    setcolor(4);
    ellipse(midx3_2-25,midy3_2-155,0,360,70,24);
    line(25+i,midy3_2-100,midx3_2-30,midy3_2-130);
    setcolor(WHITE);
    //heart
    setfillstyle(SOLID_FILL,RED);
    arc(i+60,midy3_2-100,0,180,5);
    arc(i+70,midy3_2-100,0,180,5);
    line(i+60+5,midy3_2-90,i+55,midy3_2-100);
    line(i+60+5,midy3_2-90,i+75,midy3_2-100);
    floodfill(i+60+1,midy3_2-100,WHITE);
    setcolor(WHITE);

}
int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    midx=getmaxx()/2;
    midy=getmaxy()/2;
    midx3_2=midx+midx/2;
    midy3_2=midy+midy/2;
    downline();
    girl();
    int spedd=0;
    int i;
    for(i=0; i<=midx3_2-100; i++)
    {

        cleardevice();
        downline();
        girl();
        man(i,spedd);
        spedd+=1;
        spedd*= spedd >5 ? -1: 1;

        Sleep(50);

    }
    textandheart(i);
    getch();
    closegraph();
    return 0;
}
