#include <bits/stdc++.h>
using namespace std;

class Process
{
public:
    int p_id;
    int arrival_time;
    int burst_time;
    int remaining_burst_time;

    int start_time; // first time cpu alloted time
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
};

int main()
{
    int n;
    cout << "Enter number of processes:";
    cin >> n;

    Process p[n];

    bool is_completed[n] = {false};
    bool is_in_queue[n] = {false};

    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int total_response_time = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter arrival time of process " << i + 1 << ": ";
        cin >> p[i].arrival_time;
        cout << "Enter burst time of process " << i + 1 << ": ";
        cin >> p[i].burst_time;
        p[i].remaining_burst_time = p[i].burst_time;

        p[i].p_id = i + 1;
        cout << endl;
    }

    int completed = 0;
    int current_time = 0;

    while (completed != n)
    {
        int curr_process = -1;
        int minimum_burst_time = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (p[i].arrival_time <= current_time && is_completed[i] == false)
            {
                if (p[i].burst_time < minimum_burst_time)
                {
                    minimum_burst_time = p[i].burst_time;
                    curr_process = i;
                }
                if (p[i].burst_time == minimum_burst_time)
                {
                    if (p[i].arrival_time < p[curr_process].arrival_time)
                    {
                        minimum_burst_time = p[i].burst_time;
                        curr_process = i;
                    }
                }
            }
        }

        if (curr_process != -1)
        {
            if (p[curr_process].remaining_burst_time == p[curr_process].burst_time)
            {
                p[curr_process].start_time = current_time;
            }

            p[curr_process].remaining_burst_time--;
            current_time++;

            if (p[curr_process].remaining_burst_time == 0)
            {
                p[curr_process].completion_time = current_time;
                p[curr_process].turnaround_time = p[curr_process].completion_time - p[curr_process].arrival_time;
                p[curr_process].waiting_time = p[curr_process].turnaround_time - p[curr_process].burst_time;
                p[curr_process].response_time = p[curr_process].start_time - p[curr_process].arrival_time;

                total_turnaround_time = total_turnaround_time + p[curr_process].turnaround_time;
                total_waiting_time = total_waiting_time + p[curr_process].waiting_time;
                total_response_time = total_response_time + p[curr_process].response_time;

                is_completed[curr_process] = true;
                completed++;
            }
        }
        else
        {
            current_time++;
        }
    }


    // final data to show
    cout << "#P\t"
         << "AT\t"
         << "BT\t"
         << "ST\t"
         << "CT\t"
         << "TAT\t"
         << "WT\t"
         << "RT\t"
         << "\n"
         << endl;
    for (int i = 0; i < n; i++)
    {
        cout << p[i].p_id << "\t" << p[i].arrival_time << "\t" << p[i].burst_time << "\t" << p[i].start_time << "\t" << p[i].completion_time << "\t" << p[i].turnaround_time << "\t" << p[i].waiting_time << "\t" << p[i].response_time << "\t"
             << "\n"
             << endl;
    }

    cout << "Average Turnaround Time: " << (float)total_turnaround_time / n << endl;
    cout << "Average Waiting Time: " << (float)total_waiting_time / n << endl;
    cout << "Average Response Time: " << (float)total_response_time / n << endl;
}