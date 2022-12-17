/*arr[0].pno = 0, arr[1].pno = 1, arr[2].pno = 2, arr[3].pno = 3, arr[4].pno = 4;
arr[0].ari = 0, arr[1].ari = 1, arr[2].ari = 2, arr[3].ari = 3, arr[4].ari = 4;
arr[0].bur = 4, arr[1].bur = 3, arr[2].bur = 1, arr[3].bur = 5, arr[4].bur = 2;
arr[0].pri = 2, arr[1].pri = 3, arr[2].pri = 4, arr[3].pri = 5, arr[4].pri = 5;*/
#include <iostream>
#include <stdbool.h>
#include <algorithm>
using namespace std;
class DataDetails
{
public:
    int ari, pno, bur, pri;
    int ct, tat, wt;
    bool visit;
};
bool comparator(DataDetails d1, DataDetails d2)
{
    if (d1.pri != d2.pri)   
        return (d1.pri < d2.pri);
    else
    {
        if (d1.ari != d2.ari)
            return (d1.ari < d2.ari);
        return (d1.pno < d2.pno);
    }
}
bool comparatorPno(DataDetails d1, DataDetails d2)
{
    return (d1.pno < d2.pno);
}
int main()
{
    int n, ti = 0, ch = 0;
    cout << "input n:";
    cin >> n;
    float avgtat = 0, avgwt = 0;
    vector<DataDetails> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i].pno = i;
        cin >> arr[i].ari;
        cin >> arr[i].bur;
        cin >> arr[i].pri;
    }
    for (int i = 0; i < n; i++)
        arr[i].visit = false;
    sort(arr.begin(), arr.end(), comparator);
    for (int i = 0; i < n; i++)
    {
        ch = 0;
        for (int j = 0; j < n; j++)
        {
            if (!arr[j].visit && ti >= arr[j].ari)
            {
                ti += arr[j].bur;
                arr[j].ct = ti;
                arr[j].tat = arr[j].ct - arr[j].ari;
                arr[j].wt = arr[j].tat - arr[j].bur;
                avgtat += arr[j].tat;
                avgwt += arr[j].wt;
                arr[j].visit = true;
                ch = 1;
                break;
            }
        }
        if (!ch)
        {
            ti++;
            i--;
        }
    }
    sort(arr.begin(), arr.end(), comparatorPno);
    cout << endl;
    cout << " *********SOLUTION" << endl;
    cout << "PN "
         << "AT "
         << "BT "
         << "CT "
         << "TAT "
         << "WT " << endl;
    for (int i = 0; i < n; i++)
        cout << "P" << arr[i].pno << " " << arr[i].ari << " " << arr[i].bur << " " << arr[i].ct << " " << arr[i].tat << " " << arr[i].wt << " " << endl;
    avgtat = avgtat / n;
    avgwt = avgwt / n;
    cout << "Average TurnAroundTime is :" << avgtat << endl;
    cout << "Average WaitingTime is :" << avgwt << endl;
    return 0;
}