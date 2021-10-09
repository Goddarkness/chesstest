#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;
int ra( ); //产生随机数

class Chess {
public:
    int a[9] = {0};
    int playerwin();
    int computerwin();
};

class Player {
public :
    void play ( Chess *chess);
};

class Computer{
public :
    void play ( Chess *chess);
};

int Chess::playerwin()   // 判断玩家是否赢，如果win，return 1； 如果lose，return 0
{
    int judgement =0;  // 如果ju为0，函数return0，ju为1，return 1
    for ( int i =0 ; i < 3 ;i++)   //  此处先判断行
    {
        for ( int j =0 ; j < 3-2 ; j++)
        {
            if ( a[i*3+j]==1)
            {
                int count =1;
                for ( int k =  j+1; k <j+3 ; k++)
                {
                    if( a[i*3+k]== 1)
                        count++ ;
                    else
                        break;
                }
                if ( count == 3)
                    judgement = 1;
            }
        }
    }
    for ( int  i= 0 ; i < 3-2 ; i++)
    {
        for ( int j = 0 ; j < 3 ; j++)
        {
            if (a[i*3+j]==1)
            {
                int count =1;
                for ( int k = i+1; k < i+3; k++)
                {

                    if ( a[k*3+j]== 1)
                    count ++;
                else
                    break;
                }
                if ( count == 3)
                    judgement = 1;
            }
        }
    }
    for ( int i =0 ; i<3-2 ; i++)
    {
        for ( int j =0 ; j<3-2; j++ )
        {
            if ( a[i*3+j]==1)
            {
                int count  =1;
                for ( int k=1 ; k<3 ;k++)
                {
                    if ( a[(i+k)*+j+k]==1)
                        count++;
                    else
                        break;
                }
                if ( count ==3)
                    judgement =1;
            }
        }
    }
    if ( judgement == 1)
        return 1;
    else
        return 0;
}

int Chess::computerwin()  //判断电脑是否赢，win，return 1；lose return 0；
{
    int judgement =0;  // 如果ju为0，函数return0，ju为1，return 1
    for ( int i =0 ; i < 3 ;i++)   //  此处先判断行
    {
        for ( int j =0 ; j < 3-2 ; j++)
        {
            if ( a[i*3+j]==2)
            {
                int count =1;
                for ( int k =  j+1; k <j+3 ; k++)
                {
                    if( a[i*3+k]== 2)
                        count++ ;
                    else
                        break;
                }
                if ( count == 3)
                    judgement = 1;
            }
        }
    }
    for ( int  i= 0 ; i < 3-2 ; i++)
    {
        for ( int j = 0 ; j < 3 ; j++)
        {
            if (a[i*3+j]==2)
            {
                int count =1;
                for ( int k = i+1; k < i+3; k++)
                {

                    if ( a[k*3+j]== 2)
                    count ++;
                else
                    break;
                }
                if ( count == 3)
                    judgement = 1;
            }
        }
    }
    for ( int i =0 ; i<3-2 ; i++)
    {
        for ( int j =0 ; j<3-2; j++ )
        {
            if ( a[i*3+j]==2)
            {
                int count  =1;
                for ( int k=1 ; k<3 ;k++)
                {
                    if ( a[(i+k)*+j+k]==2)
                        count++;
                    else
                        break;
                }
                if ( count ==3)
                    judgement =1;
            }
        }
    }
    if ( judgement == 1)
        return 1;
    else
        return 0;
}

void Player::play(Chess *chess)
{
     int n=0,count = 0;
     srand((unsigned)time(0));
     for ( int i= 0; i< 9;i++)
     {
         if(chess->a[i]==0)
            count++;
     }
     if ( count == 9)
     {
         n = ra();
         chess->a[n]=1;
     }

     else
     {
        for (  n = ra() ;chess->a[n] ==1 || chess->a[n] == 2;  )
            {

            }
        chess->a[n] =1 ;
     }
    // cout << n << "  " << count << chess.a[n]  << " "<<endl;
}

void Computer::play(Chess *chess)
{
     int n=0,count = 0;
     srand((unsigned)time(0));
     for ( int i= 0; i< 9;i++)
     {
         if(chess->a[i]==0)
            count++;
     }
     if ( count == 9)
     {
         n = ra();
         chess->a[n]=2;

     }

     else
     {
        for (  n = ra() ;chess->a[n] ==1 || chess->a[n] == 2;  )
            {

            }
        chess->a[n] =2 ;
     }
    //cout << n << "  " << count << endl;
}

int main()
{
    Chess *chess = new Chess;
    Player player;
    Computer computer;
    for (int i = 0 ; i < 9 ; i++)
    {
        player.play( chess );
        if ( chess->playerwin() == 1)
            break;
        computer.play( chess);
        if ( chess->computerwin()==1 )
             break;
    }


    if ( chess->playerwin() == 1)
            cout << " player win" << endl;
       else
            if ( chess->computerwin()==1 )
                  cout << " computer win"  << endl;
      else
            cout << "draw" << endl;
      for ( int i =0 ; i < 3 ; i++)
      {
          for ( int j = 0; j <3 ;j++)
            cout << chess->a[i*3+j] << "\t";
          cout  << endl;
      }
    return 0;
}

int ra ( )
{
    int a[9] = {0};
    int n;
    srand((unsigned)time(0));
    n = rand()%8;
    for ( int i=0 ; i < 9 ; i++)
    {
        a[i] = rand()%8;
        Sleep(500);
    }

    return a[n];

}
