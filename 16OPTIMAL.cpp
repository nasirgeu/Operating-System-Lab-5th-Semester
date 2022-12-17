/*Mohd Nasir (Optimal)*/
#include <iostream>
#include <vector>
#include <stdbool.h>
using namespace std;
bool hit(vector<int> &arr, int key)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            return true;
    return false;
}
int rightmost(vector<int> &f, vector<int> &p, int k)
{
    int nf = f.size(), np = p.size();
    int index = 0, maxindex = 0, ipos = 0, j;
    for (int i = 0; i < nf; i++)
    {
        for (j = k + 1; j < np; j++)
        {
            if (f[i] == p[j])
            {
                index = j;
                break;
            }
        }
        if (j == np)
            return i;
        else
        {
            if (maxindex < index)
            {
                maxindex = index;
                ipos = i;
            }
        }
    }
    return ipos;
}
int main()
{
    int fs, pno, count = 0, j = 0;
    cout << "frame size :";
    cin >> fs;
    vector<int> f(fs, -1);
    cout << "input no of processor :";
    cin >> pno;
    vector<int> p(pno);
    for (int i = 0; i < pno; i++)
        cin >> p[i];
    for (int i = 0; i < pno; i++)
    {
        if (j < fs)
        {
            bool found = hit(f, p[i]);
            if (!found)
            {
                f[j] = p[i];
                j++;
                count++;
            }
        }
        else
        {
            bool found = hit(f, p[i]);
            if (!found)
            {
                int index;
                index = rightmost(f, p, i);
                f[index] = p[i];
                count++;
            }
        }
    }
    cout << "No. of hits is :" << pno - count << endl;
    cout << "No. of misses is :" << count;
    return 0;
}