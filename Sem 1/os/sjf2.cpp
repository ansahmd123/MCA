#include <bits/stdc++.h>
using namespace std;

class Process
{
public:
    int p_id;
    int arrival_time;
    int burst_time;

    int start_time;
    int first_cpu_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
};

bool compareBurstTime(Process p1, Process p2)
{
    if (p1.burst_time < p2.burst_time)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool compareArrivalTime(Process p1, Process p2)
{
    if (p1.arrival_time < p2.arrival_time)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool compareID(Process p1, Process p2)
{
    if (p1.p_id < p2.p_id)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool myFunc(Process p1,Process p2){
    
}

int main()
{
    int n;
    cout << "Enter number of processes:";
    cin >> n;

    Process p[n];

    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int total_response_time = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter arrival time of process " << i + 1 << ": ";
        cin >> p[i].arrival_time;
        cout << "Enter burst time of process " << i + 1 << ": ";
        cin >> p[i].burst_time;

        p[i].p_id = i + 1;
        cout << endl;
    }

    sort(p, p + n, compareArrivalTime);
    cout << "displaying data:" << endl;
    cout << "#P\t"
         << "AT\t"
         << "BT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << p[i].p_id << "\t" << p[i].arrival_time << "\t" << p[i].burst_time << endl;
    }

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            p[i].first_cpu_time = p[i].arrival_time;
        }
        else
        {
            if(myFunc){
                p[i].first_cpu_time = max(p[i-1].completion_time,p[i].arrival_time)
            }
        }

        p[i].completion_time = p[i].first_cpu_time + p[i].burst_time;
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
        p[i].response_time = p[i].first_cpu_time - p[i].arrival_time;

        total_turnaround_time = total_turnaround_time + p[i].turnaround_time;
        total_waiting_time = total_waiting_time + p[i].waiting_time;
        total_response_time = total_response_time + p[i].response_time;
    }

    return 0;
}