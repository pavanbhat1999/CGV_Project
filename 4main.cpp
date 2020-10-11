
#include<iostream>


class ball
{
	public:
	int x,y,x1,y1,x2,y2,mx,my;

	
	ball(int m,int n)
	{
		x=m;
		y=n;
		x1=x-10;
		x2=x+10;
		y1=y-10;
		y2=y+10;
		mx=5;
		my=5;
	}


	void move(int mx,int my);
	void reorder();
	void bounce();
	void reset()
	{
			x=170;
			y=250;
			mx=5;
			my=5;

	}
	
	void bnc()
	{
		my=-my;
	}



};

void ball::reorder()
{
	x1=x-10;
	y1=y-10;
	x2=x+10;
	y2=y+10;

}
void ball::move(int mx,int my)
{
	x=x+mx;
	y=y+my;
}
void ball::bounce()
{
	if(y2==370)
	{
		my=-my;
	}
	else if(x2==450)
	{
		mx=-mx;
	}
	else if(y1==20)
	{
		my=-my;
	}
	else if(x1==150)
	{
		mx=-mx;
	}


}
class bumper
{
	public:
	int x,x1,x2,m,n;
	bumper()
	{
		x=250;
		x1=x-40;
		x2=x+40;
	}
	void left()
	{
		x=x-10;
	}
	void right()
	{
		x=x+10;
	}
	void breorder()
	{
		x1=x-40;
		x2=x+40;
	}
};
class brick
{
	public:
	int x,y,x1,y1,x2,y2;

	void bk()
	{
		x1=x-25;
		y1=y-10;
		x2=x+25;
		y2=y+10;
	}
	void brk()
	{
		x1=150;
		y1=20;
		x2=450;
		y2=400;


	}
};

void main()
{
	int gd,gm;
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");
	ball b(170,250);
	bumper p;
	char ch;
	brick br[45];
	int i,a=1,k,ll=3,bb=0,l=1,lbr=18,bl=lbr,d=30;

	setcolor(BLACK);


	do
	{
		clrscr();
		setcolor(BLACK);
		cout<<"\t\t\t\tBRICK BREAKER\t\t\t\t\t\n\nLEVEL:"<<l<<"\n\nLIFES LEFT:"<<ll<<"\n\nBRICKS LEFT:"<<bl<<"\n\nBRICKS BROKEN:"<<bb;
		rectangle(150,20,450,400);

		bar(b.x1,b.y1,b.x2,b.y2);
		bar(p.x1,370,p.x2,400);
		b.move(b.mx,b.my);
		b.reorder();


		k=lbr;
		while(a>0)
		{

			br[a].x=175;
			br[a].y=55;
			for(i=1;i<=lbr;i++)
			{
				br[i].bk();

				if(br[i].x2<450)
				{
					br[i+1].x=br[i].x+50;
					br[i+1].y=br[i].y;
				}
				if(br[i].x2==450)
				{

					br[i+1].x=175;
					br[i+1].y=br[i].y+20;
				}


			}
			a--;
		}
		for(i=1;i<=lbr;i++)
		{
			rectangle(br[i].x1,br[i].y1,br[i].x2,br[i].y2);
		}

		if(b.y1==20)
		{
			b.bounce();
		}
		if(b.y2==400)
		{

			b.reset();
			ll--;
			if(ll==0)
			{
				a=1;
				ll=3;
				bl=lbr;
				bb=0;
			}


		}
		if(b.x2==450)
		{
			b.bounce();
		}


		if(b.x1==150)
		{
			b.bounce();
		}


		if(b.y2==370 && b.x1>=p.x1-10 && b.x2<=p.x2+10)
		{
			b.bounce();
		}



		if(kbhit())
		{
			switch (ch=getch())
			{
				case 'n':
				{
					if(p.x1>150)
					{
						p.left();
						p.breorder();

					}
					break;
				}
				case 'm':
				{
					if(p.x2<450)
					{
						p.right();
						p.breorder();

					}
					break;
				}
				default:
				break;
			}
		}
		for(i=lbr;i>=1 && i==k;i--)
		{

			if(b.y1==br[i].y2 && b.x>=br[i].x1 && b.x<=br[i].x2
				|| b.x2==br[i].x1 && b.y<=br[i].y2 && b.y>=br[i].y1
				|| b.x1==br[i].x2 && b.y<=br[i].y2 && b.y>=br[i].y1
				|| b.y2==br[i].y1 && b.x>=br[i].x1 && b.x<=br[i].x2)
			{
				br[i].brk();
				rectangle(br[i].x1,br[i].y1,br[i].x2,br[i].y2);
				b.bnc();
				k++;
				bl--;
				bb++;
			}

			k--;
		}
		if(bb==lbr)
		{
			if(l<3)
			{
				l++;
				lbr=lbr+12;
				ll=3;
				a=1;
				bl=lbr;
				bb=0;
				b.reset();
				d=d-5;
			}
			else if(l>=3)
			{
				cout<<"\n\nGAME OVER!";
			}
			
			
		}
		if(l==2)
		{
			setbkcolor(BLUE);

		}

		else if(l==3)
		{
			setbkcolor(RED);
		}


		delay(d);
	}while(ch!='e');
	getch();
	closegraph();
}