#include<bits/stdc++.h>
using namespace std;

int a[10][10]={0}; //九宮格陣列
int d=1; //判斷此時是否可以再任意九宮格填放，若是則1，否則0
int fix=0; //判斷目前是圈還是叉的回合
int x,y; //座標
int scorex=0,scoreo=0; //連線數


void printgame() //輸出目前戰況
{
    cout << "==========================================================\n|";
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            if(a[i][j]==1) cout << "  X  ";
            else if(a[i][j]==2) cout << "  O  ";
            else cout << (i-1)/3*3+(j-1)/3+1<<"("<<(i-1)%3*3+(j-1)%3+1<<") ";
            if(j%3==0) cout <<"||";
            else cout <<"|";
        }
        if(i%3==0) cout<<"\n==========================================================\n|";
        else cout <<"\n----------------------------------------------------------\n|";
    }
}

void turn() //判斷下回合是否可以自由選
{
    int k=(x-1)/3*3,w=(x-1)%3*3;
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(a[k+i][w+j]==0)
            {
                d=0;
                return;
            }
        }
    }
    d=1;
}

void judge() //判斷連線數
{
    scorex=0;scoreo=0;
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=7;j+=3)
        {
            if(a[i][j]==a[i][j+1]&&a[i][j]==a[i][j+2]&&a[i][j]!=0) //橫的連線
            {
                if(a[i][j]==1) scorex++;
                else scoreo++;
            }
            if(a[j][i]==a[j+1][i]&&a[j][i]==a[j+2][i]&&a[j][i]!=0) //直的連線
            {
                if(a[j][i]==1) scorex++;
                else scoreo++;
            }
        }
        int k=(i-1)/3*3+1,w=(i-1)%3*3+1;
        if(((a[k][w]==a[k+1][w+1]&&a[k][w]==a[k+2][w+2])||(a[k][w+2]==a[k+1][w+1]&&a[k][w+2]==a[k+2][w]))&&a[k+1][w+1]!=0) //斜的連線
        {
            if(a[k+1][w+1]==1) scorex++;
            else scoreo++;
        }

    }
    cout<<"x:"<<scorex<<"\n";
    cout<<"o:"<<scoreo<<"\n";
}

void play()
{
    if(d==1)
    {
        cout << "輸入兩個數\n";
        if(fix==0) cout << "現在是x的回合\n";
        else cout << "現在是o的回合\n";
        do
        {
            cin >> x >> y;
            if(x<1||x>9||y<1||y>9||a[(x-1)/3*3+(y-1)/3+1][(x-1)%3*3+(y-1)%3+1]!=0) cout << "請再輸入一次\n"; //防止輸入錯誤程式崩潰
        }while (x<1||x>9||y<1||y>9||a[(x-1)/3*3+(y-1)/3+1][(x-1)%3*3+(y-1)%3+1]!=0);
        if(fix==0) a[(x-1)/3*3+(y-1)/3+1][(x-1)%3*3+(y-1)%3+1]=1;
        else a[(x-1)/3*3+(y-1)/3+1][(x-1)%3*3+(y-1)%3+1]=2;
    }
    else
    {
        cout << "請選擇要在第"<<x<<"個九宮格的哪格填入\n";
        if(fix==0) cout << "現在是x的回合\n";
        else cout << "現在是o的回合\n";
        do
        {
            cin >> y;
            if(y<1||y>9||a[(x-1)/3*3+(y-1)/3+1][(x-1)%3*3+(y-1)%3+1]!=0) cout << "請再輸入一次\n";
        }while (y<1||y>9||a[(x-1)/3*3+(y-1)/3+1][(x-1)%3*3+(y-1)%3+1]!=0);
        if(fix==0) a[(x-1)/3*3+(y-1)/3+1][(x-1)%3*3+(y-1)%3+1]=1;
        else a[(x-1)/3*3+(y-1)/3+1][(x-1)%3*3+(y-1)%3+1]=2;
    }
    x=y;
    fix=1-fix;
    turn();
    judge();
}

int main()
{
    int step = 81;
    while(step--) //判斷遊戲是否結束
    {
        printgame();
        play();
        cout << "現在是第" << 81-step<<"回\n";
    }
    printgame();
    if(scorex>scoreo) cout << "x win!";
    else if(scorex<scoreo) cout << "o win!";
    else cout << "平手";
}
