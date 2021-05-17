#include <iostream.h>
#include <dos.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void main()
{
	clrscr();
	int a[100][100], t = 1, y;
	char x[] = "  WELCOME TO THE GAME!  ",ran;
	randomize();
	do{
		t++;
		y = 0;
		for(int i = 0; i<24;i++)
			{for(int j = 0; j<70;j++)
				{  /*	ran = random(3);
					if(ran == 0) */
						ran = random(10) + 48;
					/*else if (ran == 1)
						ran = random(26) + 97;
					else
						ran = random(26) + 65;*/
					//randomize();
					//if((ran >=65 && ran <=92) || (ran >=97 && ran <=122) || (ran >=48 && ran <=57))

					if(i == 10)
					{
						if(t>(6 + y) && j == (23 + y) && y<strlen(x))
							cout<<x[y++];
						else if (t>(6 + y) && j == (24 + y) && y<strlen(x))
							cout<<" ";
						else
							cout<<ran;
					}
					else
						cout<<ran;

				}

			cout<<"\n";
			}
		delay(70);
		clrscr();
		}while(t<=80);

	getch();
}