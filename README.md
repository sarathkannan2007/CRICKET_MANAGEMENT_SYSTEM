# Cricket Management and Match Simulation System

A C++ based Cricket Management and Match Simulation System designed to apply Data Structures and Object-Oriented Programming concepts to a practical cricket application.

The project manages teams and players, generates a Best Playing XI based on player ratings, creates a match dashboard, and simulates a cricket match ball by ball.

## Project Overview

This project was developed as a practical implementation of Data Structures and C++ programming concepts.

Instead of using DSA concepts only for individual problems, the goal of this project is to understand how these concepts can work together as part of a complete system.

The system currently supports:

- Team management
- Player management
- Team-wise player management
- Best XI prediction
- Playing XI generation
- Match dashboard
- Toss and batting/bowling decision
- Ball-by-ball match simulation
- Runs and wickets tracking
- Striker and non-striker management
- Batsman replacement after a wicket
- Bowler rotation
- Two innings
- Target calculation
- Match result and winning margin

## Data Structures Used

### Linked List

Linked Lists are used to manage players and Playing XI selections.

They are also used during match simulation to move between players dynamically.

For example:

- Moving to the next batsman after a wicket
- Moving to the next bowler after an over
- Maintaining the order of players in the Playing XI

This helped me understand how node traversal and pointers can be applied to a real-world simulation.

### Priority Queue

A custom Priority Queue is used for Best XI prediction.

Players are assigned a score based on their role and performance ratings. The Priority Queue maintains players in descending order of their calculated score.

The highest-rated players can then be selected to construct the Playing XI.

### Structures and Pointers

Structures and pointers are used to create and connect player nodes dynamically.

The project uses pointers to maintain relationships between players, teams, and match components.

### Object-Oriented Programming

The project is divided into separate classes and modules for different responsibilities.

Some of the major components include:

- Team Management
- Player Management
- Best XI Prediction
- Playing XI
- Match Management
- Match Simulation

This modular approach makes the project easier to understand and extend.

## System Flow

```text
Team Management
        |
        v
Player Management
        |
        v
Best XI Prediction
        |
        v
Playing XI Generation
        |
        v
Match Dashboard
        |
        v
Toss
        |
        v
First Innings
        |
        v
Second Innings
        |
        v
Match Result

### How to Run

Open Terminal

1.    g++ *.cpp -o output
2.    ./output
