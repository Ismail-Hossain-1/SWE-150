#include<graphics.h>
#include<time.h>
#include<iostream>
#include<windows.h>
#include<stdlib.h>

using namespace std;

int endfunc(int another);

int main(){
    //direction
    int gd,gm,rx=200,ry=200,x[200]={0},y[200]={0},d;


    //Food eaten
    int food=1, chk= getmaxx();


    //directions
    int dir=1;
    detectgraph(&gd,&gm);
    initgraph(&gd,&gm,"");
    setfillstyle(SOLID_FILL,YELLOW);//(style,color)
    x[0]=200,y[0]=200;
    d=1;
    int length = 1;

    // The continuous animation

for(;;){
        //Score board
    setcolor(LIGHTCYAN);

    settextstyle(BOLD_FONT, 0,2);




        // Background
    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(0,0,getmaxx(),getmaxy());

    char arr[50];
    sprintf(arr, "Score is :%d", food-2);
    outtextxy(20, 40, arr);

       //IF the food is taken
   if(x[0]==rx && y[0]==ry ){

    length += 1;
    food = food+1;

    //make food
    do{
	rx = (1+rand()%(getmaxx()-10));
	ry = (1+rand()%(getmaxy()-10));
    }while(rx<=10 && ry<=10);

    rx=rx/10;
    rx=rx*10;
    ry=ry/10;
    ry=ry*10;

    setfillstyle(HATCH_FILL,YELLOW);
     }
     //FOOD STYLE
     setfillstyle(SOLID_FILL,RED);
        bar(rx,ry,rx+10,ry+10);
        // FOUR BOUNDARIES
     setfillstyle(SOLID_FILL, LIGHTBLUE);
        bar(0,0,getmaxx(),10);
        bar(0,0,10,getmaxy());
        bar(0,getmaxy(),getmaxx(),getmaxy()-10);
        bar(getmaxx()-10,10,getmaxx(),getmaxy());

    if(GetAsyncKeyState(VK_RIGHT)){d=1;}
    else if(GetAsyncKeyState(VK_LEFT)){ d=2;}
    else if(GetAsyncKeyState(VK_UP)){ d=3;}
    else if(GetAsyncKeyState(VK_DOWN)) {d=4;}
    else{d=0;}
    switch(d){
    case 0:
      if(dir==1){x[0]=x[0]+10;}
      else if(dir==2){x[0]=x[0]-10;}
      else if(dir==3){ y[0]=y[0]-10;}
      else if(dir==4) {y[0]=y[0]+10;}
      else{d=0;}
      break;
    case 1:
           x[0]=x[0]+10;
           dir=1;
           break;
    case 2:
         x[0]= x[0]-10;
         dir=2;
          break;
    case 3:
        dir=3;
        y[0]=y[0]-10;
        break;
    case 4:
        dir=4;
       y[0]= y[0]+10;
        break;
    }
    for(int i = 0; i < length;i++){
            setfillstyle(HATCH_FILL,YELLOW);
        bar(x[i],y[i],x[i]+10,y[i]+10);
    }
    for(int i= 199; i >0;i--){
        x[i] = x[i-1];
        y[i] = y[i -1];
    }
    delay(100);
    if(x[0] >= getmaxx() || x[0]<=0|| y[0]<=0 || y[0]>=getmaxy()){
    endfunc(food);
    break;
    }

    for(int i = 2; i < length;i++){
        if(x[0] == x[i] && y[0] == y[i]){
            chk = i;
            break;
            }
    }
    if(x[0] == x[chk] && y[0] == y[chk]){
    endfunc(food);
    break;
    }
}

    return 0;

}

int endfunc(int another){
    setfillstyle(SOLID_FILL,LIGHTRED);
    another=another-2;
    bar(0,0,getmaxx(),getmaxy()-10);
    //char s = (char)another;

    system("cls");

    cout << "Score is : " << another<<endl;
    getch();
    return 0;
}

