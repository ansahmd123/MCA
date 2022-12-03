#include <bits/stdc++.h>
using namespace std;

// We need this function to define how to sort
// the vector. We will pass this function into the
// third parameter and it will tell it to sort descendingly.
bool wayToSort(int i, int j) { return i > j; }

int main()
{
    vector<int> intVec = {56, 32, -43, 23, 12, 93, 132, -154};

    // sort(intVec.begin(), intVec.end());
    sort(intVec.begin(), intVec.end(), wayToSort);

    for (int i : intVec)
        cout << i << " ";

    return 0;
}