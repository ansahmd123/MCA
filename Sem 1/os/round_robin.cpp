// #include <bits/stdc++.h>
// using namespace std;

// class Process
// {
// public:
//     int p_id, at, bt, st, rbt, ct, tat, wt, rt;
// };

// int main()
// {
//     int n, tq;

//     cout << "Enter the number of processes:";
//     cin >> n;
//     cout << "Enter the time quantum:";
//     cin >> tq;

//     Process p[n];

//     bool is_completed[n] = {false};
//     bool is_suspended[n] = {false};

//     queue<int> running_queue;

//     for (int i = 0; i < n; i++)
//     {
//         cout << "Enter arrival time and burst time of process " << i + 1 << ": ";
//         cin >> p[i].at >> p[i].bt;
//         p[i].rbt = p[i].bt;
//         p[i].p_id = i + 1;
//     }

//     int completed = 0;
//     int current_time = 0;
//     int total_tat = 0;
//     int total_wt = 0;
//     int total_rt = 0;
//     int last_process = -1;

//     while (completed != n)
//     {
//         cout << "inside while" << endl;
//         int curr_process = -1;

//         for (int i = 0; i < n; i++)
//         {
//             cout << "i:" << i << endl;
//             if (p[i].at <= current_time && is_completed[i] == false)
//             {
//                 if(is_suspended[i]==true)   continue;

//                 running_queue.push(i);
//                 curr_process = running_queue.front();
//                 last_process = curr_process;
//                 cout << "Queue front:" << running_queue.front() << endl;
//                 cout << "current process:" << curr_process << endl;
//                 cout << "Queue back:" << running_queue.back() << endl;
//                 cout << "Queue size:" << running_queue.size() << endl;

//                 if (p[i].at == p[curr_process].at)
//                 {
//                     cout << "under if" << endl;
//                     if (p[i].p_id > p[curr_process].p_id)
//                     {
//                         cout << "under under if" << endl;
//                         running_queue.push(i);
//                         curr_process = running_queue.front();
//                         last_process = curr_process;
//                         // running_queue.pop();
//                         cout << "if k andar ka process:" << curr_process << endl;
//                     }
//                     cout << "if k bahar" << endl;
//                 }
//             }
//         }

//         if (curr_process != -1)
//         {
//             if (p[curr_process].rbt == p[curr_process].bt)
//             {
//                 p[curr_process].st = current_time;
//                 cout << "Starting time[" << curr_process << "]=" << p[curr_process].st << endl;
//                 current_time = current_time + tq;
//                 p[curr_process].rbt = p[curr_process].rbt - tq;
//                 running_queue.pop();
//                 is_suspended[curr_process] = true;
//                 cout << "ab queue ka front kya hai:" << running_queue.front() << endl;
//                 cout << "ab queue size:" << running_queue.size() << endl;
//             }

//             else if (p[curr_process].rbt <= tq)
//             {
//                 p[curr_process].ct = current_time;

//                 p[curr_process].tat = p[curr_process].ct - p[curr_process].at;
//                 p[curr_process].wt = p[curr_process].tat - p[curr_process].bt;
//                 p[curr_process].rt = p[curr_process].st - p[curr_process].at;

//                 total_tat = total_tat + p[curr_process].tat;
//                 total_wt = total_wt + p[curr_process].wt;
//                 total_rt = total_rt + p[curr_process].rt;

//                 running_queue.pop();
//                 is_completed[curr_process] = true;

//                 completed++;
//             }
//             else
//             {
//                 p[curr_process].rbt -= tq;
//                 current_time += tq;
//                 is_suspended[curr_process] = true;
//                 running_queue.pop();
//             }
//         }
//         else
//         {
//             current_time++;
//         }
//     }

//     cout << "#P\t"
//          << "AT\t"
//          << "BT\t"
//          << "ST\t"
//          << "CT\t"
//          << "TAT\t"
//          << "WT\t"
//          << "RT\t"
//          << "\n"
//          << endl;

//     for (int i = 0; i < n; i++)
//     {
//         cout << p[i].p_id << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].st << "\t" << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << "\t" << p[i].rt << "\t"
//              << "\n"
//              << endl;
//     }

//     cout << "Average Turnaround Time: " << (float)total_tat / n << endl;
//     cout << "Average Waiting Time: " << (float)total_wt / n << endl;
//     cout << "Average Response Time: " << (float)total_rt / n << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// class Process
// {
// public:
//     int p_id, at, bt, st, rbt, ct, tat, wt, rt;
// };

// int main()
// {
//     int n, tq;

//     cout << "Enter the number of processes:";
//     cin >> n;
//     cout << "Enter the time quantum:";
//     cin >> tq;

//     Process p[n];

//     bool is_completed[n] = {false};

//     queue<int> ready_queue;
//     queue<int> running_queue;

//     for (int i = 0; i < n; i++)
//     {
//         cout << "Enter arrival time and burst time of process " << i + 1 << ": ";
//         cin >> p[i].at >> p[i].bt;
//         p[i].rbt = p[i].bt;
//         p[i].p_id = i + 1;
//     }

//     int completed = 0;
//     int current_time = 0;
//     int total_tat = 0;
//     int total_wt = 0;
//     int total_rt = 0;
//     // int last_process = -1;

//     while (completed != n)
//     {
//         cout << "inside while" << endl;
//         int curr_process = -1;

//         for (int i = 0; i < n; i++)
//         {
//             // cout << "i:" << i << endl;

//             if (p[i].at <= current_time && is_completed[i] == false)
//             {
//                 if(ready_queue.front()==i)    continue;

//                 ready_queue.push(i);
//                 // running_queue.push(ready_queue.front());
//                 // curr_process = running_queue.front();
//                 // cout << "Ready Queue front:" << ready_queue.front() << endl;
//                 // cout << "ready Queue back:" << ready_queue.back() << endl;
//                 // cout << "ready Queue size:" << ready_queue.size() << endl;

//                 if (p[i].at == p[curr_process].at)
//                 {
//                     // cout << "under if" << endl;
//                     if (p[i].p_id > p[curr_process].p_id)
//                     {
//                         // cout << "under under if" << endl;
//                         ready_queue.push(i);
//                         // cout << "if k andar ka process:" << curr_process << endl;
//                     }
//                     // cout << "if k bahar" << endl;
//                 }
//             }
//         }

//         running_queue.push(ready_queue.front());
//         curr_process = running_queue.front();

//         cout<<"Select hua ye:"<<curr_process<<endl;

//         if (curr_process != -1)
//         {
//             if (p[curr_process].rbt == p[curr_process].bt)
//             {
//                 p[curr_process].st = current_time;
//                 cout << "Starting time[" << curr_process << "]=" << p[curr_process].st << endl;
//                 current_time = current_time + tq;
//                 p[curr_process].rbt = p[curr_process].rbt - tq;
//                 running_queue.pop();
//                 // ready_queue.pop();
//                 // cout << "ab queue ka front kya hai:" << running_queue.front() << endl;
//                 // cout << "ab queue size:" << running_queue.size() << endl;
//             }

//             else if (p[curr_process].rbt <= tq)
//             {
//                 p[curr_process].ct = current_time;

//                 p[curr_process].tat = p[curr_process].ct - p[curr_process].at;
//                 p[curr_process].wt = p[curr_process].tat - p[curr_process].bt;
//                 p[curr_process].rt = p[curr_process].st - p[curr_process].at;

//                 total_tat = total_tat + p[curr_process].tat;
//                 total_wt = total_wt + p[curr_process].wt;
//                 total_rt = total_rt + p[curr_process].rt;

//                 running_queue.pop();
//                 // ready_queue.pop();
//                 is_completed[curr_process] = true;

//                 completed++;
//             }
//             else
//             {
//                 p[curr_process].rbt -= tq;
//                 current_time += tq;
//                 running_queue.pop();
//                 // ready_queue.pop();
//             }
//         }
//         else
//         {
//             current_time++;
//         }
//     }

//     cout << "#P\t"
//          << "AT\t"
//          << "BT\t"
//          << "ST\t"
//          << "CT\t"
//          << "TAT\t"
//          << "WT\t"
//          << "RT\t"
//          << "\n"
//          << endl;

//     for (int i = 0; i < n; i++)
//     {
//         cout << p[i].p_id << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].st << "\t" << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << "\t" << p[i].rt << "\t"
//              << "\n"
//              << endl;
//     }

//     cout << "Average Turnaround Time: " << (float)total_tat / n << endl;
//     cout << "Average Waiting Time: " << (float)total_wt / n << endl;
//     cout << "Average Response Time: " << (float)total_rt / n << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// class Process
// {
// public:
//     int p_id, at, bt, st, rbt, ct, tat, wt, rt;
// };

// int main()
// {
//     int n, tq;

//     cout << "Enter the number of processes:";
//     cin >> n;
//     cout << "Enter the time quantum:";
//     cin >> tq;

//     Process p[n];

//     bool is_completed[n] = {false};

//     queue<int> running_queue;

//     for (int i = 0; i < n; i++)
//     {
//         cout << "Enter arrival time and burst time of process " << i + 1 << ": ";
//         cin >> p[i].at >> p[i].bt;
//         p[i].rbt = p[i].bt;
//         p[i].p_id = i + 1;
//     }

//     int completed = 0;
//     int current_time = 0;
//     int total_tat = 0;
//     int total_wt = 0;
//     int total_rt = 0;
//     int curr_process = -1;
//     while (completed != n)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             if (curr_process == i)
//             {
//                 continue;
//             }

//             if (p[i].at <= current_time && is_completed[i] == false)
//             {
//                 running_queue.push(i);
//             }
//         }

//         curr_process = running_queue.front();

//         cout<<"current process="<<curr_process<<endl;
//         if (curr_process != -1)
//         {
//             if (p[curr_process].rbt == p[curr_process].bt)
//             {
//                 // p[curr_process].st = current_time;
//                 p[curr_process].st = max(current_time,p[curr_process].at);
//                 current_time = current_time + tq;
//                 p[curr_process].rbt = p[curr_process].rbt - tq;
//                 running_queue.pop();

//             }

//             else if (p[curr_process].rbt <= tq)
//             {
//                 p[curr_process].ct = current_time;

//                 p[curr_process].tat = p[curr_process].ct - p[curr_process].at;
//                 p[curr_process].wt = p[curr_process].tat - p[curr_process].bt;
//                 p[curr_process].rt = p[curr_process].st - p[curr_process].at;

//                 total_tat = total_tat + p[curr_process].tat;
//                 total_wt = total_wt + p[curr_process].wt;
//                 total_rt = total_rt + p[curr_process].rt;
//                 running_queue.pop();
//                 is_completed[curr_process] = true;

//                 completed++;
//             }
//             else
//             {
//                 p[curr_process].rbt -= tq;
//                 current_time += tq;
//                 running_queue.pop();
//             }
//         }
//         else
//         {
//             current_time++;
//         }
//     }

//     cout << "#P\t"
//          << "AT\t"
//          << "BT\t"
//          << "ST\t"
//          << "CT\t"
//          << "TAT\t"
//          << "WT\t"
//          << "RT\t"
//          << "\n"
//          << endl;

//     for (int i = 0; i < n; i++)
//     {
//         cout << p[i].p_id << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].st << "\t" << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << "\t" << p[i].rt << "\t"
//              << "\n"
//              << endl;
//     }

//     cout << "Average Turnaround Time: " << (float)total_tat / n << endl;
//     cout << "Average Waiting Time: " << (float)total_wt / n << endl;
//     cout << "Average Response Time: " << (float)total_rt / n << endl;

//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// class Process
// {
// public:
//     int p_id, at, bt, st, rbt, ct, tat, wt, rt;
// };

// bool compareArrival(Process p1, Process p2)
// {
//     return p1.at < p2.at;
// }

// bool compareID(Process p1, Process p2)
// {
//     return p1.p_id < p2.p_id;
// }

// int main()
// {
//     int n, tq;

//     cout << "Enter the number of processes:";
//     cin >> n;
//     cout << "Enter the time quantum:";
//     cin >> tq;

//     Process p[n];

//     bool is_completed[n] = {false};
//     bool is_visited[n] = {false};

//     queue<int> running_queue;

//     for (int i = 0; i < n; i++)
//     {
//         cout << "Enter arrival time and burst time of process " << i + 1 << ": ";
//         cin >> p[i].at >> p[i].bt;
//         p[i].rbt = p[i].bt;
//         p[i].p_id = i + 1;
//     }

//     int completed = 0;
//     int current_time = 0;
//     int total_tat = 0;
//     int total_wt = 0;
//     int total_rt = 0;
//     int curr_process = -1;
//     int last_process = -1;

//     // sort(p,p+n,compareArrival);

//     while (completed != n)
//     {

//         for (int i = 0; i < n; i++)
//         {
//             cout << "i=" << i << endl;

//             if (curr_process == i)
//                 continue;


//             if (p[i].at <= current_time && is_completed[i] == false)
//             {
//                 cout << "andar ka i=" << i << endl;

//                 if(running_queue.back()!=i)
//                     running_queue.push(i);

//                 if (p[running_queue.front()].rbt > p[i].rbt)
//                 {
//                     running_queue.pop();
//                     running_queue.push(i);
//                 }
//             }
//         }
        
//         if(running_queue.back()!=curr_process)
//             running_queue.push(last_process);

//         curr_process = running_queue.front();
//         last_process = curr_process;

//         cout << "Queue size(before):" << running_queue.size() << endl;
//         cout << "current process=" << curr_process << endl;
//         if (curr_process != -1)
//         {
//             if (p[curr_process].rbt == p[curr_process].bt)
//             {
//                 p[curr_process].st = current_time;

//                 if (p[curr_process].rbt <= tq)
//                 {
//                     current_time = current_time + p[curr_process].rbt;
//                     p[curr_process].ct = current_time;

//                     p[curr_process].tat = p[curr_process].ct - p[curr_process].at;
//                     p[curr_process].wt = p[curr_process].tat - p[curr_process].bt;
//                     p[curr_process].rt = p[curr_process].st - p[curr_process].at;

//                     total_tat = total_tat + p[curr_process].tat;
//                     total_wt = total_wt + p[curr_process].wt;
//                     total_rt = total_rt + p[curr_process].rt;
//                     running_queue.pop();
//                     is_completed[curr_process] = true;

//                     completed++;
//                 }
//                 else
//                 {
//                     p[curr_process].rbt = p[curr_process].rbt - tq;
//                     current_time = current_time + tq;

//                     // if (p[curr_process].rbt <= tq)
//                     // {
//                     //     current_time = current_time + p[curr_process].rbt;
//                     //     p[curr_process].ct = current_time;

//                     //     p[curr_process].tat = p[curr_process].ct - p[curr_process].at;
//                     //     p[curr_process].wt = p[curr_process].tat - p[curr_process].bt;
//                     //     p[curr_process].rt = p[curr_process].st - p[curr_process].at;

//                     //     total_tat = total_tat + p[curr_process].tat;
//                     //     total_wt = total_wt + p[curr_process].wt;
//                     //     total_rt = total_rt + p[curr_process].rt;
//                     //     running_queue.pop();
//                     //     is_completed[curr_process] = true;

//                     //     completed++;
//                     // }
                    
//                     running_queue.pop();
//                 }
//             }

//             else if (p[curr_process].rbt <= tq)
//             {
//                 p[curr_process].ct = current_time;

//                 p[curr_process].tat = p[curr_process].ct - p[curr_process].at;
//                 p[curr_process].wt = p[curr_process].tat - p[curr_process].bt;
//                 p[curr_process].rt = p[curr_process].st - p[curr_process].at;

//                 total_tat = total_tat + p[curr_process].tat;
//                 total_wt = total_wt + p[curr_process].wt;
//                 total_rt = total_rt + p[curr_process].rt;
//                 running_queue.pop();
//                 is_completed[curr_process] = true;

//                 completed++;
//             }
//             else
//             {
//                 p[curr_process].rbt -= tq;
//                 current_time += tq;
//                 running_queue.pop();
//             }
//         }
//         else
//         {
//             current_time++;
//         }
//         cout << "Queue size(after):" << running_queue.size() << endl;
//     }

//     // sort(p,p+n,compareID);

//     cout << "#P\t"
//          << "AT\t"
//          << "BT\t"
//          << "ST\t"
//          << "CT\t"
//          << "TAT\t"
//          << "WT\t"
//          << "RT\t"
//          << "\n"
//          << endl;

//     for (int i = 0; i < n; i++)
//     {
//         cout << p[i].p_id << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].st << "\t" << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << "\t" << p[i].rt << "\t"
//              << "\n"
//              << endl;
//     }

//     cout << "Average Turnaround Time: " << (float)total_tat / n << endl;
//     cout << "Average Waiting Time: " << (float)total_wt / n << endl;
//     cout << "Average Response Time: " << (float)total_rt / n << endl;

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

class Process
{
public:
    int p_id, at, bt, st, rbt, ct, tat, wt, rt;
};

bool compareArrival(Process p1, Process p2)
{
    return p1.at < p2.at;
}

bool compareID(Process p1, Process p2)
{
    return p1.p_id < p2.p_id;
}

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

    // queue<int> running_queue;
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
    int last_process = -1;

    int queue_front = -1;
    int queue_back = -1;

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

        queue_front = running_queue.front();
        queue_back = running_queue.back();
    }

    // sort(p,p+n,compareID);

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
