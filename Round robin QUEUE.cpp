#include <stdio.h>

#define MAX 10  // Maximum number of processes

// Define a Process structure
typedef struct {
    int processID;       // Process ID
    int arrivalTime;     // Arrival Time
    int burstTime;       // Burst Time
    int remainingTime;   // Remaining Time (used to track burst time during RR scheduling)
    int waitingTime;     // Waiting Time
    int turnaroundTime;  // Turnaround Time
    int completionTime;  // Completion Time
} Process;

// Function to implement Round Robin Scheduling
void roundRobinScheduling(Process processes[], int n, int timeQuantum) {
    int totalWaitingTime = 0, totalTurnaroundTime = 0;
    int time = 0;  // Current time
    int completed = 0;  // Count of completed processes

    // Queue to store processes
    int queue[MAX];
    int front = 0, rear = 0;

    // Add all processes to the queue
    for (int i = 0; i < n; i++) {
        processes[i].remainingTime = processes[i].burstTime;
        queue[rear++] = i;  // Enqueue process
    }

    // Execute processes in a round-robin fashion
    while (completed < n) {
        int processIndex = queue[front++];
        if (front == rear) {
            front = rear = 0;  // Reset the queue
        }

        // If the process is already completed, continue
        if (processes[processIndex].remainingTime == 0) {
            continue;
        }

        // If the process can finish within its time quantum
        if (processes[processIndex].remainingTime <= timeQuantum) {
            time += processes[processIndex].remainingTime;  // Increase current time
            processes[processIndex].remainingTime = 0;  // Process finished
            completed++;

            // Calculate completion, turnaround, and waiting times
            processes[processIndex].completionTime = time;
            processes[processIndex].turnaroundTime = processes[processIndex].completionTime - processes[processIndex].arrivalTime;
            processes[processIndex].waitingTime = processes[processIndex].turnaroundTime - processes[processIndex].burstTime;

            // Update totals for averages later
            totalWaitingTime += processes[processIndex].waitingTime;
            totalTurnaroundTime += processes[processIndex].turnaroundTime;
        } 
        // If the process cannot finish within the time quantum
        else {
            time += timeQuantum;  // Increase current time by time quantum
            processes[processIndex].remainingTime -= timeQuantum;  // Reduce remaining time

            // Add the process back to the queue for the next round
            queue[rear++] = processIndex;
        }
    }

    // Print the results for each process
    printf("\nProcess ID | Arrival Time | Burst Time | Waiting Time | Turnaround Time | Completion Time\n");
    for (int i = 0; i < n; i++) {
        printf("   %d\t\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n", 
            processes[i].processID, 
            processes[i].arrivalTime, 
            processes[i].burstTime, 
            processes[i].waitingTime, 
            processes[i].turnaroundTime, 
            processes[i].completionTime);
    }

    // Print average waiting and turnaround time
    printf("\nAverage Waiting Time: %.2f\n", (float)totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", (float)totalTurnaroundTime / n);
}

int main() {
    int n;
    int timeQuantum;

    // Read the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        printf("Enter details for process %d:\n", i + 1);
        processes[i].processID = i + 1;
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrivalTime);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burstTime);
    }

    // Read time quantum
    printf("Enter the time quantum: ");
    scanf("%d", &timeQuantum);

    // Perform Round Robin Scheduling
    roundRobinScheduling(processes, n, timeQuantum);

    return 0;
}

