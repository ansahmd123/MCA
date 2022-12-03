//first come first serve CPU scheduling algo implemented using vector of vector.

#include <bits/stdc++.h>
using namespace std;

bool compareArrivalTime(const vector<int> &v1, const vector<int> &v2)
{
    return v1[1] < v2[1];
}

bool compareId(const vector<int> &v1, const vector<int> &v2){
    return v1[0] < v2[0];
}
int main()
{
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int total_response_time = 0;

    vector<vector<int>> process;
    int n;
    cout << "Enter number of processes:";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        temp.push_back(i + 1);
        cout << "Enter arrival time of process " << i + 1 << ": ";
        int arrival_time;
        cin >> arrival_time;
        temp.push_back(arrival_time);
        cout << "Enter burst time of process " << i + 1 << ": ";
        int burst_time;
        cin >> burst_time;
        temp.push_back(burst_time);

        process.push_back(temp);
    }
    sort(process.begin(), process.end(), compareArrivalTime);

    for (int i = 0; i < process.size(); i++)
    {
        if (i == 0)
        {
            int first_time_cpu_time = process[i][1];
            process[i].push_back(first_time_cpu_time);
        }
        else{
            int first_time_cpu_time = max(process[i - 1][4], process[i][1]);
            process[i].push_back(first_time_cpu_time);
        }

        int completion_time = process[i][3] + process[i][2];
        process[i].push_back(completion_time);
        int turnaround_time = process[i][4] - process[i][1];
        process[i].push_back(turnaround_time);
        int waiting_time = process[i][5] - process[i][2];
        process[i].push_back(waiting_time);
        int response_time = process[i][3] - process[i][1];
        process[i].push_back(response_time);

    }

    sort(process.begin(), process.end(),compareId);

    for(int i = 0 ; i < process.size() ; i++){
        total_turnaround_time += process[i][5];
        total_waiting_time += process[i][6];
        total_response_time += process[i][7];
    }
    // displaying data
    cout << "#P\t"
         << "AT\t"
         << "BT\t"
         << "ST\t"
         << "CT\t"
         << "TAT\t"
         << "WT\t"
         << "RT"
         << endl;
    for (int i = 0; i < process.size(); i++)
    {
        for (int j = 0; j < process[i].size(); j++)
        {
            cout << process[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "Average Turnaround Time: " << (float)total_turnaround_time / n << endl;
    cout << "Average Waiting Time: " << (float)total_waiting_time / n << endl;
    cout << "Average Response Time: " << (float)total_response_time / n << endl;

    return 0;
}