#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <g2.h>
#include <g2_X11.h>
#include <g2_PS.h>
#include <g2_gd.h>
#include <stdint.h>
#include <unistd.h>

#define PI 3.14159265


int d;
int fp;

void openg2 (int *d)
{
   int dev;
   *d = g2_open_vd ();
   dev = g2_open_X11(600, 600);
   g2_attach(*d, dev);
   g2_clear(*d);
   g2_set_font_size(*d,30);
   g2_set_auto_flush(*d,1); 
}



void closeg2 (int d)
{
   
   g2_flush(d);
   g2_close(d);
}

void drawVOR(int teta, int psi, int b){
   int r=200; // size of circle
   float dt=0.3;
   int dr=50;
   float val = PI / 180.0;
   int p[10];
   char data_1[3];
   int aux_teta=teta;
   int i=0;


//**********************back circle************************************
   int center=300; // half of the window size
   g2_pen(d, 1);
   g2_filled_circle(d,center,center, r+70);   

//**********************bars*************************************
   g2_set_font_size(d,30);

  for (i=0;i<=4;i++){ // draw principal bars bars 
    
      //double *ref=&p[0];
     
      p[0]=center+(int)r*cos(teta*val); //x1
      p[1]=center+(int)r*sin(teta*val); //y1
      p[2]=center+(int)(r-dr)*cos(teta*val); //x2
      p[3]=center+(int)(r-dr)*sin(teta*val); //y2
      p[4]=center+(int)r*cos((teta+dt)*val); //x3
      p[5]=center+(int)r*sin((teta+dt)*val); //y3
      p[6]=center+(int)(r-dr)*cos((teta+dt)*val); //x4
      p[7]=center+(int)(r-dr)*sin((teta+dt)*val); //y4

      
      p[8]=center-10+(int)(r+20)*cos(teta*val); //x2
      p[9]=center+(int)(r+25)*sin(teta*val); //y2
      teta+=90;

      g2_pen(d, 0);
      g2_line(d,p[0],p[1],p[2],p[3]);
      g2_line(d,p[4],p[5],p[6],p[7]);
      g2_pen(d,0);
         

        switch(i){
            case (1):
               sprintf(data_1, "N");
               g2_string(d, p[8], p[9], data_1);   
               break;
            case (2):
               sprintf(data_1, "W");
              g2_string(d, p[8], p[9], data_1);    
               break;
            case (3):
               sprintf(data_1, "S");
               g2_string(d, p[8], p[9], data_1);    
               break;
                break;
            case (4):
               sprintf(data_1, "E");
               g2_string(d, p[8], p[9], data_1);  
               break;
            }
  
  }  

   teta=aux_teta;
   dr=30; //comprimento do traço

 for (i=0;i<=12;i++){ // draw bars 30 deg
      int p[8];
    
      p[0]=center+(int)r*cos(teta*val); //x1
      p[1]=center+(int)r*sin(teta*val); //y1
      p[2]=center+(int)(r-dr)*cos(teta*val); //x2
      p[3]=center+(int)(r-dr)*sin(teta*val); //y2
      p[4]=center+(int)r*cos((teta+dt)*val); //x3
      p[5]=center+(int)r*sin((teta+dt)*val); //y3
      p[6]=center+(int)(r-dr)*cos((teta+dt)*val); //x4
      p[7]=center+(int)(r-dr)*sin((teta+dt)*val); //y4

      p[8]=center-22+(int)(r+25)*cos(teta*val); //x2
      p[9]=center-16+(int)(r+25)*sin(teta*val); //y2
      teta+=30;


      g2_pen(d, 0);
      g2_line(d,p[0],p[1],p[2],p[3]);
      g2_line(d,p[4],p[5],p[6],p[7]);

           switch(i){
            case (1):
               sprintf(data_1, "60");
               g2_string(d, p[8], p[9], data_1);   
               break;
            case (2):
               sprintf(data_1, "30");
               g2_string(d, p[8], p[9], data_1);   
               break;
            case (4):
               sprintf(data_1, "330");
               g2_string(d, p[8], p[9], data_1);   
               break;
                break;
            case (5):
               sprintf(data_1, "300");
               g2_string(d,p[8], p[9], data_1);   
               break;
              case (7):
               sprintf(data_1, "270");
               g2_string(d, p[8], p[9], data_1);   
               break;
                break;
            case (8):
               sprintf(data_1, "240");
               g2_string(d, p[8], p[9], data_1);   
               break;
            case (10):
               sprintf(data_1, "150");
               g2_string(d,p[8], p[9], data_1);   
               break;
                break;
            case (11):
               sprintf(data_1, "120");
               g2_string(d, p[8], p[9], data_1);   
               break;
         
         }
         

   }

    teta=aux_teta;
    dr=10;
 for (i=0;i<=36;i++){ // draw bars 10 deg
      int p[8];

      //double *ref=&p[0];
      p[0]=center+(int)r*cos(teta*val); //x1
      p[1]=center+(int)r*sin(teta*val); //y1
      p[2]=center+(int)(r-dr)*cos(teta*val); //x2
      p[3]=center+(int)(r-dr)*sin(teta*val); //y2
      p[4]=center+(int)r*cos((teta+dt)*val); //x3
      p[5]=center+(int)r*sin((teta+dt)*val); //y3
      p[6]=center+(int)(r-dr)*cos((teta+dt)*val); //x4
      p[7]=center+(int)(r-dr)*sin((teta+dt)*val); //y4
      teta+=10;
      g2_pen(d, 0);
      g2_line(d,p[0],p[1],p[2],p[3]);
      g2_line(d,p[4],p[5],p[6],p[7]);
   }

// inner circle

 g2_pen(d,14);
g2_filled_circle(d,center,center, r-30);   


//************yellow triangle

g2_pen(d, 25);
g2_filled_triangle(d,center-20,center+170, center+20,center+170,center,center+190);

//************FROM TO
    g2_pen(d, 1);
    g2_set_font_size(d,22); 
    if (b==1){
          sprintf(data_1, "FROM");
          g2_string(d, center+40, center+60, data_1);  
    }
    if (b==-1){
          sprintf(data_1, "TO");
    g2_string(d, center+40, center+60, data_1); 
    }


//************target 

    g2_filled_rectangle(d,center-100,center+2,center+100,center-2);
    g2_filled_rectangle(d,center+2,center-100,center-2,center+100);
   

    //little dots each dot is 5 deg
    for (i=0;i<=100;i+=25){
      g2_filled_circle(d,center+i,center,5);
      g2_filled_circle(d,center-i,center,5);
      g2_filled_circle(d,center,center+i,5);
      g2_filled_circle(d,center,center-i,5);

    }
//************INDICATOR x
    teta=aux_teta;
    int deviation=0;

    
    if(b==-1){
       deviation=b*(teta-psi+180)*5;
    }
     if(b==1){
      deviation=b*(teta-psi)*5;
    }

    if (deviation>150){deviation=150;}
   if (deviation<(-150)){deviation=(-150);}

   g2_filled_rectangle(d,center+2+deviation,center-140,center-2+deviation,center+140);


}

void main(){


int rotate=0; //rotate is de angle that we set to follow
int current_angle=160; // is the actual VOR radial algle that the airplane is
int b=-1;  //-1 means "to the station ; 1 means from the station"
// b is generated by the dme



int i;
      openg2(&d);

      while (1){
         i++;
         if (i>10){rotate++;}
       current_angle+=1; 
       drawVOR(rotate,current_angle,b);
       sleep(1);
 

      }


      closeg2(d);

}
