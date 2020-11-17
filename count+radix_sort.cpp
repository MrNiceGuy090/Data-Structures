#include <iostream>
using namespace std;
void countSort(int n, int* v, int exp) {
    int i, ret[1001] = { 0 }, fr[1001] = { 0 };
    for (i = 1; i <= n; i++)
    {
        fr[ (v[i]/exp)%10 ]++;
    }
    for (i = 1; i <10; i++)
        fr[i] = fr[i] + fr[i - 1];

    for (i = n; i>=1; i--) {
        ret[fr[ (v[i]/exp) %10 ] ] = v[i];
        fr[ (v[i] / exp) % 10 ]--;
    }
    for (i = 1; i <= n; i++)
        v[i] = ret[i];

}

void radixSort(int n, int* v) {
    int mx = v[1];
    for (int i = 2; i <= n; i++)
        if (v[i] > mx)
            mx = v[i];
    
    for (int exp = 1; mx / exp > 0; exp *= 10)
        countSort(n, v, exp);

}

int main()
{
    int n, v[1001];
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> v[i];
    radixSort(n, v);
    for (int i = 1; i <= n; i++) cout << v[i] << " ";
}
