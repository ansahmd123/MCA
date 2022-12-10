#include <bits/stdc++.h>
using namespace std;

bool sortcol(const vector<int> &v1, const vector<int> &v2)
{
    return v1[1] < v2[1];
}

bool isSafe(int i,int prev_ct,vector<vector<int>> Process){
    if(prev_ct > Process[0][1] && prev_ct > Process[0][1]);
    int n = Process.size();
    for(int j = i+1;j<n;j++){
        if(prev_ct>Process[j][1]){
            return true;
        }
    }

    return false;
}
    
int foundMin(int i,vector<vector<int>> Process){
    for (int j = i; j < Process.size(); j++)
    {
        
    }
    
    
}

int main()
{
    int n;
    cout << "Enter number of process:";
    cin >> n;

    vector<vector<int>> Process;

    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        temp.push_back(i + 1);
        int arr_time, bur_time;
        cout << "Enter arrival time and burst time for process" << i + 1 << ": ";
        cin >> arr_time >> bur_time;
        temp.push_back(arr_time);
        temp.push_back(bur_time);
        Process.push_back(temp);
    }

    cout << "Displaying the data:" << endl;
    cout << "#P\t"
         << "AT\t"
         << "BT" << endl;
    for (int i = 0; i < Process.size(); i++)
    {
        for (int j = 0; j < Process[i].size(); j++)
        {
            cout << Process[i][j] << "\t";
        }
        cout << endl;
    }

    // sorting according to arrival time
    sort(Process.begin(), Process.end(), sortcol);

    cout << "Displaying sorted data:" << endl;
    cout << "#P\t"
         << "AT\t"
         << "BT" << endl;
    for (int i = 0; i < Process.size(); i++)
    {
        for (int j = 0; j < Process[i].size(); j++)
        {
            cout << Process[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        if(i==0){
            int start_time = Process[i][1];
            Process[i].push_back(start_time);

            int completion_time = Process[i][3] + Process[i][2];
            Process[i].push_back(completion_time);

            int turnaround_time = Process[i][4] - Process[i][1];
            Process[i].push_back(turnaround_time);

            int waiting_time = Process[i][5] - Process[i][2];
            Process[i].push_back(waiting_time);

            int response_time = Process[i][3] - Process[i][1];
            Process[i].push_back(response_time);
        }
        else{
            if(isSafe(i,Process[i-1][4],Process)){
                int foundMin = foundMin(i,Process)

                
                
            }
        }
        
    }

    cout << "Displaying final data:" << endl;
    cout << "#P\t"
         << "AT\t"
         << "BT\t"
         << "ST\t"
         << "CT\t"
         << "TAT\t"
         << "WT\t"
         << "RT" << endl;

    for (int i = 0; i < Process.size(); i++)
    {
        for (int j = 0; j < Process[i].size(); j++)
        {
            cout << Process[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}