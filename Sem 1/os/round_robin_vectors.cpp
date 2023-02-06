#include <bits/stdc++.h>
using namespace std;
class Process
{
public:
    int p_id; // process id
    int at;   // arrival time
    int bt;   // burst time
    int rbt;  // remaining burst time
    int st;   // start time
    int ct;   // completion time
    int tat;  // turnaround time
    int wt;   // waiting time
    int rt;   // response time
};

bool findVal(vector<int> &anas, int i)
{
    int start = 0;
    int end = anas.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (anas[mid] == i)
            return true;
        if (anas[mid] < i)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

        return false;
    }
}

int main()
{
    // Anas Ahmad Ilyas Ahmad    Batch No - 1    Roll No - 1

    int n, tq;

    cout << "Enter the number of processes:";
    cin >> n;
    cout << "Enter the time quantum:";
    cin >> tq;

    Process p[n];

    bool is_completed[n] = {false};

    // deque<int> running_queue;
    vector<int> running_queue;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter arrival time and burst time of process " << i + 1 << ": ";
        cin >> p[i].at >> p[i].bt;
        p[i].rbt = p[i].bt;
        p[i].p_id = i + 1;
    }

    int completed = 0;
    int current_time = 0;

    int total_tat = 0;
    int total_wt = 0;
    int total_rt = 0;

    int curr_process = -1;

    while (completed != n)
    {
        for (int i = 0; i < n; i++)
        {

            if (curr_process == i)
                continue;

            if (p[i].at <= current_time && is_completed[i] == false)

                if (findVal(running_queue, i))
                    running_queue.push_back(i);
        }

        if (curr_process != -1 && is_completed[curr_process] == false)
            running_queue.push_back(curr_process);

        if (!running_queue.empty())
            curr_process = running_queue[0];
        else
            curr_process = -1;

        if (curr_process != -1)
        {
            if (p[curr_process].rbt == p[curr_process].bt || p[curr_process].rbt <= tq)
            {
                if (p[curr_process].rbt == p[curr_process].bt)
                    p[curr_process].st = current_time;

                if (p[curr_process].rbt <= tq)
                {
                    current_time = current_time + p[curr_process].rbt;
                    p[curr_process].ct = current_time;

                    p[curr_process].tat = p[curr_process].ct - p[curr_process].at;
                    p[curr_process].wt = p[curr_process].tat - p[curr_process].bt;
                    p[curr_process].rt = p[curr_process].st - p[curr_process].at;

                    total_tat = total_tat + p[curr_process].tat;
                    total_wt = total_wt + p[curr_process].wt;
                    total_rt = total_rt + p[curr_process].rt;
                    // running_queue.pop_front();
                    running_queue.erase(running_queue.begin());
                    is_completed[curr_process] = true;
                    completed++;
                }
                else
                {
                    p[curr_process].rbt = p[curr_process].rbt - tq;
                    current_time = current_time + tq;
                    // running_queue.pop_front();
                    running_queue.erase(running_queue.begin());
                }
            }
            else
            {
                p[curr_process].rbt -= tq;
                current_time += tq;
                // running_queue.pop_front();
                running_queue.erase(running_queue.begin());
            }
        }
        else
        {
            current_time++;
        }
    }

    cout << endl;
    cout << "------Round Robin CPU Scheduling Algorithm------\n"
         << endl;

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
        cout << p[i].p_id << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].st << "\t" << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << "\t" << p[i].rt << "\t"
             << "\n"
             << endl;
    }

    cout << "Average Turnaround Time: " << (float)total_tat / n << endl;
    cout << "Average Waiting Time: " << (float)total_wt / n << endl;
    cout << "Average Response Time: " << (float)total_rt / n << endl;

    return 0;
}
