#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <g2.h>
#include <g2_X11.h>

#include <stdint.h>
#include <unistd.h>

#define pi 3.14159265


int d;
int fp;
int window_size=600;

void openg2 (int *d)
{
   int dev;
   *d = g2_open_vd ();
   dev = g2_open_X11(window_size, window_size);
   g2_attach(*d, dev);
   g2_clear(*d);
   g2_set_font_size(*d,window_size/20);
   g2_set_auto_flush(*d,1); 
}



void closeg2 (int d)
{
   
   g2_flush(d);
   g2_close(d);
}

void draw_att(float pitch, float roll){
  //pitch 10 d50 untits 
  g2_set_font_size(d,15);
  g2_set_background(d,3); // set blue background
  double points[8];
  double *pt;
  pt=points;
  int center=window_size/2;
  char data_1[2];
  roll=-roll* pi / 180.0;


  //PONINTS CALCULATED FOR ARTIFICIAL HORIZON
      points[0]=0; //fixed
      points[1]=0; ////fixed
      points[2]=0; //fixed

      points[4]=window_size; //fixed
      points[6]=window_size; //fixed
      points[7]=0; //fixed


      //needs to be calculated
      int new_angle=sin(roll)*300;
     
      points[3]=center-pitch*10+new_angle;
      points[5]=center-pitch*10-new_angle;

      g2_pen(d,10); // CASTANHO
      g2_filled_polygon(d,4,pt);

  //GRID



    g2_pen(d,0); //branco
    g2_line(d,points[2],points[3],points[4],points[5] ); //horizon line 
    sprintf(data_1, "0");
    g2_string(d,center,(points[3]+points[5])/2, data_1); 


    g2_line(d,points[2],points[3]+100,points[4],points[5]+100); //10 deg
    sprintf(data_1, "10");
    g2_string(d,center,(points[3]+200+points[5])/2, data_1); 

    g2_line(d,points[2],points[3]+200,points[4],points[5]+200); //10 deg
     sprintf(data_1, "20");
    g2_string(d,center,(points[3]+400+points[5])/2, data_1); 

   g2_line(d,points[2],points[3]+300,points[4],points[5]+300); //10 deg
    sprintf(data_1, "30");
    g2_string(d,center,(points[3]+600+points[5])/2, data_1); 


   g2_line(d,points[2],points[3]+400,points[4],points[5]+400); //10 deg
    sprintf(data_1, "40");
    g2_string(d,center,(points[3]+800+points[5])/2, data_1); 

   g2_line(d,points[2],points[3]-100,points[4],points[5]-100); //10 deg
     sprintf(data_1, "-10");
    g2_string(d,center,(points[3]-200+points[5])/2, data_1); 


   g2_line(d,points[2],points[3]-200,points[4],points[5]-200); //10 deg
    sprintf(data_1, "-20");
    g2_string(d,center,(points[3]-400+points[5])/2, data_1); 

   g2_line(d,points[2],points[3]-300,points[4],points[5]-300); //10 deg
     sprintf(data_1, "-30");
    g2_string(d,center,(points[3]-600+points[5])/2, data_1); 

   g2_line(d,points[2],points[3]-400,points[4],points[5]-400); //10 deg
   
    sprintf(data_1, "-40");
    g2_string(d,center,(points[3]-800+points[5])/2, data_1); 




  // AIRPLANE 
   g2_pen(d,25);
    g2_filled_rectangle(d,center-150,center-3,center-30, center+3);
    g2_filled_rectangle(d,center+150,center+3,center+30, center-3);

  //frame
    g2_pen(d,3); 
    g2_filled_rectangle(d,0,600,600,530);


  //grid for roll
    g2_pen(d,0);
    g2_line(d,50,560,550,560);
    for (int j=0;j<6;j++){
      g2_line(d,center+j*50,575,center+j*50,560);


           switch(j){
            case (0):
               sprintf(data_1, "0");
               g2_string(d,center+j*50,580, data_1);   
               break;
            case (1):
               sprintf(data_1, "10");
               g2_string(d, center+j*50,580, data_1);   
               break;
            case (2):
               sprintf(data_1, "20");
               g2_string(d,center+j*50,580,data_1);   
               break;
                break;
            case (3):
               sprintf(data_1, "30");
               g2_string(d,center+j*50,580, data_1);   
               break;
              case (4):
               sprintf(data_1, "40");
               g2_string(d, center+j*50,580,data_1);   
               break;
                break;
            case (5):
               sprintf(data_1, "50");
               g2_string(d, center+j*50,580, data_1);   
               break;
            
         }
    }
    for (int j=0;j<6;j++){
      g2_line(d,center-j*50,575,center-j*50,560);
      switch(j){
  
            case (1):
               sprintf(data_1, "-10");
               g2_string(d, center-j*50,580, data_1);   
               break;
            case (2):
               sprintf(data_1, "-20");
               g2_string(d,center-j*50,580,data_1);   
               break;
                break;
            case (3):
               sprintf(data_1, "-30");
               g2_string(d,center-j*50,580, data_1);   
               break;
              case (4):
               sprintf(data_1, "-40");
               g2_string(d, center-j*50,580,data_1);   
               break;
                break;
            case (5):
               sprintf(data_1, "-50");
               g2_string(d, center-j*50,580, data_1);   
               break;
             }
    }

  //roll indicator
  g2_pen(d, 25);
  g2_filled_triangle(d,center-20-roll*290,center+230, center+20-roll*290,center+230,center-roll*290,center+260);


   
}

void main(){


int i=0;

      openg2(&d);

      while (1){
         i+=1;
       draw_att(i,i);
       sleep(1);
 

      }


      closeg2(d);

}