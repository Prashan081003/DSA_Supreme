//Leetcode 69 (Easy) ;

//find square root of a number 
class Solution {
public:


    int mySqrt(int x) {
        int s = 0;
        int e = x;
        long long int mid = s + (e-s)/2;
        int ans = -1;

        while(s <= e) {
            //kya mid hi toh answer nahi
            if(mid*mid == x) {
                return mid;
            }
            else if(mid*mid < x) {
                //ans store
                //right me jao
                ans = mid;
                s = mid+1;
            }
            else {
                //left me jana h 
                e = mid-1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
};


#include <cmath>

class Solution {
public:
    // Function to calculate the integer part of the square root
    int integerSqrt(int x) {
        int s = 0;
        int e = x;
        long long int mid = s + (e - s) / 2;
        int ans = -1;

        while (s <= e) {
            if (mid * mid == x) {
                return mid;
            } else if (mid * mid < x) {
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
            mid = s + (e - s) / 2;
        }
        return ans;
    }

    // Function to calculate the square root up to three decimal places
    double mySqrt(int x) {
        int intPart = integerSqrt(x);
        double ans = intPart;
        double increment = 0.1;

        for (int i = 0; i < 3; ++i) {  // Loop to calculate up to three decimal places
            while (ans * ans <= x) {
                ans += increment;
            }
            ans -= increment;
            increment /= 10;
        }

        return ans;
    }
};
