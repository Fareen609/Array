#include <stdio.h>

struct Process {
    int id;             // Process ID
    int burst_time;     // Burst time
    int priority;       // Priority of the process
    int waiting_time;   // Waiting time
    int turn_around_time; // Turnaround time
};

// Function to calculate waiting time and turn around time
void calculateWaitingTime(struct Process proc[], int n) {
    proc[0].waiting_time = 0; // First process has no waiting time
    
    // Calculate waiting time for each process
    for (int i = 1; i < n; i++) {
        proc[i].waiting_time = proc[i-1].waiting_time + proc[i-1].burst_time;
    }
}

void calculateTurnaroundTime(struct Process proc[], int n) {
    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++) {
        proc[i].turn_around_time = proc[i].waiting_time + proc[i].burst_time;
    }
}

void sortByPriority(struct Process proc[], int n) {
    // Sorting the processes according to priority (lower number means higher priority)
    struct Process temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (proc[i].priority > proc[j].priority) {
                // Swap processes based on priority
                temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}

void display(struct Process proc[], int n) {
    printf("\nProcess ID | Burst Time | Priority | Waiting Time | Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].id, proc[i].burst_time, proc[i].priority,
                proc[i].waiting_time, proc[i].turn_around_time);
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];

    // Input the burst time and priority for each process
    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1;  // Process ID (1, 2, 3, ...)
        printf("Enter burst time for process P%d: ", proc[i].id);
        scanf("%d", &proc[i].burst_time);
        printf("Enter priority for process P%d: ", proc[i].id);
        scanf("%d", &proc[i].priority);
    }

    // Sort processes based on their priority (lower value means higher priority)
    sortByPriority(proc, n);

    // Calculate waiting time and turnaround time
    calculateWaitingTime(proc, n);
    calculateTurnaroundTime(proc, n);

    // Display the result
    display(proc, n);

    // Calculate and display average waiting time and turnaround time
    float total_waiting_time = 0, total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += proc[i].waiting_time;
        total_turnaround_time += proc[i].turn_around_time;
    }

    printf("\nAverage Waiting Time: %.2f", total_waiting_time / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_turnaround_time / n);

    return 0;
}

