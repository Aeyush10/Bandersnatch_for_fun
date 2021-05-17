#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

struct card{
	char suit;
	int num;
};

void cdet(int ca, char cs, int &cb, int &cc){
		if(ca <=10)
			{cout<<"The "<<ca<<" of ";
			cb+= ca;}
		else if (ca == 11)
			{cout<<"The jack of ";
			cb+= 10;}
		else if (ca == 12)
			{cout<<"The queen of ";
			cb+= 10;}
		else if (ca == 13)
			{cout<<"The king of ";
			cb+= 10;}
		else if (ca == 14)
			{cout<<"The ace of ";
			cb+= 11;
			cc++;}
		if (cs == 4)
			cout<<"clubs.\n";
			else if (cs == 5)
			cout<<"hearts.\n";
		else if (cs == 6)
			cout<<"diamonds.\n";
		else
			cout<<"spades.\n";
}


void main()
{
	cout<<"\nWelcome to blackjack.\nHere are the rules:\nMinimum bet = 5 dollars\nMaixmum bet = 30 dollars\nYou lose 10 dollars if you go bust";
	cout<<"\nPress any key to begin: ";
	int m = 100,bet,f;
	getch();
	randomize();
	clrscr();
	char ch2;
	int pw = 0, dw = 0;
	do{
	clrscr();
	card c[10];
	int ch;
	int a = 0,f = 1, x = 0,b,dx = 0;
	do{
		cout<<"Total: "<<x;
		cout<<"\n1.Hit";
		cout<<"\n2.Stop\n";
		cin>>ch;

		if(ch==1)
		{
			do{
				c[a].num = random(13) + 2;
				c[a].suit = random(4) + 3;
				if(a == 0)f = 0;
				for(int i = 0; i<a; i++)
				{
					if(c[i].suit == c[a].suit && c[i].num == c[a].num)
					{
						f = 1;
						break;
					}
					f = 0;
				}
			}while(f);

			clrscr();
			x = 0;
			b = 0;
			if(c[a].num <=10)
				cout<<"You drew the "<<c[a].num<<" of ";
			else if (c[a].num == 11)
				cout<<"You drew the jack of ";
			else if (c[a].num == 12)
				cout<<"You drew the queen of ";
			else if (c[a].num == 13)
				cout<<"You drew the king of ";
			else if (c[a].num == 14)
				cout<<"You drew the ace of ";
			if(c[a].suit == 3)
				cout<<"spades.";
			else if (c[a].suit == 4)
				cout<<"clubs.";
			else if (c[a].suit == 5)
				cout<<"hearts.";
			else if (c[a].suit == 6)
				cout<<"diamonds.";
			cout<<" You currently have: \n";
			a++;
			for(int i = 0; i<a;i++)
			{
				cdet(c[i].num,c[i].suit,x,b);
			}
			while(x>21 && b)
			{
				x -=10;
				b--;
			}
			if(x>21)
				{cout<<"You've gone bust. Dealer wins.\n";
				dw++;
				m -=10;
				break;}
			if(x==21)
				{cout<<"Blackjack!\n";

				ch = 2;}
		}

		if(ch==2){
			do{cout<<"\nHow much will you bet?";
			cin>>bet;
			if(bet>30 || bet<5)
			{cout<<"\nInvalid bet. Enter a different amount.";
			f = 1;}
			else
			f = 0;
			}while(f);


			b = 0;
			cout<<"Dealer drew: \n";
			while(dx<x || (dx==x && x<14)){
				do{
					c[a].num = random(13) + 2;
					c[a].suit = random(4) + 3;
					if(a == 0)f = 0;
					for(int i = 0; i<a; i++)
					{
						if(c[i].suit == c[a].suit && c[i].num == c[a].num)
						{
							f = 1;
							break;
						}
						f = 0;
					}
				}while(f);
				cdet(c[a].num,c[a].suit,dx,b);
				a++;
				while(dx>21 && b)
					dx-=10;
			}

			if (dx == x)
			{
				cout<<"Dealer Total:"<<dx;
				cout<<"\nDraw.";
			}
			else if(dx <=21)
				{
					cout<<"Dealer Total:"<<dx;
					cout<<"\nDealer wins.";
					m-=bet;
					dw++;
				}
			else
				{
					cout<<"Dealer went bust.";
					cout<<"\nPlayer wins.";
					m +=bet;
					pw++;
				}

		}

	}while(ch==1);
	cout<<"\nDealer Wins: "<<dw;
	cout<<"\nPlayer Wins: "<<pw;
	cout<<"\nMoney: "<<m;
	cout<<"\nPlay Again? (y/n): ";
	cin>>ch2;
	}while(ch2 == 'y');
}