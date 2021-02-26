// str1[i] == str2[j]
// lcs(i, j) = lcs(i-1, j-1) + 1

// str1[i] != str2[j]
// lcs(i, j) = max (lcs(i, j-1), lcs(i-1, j))

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string	str1, str2;
int		lcs[1002][1002];
int		len1, len2;

int		main(void)
{
	cin>>str1>>str2;
	len1 = str1.size();
	len2 = str2.size();
	memset(lcs, 0, sizeof(lcs));
	for(int i=1; i<=len1; i++)
		for(int j=1; j<=len2; j++)
		{
			if (str1[i-1] == str2[j-1])  // 같은 글자가 나오면
				lcs[i][j] = lcs[i-1][j-1]+1;  // lcs(i, j) = lcs(i-1, j-1) + 1
			else
				// lcs(i, j) = max (lcs(i, j-1), lcs(i-1, j))
				lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
		}
	cout<<lcs[len1][len2];
}