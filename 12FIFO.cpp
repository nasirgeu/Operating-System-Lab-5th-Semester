#include <iostream>
#include <vector>
using namespace std;
int IsPresent(vector<int> v, int key)
{
    int size = v.size();
    for (int i = 0; i < size; i++)
        if (v[i] == key)
            return 1;
    return 0;
}
int main()
{
    int ms, nop, count = 0, f = 0, s = 0;
    cout << "input cache size :";
    cin >> ms;
    vector<int> cv(ms, -1);
    cout << "Input no of processes :";
    cin >> nop;
    cout << "Input processes" << endl;
    vector<int> pv(nop);
    for (int i = 0; i < nop; i++)
        cin >> pv[i];
    for (int i = 0; i < nop; i++)
    {
        if (f < ms)
        {
            int found = IsPresent(cv, pv[i]);
            if (!found)
            {
                cv[f] = pv[i];
                f++;
                count++;
            }
        }
        else
        {
            int found = IsPresent(cv, pv[i]);
            if (!found)
            {
                cv[s] = pv[i];
                f++;
                count++;
                s++;
            }
        }
        if (s == ms)
            s = 0;
    }
    cout << "No. of misses (Pages Faults) is :" << count<<endl;
    cout << "No. of hits is :" << nop - count << endl;
    return 0;
}