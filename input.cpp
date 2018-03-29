#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include <iomanip>
#include <fstream>
#include <string.h>

using namespace std;

class figure
{
protected:
int x; // 1..8 like a..h
int y; // 1..8
int a[9][9];
public:
figure(int x_,int y_,int a_[9][9])
{
x=x_;
y=y_;
for (int i=1; i<9; i++)
for (int j=1; j<9; j++)
a[j]=a_[j];
}


bool is(int i, int j) // попадает ли клетка [i,j] на доску
{
if (i<9 && i>0 && j>0 && j<9)
return true;
return false;
}

bool isfight(int x0, int y0) // бьют ли черные фигуры клетку [x0,y0]
{
// координаты черных фигур
int xk,yk;
int xn[2],yn[2];
int xq,yq;

int count=0;
for (int i=1; i<9; i++)
for (int j=1; j<9; j++)
{
if (a[j]==1)
{ xk=i; yk=j;}
if (a[j]==2)
{ xq=i; yq=j;}
if (a[j]==3)
{
xn[count]=i; yn[count]=j;
count++;
}
}
//черный король
if (abs(xk-x0)<=1 && abs(yk-y0)<=1)
return true;
//черный конь
if ( (is(x0+1,y0+2) && a[x0+1][y0+2]==3)
|| (is(x0+1,y0-2) && a[x0+1][y0-2]==3)
|| (is(x0-1,y0+2) && a[x0-1][y0+2]==3)
|| (is(x0-1,y0-2) && a[x0-1][y0-2]==3)
|| (is(x0+2,y0+1) && a[x0+2][y0+1]==3)
|| (is(x0+2,y0-1) && a[x0+2][y0-1]==3)
|| (is(x0-2,y0+1) && a[x0-2][y0+1]==3)
|| (is(x0-2,y0-1) && a[x0-2][y0-1]==3)
)
return true;
//черный ферзь

// горизонтали и вертикали
for (int i=xq+1; i<9; i++)
{
if (x0==i && y0==yq)
return true;
if (a[yq]!=0)
break;
}
for (int i=xq-1; i>0; i--)
{
if (x0==i && y0==yq)
return true;
if (a[yq])
break;
}
for (int j=yq+1; j<9; j++)
{
if (x0==xq && j==y0)
return true;
if (a[xq][j])
break;
}
for (int j=yq-1; j>0; j--)
{
if (x0==xq && j==y0)
return true;
if (a[xq][j])
break;
}
// диагонали
for (int i=1; xq+i<9 && yq+i<9; i++)
{
if (x0==xq+i && y0==yq+i)
return true;
if (a[xq+i][yq+i])
break;
}
for (int i=1; xq-i>0 && yq-i>0; i++)
{
if (x0==xq-i && y0==yq-i)
return true;
if (a[xq-i][yq-i])
break;
}
for (int i=1; xq-i>0 && yq+i<9; i++)
{
if (x0==xq-i && y0==yq+i)
return true;
if (a[xq-i][yq+i])
break;
}
for (int i=1; xq+i<9 && yq-i>0; i++)
{
if (x0==xq+i && y0==yq-i)
return true;
if (a[xq+i][yq-i])
break;
}

return false;
}

bool isfight(int x0, int y0, int a[9][9], bool fl) // бьют ли черные фигуры клетку [x0,y0]
// если там черная фигура и никто не бьет,то
// fl
{
// координаты черных фигур
int xk,yk;
int xn[2],yn[2];
int xq,yq;

int count=0;
for (int i=1; i<9; i++)
for (int j=1; j<9; j++)
{
if (a[j]==1)
{ xk=i; yk=j;}
if (a[j]==2)
{ xq=i; yq=j;}
if (a[j]==3)
{
xn[count]=i; yn[count]=j;
count++;
}
}
//черный король
if (abs(xk-x0)<=1 && abs(yk-y0)<=1)
return true;
//черный конь
if ( (is(x0+1,y0+2) && a[x0+1][y0+2]==3)
|| (is(x0+1,y0-2) && a[x0+1][y0-2]==3)
|| (is(x0-1,y0+2) && a[x0-1][y0+2]==3)
|| (is(x0-1,y0-2) && a[x0-1][y0-2]==3)
|| (is(x0+2,y0+1) && a[x0+2][y0+1]==3)
|| (is(x0+2,y0-1) && a[x0+2][y0-1]==3)
|| (is(x0-2,y0+1) && a[x0-2][y0+1]==3)
|| (is(x0-2,y0-1) && a[x0-2][y0-1]==3)
)
return true;
//черный ферзь

// горизонтали и вертикали
for (int i=xq+1; i<9; i++)
{
if (x0==i && y0==yq)
return true;
if (a[yq]!=0)
break;
}
for (int i=xq-1; i>0; i--)
{
if (x0==i && y0==yq)
return true;
if (a[yq])
break;
}
for (int j=yq+1; j<9; j++)
{
if (x0==xq && j==y0)
return true;
if (a[xq][j])
break;
}
for (int j=yq-1; j>0; j--)
{
if (x0==xq && j==y0)
return true;
if (a[xq][j])
break;
}
// диагонали
for (int i=1; xq+i<9 && yq+i<9; i++)
{
if (x0==xq+i && y0==yq+i)
return true;
if (a[xq+i][yq+i])
break;
}
for (int i=1; xq-i>0 && yq-i>0; i++)
{
if (x0==xq-i && y0==yq-i)
return true;
if (a[xq-i][yq-i])
break;
}
for (int i=1; xq-i>0 && yq+i<9; i++)
{
if (x0==xq-i && y0==yq+i)
return true;
if (a[xq-i][yq+i])
break;
}
for (int i=1; xq+i<9 && yq-i>0; i++)
{
if (x0==xq+i && y0==yq-i)
return true;
if (a[xq+i][yq-i])
break;
}

if (a[x0][y0] && a[x0][y0]!=4)
return fl;
return false;
}


virtual void moves() {}
};

class knight: public figure
{
public:
knight(int x_,int y_,int a_[9][9]) : figure(x_,y_,a_)
{}

char xtoc(int x)
{
return (char)(x+96);
}

void moves(ofstream &out)
{
cout<<"moves black knight ("<<xtoc(x)<<y<<"):"<<endl;
out<<"moves black knight ("<<xtoc(x)<<y<<"):"<<endl;
if (is(x+2,y+1) && !a[x+2][y+1])
{
cout<<xtoc(x+2)<<y+1<<" ";
out<<xtoc(x+2)<<y+1<<" ";}
if (is(x+2,y-1) && !a[x+2][y-1])
{cout<<xtoc(x+2)<<y-1<<" ";
out<<xtoc(x+2)<<y-1<<" ";}
if (is(x-2,y+1) && !a[x-2][y+1])
{cout<<xtoc(x-2)<<y+1<<" ";
out<<xtoc(x-2)<<y+1<<" ";}
if (is(x-2,y-1) && !a[x-2][y-1])
{cout<<xtoc(x-2)<<y-1<<" ";
out<<xtoc(x-2)<<y-1<<" ";}

if (is(x+1,y+2) && !a[x+1][y+2])
{cout<<xtoc(x+1)<<y+2<<" ";
out<<xtoc(x+1)<<y+2<<" ";}
if (is(x+1,y-2) && !a[x+1][y-2])
{cout<<xtoc(x+1)<<y-2<<" ";
out<<xtoc(x+1)<<y-2<<" ";}
if (is(x-1,y+2) && !a[x-1][y+2])
{cout<<xtoc(x-1)<<y+2<<" ";
out<<xtoc(x-1)<<y+2<<" ";}
if (is(x-1,y-2) && !a[x-1][y-2])
{cout<<xtoc(x-1)<<y-2<<" ";
out<<xtoc(x-1)<<y-2<<" ";}
cout<<endl;
out<<endl;
}
};

class queen: public figure
{
public:
queen(int x_,int y_,int a_[9][9]) : figure(x_,y_,a_)
{}

char xtoc(int x)
{
return (char)(x+96);
}

void moves(ofstream &out)
{
cout<<"moves black queen:"<<endl;
out<<"moves black queen:"<<endl;
int xq=x;
int yq=y;
for (int i=xq+1; i<9; i++)
{
if (a[yq]!=0)
break;
cout<<xtoc(i)<<yq<<" ";
out<<xtoc(i)<<yq<<" ";
}
for (int i=xq-1; i>0; i--)
{
if (a[yq])
break;
cout<<xtoc(i)<<yq<<" ";
out<<xtoc(i)<<yq<<" ";
}
for (int j=yq+1; j<9; j++)
{
if (a[xq][j])
break;
cout<<xtoc(xq)<<j<<" ";
out<<xtoc(xq)<<j<<" ";
}
for (int j=yq-1; j>0; j--)
{
if (a[xq][j])
break;
cout<<xtoc(xq)<<j<<" ";
out<<xtoc(xq)<<j<<" ";
}
// диагонали
for (int i=1; xq+i<9 && yq+i<9; i++)
{
if (a[xq+i][yq+i])
break;
cout<<xtoc(i+xq)<<yq+i<<" ";
out<<xtoc(i+xq)<<yq+i<<" ";
}
for (int i=1; xq-i>0 && yq-i>0; i++)
{
if (a[xq-i][yq-i])
break;
cout<<xtoc(xq-i)<<yq-i<<" ";
out<<xtoc(xq-i)<<yq-i<<" ";
}
for (int i=1; xq-i>0 && yq+i<9; i++)
{
if (a[xq-i][yq+i])
break;
cout<<xtoc(xq-i)<<yq+i<<" ";
out<<xtoc(xq-i)<<yq+i<<" ";
}
for (int i=1; xq+i<9 && yq-i>0; i++)
{
if (a[xq+i][yq-i])
break;
cout<<xtoc(i+xq)<<yq-i<<" ";
out<<xtoc(i+xq)<<yq-i<<" ";
}

cout<<endl;
out<<endl;

}
};

class king: public figure
{
int color;
public:
king(int x_,int y_, int color_,int a_[9][9]) : figure(x_,y_,a_) // color: 1 or 4
{
color=color_;
}

char xtoc(int x)
{
return (char)(x+96);
}

void moves(ofstream &out)
{
if (color==1)
{
int xw,yw;
for (int i=1; i<9; i++)
for (int j=1; j<9; j++)
if (a[j]==4)
{
xw=i; yw=j;
i=9; break;
}
cout<<"moves black king:"<<endl;
out<<"moves black king:"<<endl;
if (is(x+1,y+1) && !a[x+1][y+1] && !(abs(x+1-xw)<=1 && abs(y+1-yw)<=1))
{
cout<<xtoc(x+1)<<y+1<<" ";
out<<xtoc(x+1)<<y+1<<" ";
}
if (is(x+1,y-1) && !a[x+1][y-1] && !(abs(x+1-xw)<=1 && abs(y-1-yw)<=1))
{cout<<xtoc(x+1)<<y-1<<" ";
out<<xtoc(x+1)<<y-1<<" ";}
if (is(x-1,y+1) && !a[x-1][y+1] && !(abs(x-1-xw)<=1 && abs(y+1-yw)<=1))
{cout<<xtoc(x-1)<<y+1<<" ";
out<<xtoc(x-1)<<y+1<<" ";}
if (is(x-1,y-1) && !a[x-1][y-1] && !(abs(x-1-xw)<=1 && abs(y-1-yw)<=1))
{cout<<xtoc(x-1)<<y-1<<" ";
out<<xtoc(x-1)<<y-1<<" ";}
if (is(x,y-1) && !a[x][y-1] && !(abs(x-xw)<=1 && abs(y-1-yw)<=1))
{cout<<xtoc(x)<<y-1<<" ";
out<<xtoc(x)<<y-1<<" ";}
if (is(x,y+1) && !a[x][y+1] && !(abs(x-xw)<=1 && abs(y+1-yw)<=1))
{cout<<xtoc(x)<<y+1<<" ";
out<<xtoc(x)<<y+1<<" ";}
if (is(x+1,y) && !a[x+1][y] && !(abs(x+1-xw)<=1 && abs(y-yw)<=1))
{cout<<xtoc(x+1)<<y<<" ";
out<<xtoc(x+1)<<y<<" ";}
if (is(x-1,y) && !a[x-1][y] && !(abs(x-1-xw)<=1 && abs(y-yw)<=1))
{cout<<xtoc(x-1)<<y<<" ";
out<<xtoc(x-1)<<y<<" ";}
cout<<endl;
out<<endl;
}
else
{
cout<<"moves white king:"<<endl;
out<<"moves white king:"<<endl;
int b[9][9];

if (is(x+1,y+1) && !a[x+1][y+1] && !isfight(x+1,y+1))
{
for (int i=1; i<9; i++)
for (int j=1; j<9; j++)
b[j]=a[j];
b[x][y]=0;
b[x+1][y+1]=4;

if (!isfight(x+1,y+1,b,true))
{
cout<<xtoc(x+1)<<y+1<<" ";
out<<xtoc(x+1)<<y+1<<" ";}

}
if (is(x+1,y-1) && !a[x+1][y-1] && !isfight(x+1,y-1))
{
for (int i=1; i<9; i++)
for (int j=1; j<9; j++)
b[j]=a[j];
b[x][y]=0;
b[x+1][y-1]=4;

if (!isfight(x+1,y-1,b,true))
{ cout<<xtoc(x+1)<<y-1<<" ";
out<<xtoc(x+1)<<y-1<<" ";}
}
if (is(x-1,y+1) && !a[x-1][y+1] && !isfight(x-1,y+1))
{
for (int i=1; i<9; i++)
for (int j=1; j<9; j++)
b[j]=a[j];
b[x][y]=0;
b[x-1][y+1]=4;
if (!isfight(x-1,y+1,b,true))
{cout<<xtoc(x-1)<<y+1<<" ";
out<<xtoc(x-1)<<y+1<<" ";}
}
if (is(x-1,y-1) && !a[x-1][y-1] && !isfight(x-1,y-1))
{
for (int i=1; i<9; i++)
for (int j=1; j<9; j++)
b[j]=a[j];
b[x][y]=0;
b[x-1][y-1]=4;

if (!isfight(x-1,y-1,b,true))

{cout<<xtoc(x-1)<<y-1<<" ";
out<<xtoc(x-1)<<y-1<<" ";}
}
if (is(x,y-1) && !a[x][y-1] && !isfight(x,y-1))
{
for (int i=1; i<9; i++)
for (int j=1; j<9; j++)
b[j]=a[j];
b[x][y]=0;
b[x][y-1]=4;

if (!isfight(x,y-1,b,true))

{cout<<xtoc(x)<<y-1<<" ";
out<<xtoc(x)<<y-1<<" ";}
}
if (is(x,y+1) && !a[x][y+1] && !isfight(x,y+1))
{
for (int i=1; i<9; i++)
for (int j=1; j<9; j++)
b[j]=a[j];
b[x][y]=0;
b[x][y+1]=4;

if (!isfight(x,y+1,b,true))

{cout<<xtoc(x)<<y+1<<" ";
out<<xtoc(x)<<y+1<<" ";}
}
if (is(x+1,y) && !a[x+1][y] && !isfight(x+1,y))
{
for (int i=1; i<9; i++)
for (int j=1; j<9; j++)
b[j]=a[j];
b[x][y]=0;
b[x+1][y]=4;

if (!isfight(x+1,y,b,true))

{cout<<xtoc(x+1)<<y<<" ";
out<<xtoc(x+1)<<y<<" ";}
}
if (is(x-1,y) && !a[x-1][y] && !isfight(x-1,y))
{
for (int i=1; i<9; i++)
for (int j=1; j<9; j++)
b[j]=a[j];
b[x][y]=0;
b[x-1][y]=4;

if (!isfight(x-1,y,b,true))

{cout<<xtoc(x-1)<<y<<" ";
out<<xtoc(x-1)<<y<<" "; }
}

cout<<endl;
out<<endl;
}

}
};

class chess
{
int x; // 1..8 like a..h
int y; // 1..8
int a[9][9]; // 0 - empty, 1 - K black, 2 - Q black, 3 - N black, 4 - K white
bool noerror;
king* bk;
king* wk;
knight* bn1,*bn2;
queen* bq;
ofstream out;
public:
void getxy(char s[3]); // здесь нотация (например, h8). получаем x и y
int notationtotype(char c); // K Q N в 1 2 3 соответственно
void checkstartposition(); // проверка, действительно ли король, два коня и ферзь
chess(char fname[30]);
~chess();
void showboard();
bool is(int i, int j); // попадает ли клетка [i,j] на доску
bool isfight(int x0, int y0, bool fl=true); // бьют ли черные фигуры клетку [x0,y0]
// если там черная фигура и никто не бьет,то
// fl
void analyze(); // в какой ситуации находится белый король
void moves();
};

void chess::getxy(char s[3]) // здесь нотация (например, h8). получаем x и y
{
x=(int)s[0]-96;
y=((int)s[1])-48;

if (x<1 || x>8 || y<1 || y>8)
noerror=false;
}

int chess::notationtotype(char c) // K Q N в 1 2 3 соответственно
{
if (c=='K' || c=='k' || c=='к' || c=='К')
return 1;
if (c=='Q' || c=='q')
return 2;
if (c=='N' || c=='n')
return 3;
noerror=false;
return 0;
}

void chess::checkstartposition() // проверка, действительно ли король, два коня и ферзь
{
int k=0,n=0,q=0;

for (int i=1; i<9; i++)
for (int j=1; j<9; j++)
{
if (a[j]==1)
k++;
else if (a[j]==2)
q++;
else if (a[j]==3)
n++;
else if (a[j]!=0)
{
noerror=false;
return;
}
}
if (k!=1 || q!=1 || n!=2)
noerror=false;
}

chess::chess(char fname[30])
{
noerror=true;
ifstream in;
out.open("output.txt");
in.open(fname);
if (!in)
{
cout<<"file "<<fname<<": bad open"<<endl;
out<<"file "<<fname<<": bad open"<<endl;
out.close();
noerror=false;
}
else
{
char ps[3];
char wk[3];
int tp;

for (int i=1; i<9; i++)
for (int j=1; j<9; j++)
a[j]=0;
out<<"start position: "<<endl;
for (int i=0; i<4 && noerror; i++)
{
in>>ps;
out<<ps<<" ";
strcpy(wk,&ps[1]);
getxy(wk);

if (noerror)
{
a[x][y]=notationtotype(ps[0]);
}
else
{
cout<<"bad data in file "<<fname<<endl;
out<<"bad data in file "<<fname<<endl;
out.close();
return;
}
}
in.close();
checkstartposition();
if (!noerror)
{
cout<<"bad start position of black figures from "<<fname<<endl;
out<<"bad start position of black figures from "<<fname<<endl;
out.close();
}
else
{
cout<<"input position of white king (for example, h4): ";
cin>>wk;
out<<"white king: "<<wk<<endl;
getxy(wk);
if (noerror && a[x][y]==0)
a[x][y]=4;
else
{
if (!noerror && a[x][y]==0)
{
cout<<"bad input"<<endl;
out<<"bad input"<<endl;
out.close();
}
else
{
cout<<"this position is not empty"<<endl;
out<<"input position is not empty"<<endl;
out.close();
noerror=false;
}
return;
}

int xb,yb;
for (int i=1; i<9; i++)
for (int j=1; j<9; j++)
if (a[j]==1)
{
xb=i;
yb=j;
i=9;
break;
}
if (abs(x-xb)<=1 && abs(y-yb)<=1)
{
noerror=false;
cout<<"kings can not be side by side"<<endl;
out<<"kings can not be side by side"<<endl;
out.close();
}
}
}

if (noerror)
{
// координаты черных фигур
int xk,yk;
int xn[2],yn[2];
int xq,yq;

int count=0;
for (int i=1; i<9; i++)
for (int j=1; j<9; j++)
{
if (a[j]==1)
{ xk=i; yk=j;}
if (a[j]==2)
{ xq=i; yq=j;}
if (a[j]==3)
{
xn[count]=i; yn[count]=j;
count++;
}
}

bk=new king(xk,yk,1,a);
wk=new king(x,y,4,a);
bn1=new knight(xn[0],yn[0],a);
bn2=new knight(xn[1],yn[1],a);
bq=new queen(xq,yq,a);
}
}

chess::~chess()
{
delete bk;
delete wk;
delete bn1;
delete bn2;
delete bq;
}

void chess::showboard()
{
if (noerror)
{
// x - столбец, y - строка, причем <-> 8-y+1
for (int i=1; i<9; i++)
{
cout<<9-i<<" ";
out<<9-i<<" ";
for (int j=1; j<9; j++)
{
if (a[j][8-i+1]==0)
{ cout<<"-"; out<<"-";}
else if (a[j][8-i+1]==1)
{cout<<"K"; out<<"K";}
else if (a[j][8-i+1]==2)
{cout<<"Q"; out<<"Q";}
else if (a[j][8-i+1]==3)
{cout<<"N"; out<<"N";}
else if (a[j][8-i+1]==4)
{cout<<"W"; out<<"W";}
else
{cout<<"?"; out<<"?";}

cout<<" ";
out<<" ";
}
cout<<endl;
out<<endl;
}

cout<<" a b c d e f g h"<<endl;
out<<" a b c d e f g h"<<endl;

}
}


bool chess::is(int i, int j) // попадает ли клетка [i,j] на доску
{
if (i<9 && i>0 && j>0 && j<9)
return true;
return false;
}
bool chess::isfight(int x0, int y0, bool fl) // бьют ли черные фигуры клетку [x0,y0]
// если там черная фигура и никто не бьет,то
// fl
{
// координаты черных фигур
int xk,yk;
int xn[2],yn[2];
int xq,yq;

int count=0;
for (int i=1; i<9; i++)
for (int j=1; j<9; j++)
{
if (a[j]==1)
{ xk=i; yk=j;}
if (a[j]==2)
{ xq=i; yq=j;}
if (a[j]==3)
{
xn[count]=i; yn[count]=j;
count++;
}
}
//черный король
if (abs(xk-x0)<=1 && abs(yk-y0)<=1)
return true;
//черный конь
if ( (is(x0+1,y0+2) && a[x0+1][y0+2]==3)
|| (is(x0+1,y0-2) && a[x0+1][y0-2]==3)
|| (is(x0-1,y0+2) && a[x0-1][y0+2]==3)
|| (is(x0-1,y0-2) && a[x0-1][y0-2]==3)
|| (is(x0+2,y0+1) && a[x0+2][y0+1]==3)
|| (is(x0+2,y0-1) && a[x0+2][y0-1]==3)
|| (is(x0-2,y0+1) && a[x0-2][y0+1]==3)
|| (is(x0-2,y0-1) && a[x0-2][y0-1]==3)
)
return true;
//черный ферзь

// горизонтали и вертикали
for (int i=xq+1; i<9; i++)
{
if (x0==i && y0==yq)
return true;
if (a[yq]!=0)
break;
}
for (int i=xq-1; i>0; i--)
{
if (x0==i && y0==yq)
return true;
if (a[yq])
break;
}
for (int j=yq+1; j<9; j++)
{
if (x0==xq && j==y0)
return true;
if (a[xq][j])
break;
}
for (int j=yq-1; j>0; j--)
{
if (x0==xq && j==y0)
return true;
if (a[xq][j])
break;
}
// диагонали
for (int i=1; xq+i<9 && yq+i<9; i++)
{
if (x0==xq+i && y0==yq+i)
return true;
if (a[xq+i][yq+i])
break;
}
for (int i=1; xq-i>0 && yq-i>0; i++)
{
if (x0==xq-i && y0==yq-i)
return true;
if (a[xq-i][yq-i])
break;
}
for (int i=1; xq-i>0 && yq+i<9; i++)
{
if (x0==xq-i && y0==yq+i)
return true;
if (a[xq-i][yq+i])
break;
}
for (int i=1; xq+i<9 && yq-i>0; i++)
{
if (x0==xq+i && y0==yq-i)
return true;
if (a[xq+i][yq-i])
break;
}

if (a[x0][y0] && a[x0][y0]!=4)
return fl;
return false;
}

void chess::analyze() // в какой ситуации находится белый король
{
if (noerror)
{
cout<<"analyze position by white king: ";
out<<"analyze position by white king: ";
if (isfight(x,y))
{
if (
(!is(x+1,y+1) || (is(x+1,y+1) && isfight(x+1,y+1))) &&
(!is(x+1,y-1) || (is(x+1,y-1) && isfight(x+1,y-1))) &&
(!is(x-1,y+1) || (is(x-1,y+1) && isfight(x-1,y+1))) &&
(!is(x-1,y-1) || (is(x-1,y-1) && isfight(x-1,y-1))) &&
(!is(x,y+1) || (is(x,y+1) && isfight(x,y+1))) &&
(!is(x,y-1) || (is(x,y-1) && isfight(x,y-1))) &&
(!is(x+1,y) || (is(x+1,y) && isfight(x+1,y))) &&
(!is(x-1,y) || (is(x-1,y) && isfight(x-1,y)))
)
{

cout<<"checkmate"<<endl;
out<<"checkmate"<<endl;
}
else
{
cout<<"check"<<endl;
out<<"check"<<endl;
}
}
else
{
if (
(!is(x+1,y+1) || (is(x+1,y+1) && isfight(x+1,y+1))) &&
(!is(x+1,y-1) || (is(x+1,y-1) && isfight(x+1,y-1))) &&
(!is(x-1,y+1) || (is(x-1,y+1) && isfight(x-1,y+1))) &&
(!is(x-1,y-1) || (is(x-1,y-1) && isfight(x-1,y-1))) &&
(!is(x,y+1) || (is(x,y+1) && isfight(x,y+1))) &&
(!is(x,y-1) || (is(x,y-1) && isfight(x,y-1))) &&
(!is(x+1,y) || (is(x+1,y) && isfight(x+1,y))) &&
(!is(x-1,y) || (is(x-1,y) && isfight(x-1,y)))
)
{
cout<<"stalemate"<<endl;
out<<"stalemate"<<endl;
}
else
{
cout<<"no danger"<<endl;
out<<"no danger"<<endl;
}
}
}
}

void chess::moves()
{
if (noerror)
{
bk->moves(out);
wk->moves(out);
bn1->moves(out);
bn2->moves(out);
bq->moves(out);
out.close();
}
}

int main()
{
char fname[30];
strcpy(fname,"input.txt");

chess game(fname);
game.showboard();
game.analyze();
game.moves();

cout<<"result saved to output.txt"<<endl;

getch();
return 0;
}