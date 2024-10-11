
A car travels from a starting position to a destination which is target miles east of the starting position.

There are gas stations along the way. The gas stations are represented as an array stations
where stations[i] = [positioni, fueli] indicates that the ith gas station is positioni miles 
east of the starting position and has fueli liters of gas.
The car starts with an infinite tank of gas, which initially has startFuel liters of fuel in it.
It uses one liter of gas per one mile that it drives.
When the car reaches a gas station, it may stop and refuel, transferring all the gas from the station into the car.
Return the minimum number of refueling stops the car must make in order to reach its destination. 
If it cannot reach the destination, return -1.
Note that if the car reaches a gas station with 0 fuel left, the car can still refuel there. 
If the car reaches the destination with 0 fuel left, it is still considered to have arrived.

Example 1:

Input: target = 1, startFuel = 1, stations = []
Output: 0
Explanation: We can reach the target without refueling.


class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
         
          int stops = 0;
         int dist = 0 ; 
         priority_queue<pair<int,int>>pq; 
         int i = 0 ;
         int fuel = startFuel;
         while(true){
              while(i<stations.size()){
              //push stations within the  reach with my current fuel levels from my current position 
                 if(stations[i][0]  <= dist+fuel)
                     pq.push({stations[i][1],stations[i][0]});
                 else 
                    break;
                 ++i;
              }

            // travel with full fuel level 
              dist += fuel;
              fuel =0 ;

            // if raeched
              if(dist>= target) break;


            //no fuel statioins within reach 
              if(pq.empty()){
                stops = -1;
                break;
              }

            // refuel ans re-adjust dist & fuel 
              auto&top = pq.top();
              fuel = (dist - top.second) + top.first;
              dist = top.second;
              pq.pop();
              ++stops;

         }
         return stops;
    }
};
