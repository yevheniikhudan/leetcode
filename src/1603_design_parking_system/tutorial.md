# 1603. Design Parking System - Tutorial

This is a simple simulation and counting problem. The goal is to track the number of available parking spots for each type and update them as cars arrive.

## Approach Outline
1. Store the available spots for each car type in an array or separate variables.
2. When a car arrives, check if a spot is available for its type.
3. If available, decrement the count and return true; otherwise, return false.

## Key Concepts
- Array or variable tracking
- Simple conditional logic
- No advanced data structures needed

## Edge Cases
- All spots of a type are full
- All spots are zero at initialization
- Multiple calls to addCar

This problem is a good introduction to simulation and state tracking.
