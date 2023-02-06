#include <bits/stdc++.h>
using namespace std;

int main(){
    // deque<int> ready_queue;

    // ready_queue.push_back(4);
    // ready_queue.push_back(5);
    // ready_queue.push_back(2);
    // ready_queue.push_back(9);
    

    // auto ans = find(ready_queue.begin(),ready_queue.end(),5);
    
    vector<int> anas = {2,4,6,5};
    // anas.pop_back();
    anas.erase(anas.begin());
    for(auto a:anas)
        cout<<a<<"  ";
    
    return 0;
}