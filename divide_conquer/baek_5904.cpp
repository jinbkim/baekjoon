#include <iostream>
using namespace std;

int     len[30];  // len[i] : 수열 s(i)의 길이
int     n, i;

void    divide_conquer(int v, int cnt)
{
    if (cnt == 0)  // 기저 사례. == if (len[cnt] == 3)
    {
        if (v == 0)
            cout<<'m';
        else
            cout<<'o';
        return ;
    }
    if (v < len[cnt-1])  // 3분할중 왼쪽 일때
        divide_conquer(v, cnt-1);
    else if (len[cnt-1]<=v && v<len[cnt-1]+cnt+3)  // 3분할중 가운데 일때
    {
        if (v == len[cnt-1])
            cout<<'m';
        else
            cout<<'o';
        return ;
    }
    else if (len[cnt-1]+cnt+3 <= v)  // 3분할중 오른쪽 일때
        divide_conquer(v-len[cnt-1]-cnt-3, cnt-1);
}

int     main(void)
{
    cin>>n;
    len[0] = 3;  // s(0) 수열의 길이
    for(i=1; len[i-1]<n; i++)
        len[i] = 2*len[i-1]+(i+3);  // dp
    divide_conquer(n-1, i-1);
}