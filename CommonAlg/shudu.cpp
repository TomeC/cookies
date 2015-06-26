#include <iostream>
using namespace std;
 
int data[9][9] = {
				 {0,7,0,2,6,0,9,0,0},
				 {3,0,0,0,0,8,0,0,7},
				 {0,9,0,0,5,7,0,0,0},
				 {5,0,0,0,0,0,0,7,0},
				 {0,4,7,3,1,2,8,5,0},
				 {0,8,0,0,0,0,0,0,1},
				 {0,0,0,8,2,0,0,4,0},
				 {7,0,0,6,0,0,0,0,2},
				 {0,0,4,0,3,9,0,8,0}
				};
void output()
{
    int i,j;
    for(i = 0;i < 9;i++)
    {
        for(j = 0;j < 9;j++)
            cout<<data[i][j]<<"\t";
        cout<<endl;
    }
    printf("\n");
}

 int CheckSquare(int line,int col,int num)
{
    int i = (line / 3) * 3;
    int j = (col / 3) * 3;
    int m,n;
    for(m = i;m < i + 3;m++)
        for(n = j;n < j + 3;n++)
            if((data[m][n] == num) && !(m == line && n == col))
                return 0;
    return 1;
}
int CheckLine(int line,int col,int num)
{
    int i = 9;
    while(i--)
        if((data[line][i] == num) && (i != col))
            return 0;
    return 1;
}
 /*检查列冲突*/
int CheckColumn(int line,int col,int num)
{
    int i = 9;
    while(i--)
        if((data[i][col] == num) && (i != line))
            return 0;
    return 1;
}
/*检查i行j列是否可放置num*/
int Check(int i,int j,int num)
{
    return CheckSquare(i,j,num) && CheckLine(i,j,num) && CheckColumn(i,j,num);
}
/*检查是否完成*/
int IsDone()
{
    int i,j;
    for(i = 0;i < 9;i++)
        for(j = 0;j < 9;j++)
            if(!Check(i,j,data[i][j]) || (data[i][j] == 0))
                return 0;
    return 1;
}
 void Calc()
{
    int i,j,x;
    if(IsDone())
    {
        output();
        return;
    }
    for(i = 0;i < 9;i++)
    {
        for(j = 0;j < 9;j++)
        {
            if(data[i][j] == 0)
            {
				for(x = 1; x <= 9;x++)
                {
                    if(Check(i,j,x))
                    {
                        data[i][j] = x;
                        Calc();
                    }
                }
            if(x == 10)
                {
                    data[i][j] = 0;
                    return ;
                }
            }
        }
    }
}

int main ()
{
	Calc();
    output();
}