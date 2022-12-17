/*Mohd Nasir*/
#include <iostream>
#include <vector>
using namespace std;
int minimumindex(vector<pair<int, int>> v)
{
    int size = v.size(), mini = v[0].second, index = 0;
    for (int i = 0; i < size; i++)
    {
        if (mini > v[i].second)
        {
            mini = v[i].second;
            index = i;
        }
    }
    return index;
}
int main()
{
    int n;
    cout << "queue size :";
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        v[i].first = -1;
    int np, j = 0, pos = 0, count = 0;
    cout << "proce no :";
    cin >> np;
    vector<int> p(np);
    cout << "input process." << endl;
    for (int i = 0; i < np; i++)
        cin >> p[i];
    for (int i = 0; i < np; i++)
    {
        if (pos < n)
        {
            int found = 0;
            for (int k = 0; k < n; k++)
            {
                if (p[i] == v[k].first)
                {
                    found = 1;
                    v[k].second = j;
                    j++;
                    break;
                }
            }
            if (!found)
            {
                v[pos].first = p[i];
                v[pos].second = j;
                j++;
                pos++;
                count++;
            }
        }
        else
        {
            int mini = minimumindex(v);
            int found = 0;
            for (int k = 0; k < n; k++)
            {
                if (p[i] == v[k].first)
                {
                    found = 1;
                    v[k].second = j;
                    j++;
                    break;
                }
            }
            if (!found)
            {
                int index = minimumindex(v);
                v[index].first = p[i];
                v[index].second = j;
                j++;
                count++;
            }
        }
    }
    cout << "No. of hits is :" << np - count << endl;
    cout << "No. of misses is :" << count;
    return 0;
}