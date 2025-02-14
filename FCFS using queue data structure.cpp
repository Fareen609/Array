#include <stdio.h>
#include <stdlib.h>

#define MAX 10  // Maximum number of processes

// Define a Process structure
typedef struct {
    int processID;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
    int completionTime;
} Process;

// Queue structure for holding processes
typedef struct {
    Process queue[MAX];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initializeQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->front == -1;
}

// Function to add a process to the queue
void enqueue(Queue* q, Process p) {
    if (q->rear == MAX - 1) {
        printf("Queue is full!\n");
    } else {
        if (isEmpty(q)) {
            q->front = 0;  // If it's the first element
        }
        q->rear++;
        q->queue[q->rear] = p;
    }
}

// Function to remove a process from the queue
Process dequeue(Queue* q) {
    Process p;
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        p.processID = -1;  // Return an invalid process if empty
    } else {
        p = q->queue[q->front];
        if (q->front == q->rear) {
            q->front = q->rear = -1;  // Queue is now empty
        } else {
            q->front++;
        }
    }
    return p;
}

// Function to implement FCFS Scheduling
void FCFS_Scheduling(Process processes[], int n) {
    Queue q;
    initializeQueue(&q);

    // Sort processes by Arrival Time (not strictly necessary for FCFS, but good for testing)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].arrivalTime > processes[j].arrivalTime) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Enqueue all processes into the queue
    for (int i = 0; i < n; i++) {
        enqueue(&q, processes[i]);
    }

    // Variables to track time
    int currentTime = 0;

    // Process each process
    while (!isEmpty(&q)) {
        Process p = dequeue(&q);

        if (currentTime < p.arrivalTime) {
            currentTime = p.arrivalTime;  // If the CPU is idle, wait for the process to arrive
        }

        p.completionTime = currentTime + p.burstTime;
        p.turnaroundTime = p.completionTime - p.arrivalTime;
        p.waitingTime = p.turnaroundTime - p.burstTime;

        currentTime = p.completionTime;  // Update current time

        // Print the results for the process
        printf("Process ID: %d\n", p.processID);
        printf("Arrival Time: %d\n", p.arrivalTime);
        printf("Burst Time: %d\n", p.burstTime);
        printf("Waiting Time: %d\n", p.waitingTime);
        printf("Turnaround Time: %d\n", p.turnaroundTime);
        printf("Completion Time: %d\n\n", p.completionTime);
    }
}

int main() {
    int n;

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

    // Perform FCFS Scheduling
    FCFS_Scheduling(processes, n);

    return 0;
}

