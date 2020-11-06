#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
 
using namespace std;
 
typedef pair<int, int> pii;
 
bool comp(const pii &a, const pii &b)
{
    return a.first < b.first;
}
 
int main()
{
    vector<pii> arr;
 
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        arr.push_back(pii(x, y)); 
        /* 
            arr.push_back(make_pair(a,b));
            이때 C++ 11 이상 부터는
            arr.push_back({a,b});로도 쓸 수 있다.
        */
    }
 
    // lower_bound, upper_bound를 쓰기 위해 sort를 해준다.
    sort(arr.begin(), arr.end());
 
    for (int i = 0; i < n; i++)
        cout << "i :: " << i << " x :: " << arr[i].first << " y :: " << arr[i].second << endl;
 
    // x가 5이상인 값이 있는 첫 index를 찾는 과정이다. 
    // vector<pii>::iterator lo_it = lower_bound(arr.begin(), arr.end(), pii(5, 0), comp);
    vector<pii>::iterator lo_it = lower_bound(arr.begin(), arr.end(), make_pair(5, 0));

    printf("lower_bound :: %d\n", lo_it->first);

    // x가 5초과인 값이 있는 첫 index를 찾는 과정이다. 
    vector<pii>::iterator up_it = upper_bound(arr.begin(), arr.end(), pii(5, 0), comp);
    printf("upper_bound :: %d\n", up_it->first);
 
    return 0;
} 
