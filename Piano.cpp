#include<graphics.h>
#include<stdio.h>
#include<windows.h>
#include<mmsystem.h>
char notes[100]={0};//array for recording notes
int count=0;//keeping count of notes
int main(){//main function
      int welcome();
      int x = welcome();//x denotes whether the user wants to use the piano
      if(x){
            void drawPiano();
            drawPiano();
            void control();
            control();
      }
      else{
            void thank();
            thank();
      }
      return 0;
}
int welcome(){//function to display welcome screen
      int gd = DETECT, gm;
      initgraph(&gd, &gm, "");
      setcolor(WHITE);
      //settextstlye will set the font, orientation and size of text
      settextstyle(5,0,5);
      //outtextxy will place the writing at give x y coordinate
      outtextxy(185,175,"WELCOME");
      PlaySound(TEXT("piano.wav"), NULL, SND_SYNC);
      delay(300);
      outtextxy(150,225,"Enter 1 to start");
      settextstyle(0,0,2);
      outtextxy(175,275,"All other keys Exit");
      char ch = getch();
      if(ch=='1')
            return 1;
      else
            return 0;
}
void drawPiano(){//function to draw the piano
      //block to fill entire backgroung with red color
      {
            setfillstyle(1,RED);
            floodfill(498,400,RED);
            setcolor(WHITE);
            settextstyle(0,0,2);
            outtextxy(500,450,"Off-m");
            outtextxy(325,425,"Start/PLay Record - n");
      }
      //block to draw white keys
      {
            setcolor(BLACK);//this will set the drawing color to black
            setfillstyle(1,WHITE);//fillstyle 1 is bold, color is white
            int i;
            //drawing 8 white keys
            for(i=0;i<8;i++){
                  int j = i*75;
                  rectangle(j,0,j+75,275);//draw a rectangle
                  floodfill(j+2,2,BLACK);
                  /*
                  Now the floodfill will fill with whatever color is given in the setfillstyle
                  Here it is white
                  The first two parameter are x and y coordinates
                  The coordinates are any point inside the boundary of what you want to fill
                  The third parameter is the boundary colour, therefore until you reach that
                  color it will keep filling
                  Here until we reach the black color, white will keep filling
                  */
            }


      }
      //block to draw black keys
      //here we can't use a loop since it's not even
      {
            /*
            each rectangle drawn requires two filling, because the border line of the
            white key will run through the centre of the blaack key
            */
            setfillstyle(1,BLACK);//setting the fill color as black
            rectangle(50, 0, 100, 200);
            floodfill(52,2,BLACK);
            floodfill(77,2,BLACK);
            rectangle(125,0,175,200);
            floodfill(127,2,BLACK);
            floodfill(152,2,BLACK);
            rectangle(275,0,325,200);
            floodfill(277,2,BLACK);
            floodfill(302,2,BLACK);
            rectangle(350,0,400,200);
            floodfill(352,2,BLACK);
            floodfill(377,2,BLACK);
            rectangle(425,0,475,200);
            floodfill(427,2,BLACK);
            floodfill(452,2,BLACK);
      }

}
void control(){//function to control whichever keys are being played and ckecking for exit and invlid keys
      void playPiano(char);
      int rec=0;
      char ch ='a';
      void record(char);
      do{
            ch = getch();
            //checking for valid key input
            if(ch=='a' || ch=='s' || ch=='d' || ch=='f' || ch=='g' || ch=='h' || ch=='j' || ch=='k' || ch=='w' || ch=='e' || ch=='t' || ch=='y' || ch=='u'){
                  playPiano(ch);
                  if(rec){//if the notes have to be recorded
                        record(ch);
                        if(count==99){
                              settextstyle(0,0,2);
                              setcolor(WHITE);
                              outtextxy(50,450,"Max Limit");
                        }
                        putpixel(74+count,440,WHITE);//change the color of the record bar
                        putpixel(74+count,440,WHITE);
                  }
            }
            //recording
            else if(ch=='n'){
                  if(rec==0){//start recording
                        setcolor(BLACK);
                        line(75,440,174,440);//record bar to show how many notes can be recorded
                        line(75,441,174,441);
                        count=0;
                        rec=1;
                        setcolor(WHITE);
                        settextstyle(0,0,2);
                        outtextxy(50,450,"Recording");
                  }
                  else if(rec==1){//play recording
                        setcolor(BLACK);
                        line(75,440,174,440);//resetting record bar before playing recording
                        line(75,441,174,441);
                        setcolor(WHITE);
                        settextstyle(0,0,2);
                        outtextxy(50,450," Playing ");
                        void playRecord();
                        playRecord();
                        setcolor(WHITE);
                        settextstyle(0,0,2);
                        outtextxy(50,450,"  Done   ");
                        delay(100);
                        setcolor(RED);
                        line(75,440,174,440);//removing record bar by making red again
                        line(75,441,174,441);
                        rec=0;//resetting to record next time
                  }
            }
            else if(ch=='m'){//exiting
                  setcolor(WHITE);
                  settextstyle(0,0,5);
                  outtextxy(200,350,"Exiting");
                  delay(1000);
                  void thank();
                  thank();
            }
            else{
                  outtextxy(300,350,"  ");
            }
      }while(ch!='m');

}
void playPiano(char x){//function to highlight keys and play sound when corresponding keys are pressed
      setcolor(WHITE);
      settextstyle(0,0,5);
      switch(x){
            /*
            For each key, we change its color wait for the sound to be played and then revert the color back
            The sound is played from prerecorded audio wav files which contain the corresponding key note
            To do this we use the setfillstyle and floodfill functions to change the color, delay to wait and setfillstyle and floodfill to revert back
            In the case of black keys, the border color being searched for is white
            Since the top of the key and the point at the bottom of the key at the center are not white, we add a white point at the bottom and a white line at the top
            To do this we use the line function and putpixel function
            Also these two have to be reverted back as well to black
            */
                  case 'a':{
                  outtextxy(300,350,"C ");
                  setfillstyle(1,LIGHTGRAY);
                  floodfill(2,2,BLACK);
                  PlaySound(TEXT("c.wav"), NULL, SND_SYNC);
                  setfillstyle(1,WHITE);
                  floodfill(2,2,BLACK);
                  break;
            }
            case 's':{
                  outtextxy(300,350,"D ");
                  setfillstyle(1,LIGHTGRAY);
                  floodfill(102,2,BLACK);
                  PlaySound(TEXT("d.wav"), NULL, SND_SYNC);
                  setfillstyle(1,WHITE);
                  floodfill(102,2,BLACK);
                  break;
            }
            case 'd':{
                  outtextxy(300,350,"E ");
                  setfillstyle(1,LIGHTGRAY);
                  floodfill(202,2,BLACK);
                  PlaySound(TEXT("e.wav"), NULL, SND_SYNC);
                  setfillstyle(1,WHITE);
                  floodfill(202,2,BLACK);
                  break;
            }
            case 'f':{
                  outtextxy(300,350,"F ");
                  setfillstyle(1,LIGHTGRAY);
                  floodfill(227,2,BLACK);
                  PlaySound(TEXT("f.wav"), NULL, SND_SYNC);
                  setfillstyle(1,WHITE);
                  floodfill(227,2,BLACK);
                  break;
            }
            case 'g':{
                  outtextxy(300,350,"G ");
                  setfillstyle(1,LIGHTGRAY);
                  floodfill(327,2,BLACK);
                  PlaySound(TEXT("g.wav"), NULL, SND_SYNC);
                  setfillstyle(1,WHITE);
                  floodfill(327,2,BLACK);
                  break;
            }
            case 'h':{
                  outtextxy(300,350,"A ");
                  setfillstyle(1,LIGHTGRAY);
                  floodfill(402,2,BLACK);
                  PlaySound(TEXT("a.wav"), NULL, SND_SYNC);
                  setfillstyle(1,WHITE);
                  floodfill(402,2,BLACK);
                  break;
            }
            case 'j':{
                  outtextxy(300,350,"B ");
                  setfillstyle(1,LIGHTGRAY);
                  floodfill(502,2,BLACK);
                  PlaySound(TEXT("b.wav"), NULL, SND_SYNC);
                  setfillstyle(1,WHITE);
                  floodfill(502,2,BLACK);
                  break;
            }
            case 'k':{
                  outtextxy(300,350,"C ");
                  setfillstyle(1,LIGHTGRAY);
                  floodfill(527,2,BLACK);
                  PlaySound(TEXT("c7.wav"), NULL, SND_SYNC);
                  setfillstyle(1,WHITE);
                  floodfill(527,2,BLACK);
                  break;
            }
            case 'w':{
                  outtextxy(300,350,"C#");
                  setcolor(WHITE);
                  putpixel(75,201,WHITE);
                  line(50,1,100,1);
                  setfillstyle(1,DARKGRAY);
                  floodfill(52,2,WHITE);
                  PlaySound(TEXT("c#.wav"), NULL, SND_SYNC);
                  setfillstyle(1,BLACK);
                  floodfill(52,2,WHITE);
                  putpixel(75,201,BLACK);
                  setcolor(BLACK);
                  line(50,1,100,1);
                  break;
            }
            case 'e':{
                  outtextxy(300,350,"D#");
                  setcolor(WHITE);
                  putpixel(150,201,WHITE);
                  line(125,1,175,1);
                  setfillstyle(1,DARKGRAY);
                  floodfill(152,2,WHITE);
                  PlaySound(TEXT("d#.wav"), NULL, SND_SYNC);
                  setfillstyle(1,BLACK);
                  floodfill(150,2,WHITE);
                  putpixel(150,201,BLACK);
                  setcolor(BLACK);
                  line(125,1,175,1);
                  break;
            }
            case 't':{
                  outtextxy(300,350,"F#");
                  setcolor(WHITE);
                  putpixel(300,201,WHITE);
                  line(275,1,325,1);
                  setfillstyle(1,DARKGRAY);
                  floodfill(302,2,WHITE);
                  PlaySound(TEXT("f#.wav"), NULL, SND_SYNC);
                  setfillstyle(1,BLACK);
                  floodfill(302,2,WHITE);
                  putpixel(300,201,BLACK);
                  setcolor(BLACK);
                  line(275,1,325,1);
                  break;
            }
            case 'y':{
                  outtextxy(300,350,"G#");
                  setcolor(WHITE);
                  putpixel(375,201,WHITE);
                  line(350,1,400,1);
                  setfillstyle(1,DARKGRAY);
                  floodfill(375,2,WHITE);
                  PlaySound(TEXT("g#.wav"), NULL, SND_SYNC);
                  setfillstyle(1,BLACK);
                  floodfill(375,2,WHITE);
                  putpixel(375,201,BLACK);
                  setcolor(BLACK);
                  line(350,1,400,1);
                  break;
            }
            case 'u':{
                  outtextxy(300,350,"A#");
                  setcolor(WHITE);
                  putpixel(450,201,WHITE);
                  line(425,1,475,1);
                  setfillstyle(1,DARKGRAY);
                  floodfill(450,2,WHITE);
                  PlaySound(TEXT("a#.wav"), NULL, SND_SYNC);
                  setfillstyle(1,BLACK);
                  floodfill(450,2,WHITE);
                  putpixel(450,201,BLACK);
                  setcolor(BLACK);
                  line(425,1,475,1);
                  break;
            }
      }
      outtextxy(300,350,"  ");
}
void thank(){//function to display thank you screen
      setfillstyle(1,BLACK);
      floodfill(200,200,GREEN);
      //to make whole screen black boundary color is given as a color not present, here green
      setcolor(WHITE);
      settextstyle(3,0,5);
      outtextxy(155,200,"THANK YOU");
      delay(1500);
      closegraph();
}
void record(char x){//function to store notes being recorded
      if(count<100){
            notes[count]=x;
            count++;
      }
}
void playRecord(){//function to play recording
      for(int i=0;i<count;i++){
            playPiano(notes[i]);
            putpixel(75+i,440,WHITE);
            putpixel(75+i,440,WHITE);
      }
}
