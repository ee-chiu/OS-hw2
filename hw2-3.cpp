#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct process{
    int arrival_time;
    int burst_time;
    int remaining_time;
    int start_time;
    int end_time;
    int waiting_time;
    int turnaround_time;
    bool run = false;
};

int main(){
    int n;
    cin >> n;
    
    vector<process> p(n);
    queue<process*> p2;

    for(int i = 0 ; i < n ; i++)
        cin >> p[i].arrival_time;

    for(int i = 0 ; i < n ; i++){
        cin >> p[i].burst_time;
        p[i].remaining_time = p[i].burst_time;
    }

    int q;
    cin >> q;

    p2.push(&p[0]);

    int time = 0;

    while(!p2.empty()){
        process* now = p2.front();
        p2.pop();

        if(!now -> run){
            now -> start_time = time;
            now -> run = true;
        }

        int use_time = min(q, now -> remaining_time);
        for(int i = 0 ; i < n ; i++){
            for(int j = time + 1 ; j <= time + use_time ; j++){
                if(p[i].arrival_time == j) p2.push(&p[i]);
            }
        }
        time += use_time;
        now -> remaining_time -= use_time;        

        if(now -> remaining_time == 0) now -> end_time = time;
        else p2.push(now);
    }  

    for(int i = 0 ; i < n ; i++)
        p[i].turnaround_time = p[i].end_time - p[i].arrival_time;

    for(int i = 0 ; i < n ; i++)
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;

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