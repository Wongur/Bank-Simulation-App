/*
 * BankSimApp.cpp
 *
 * Description: PBanking simulation app 
 *
 * Class Invariant: uses a priority queue as underlying data structure
 *
 * Authors: KW
 * Last Modified: April, 2024
 */

#include "BinaryHeap.h"
#include "EmptyDataCollectionException.h"
#include "Event.h"
#include "PriorityQueue.h"
#include "Queue.h"
#include <iostream>
using namespace std;

constexpr static char ARRIVAL = 'A';
constexpr static char DEPARTURE = 'D';

// processes all arrival events
void processArrival(Queue<Event>& bankLine, PriorityQueue<Event>& eventPriorityQueue, bool& tellerAvailable, int& nextAvailableTime, int& timeWaited, Event& current)
{
    cout << "Processing an arrival event at time:   " << current.getTime() << endl;
    if (bankLine.isEmpty() && tellerAvailable)
    {
        // gets depearture time by adding the current time and the length of the event
        int departureTime = current.getTime() + current.getLength();
        // the next available time will then be when the last event is finished 
        nextAvailableTime = departureTime;
        // creates a new event for the departure
        Event newDepartureEvent = Event(DEPARTURE, departureTime);
        // adds the departure to the queue of events
        eventPriorityQueue.enqueue(newDepartureEvent);
        // teller is unvailable when an arrival happens so we make it equal to false
        tellerAvailable = false;
    }
    else
    {
        // gets the current time of the event
        int currentTime = current.getTime();
        // calculates the time waited by taking the next available time and reducing it by the current time
        timeWaited += nextAvailableTime - currentTime;
        // gets the new next available time by adding the current event length
        nextAvailableTime += current.getLength();
        // adds the current event to the queue
        bankLine.enqueue(current);
    }
}

// processes departures
void processDeparture(Queue<Event>& bankLine, PriorityQueue<Event>& eventPriorityQueue, bool& tellerAvailable, int& nextAvailableTime, Event& current)
{
    cout << "Processing a departure event at time:  " << current.getTime() << endl;
    if (!bankLine.isEmpty())
    {
        // front customer is helped by teller
        Event customer = bankLine.peek();
        bankLine.dequeue();
        // gets depearture time by adding the current time and the length of the event
        int departureTime = current.getTime() + customer.getLength();
        // creates new event for departure
        Event newDepartureEvent = Event(DEPARTURE, departureTime);
        eventPriorityQueue.enqueue(newDepartureEvent);
    }
    else
    {
        tellerAvailable = true;
    }
}

int main()
{
    int arrivalTime, TransactionTime;
    // stores arrival events
    Queue<Event> bankLine = Queue<Event>();  
    // stores arival and departure events
    PriorityQueue<Event> eventPriorityQueue = PriorityQueue<Event>(); 
    bool tellerAvailable = true;
    int nextAvailableTime = 0;
    int timeWaited = 0;
    int numOfElements = 0;

    while (cin >> arrivalTime >> TransactionTime)
    {
        Event myEvent = Event(ARRIVAL, arrivalTime, TransactionTime);
        eventPriorityQueue.enqueue(myEvent);
        numOfElements += 1;
    }

    cout << "Simulation Begins" << endl;

    while (!eventPriorityQueue.isEmpty())
    {
        // Process an arrival or departure event
        Event current = eventPriorityQueue.peek();
        eventPriorityQueue.dequeue();

        if (current.getType() == ARRIVAL)
        {
            processArrival(bankLine, eventPriorityQueue, tellerAvailable, nextAvailableTime, timeWaited, current);
        }
        else
        {
            processDeparture(bankLine, eventPriorityQueue, tellerAvailable, nextAvailableTime, current);
        }
    }

    cout << "Simulation Ends" << endl;
    cout << "\nFinal Statistics:" << endl;
    cout << endl;
    cout << "   Total number of people processed: " << numOfElements << endl;
    float solution = (timeWaited * 100 / numOfElements) / 100.0f;
    cout << "   Average amount of time spent waiting: " << solution << endl;

    return 0;
}
