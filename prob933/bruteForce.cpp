#include <iostream>
#include <vector>
using namespace std;

class RecentCounter {
    vector<int> times;
public:
    RecentCounter() {}

    int ping(int t) {
        times.push_back(t);
        int count = 0;
        for (int x : times) {
            if (x >= t - 3000 && x <= t) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    RecentCounter rc;

    cout << rc.ping(1) << endl;     
    cout << rc.ping(100) << endl;   
    cout << rc.ping(3001) << endl;  
    cout << rc.ping(3002) << endl;  

    return 0;
}
