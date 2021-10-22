#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> arrival_time(n);
    vector<int> burst_time(n);
    vector<int> waiting_time(n);
    vector<int> start_time(n);
    vector<int> end_time(n);
    vector<int> turnaround_time(n);

    for(int i = 0 ; i < n ; i++)
        cin >> arrival_time[i];
    
    for(int i = 0 ; i < n ; i++)
        cin >> burst_time[i];

    end_time[0] = start_time[0] + burst_time[0]; 
    for(int i = 1 ; i < n ; i++){
        start_time[i] = end_time[i-1];
        end_time[i] = start_time[i] + burst_time[i]; 
    }

    for(int i = 0 ; i < n ; i++){
        waiting_time[i] = start_time[i] - arrival_time[i];
        turnaround_time[i] = end_time[i] - arrival_time[i];
    }

    for(int i = 0 ; i < n ; i++)
        cout << waiting_time[i] << " " << turnaround_time[i] << endl;
    
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    for(int i = 0 ; i < n ; i++){
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    cout << total_waiting_time << endl;
    cout << total_turnaround_time << endl;

    return 0;
}