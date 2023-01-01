#include <bits/stdc++.h>
using namespace std;

class Process
{
public:
    int p_id, at, bt, st, rbt, ct, tat, wt, rt;
};


bool findVal(deque<int> q,int val)
{
  deque<int>::iterator itr;
  itr = find(q.begin(), q.end(), val);
  if(itr != q.end())
  {
    return false;
  }
  else
  {
    return true;
  }
}

int main()
{
    int n, tq;

    cout << "Enter the number of processes:";
    cin >> n;
    cout << "Enter the time quantum:";
    cin >> tq;

    Process p[n];

    bool is_completed[n] = {false};

    deque<int> running_queue;

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
            cout << "i=" << i << endl;

            if (curr_process == i)
                continue;
            

            if (p[i].at <= current_time && is_completed[i] == false)
            {

                if(findVal(running_queue,i)){
                    cout<<"andar ka i="<<i<<endl;
                    running_queue.push_back(i);
                }
            }
        }

        if(curr_process != -1 && is_completed[curr_process]==false)
            running_queue.push_back(curr_process);

        curr_process = running_queue.front();

        cout << "Queue size(before):" << running_queue.size() << endl;
        cout << "Queue front:" << running_queue.front() << endl;
        cout << "Queue back:" << running_queue.back() << endl;

        cout << "current process====================" << curr_process << endl;

        if (curr_process != -1)
        {
            if (p[curr_process].rbt == p[curr_process].bt)
            {
                p[curr_process].st = current_time;
                cout<<"P["<<curr_process<<"].start_time="<<p[curr_process].st<<endl;

                if (p[curr_process].rbt <= tq)
                {
                    cout<<"if => if = "<<curr_process<<endl;
                
                    current_time = current_time + p[curr_process].rbt;
                    p[curr_process].ct = current_time;
                    cout<<"P["<<curr_process<<"].completion_time="<<p[curr_process].ct<<endl;

                    p[curr_process].tat = p[curr_process].ct - p[curr_process].at;
                    p[curr_process].wt = p[curr_process].tat - p[curr_process].bt;
                    p[curr_process].rt = p[curr_process].st - p[curr_process].at;

                    total_tat = total_tat + p[curr_process].tat;
                    total_wt = total_wt + p[curr_process].wt;
                    total_rt = total_rt + p[curr_process].rt;

                    running_queue.pop_front();

                    is_completed[curr_process] = true;

                    for (int i = 0; i < n; i++)
                    {
                        cout<<"iscompleted:";
                        cout<<is_completed[i]<<"  ";   
                    }
                    cout<<endl;
                    completed++;
                }
                else
                {
                    cout<<"if => else  = "<<curr_process<<endl;

                    p[curr_process].rbt = p[curr_process].rbt - tq;
                    current_time = current_time + tq; 
                    running_queue.pop_front();
                }
            }

            else if (p[curr_process].rbt <= tq)
            {
                cout<<"else if = "<<curr_process<<endl;
                current_time = current_time + p[curr_process].rbt;
                p[curr_process].ct = current_time;
                cout<<"P["<<curr_process<<"].completion_time="<<p[curr_process].ct<<endl;

                p[curr_process].tat = p[curr_process].ct - p[curr_process].at;
                p[curr_process].wt = p[curr_process].tat - p[curr_process].bt;
                p[curr_process].rt = p[curr_process].st - p[curr_process].at;

                total_tat = total_tat + p[curr_process].tat;
                total_wt = total_wt + p[curr_process].wt;
                total_rt = total_rt + p[curr_process].rt;
                running_queue.pop_front();
                is_completed[curr_process] = true;

                completed++;
            }
            else
            {
                cout<<"else me direct ="<<curr_process<<endl;
                p[curr_process].rbt -= tq;
                current_time += tq;
                running_queue.pop_front();
            }
        }
        else
        {
            current_time++;
        }

        cout << "Queue size(after):" << running_queue.size() << endl;
        cout << "Queue front(after):" << running_queue.front() << endl;
        cout << "Queue back(after):" << running_queue.back() << endl;

        cout<<"current time ========"<<current_time<<endl;

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
