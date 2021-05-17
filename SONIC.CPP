#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <iomanip.h>
#include <process.h>
//0 - silence, 1 - short low,2- long low,3-short high,4 - long high,5 - laser
void play(int x)
{
   if (x ==1)
   {
	sound(200);
	delay(300);
	nosound();
	delay(200);
   }
   else if(x == 2)
   {
	sound(200);
	delay(700);
	nosound();
	delay(200);
   }
   else if (x ==3)
   {
	sound(500);
	delay(300);
	nosound();
	delay(200);
   }
   else if(x == 4)
   {
	sound(500);
	delay(700);
	nosound();
	delay(200);
   }
   else if(x == 5)
   {
	for(int k =0;k<10;k++)
	{
	 sound(500 - 50 * k);
	 delay(60);
	 nosound();
	}
	delay(200);
   }
   else if(x == 6)
   {
	for(int k =0;k<10;k++)
	{
	 sound(50 + 50 * k);
	 delay(70);
	 nosound();
	}
	delay(200);
	}

}

void main()
{
 clrscr();
 char des[7][30] = {"silence","short low pitched sound","long low pitched sound","short high pitched sound","long high pitched sound","down laser!","up laser!"};
 cout<<setw(30)<<"SONIC";
 cout<<"\nInstructions :\nYour task is to identify the series of given sounds based on their numerical constants. A sample of each sound and its assigned constant will be played for you now.";
 cout<<"\nPress any key to continue: ";
 getch();
 clrscr();
 for(int i = 1; i<7;i++)
 {
  cout<<i<<":- "<<des[i]<<'\n';
  play(i);
  cout<<"Press any key to continue: \n\n";
  getch();
 }
 clrscr();
 int l = 1;
 int a[7],inp[7];
 randomize();
 while(l<4)
 {
  int size = l + 2,f = 0;
  clrscr();
  cout<<setw(30)<<"\nLevel "<<l<<": ";

  cout<<"\nPress any key to play the sounds ";
  getch();
  clrscr();
  cout<<setw(30)<<"\nLevel "<<l<<"\n";
  for(i = 1; i<7;i++)
 {
  cout<<i<<":- "<<des[i]<<'\n';
 }
  for(int i=0;i<size;i++)
  {
   do
   {
	a[i] = random(6) + 1;
	if((a[i] == a[i - 1] && a[i] == 0)  || a[0] == 0)
	f = 1;
	else
	f =0;
   }while(f);
   int x = a[i];
   play(x);
  }
  int p=0;
  cout<<"Enter the numerical constants sequentially (separated by spaces) : ";
  for(int j =0;j<size;j++)
  {
   cin>>inp[j];
   if(a[j] == inp[j])
   {
	p++;
   }
  }
  if(p == size)
  {
   cout<<"\nYou win!";
   if(l!=3)cout<<"Press any key to continue to level "<<++l;
   else
   {
	cout<<"Well played!";
	l++;
   }
   getch();
  }
  else
  {
   cout<<"\nYou got "<<p<<" out of "<<size<<" sounds correct.\nThe correct sequence was: ";
   for(int g =0;g<size;g++)
   {
	cout<<a[g]<<" ";
   }
   getch();
   exit(0);
  }

 }

 getch();
}