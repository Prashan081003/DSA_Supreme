#include <vector>  // Required for using the vector container
#include <stack>   // Required for using the stack container
#include <algorithm> // Required for using the sort function

using namespace std;

class Solution {
    // Inner class to represent a Car with position and speed
    class Car {
    public:
        int pos, speed; // Position and speed of the car

        // Constructor to initialize a car object
        Car(int p, int s) : pos(p), speed(s) {}
    };

    // Comparator function to sort cars based on their positions
    static bool myComp(Car &a, Car &b) {
        return a.pos < b.pos; // Sort cars by their position in ascending order
    }

public:
    // Function to calculate the number of car fleets that reach the target
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> cars; // Vector to store car objects

        // Create car objects and store them in the cars vector
        for (int i = 0; i < position.size(); i++) {
            Car car(position[i], speed[i]); // Initialize a car with position and speed
            cars.push_back(car); // Add the car to the vector
        }

        // Sort the cars by their position using the custom comparator
        sort(cars.begin(), cars.end(), myComp);

        stack<float> st; // Stack to keep track of time taken by each car to reach the target

        // Iterate over the sorted cars to calculate the time for each car
        for (auto car : cars) {
            float time = (target - car.pos) / static_cast<float>(car.speed); // Time = Distance / Speed

            // Merge fleets if the current car catches up with the previous one
            while (!st.empty() && time >= st.top()) {
                st.pop(); // Remove the fleet that is caught up
            }

            st.push(time); // Push the time of the current car onto the stack
        }

        return st.size(); // The size of the stack represents the number of car fleets
    }
};
