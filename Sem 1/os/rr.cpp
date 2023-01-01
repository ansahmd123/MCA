#include <bits/stdc++.h>
using namespace std;

class Process
{
public:
    int p_id, at, bt, st, rbt, ct, tat, wt, rt;
};

int main()
{
    int n, tq;

    cout << "Enter the number of processes:";
    cin >> n;
    cout << "Enter the time quantum:";
    cin >> tq;

    Process p[n];

    bool is_completed[n] = {false};
    bool is_visited[n] = {false};

    queue<int> ready_queue;
    queue<int> running_queue;

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
        while (ready_queue.empty())
        {
            for (int i = 0; i < n; i++)
            {
                if (curr_process == i)
                    continue;

                if (p[i].at <= current_time && is_completed[i] == false)
                {
                    ready_queue.push(i);
                }
            }
        }

        running_queue.push(ready_queue.front());

        ready_queue.pop();

        curr_process = running_queue.front();

        cout << "current process=" << curr_process << endl;
        
        if (curr_process != -1)
        {
            if (p[curr_process].rbt == p[curr_process].bt)
            {
                // p[curr_process].st = current_time;
                p[curr_process].st = max(current_time, p[curr_process].at);
                current_time = current_time + tq;
                p[curr_process].rbt = p[curr_process].rbt - tq;
                running_queue.pop();
            }

            else if (p[curr_process].rbt <= tq)
            {
                p[curr_process].ct = current_time;

                p[curr_process].tat = p[curr_process].ct - p[curr_process].at;
                p[curr_process].wt = p[curr_process].tat - p[curr_process].bt;
                p[curr_process].rt = p[curr_process].st - p[curr_process].at;

                total_tat = total_tat + p[curr_process].tat;
                total_wt = total_wt + p[curr_process].wt;
                total_rt = total_rt + p[curr_process].rt;
                running_queue.pop();
                is_completed[curr_process] = true;

                completed++;
            }
            else
            {
                p[curr_process].rbt -= tq;
                current_time += tq;
                running_queue.pop();
            }
        }
        else
        {
            current_time++;
        }
    }

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