/*31. В массиве А(N,M) элементы, кратные заданному числу р, пере- местить в начало строк и расположить их в порядке возрастания. */

#include <iostream>

using namespace std;

bool kratn(int x, int p)
{
    if ( !(x % p) )
        return true;
    else
        return false;
}

void swp(int &a, int &b)
{
    int t;
    t = a;
    a = b;
    b = t;
}

void selectsort(int *a, int m)
{
    int i, j, mn, x;
    for ( i = 0; i < m; ++i )
    {
        mn = i;
        x = a[i];
        for ( j = i+1; j < m; ++j )
            if( a[j] < x )
            {
                mn = j;
                x = a[j];
            }
        a[mn] = a[i];
        a[i] = x;
    }
}

void displace(int *a, int m, int p)
{
    int i, k = 0;
    for ( i = 1; i < m; ++i)
        if ( kratn(a[i], p) )
        {
            swp(a[i], a[k]);
            k++;
        }
}

void input(int *a, int m)
{
    int i;
    for ( i = 0; i < m; ++i )
        cin >> a[i];
}

void output(int *a, int m)
{
    int i;
    for ( i = 0; i < m; ++i )
    {
        cout.width(3);
        cout << a[i] << " ";
    }
}

int main()
{
    int n , m, p;
    cin >> n >> m >> p;
    int a[n][m];
    for (int i = 0; i < n; ++i)
    {
        input(a[i], m);
        selectsort(a[i], m);
        displace(a[i], m, p);


    }
    for ( int i = 0; i < n; ++i )
    {
        for ( int j = 0; j < m; ++j )
        {
            cout.width(3);
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
