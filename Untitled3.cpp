#include<bits/stdc++.h>
using namespace std;

int a[10][10]={0}; //�E�c��}�C
int d=1; //�P�_���ɬO�_�i�H�A���N�E�c����A�Y�O�h1�A�_�h0
int fix=0; //�P�_�ثe�O���٬O�e���^�X
int x,y; //�y��
int scorex=0,scoreo=0; //�s�u��


void printgame() //��X�ثe�Ԫp
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

void turn() //�P�_�U�^�X�O�_�i�H�ۥѿ�
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

void judge() //�P�_�s�u��
{
    scorex=0;scoreo=0;
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=7;j+=3)
        {
            if(a[i][j]==a[i][j+1]&&a[i][j]==a[i][j+2]&&a[i][j]!=0) //��s�u
            {
                if(a[i][j]==1) scorex++;
                else scoreo++;
            }
            if(a[j][i]==a[j+1][i]&&a[j][i]==a[j+2][i]&&a[j][i]!=0) //�����s�u
            {
                if(a[j][i]==1) scorex++;
                else scoreo++;
            }
        }
        int k=(i-1)/3*3+1,w=(i-1)%3*3+1;
        if(((a[k][w]==a[k+1][w+1]&&a[k][w]==a[k+2][w+2])||(a[k][w+2]==a[k+1][w+1]&&a[k][w+2]==a[k+2][w]))&&a[k+1][w+1]!=0) //�ת��s�u
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
        cout << "��J��Ӽ�\n";
        if(fix==0) cout << "�{�b�Ox���^�X\n";
        else cout << "�{�b�Oo���^�X\n";
        do
        {
            cin >> x >> y;
            if(x<1||x>9||y<1||y>9||a[(x-1)/3*3+(y-1)/3+1][(x-1)%3*3+(y-1)%3+1]!=0) cout << "�ЦA��J�@��\n"; //�����J���~�{���Y��
        }while (x<1||x>9||y<1||y>9||a[(x-1)/3*3+(y-1)/3+1][(x-1)%3*3+(y-1)%3+1]!=0);
        if(fix==0) a[(x-1)/3*3+(y-1)/3+1][(x-1)%3*3+(y-1)%3+1]=1;
        else a[(x-1)/3*3+(y-1)/3+1][(x-1)%3*3+(y-1)%3+1]=2;
    }
    else
    {
        cout << "�п�ܭn�b��"<<x<<"�ӤE�c�檺�����J\n";
        if(fix==0) cout << "�{�b�Ox���^�X\n";
        else cout << "�{�b�Oo���^�X\n";
        do
        {
            cin >> y;
            if(y<1||y>9||a[(x-1)/3*3+(y-1)/3+1][(x-1)%3*3+(y-1)%3+1]!=0) cout << "�ЦA��J�@��\n";
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
    while(step--) //�P�_�C���O�_����
    {
        printgame();
        play();
        cout << "�{�b�O��" << 81-step<<"�^\n";
    }
    printgame();
    if(scorex>scoreo) cout << "x win!";
    else if(scorex<scoreo) cout << "o win!";
    else cout << "����";
}
