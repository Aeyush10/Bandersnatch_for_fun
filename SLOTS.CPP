#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
#include <dos.h>
#include <stdlib.h>
void main()
{ clrscr();
  cout<<setw(40)<<"SLOTS";
  int score = 0,n =0,win =0;
  cout<<"\nHow many rounds do you wish to play (from 1 to 9): ";
  cin>>n;
  while(n<=0||n>=10)
  {
   cout<<"\nInvalid input, enter another number : ";
   cin>>n;
  }
  cout<<"Let's go!";
  delay(1000);
  int temp =n,s1=0,s2=0,s3=0;
  randomize();
  char sy[7] = {char(14),char(2),char(3),char(-19),char(-24),char(127),char(15)};
  do{
  s1=random(7),s2 = random(7),s3 = random(7);
  clrscr();
   cout<<setw(40)<<"SLOTS";
   gotoxy(15,3);
   for(int i =0;i<7;i++)
   {
    cout<<sy[i]<<" \t";
   }
   gotoxy(33,10);
   for(int j =0;j<13;j++)
   {
    cout<<(char(-37));
   }
   gotoxy(33,11);
   cout<<char(-41)<<" "<<sy[s1]<<" "<<char(-41)<<" "<<sy[s2]<<" "<<char(-41)<<" "<<sy[s3]<<" "<<char(-41);
   gotoxy(33,12);
   for(int k= 0;k<13;k++)
   {
    cout<<(char(-37));
   }
   if(s1 == s2)
   {
    if(s2 == s3)
    {
     cout<<"\n\n"<<setw(50)<<"Yay! You scored 100 points";
     score+=100;
    }
    else
    {
     cout<<"\n\n"<<setw(50)<<"You scored 50 points!";
     score+=50;
    }
   }
   else
   {
    if(s2 == s3 || s1 == s3)
    {
     cout<<"\n\n"<<setw(50)<<"You scored 50 points!";
     score+=50;
    }
    else
    {
     cout<<"\n\n"<<setw(50)<<"You didn't score :(";
    }
   }

   cout<<"\n\n\n\n\n\n\n"<<setw(40)<<"SCORE : "<<score;
   getch();
   temp--;
  }while(temp>0);
  clrscr();
  cout<<"Your final score is "<<score<<"/"<<100*n;
  float per = score/n;
  if(per>=25)
  {
   win = 1;
  }
  else
  {
   cout<<"\nTough Luck :(";
   win = 0;
  }
  getch();
}
