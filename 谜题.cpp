#include <stdio.h>
#include <string.h>
const int maxn = 10;
char a[maxn][maxn];
char b;
int main()
{
    memset(a,0,sizeof(a));
    int m,n;
    bool error = false;
    for (int i = 0; i < 5; i ++)
        for (int j = 0; j < 5; j++)
            {
                a[i][j] = getchar();
                if(a[i][j] == ' ')
                {
                    m = i;
                    n = j;
                }
            }
    getchar();
    while ((b = getchar()) != EOF & b != '0')
    {
        if (b == 'A')
        {
            a[m][n] = a[m-1][n];
            m--;
            a[m][n] = ' ';
        }
        else if (b == 'B')
        {
            a[m][n] = a[m+1][n];
            ++m;
            a[m][n] = ' ';
        }
        else if (b == 'L')
        {
            a[m][n] = a[m][n-1];
            --n;
            a[m][n] = ' ';
        }
        else if (b == 'R')
        {
            a[m][n] = a[m][n+1];
            ++n;
            a[m][n] = ' ';
        }
        else
        {
            printf("This puzzle has no final configuration\n");
            error = true;
            break;
        }
    }
    if(!error)
    {   for (int i = 0;i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
                printf("%c\t",a[i][j]);
            putchar('\n');
        }
    }
    return 0;
}
