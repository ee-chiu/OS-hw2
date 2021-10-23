#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct process{
    int id;
    int arrival_time;
    int burst_time;
    int start_time;
    int end_time;
    int waiting_time;
    int turnaround_time;
    bool run = false;
};

bool sort_by_burst_time(process a, process b){
    return a.burst_time < b.burst_time;
}

bool sort_by_id(process a, process b){
    return a.id < b.id;
}

bool remainProcess(vector<process> &p){
    for(int i = 0 ; i < p.size() ; i++){
        if(!p[i].run)
            return true;
    }

    return false;
}

int main(){
    int n;
    cin >> n;

    vector<process> p(n);

    for(int i = 0 ; i < n ; i++)
        p[i].id = i;

    for(int i = 0 ; i < n ; i++)
        cin >> p[i].arrival_time;

    for(int i = 0 ; i < n ; i++)
        cin >> p[i].burst_time;

    sort(p.begin(), p.end(), sort_by_burst_time);

    int time = 0;
    while(remainProcess(p)){
        for(int i = 0 ; i < n ; i++){
            if(!p[i].run && time >= p[i].arrival_time){
                p[i].start_time = time;
                time = time + p[i].burst_time;
                p[i].end_time = time;
                p[i].run = true;
                break;
            }
        }
    }    

    sort(p.begin(), p.end(), sort_by_id);

    for(int i = 0 ; i < n ; i++){
        p[i].waiting_time = p[i].start_time - p[i].arrival_time;
        p[i].turnaround_time = p[i].end_time - p[i].arrival_time;
    }

    for(int i = 0 ; i < n ; i++)
        cout << p[i].waiting_time << " " << p[i].turnaround_time << endl;

    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    for(int i = 0 ; i < n ; i++){
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
    }

    cout << total_waiting_time << endl;
    cout << total_turnaround_time << endl;

    return 0;
}