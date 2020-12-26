#include <iostream>
#include <graphics.h>
#include <windows.h>
using namespace std;
class shape
{
protected:
    int color;
public:
    shape()
    {
        color = 1;
    }
    shape(int x)
    {
        color = x;
    }
    void setColor(int x)
    {
        color = x;
    }
    int getcolor()
    {
        return color;
    }
};
class Point
{
    int x,y;
public:
    Point()
    {
        x = y = 0;
    }
    Point(int _num)
    {
        x = y = _num;
    }
    Point(int _x,int _y)
    {
        x = _x;
        y = _y;
    }
    void setXY(int& _x,int& _y)
    {
        x = _x;
        y = _y;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    void printPoint()
    {
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
    ~Point()
    {
    }
};
class Circle:public shape
{
    Point p;
    int radius;
public:
    Circle():p()
    {
        color = 7;
        radius = 5;
    }
    Circle(int _x,int _y):p(_x,_y)
    {
        color = 7;
        radius = 5;
    }
    Circle(int _x,int _y,int _color,int R):p(_x,_y)
    {
        color = _color;
        radius = R;
    }
    Circle(Point _p,int _color,int R):p(_p.getX(),_p.getY())
    {
        color = _color;
        radius = R;
    }
    void setter(int _x,int _y,int R,int _color)
    {
        radius = R;
        color = _color;
        p.setXY(_x,_y);
    }
    void fillIn()
    {
        for(radius;radius>0;radius--)
        {
            this->Drow();
        }
    }
    void setRadius(Point _p,int _color,int R)
    {
        p = _p;
        color = _color;
        radius = R;
    }
    Point getPoint()
    {
        return p;
    }
    int getColor()
    {
        return color;
    }
    int getRadius()
    {
        return radius;
    }
    void Drow()
    {
        setcolor(color);
        circle(p.getX(),p.getY(),radius);
    }
    ~Circle()
    {
    }

};
class Triangle:public shape
{
    Point L,T,R;
public:
    Triangle():L(100,200),T(150,50),R(300,200)
    {
        color = 7;
    }
    Triangle(Point _L,Point _T,Point _R):L(_L.getX(),_L.getY()),T(_T.getX(),_T.getY()),R(_R.getX(),_R.getY())
    {
        color = 7;
    }
    Triangle(int _lx,int _ly,int _tx,int _ty,int _rx,int _ry):L(_lx,_ly),T(_tx,_ty),R(_rx,_ry)
    {
        color = 7;
    }
    void setLTR(Point _L,Point _T,Point _R)
    {
        L = _L;
        T = _T;
        R = _R;
    }
    Point getL()
    {
        return L;
    }
    Point getT()
    {
        return T;
    }
    Point getR()
    {
        return R;
    }
    void Drow()
    {
        line(L.getX(),L.getY(),T.getX(),T.getY());
        line(T.getX(),T.getY(),R.getX(),R.getY());
        line(L.getX(),L.getY(),R.getX(),R.getY());
    }
    ~Triangle()
    {
    }


};
class comRectangle:public shape
{
    Point Lp,Rp;
public:
    comRectangle ():Lp(),Rp(),shape(12)
    {

    }
    comRectangle (Point _Lp,Point _Rp):Lp(_Lp.getX(),_Lp.getY()),Rp(_Rp.getX(),_Rp.getY()),shape(12)
    {

    }
    comRectangle (int Lx,int Ly,int Rx,int Ry):Lp(Lx,Ly),Rp(Rx,Ry)
    {
        color = 4;
    }
    /*
    void setLR(Point _Lp,Point _Rp)
    {
        Lp.setXY(_Lp.getX(),_Lp.getY());
        Rp.setXY(_Rp.getX(),_Rp.getY());
    }
    */
    void setXandY(int Lx,int Ly,int Rx,int Ry)
    {
        Lp.setXY(Lx,Ly);
        Rp.setXY(Rx,Ry);
    }
    void Drow()
    {
        setcolor(color);
        rectangle(Lp.getX(),Lp.getY(),Rp.getX(),Rp.getY());
    }
};
class Line:public shape
{
    Point S,E;
public:
    Line():S(),E()
    {
        color = 4;
    }
    Line(int _sx,int _sy,int _ex,int _ey):S(_sx,_sy),E(_ex,_ey)
    {
        color = 4;
    }
    Line(int _sx,int _sy):S(_sx,_sy)
    {
        color = 4;
    }
    Line(Point p):S(p.getX(),p.getY())
    {
        color = 4;
    }
    void setter(int _sx,int _sy,int _ex,int _ey)
    {
        S.setXY(_sx,_sy);
        E.setXY(_ex,_ey);
    }
    void setEnd(int _ex,int _ey)
    {
        E.setXY(_ex,_ey);
    }
    int getXEnd()
    {
        return E.getX();
    }
    int getYEnd()
    {
        return E.getY();
    }
    void setStart(int _sx,int _sy)
    {
        S.setXY(_sx,_sy);
    }
    void setColor(int x)
    {
        color = x;
    }
    void Drow()
    {
        setcolor(color);
        line(S.getX(),S.getY(),E.getX(),E.getY());
    }
    ~Line()
    {

    }
};
class Watch
{
    Point P;
    Line Sec,Min,Hour;
    Circle Pigpoint[4];
    Circle Smallpoint[4];
    Circle Border;
public:
    Watch():P(300,200),Sec(P),Min(P),Hour(P)
    {
        Pigpoint[0].setter(300,40 ,6,5);
        Pigpoint[1].setter(140,200,6,5);
        Pigpoint[2].setter(300,360,6,5);
        Pigpoint[3].setter(460,200,6,5);
        Smallpoint[0].setter(200,100,6,5);
        Smallpoint[1].setter(400,100,6,5);
        Smallpoint[2].setter(400,300,6,5);
        Smallpoint[3].setter(200,300,6,5);
        Min.setColor(6);
        Hour.setColor(9);
    }
    void DrowBorder()
    {
        for(int i=0;i<20;i++)
        {
            Border.setRadius(P,7,190+i);
            Border.Drow();
        }
        Border.setRadius(P,5,2);
        Border.fillIn();
    }
    void DrowPigpoint()
    {
        for(int i=0;i<4;i++)
        {
            Pigpoint[i].fillIn();
            Smallpoint[i].fillIn();
        }
    }
    void Run()
    {
        int i = 0, im = 0, ih = 1;
        int f =10, fh =75;
        int x = 300, mx = 300, hx = 300 ,y = 50, my = 50 ,hy =50;
        int sec = 0 ;
        int m = 0;
        int h = 1;
        while(1)
        {
            //------------------------------------------------------
            if(sec >= 0 && sec <= 15)
            {
            Sec.setEnd(x+(f*i),y+(f*i));
            Sec.Drow();
            delay(1000);
            setcolor(0);
            line(300,200,x+(f*i),y+(f*i));
            if(i==15)
            {
                i=0;
                x = 450;
                y = 200;
            }
            }else if(sec > 15 && sec <= 30)
            {
            Sec.setEnd(x-(f*i),y+(f*i));
            Sec.Drow();
            delay(1000);
            setcolor(0);
            line(300,200,x-(f*i),y+(f*i));
            if(i==15)
            {
                i=0;
                x = 300;
                y = 350;
            }
            }else if(sec > 30 && sec <= 45)
            {
            Sec.setEnd(x-(f*i),y-(f*i));
            Sec.Drow();
            delay(1000);
            setcolor(0);
            line(300,200,x-(f*i),y-(f*i));
            if(i==15)
            {
                i=0;
                x = 150;
                y = 200;
            }}else if(sec > 45 && sec <= 60)
            {
            Sec.setEnd(x+(f*i),y-(f*i));
            Sec.Drow();
            delay(1000);
            setcolor(0);
            line(300,200,x+(f*i),y-(f*i));
            if(i==15)
            {
                i=0;
                x = 300;
                y = 50;
                m++;
                sec = 0;
                im++;
            }}
            //------------------------------------------------------------------------
            if(m >= 0 && m <= 15){
                Min.setEnd(mx+(f*im),my+(f*im));
                setcolor(0);
                line(300,200,mx+(f*(im-1)),my+(f*(im-1)));
                if(im == 15){
                    mx = 450;
                    my = 200;
                    im=0;
                }
            }

            else if(m > 15 && m <= 30){
                Min.setEnd(mx-(f*im),my+(f*im));
                setcolor(0);
                line(300,200,mx-(f*(im-1)),my+(f*(im-1)));
                if(im == 15){

                    mx = 300;
                    my = 350;
                    im=0;
                }
            }
            else if(m > 30 && m <= 45){
                Min.setEnd(mx-(f*im),my-(f*im));
                setcolor(0);
                line(300,200,mx-(f*(im-1)),my-(f*(im-1)));
                if(im == 15){

                    mx = 150;
                    my = 200;
                    im=0;
                }
            }
            else if(m > 45 && m <= 60){
                Min.setEnd(mx+(f*im),my-(f*im));
                setcolor(0);
                line(300,200,mx+(f*(im-1)),my-(f*(im-1)));
                if(m==60)
                {
                mx = 300;
                my = 50;
                m=0;
                h++;
                im=0;
                ih++;
                }
            }
            //--------------------------------------------------------------------------------
            if(h >= 0 && h <= 2){
                Hour.setEnd(hx+(fh*ih),hy+(fh*ih));
                setcolor(0);
                line(300,200,hx+(fh*(ih-1)),hy+(fh*(ih-1)));
                if(ih == 2){
                    hx = 450;
                    hy = 200;
                    ih=0;
                }
            }
            else if(h > 2 && h <= 5){
                Hour.setEnd(hx-(fh*ih),hy+(fh*ih));
                setcolor(0);
                line(300,200,hx-(fh*(ih-1)),hy+(fh*(ih-1)));
                if(ih == 2){
                    hx = 300;
                    hy = 350;
                    ih=0;
                }
            }
            else if(h > 5 && h <= 8){
                Hour.setEnd(hx-(fh*ih),hy-(fh*ih));
                setcolor(0);
                cout<<hx-(fh*ih)<<hy-(fh*ih)<<endl;
                line(300,200,hx-(fh*(ih-1)),hy-(fh*(ih-1)));
                if(ih == 2){
                    hx = 150;
                    hy = 200;
                    ih=0;
                }
            }
            else if(h > 8 && h <= 11){
                Hour.setEnd(hx+(fh*ih),hy-(fh*ih));
                setcolor(0);
                line(300,200,hx+(fh*(ih-1)),hy-(fh*(ih-1)));
                if(ih==2)
                {
                hx = 300;
                hy = 50;
                h=0;
                ih=0;
                }
            }
            cout<<"out "<<ih<<endl;
            Min.Drow();
            Hour.Drow();
            i++;
            sec++;
        }
    }
    void Drow()
    {
        DrowBorder();
        DrowPigpoint();
        Run();
    }
    ~Watch()
    {

    }
};
int main()
{
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver,&gmode,"d:\\tc\\bgi");
    Watch W;
    W.Drow();
    getch();
    closegraph();
    return 0;
}
