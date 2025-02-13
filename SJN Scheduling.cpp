#include <stdio.h>

typedef struct {
    int process_id;    // Process ID
    int burst_time;    // Burst time
    int waiting_time;  // Waiting time
    int turn_around_time; // Turnaround time
} Process;

void findWaitingTime(Process proc[], int n) {
    proc[0].waiting_time = 0;  // Waiting time for the first process is 0
    
    // Calculate waiting time for the rest of the processes
    for (int i = 1; i < n; i++) {
        proc[i].waiting_time = proc[i - 1].waiting_time + proc[i - 1].burst_time;
    }
}

void findTurnAroundTime(Process proc[], int n) {
    // Turnaround time is the sum of burst time and waiting time
    for (int i = 0; i < n; i++) {
        proc[i].turn_around_time = proc[i].burst_time + proc[i].waiting_time;
    }
}

void findAverageTime(Process proc[], int n) {
    float total_waiting_time = 0, total_turn_around_time = 0;

    for (int i = 0; i < n; i++) {
        total_waiting_time += proc[i].waiting_time;
        total_turn_around_time += proc[i].turn_around_time;
    }

    printf("\nAverage Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turn_around_time / n);
}

void sortByBurstTime(Process proc[], int n) {
    // Sort the processes by burst time in ascending order (SJN or SJF)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (proc[i].burst_time > proc[j].burst_time) {
                // Swap the processes
                Process temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}

void printTable(Process proc[], int n) {
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", proc[i].process_id, proc[i].burst_time,
               proc[i].waiting_time, proc[i].turn_around_time);
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process proc[n];

    // Input burst time for each process
    for (int i = 0; i < n; i++) {
        proc[i].process_id = i + 1;  // Process IDs start from 1
        printf("Enter burst time for process %d: ", proc[i].process_id);
        scanf("%d", &proc[i].burst_time);
    }

    // Sort processes by burst time (Shortest Job First)
    sortByBurstTime(proc, n);

    // Calculate waiting time and turnaround time
    findWaitingTime(proc, n);
    findTurnAroundTime(proc, n);

    // Print process table with times
    printTable(proc, n);

    // Calculate and display average waiting and turnaround time
    findAverageTime(proc, n);

    return 0;
}

