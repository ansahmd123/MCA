#include <bits/stdc++.h>
using namespace std;

int main(){
    deque<int> ready_queue;

    ready_queue.push_back(4);
    ready_queue.push_back(5);
    ready_queue.push_back(2);
    ready_queue.push_back(9);
    

    auto ans = find(ready_queue.begin(),ready_queue.end(),5);
    
    
    return 0;
}