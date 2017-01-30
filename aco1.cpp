#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<windows.h>
using namespace std;
int main()
 {
     int c=COLOR(0,0,255);
     //cout<<c<<" ";
     //cout<<COLOR(0,255,0)<<" ";
     //cout<<COLOR(255,0,0)<<" ";
     int i,j,k,L=680,n=10,time;
     short map[L][L];
     short phe[L][L];
     short ant[n][3];
     initwindow(L,L,"MAP");
     floodfill(10,10,COLOR(255,255,255));
     setcolor(COLOR(0,0,255));
    // cout<<GetGValue(getpixel(100,100));
     for(i=0;i<L;i++)
      { 
         putpixel(1,i,COLOR(255,0,0));
         putpixel(L-1,i,COLOR(255,0,0));
         putpixel(i,1,COLOR(255,0,0));
         putpixel(i,L-1-20,COLOR(255,0,0));
         putpixel(i,L-1,COLOR(255,0,0));  
      }
     outtextxy(10,L-20+2,"                                                   "); 
     outtextxy(10,L-20+2,"Hello");
     putpixel(100,100,COLOR(255,0,255)); //home
     putpixel(L-1-20,L-1,COLOR(0,0,255)); //food
     
     for(i=2;i<L-1;i++)
      {
         for(j=2;j<L-20-1;j++)
          {
              if((i==1 || i==(L-1))&&(j==1 || j==(L-1-20))) map[i][j]=0; //border as obstacle
              else map[i][j]=1; //rest of the terrain as free space
              phe[i][j]=5;  //base pheromone level for entire map at beginning
          }
      }
      
     for(i=0;i<n;i++)
      {
         ant[i][0]=320;//rand()%660; //x home
         ant[i][1]=310;//rand()%660; //y home
         ant[i][2]=0; //food status 0=no food 1=food
      }
     //short ant[3][3];
     //no. of ants = 100
     //total time of running = 100 steps for each ant
     int x, y,prob[8][3],ano,rno,sum;
     for(time=0;time<10000;time++)
      {
          outtextxy(10,L-20+2,"                                                   "); 
          outtextxy(10,L-20+2,"Started");
          for(ano=0;ano<n;ano++)
           {
                
                phe[100][100]==0;
                x=ant[ano][0];
                y=ant[ano][1];
                //putpixel(x,y,COLOR(time/10000*ano,255/100*phe[x][y],time/500));
                //cout<<"Time:"<<(time+1)<<" Ant:"<<(ano+1)<<" x:"<<x<<" y:"<<y<<" ";
                prob[0][1]=x-1; prob[0][2]=y-1;
                prob[1][1]=x;   prob[1][2]=y-1;
                prob[2][1]=x+1; prob[2][2]=y-1;
                prob[3][1]=x-1; prob[3][2]=y;
                prob[4][1]=x+1; prob[4][2]=y;
                prob[5][1]=x-1; prob[5][2]=y+1;
                prob[6][1]=x;   prob[6][2]=y+1;
                prob[7][1]=x+1; prob[7][2]=y+1;
                for(i=0;i<8;i++)
                 {
                     prob[i][0]=phe[prob[i][1]][prob[i][2]]*map[prob[i][1]][prob[i][2]];
                     for(j=0;j<n;j++)
                      {
                          if(prob[i][1]==ant[j][0] && prob[i][2]==ant[j][1]) prob[i][0]=0;
                      }
                      //cout<<prob[i][0]<<" ";
                 }
                sum=prob[0][0]+prob[1][0]+prob[2][0]+prob[3][0]+prob[4][0]+prob[5][0]+prob[6][0]+prob[7][0];
                if(sum==0) continue;
                rno=rand()%sum+1;
                //cout<<"\n";
                //getch();
                i=0;
                while(rno>0 && i<8) { rno-=prob[i++][0]; }
                i--;
                
                phe[prob[i][1]][prob[i][2]]+=4;
                ant[ano][0]=prob[i][1];
                ant[ano][1]=prob[i][2];
                
                //getch();
          }
         //evaporate pheromone
         for(i=2;i<L-1;i++)
          {
              for(j=2;j<L-21;j++)
               {
                     if(phe[i][j]>5) 
                      {
                          phe[i][j]--;
                          putpixel(i,j,COLOR(255,255-(phe[i][j]-4)*25.5,255)); 
                          
                      }
                      if(time%500==0)
                          putpixel(i,j,COLOR(255,255-(phe[i][j]-5)*25.5,255)); 
                      //if(phe[i][j]>1)
                         
               }
          }
     }
                
                
                  
                  
                        
      
     getch();
                      
            
            
            
            
            
            
            
 }
