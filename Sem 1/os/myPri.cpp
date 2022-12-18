#include <bits/stdc++.h>
using namespace std;

class Process
{
public:
    int p_id;
    int at;
    int bt;
    int pri;
    
    int st; // first time cpu alloted time
    int ct;
    int tat;
    int wt;
    int rt;
};

int main()
{
    int n;
    cout << "Enter number of processes:";
    cin >> n;
    Process p[n];

    bool is_completed[n] = {false};

    int total_tat = 0;
    int total_wt = 0;
    int total_rt = 0;

    for (int i = 0; i < n; i++){
        cout << "Enter arrival time of process " << i + 1 << ": ";
        cin >> p[i].at;
        cout << "Enter burst time of process " << i + 1 << ": ";
        cin >> p[i].bt;
        cout<<"Enter the priority of process"<<i+1<<": ";
        cin>>p[i].pri;
        p[i].p_id = i + 1;
        cout << endl;
    }

    int cur_time = 0;
    int completed = 0;
    while (completed != n){
        int cur_pr = -1;
        int max_priority = INT_MIN;

        for (int i = 0; i < n; i++){
            if (p[i].at <= cur_time && is_completed[i] == false){
                if (p[i].pri > max_priority){
                    max_priority = p[i].pri;
                    cur_pr = i;
                }
                if (p[i].pri == max_priority){
                    if (p[i].at < p[cur_pr].at){
                        max_priority = p[i].pri;
                        cur_pr = i;
                    }
                }
            }
        }

        if (cur_pr != -1){

            p[cur_pr].st = cur_time;

            p[cur_pr].ct = p[cur_pr].st + p[cur_pr].bt;
            p[cur_pr].tat = p[cur_pr].ct - p[cur_pr].at;
            p[cur_pr].wt = p[cur_pr].tat - p[cur_pr].bt;
            p[cur_pr].rt = p[cur_pr].st - p[cur_pr].at;

            total_tat = total_tat + p[cur_pr].tat;
            total_wt = total_wt + p[cur_pr].wt;
            total_rt = total_rt + p[cur_pr].rt;

            completed++;
            is_completed[cur_pr] = true;
            cur_time = p[cur_pr].ct;
        }else{
            cur_time++;
        }
    }

    cout << "#P\t"<< "AT\t"<< "BT\t"<<"PT\t"<< "ST\t"<< "CT\t"<< "TAT\t"<< "WT\t"<< "RT\t"<< "\n"<< endl;

    for (int i = 0; i < n; i++){
        cout << p[i].p_id << "\t" << p[i].at << "\t" << p[i].bt << "\t"<<p[i].pri<<"\t"<< p[i].st << "\t" << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << "\t" << p[i].rt << "\t"
             << "\n"
             << endl;
    }

    cout << "Average Turnaround Time: " << (float)total_tat / n << endl;
    cout << "Average Waiting Time: " << (float)total_wt / n << endl;
    cout << "Average Response Time: " << (float)total_rt / n << endl;
}