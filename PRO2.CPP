#include<conio.h>
#include<iostream.h>
#include<stdio.h>
#include <graphics.h>
#include <stdlib.h>
void main()
{
char c,k='@',s[20],m,a[10],b[10],d;
int x,i=0,j=0,re=0,l,n=1,e,y;
int gdriver = EGA, gmode = EGAHI, errorcode;
int left,right,top,bottom;
char msg[80];
initgraph(&gdriver, &gmode, "..//bgi");
errorcode = graphresult();
if (errorcode != grOk)  /* an error occurred */
{
    printf("Graphics error: %s\n", grapherrormsg(errorcode));
    printf("Press any key to halt:");
    getch();
    exit(1); /* terminate with an error code */
}
setbkcolor(6);
setcolor(RED);
settextjustify(CENTER_TEXT, CENTER_TEXT);
settextstyle(1, HORIZ_DIR,10);
outtextxy(325,150, "QUIZ");
getch();


setcolor(BLUE);
FILE *fp,*fp1;
clrscr();
fp=fopen("stud.txt","r");
printf("enter your name with .txt extension\n");
scanf("%s",&s);
fp1=fopen(s,"w");
c=fgetc(fp);
for(l=0;l<4;l++)
{
setbkcolor(1);
clrscr();
setcolor(BLACK);
settextjustify(CENTER_TEXT, CENTER_TEXT);
settextstyle(3, HORIZ_DIR,5);
sprintf(msg,"ROUND - %d",l+1);
outtextxy(325,150,msg);
getch();
i=0;
re=0;
setbkcolor(MAGENTA);
for(j=0;j<10;j++)
{
clrscr();
printf("%d)",j+1);
while(c!=k)
{
c=fgetc(fp);
printf("%c",c);
fputc(c,fp1);
}
c=fgetc(fp);
a[i]=c;
printf("\nans:  ");
fflush(stdin);
scanf("%c",&b[i]);
fputc(b[i],fp1);
c=fgetc(fp);
i++;
}
clrscr();
cout<<"Do you want to recheck your answers(Y/N) : ";
cin>>m;
switch(m)
{
case 'Y':
case 'y':
while(n)
{
clrscr();
for(e=1;e<=10;e++)
cout<<"\t"<<e<<"\t";
cout<<"enter the que no you want to verify and 10 to get the final results";
cin>>n;
fseek(fp,0,SEEK_SET);
y=0;
while(y!=(l*10)+n-1)
{
d=fgetc(fp);
if(d==k)
y++;
}
if(n==10)
break;
c=fgetc(fp);
printf("%d)",n);
while(c!=k)
{
c=fgetc(fp);
printf("%c",c);
}
c=fgetc(fp);
printf("\nans:  ");
fflush(stdin);
scanf("%c",&b[n-1]);
}
break;
case 'N':
case 'n':
break;
}
clrscr();
//settextjustify(RIGHT_TEXT,CENTER_TEXT);
settextstyle(12, HORIZ_DIR,1);

printf("     Correct  Your \n     answer  answer\n\n\n");
for(i=0;i<9;i++)
{
cout<<endl;
if(a[i]==b[i])
{
setcolor(2);
sprintf(msg,"0%d)   %c    ,   %c ",i+1,a[i],b[i]);
outtextxy(70,50+(i*13), msg);
re++;
}
else
{
setcolor(4);
sprintf(msg,"0%d)   %c    ,   %c ",i+1,a[i],b[i]);
outtextxy(70,50+(i*13), msg);
}
}
if(a[9]==b[9])
{
setcolor(2);
sprintf(msg,"10)   %c    ,   %c ",a[i],b[i]);
outtextxy(70,50+(9*13), msg);
re++;
}
else
{
setcolor(4);
sprintf(msg,"10)   %c    ,   %c ",a[i],b[i]);
outtextxy(70,50+(9*13), msg);
}
printf("\nresults for this round = %d",re);
if(re>=6)
{
printf("\npassed the level");
}
else
{
printf("\nbetter luck next time");
break;
}
getch();
}

fclose(fp1);
fclose(fp);
getch();
closegraph();

}