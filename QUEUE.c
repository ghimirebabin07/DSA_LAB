#include <stdio.h>
#define MAX 5

int lq[MAX], cq[MAX];
int lf = -1, lr = -1;
int cf = -1, cr = -1;

/* -------- LINEAR QUEUE -------- */

void linearEnqueue(int x)
{
    if (lr == MAX - 1)
    {
        printf("Linear Queue is full\n");
    }
    else
    {
        if (lf == -1)
            lf = 0;
        lq[++lr] = x;
        printf("Inserted in linear queue: %d\n", x);
    }
}

void linearDequeue()
{
    if (lf == -1 || lf > lr)
    {
        printf("Linear Queue is empty\n");
    }
    else
    {
        printf("Deleted from linear queue: %d\n", lq[lf++]);
        if (lf > lr)
        {
            lf = lr = -1;   // reset queue
        }
    }
}

void displayLinear()
{
    if (lf == -1)
    {
        printf("Linear Queue is empty\n");
    }
    else
    {
        printf("Linear Queue: ");
        for (int i = lf; i <= lr; i++)
        {
            printf("%d ", lq[i]);
        }
        printf("\n");
    }
}

/* -------- CIRCULAR QUEUE -------- */

void circularEnqueue(int x)
{
    if ((cr + 1) % MAX == cf)
    {
        printf("Circular Queue is full\n");
    }
    else
    {
        if (cf == -1)
            cf = 0;
        cr = (cr + 1) % MAX;
        cq[cr] = x;
        printf("Inserted in circular queue: %d\n", x);
    }
}

void circularDequeue()
{
    if (cf == -1)
    {
        printf("Circular Queue is empty\n");
    }
    else
    {
        printf("Deleted from circular queue: %d\n", cq[cf]);
        if (cf == cr)
        {
            cf = cr = -1;   // reset queue
        }
        else
        {
            cf = (cf + 1) % MAX;
        }
    }
}

void displayCircular()
{
    if (cf == -1)
    {
        printf("Circular Queue is empty\n");
    }
    else
    {
        printf("Circular Queue: ");
        int i = cf;
        while (1)
        {
            printf("%d ", cq[i]);
            if (i == cr)
                break;
            i = (i + 1) % MAX;
        }
        printf("\n");
    }
}

/* -------- MAIN MENU -------- */

int main()
{
    int ch, x;

    do
    {
        printf("\n--- Queue Menu ---\n");
        printf("1. Linear Enqueue\n");
        printf("2. Linear Dequeue\n");
        printf("3. Display Linear Queue\n");
        printf("4. Circular Enqueue\n");
        printf("5. Circular Dequeue\n");
        printf("6. Display Circular Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                linearEnqueue(x);
                break;

            case 2:
                linearDequeue();
                break;

            case 3:
                displayLinear();
                break;

            case 4:
                printf("Enter value: ");
                scanf("%d", &x);
                circularEnqueue(x);
                break;

            case 5:
                circularDequeue();
                break;

            case 6:
                displayCircular();
                break;

            case 7:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (ch != 7);

    return 0;
}
