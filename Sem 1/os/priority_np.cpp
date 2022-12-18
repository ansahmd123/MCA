// #include <bits/stdc++.h>
// using namespace std;

// class Process
// {
// public:
//     int p_id;
//     int arrival_time;
//     int burst_time;
//     int process_priority;

//     int start_time; // first time cpu alloted time
//     int completion_time;
//     int turnaround_time;
//     int waiting_time;
//     int response_time;
// };

// int main()
// {
//     int n;
//     cout << "Enter number of processes:";
//     cin >> n;
//     Process p[n];

//     bool is_completed[n] = {false};

//     int total_turnaround_time = 0;
//     int total_waiting_time = 0;
//     int total_response_time = 0;

//     for (int i = 0; i < n; i++){
//         cout << "Enter arrival time of process " << i + 1 << ": ";
//         cin >> p[i].arrival_time;
//         cout << "Enter burst time of process " << i + 1 << ": ";
//         cin >> p[i].burst_time;
//         cout<<"Enter the priority of process"<<i+1<<": ";
//         cin>>p[i].process_priority;
//         p[i].p_id = i + 1;
//         cout << endl;
//     }

//     int current_time = 0;
//     int completed = 0;
//     while (completed != n){
//         int curr_process = -1;
//         int max_priority = INT_MIN;

//         for (int i = 0; i < n; i++){
//             if (p[i].arrival_time <= current_time && is_completed[i] == false){
//                 if (p[i].process_priority > max_priority){
//                     max_priority = p[i].process_priority;
//                     curr_process = i;
//                 }
//                 if (p[i].process_priority == max_priority){
//                     if (p[i].arrival_time < p[curr_process].arrival_time){
//                         max_priority = p[i].process_priority;
//                         curr_process = i;
//                     }
//                 }
//             }
//         }

//         if (curr_process != -1){

//             p[curr_process].start_time = current_time;

//             p[curr_process].completion_time = p[curr_process].start_time + p[curr_process].burst_time;
//             p[curr_process].turnaround_time = p[curr_process].completion_time - p[curr_process].arrival_time;
//             p[curr_process].waiting_time = p[curr_process].turnaround_time - p[curr_process].burst_time;
//             p[curr_process].response_time = p[curr_process].start_time - p[curr_process].arrival_time;

//             total_turnaround_time = total_turnaround_time + p[curr_process].turnaround_time;
//             total_waiting_time = total_waiting_time + p[curr_process].waiting_time;
//             total_response_time = total_response_time + p[curr_process].response_time;

//             completed++;
//             is_completed[curr_process] = true;
//             current_time = p[curr_process].completion_time;
//         }else{
//             current_time++;
//         }
//     }

//     cout << "#P\t"<< "AT\t"<< "BT\t"<<"PT\t"<< "ST\t"<< "CT\t"<< "TAT\t"<< "WT\t"<< "RT\t"<< "\n"<< endl;

//     for (int i = 0; i < n; i++){
//         cout << p[i].p_id << "\t" << p[i].arrival_time << "\t" << p[i].burst_time << "\t"<<p[i].process_priority<<"\t"<< p[i].start_time << "\t" << p[i].completion_time << "\t" << p[i].turnaround_time << "\t" << p[i].waiting_time << "\t" << p[i].response_time << "\t"
//              << "\n"
//              << endl;
//     }

//     cout << "Average Turnaround Time: " << (float)total_turnaround_time / n << endl;
//     cout << "Average Waiting Time: " << (float)total_waiting_time / n << endl;
//     cout << "Average Response Time: " << (float)total_response_time / n << endl;
// }


#include <bits/stdc++.h>
using namespace std;

class Process
{
public:
    int p_id;
    int arrival_time;
    int burst_time;
    int process_priority;
    
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

    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int total_response_time = 0;

    for (int i = 0; i < n; i++){
        cout << "Enter arrival time,burst time and priority of process " << i + 1 << ": ";
        cin >> p[i].arrival_time>>p[i].burst_time>>p[i].process_priority;
        p[i].p_id = i + 1;
        cout << endl;
    }

    int current_time = 0;
    int completed = 0;
    while (completed != n){
        int curr_process = -1;
        int max_priority = INT_MIN;

        for (int i = 0; i < n; i++){
            if (p[i].arrival_time <= current_time && is_completed[i] == false){
                if (p[i].process_priority > max_priority){
                    max_priority = p[i].process_priority;
                    curr_process = i;
                }
                if (p[i].process_priority == max_priority){
                    if (p[i].arrival_time < p[curr_process].arrival_time){
                        max_priority = p[i].process_priority;
                        curr_process = i;
                    }
                }
            }
        }

        if (curr_process != -1){

            p[curr_process].start_time = current_time;

            p[curr_process].completion_time = p[curr_process].start_time + p[curr_process].burst_time;
            p[curr_process].turnaround_time = p[curr_process].completion_time - p[curr_process].arrival_time;
            p[curr_process].waiting_time = p[curr_process].turnaround_time - p[curr_process].burst_time;
            p[curr_process].response_time = p[curr_process].start_time - p[curr_process].arrival_time;

            total_turnaround_time = total_turnaround_time + p[curr_process].turnaround_time;
            total_waiting_time = total_waiting_time + p[curr_process].waiting_time;
            total_response_time = total_response_time + p[curr_process].response_time;

            completed++;
            is_completed[curr_process] = true;
            current_time = p[curr_process].completion_time;
        }else{
            current_time++;
        }
    }

    cout << "#P\t"<< "AT\t"<< "BT\t"<<"PT\t"<< "ST\t"<< "CT\t"<< "TAT\t"<< "WT\t"<< "RT\t"<< "\n"<< endl;

    for (int i = 0; i < n; i++){
        cout << p[i].p_id << "\t" << p[i].arrival_time << "\t" << p[i].burst_time << "\t"<<p[i].process_priority<<"\t"<< p[i].start_time << "\t" << p[i].completion_time << "\t" << p[i].turnaround_time << "\t" << p[i].waiting_time << "\t" << p[i].response_time << "\t"
             << "\n"
             << endl;
    }

    cout << "Average Turnaround Time: " << (float)total_turnaround_time / n << endl;
    cout << "Average Waiting Time: " << (float)total_waiting_time / n << endl;
    cout << "Average Response Time: " << (float)total_response_time / n << endl;
    return 0;
}