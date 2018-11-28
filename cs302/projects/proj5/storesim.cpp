// Simulates the flow of customers through a line in a store.

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

// Use which ever implementation is currently configured.
#if LAB7_TEST1
#   include "QueueLinked.cpp"
#else
#   include "QueueArray.cpp"
#endif

using namespace std;

int main ()
{
#if LAB7_TEST1
    QueueLinked<int> custQ;      // Line (queue) of customers containing the
#else
    QueueArray<int> custQ;       // Line (queue) of customers containing the
#endif 				 //   time that each customer arrived and
                                 //   joined the line
    int simLength,               // Length of simulation (minutes)
        minute,                  // Current minute
        timeArrived,             // Time dequeued customer arrived
        waitTime,                // How long dequeued customer waited
        totalServed = 0,         // Total customers served
        totalWait   = 0,         // Total waiting time
        maxWait     = 0,         // Longest wait
        numArrivals = 0;         // Number of new arrivals

    // Seed the random number generator. Equally instructive to run the
    // simulation with the generator seeded and not seeded.
    srand( time(NULL) );

    cout << endl << "Enter the length of time to run the simulator : ";
    cin >> simLength;

    int randGenerated = 0;
    for (minute = 0; minute < simLength; minute++) {
        // Serve customers first
        if (!custQ.isEmpty()) {
            timeArrived = custQ.dequeue();
            totalServed++;
            totalWait += waitTime = minute - timeArrived;
            if (waitTime > maxWait) {
                maxWait = waitTime;
            }
        }

        // Randomly decide if 0, 1, or 2 customers join the line
        randGenerated = rand() % 4;
        numArrivals = 0;
        if (randGenerated == 1) {
            numArrivals = 1;
        } else if (randGenerated == 2) {
            numArrivals = 2;
        }

        // Add customers to line
        for (int i = 0; i < numArrivals; i++) {
            custQ.enqueue(minute);
        }

    }


    // Print out simulation results
    cout << endl;
    cout << "Customers served : " << totalServed << endl;
    cout << "Average wait     : " << setprecision(2)
         << double(totalWait)/totalServed << endl;
    cout << "Longest wait     : " << maxWait << endl;

    return 0;
}
