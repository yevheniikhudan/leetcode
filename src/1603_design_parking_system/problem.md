# 1603. Design Parking System

[LeetCode Link](https://leetcode.com/problems/design-parking-system/description/)

Design a parking system for a parking lot. The parking lot has three kinds of parking spaces: big, medium, and small, with a fixed number of slots for each.

Implement the `ParkingSystem` class:
- `ParkingSystem(int big, int medium, int small)` Initializes object with the number of slots for each type.
- `bool addCar(int carType)` Checks if there is a slot for the car of type `carType` (1=big, 2=medium, 3=small). If so, parks the car in that slot and returns true; otherwise, returns false.

**Example:**
Input: ["ParkingSystem","addCar","addCar","addCar","addCar"], [[1,1,0],[1],[2],[3],[1]]
Output: [null,true,true,false,false]

**Constraints:**
- 0 <= big, medium, small <= 1000
- carType is 1, 2, or 3
- At most 1000 calls to addCar will be made.
