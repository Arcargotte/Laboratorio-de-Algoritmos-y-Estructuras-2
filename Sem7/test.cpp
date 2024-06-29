#include <iostream>
#include <vector>

using namespace std;

int head = -1;

void enqueue (vector <long long> &A, long long x)
{
    if (A.size() == 0)
    {
        A.push_back(x);
        head++;
        return;
    }

    A.push_back(x);
    return;
}

void dequeue (vector <long long> &A)
{
    if (A.size() ==  0 || head >= A.size())
    {
        return;
    }
    head++;

    return;
}

void first_element (vector <long long> &A)
{
    if (head >= A.size() || A.size() == 0)
    {
        printf("Empty!\n");
        return;
    }

    printf("%lld\n", A[head]);

    return;
}

int main ()
{
    vector <long long> queue;

    long num_queries;
    int option;
    long long usrinput;

    scanf("%ld",&num_queries);

    while (num_queries > 0)
    {   
        scanf("%d",&option);
        if (option == 1)
        {
            scanf("%lld",&usrinput);
            
            enqueue(queue, usrinput);
        } 
        else if (option == 2) 
        {
            dequeue(queue);
        }
        else if (option == 3)
        {
            first_element(queue);
        }

        num_queries--;
    }

    return 0;
}