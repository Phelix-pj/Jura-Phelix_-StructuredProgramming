#include <stdio.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int head = 0;
int count = 0;
void insert(int val) {
    buffer[head] = val;
    head = (head + 1) % BUFFER_SIZE;
    if (count < BUFFER_SIZE) count++;
}

void printBuffer() {
    printf("Chronological order: ");
    // The oldest is at 'head' if buffer is full, otherwise at index 0
    int start = (count < BUFFER_SIZE) ? 0 : head;
    for (int i = 0; i < count; i++) {
        printf("%d ", buffer[(start + i) % BUFFER_SIZE]);
    }
    printf("\n");
}

int main() {
    int choice, value;
    while(1) {
        printf("\n1. Insert Sensor Data\n2. Print Logger\n3. Exit\nChoice: ");
        scanf("%d", &choice);
        if(choice == 1) {
            printf("Enter value: ");
            scanf("%d", &value);
            insert(value);
        } else if(choice == 2) {
            printBuffer();
        } else break;
    }
    return 0;
}
