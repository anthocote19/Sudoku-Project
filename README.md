# Sudoku Command Line Game

## Description
The **Sudoku Command Line Game** is a console-based puzzle game where the objective is to fill a 9x9 grid with numbers such that each row, column, and each of the nine 3x3 blocks contains all the numbers from 1 to 9 without repeating any number in any row, column, or block. The game offers a partially completed Sudoku grid, and the player must fill in the missing numbers. The game ends when the grid is completely and correctly filled.

## Features
- **Level Selection**:
  - The player can choose the difficulty level of the Sudoku puzzle.
  - The difficulty determines the number of pre-filled cells in the grid (easy, medium, hard).

- **Sudoku Grid Generation**:
  - A valid Sudoku grid is generated at the start.
  - The grid can be created by permuting rows/columns or using a backtracking algorithm for a more challenging puzzle.

- **Interactive Gameplay**:
  - The player is asked to input a number and select a position to insert it.
  - The grid is displayed after each input, showing the current state of the game.

- **Validation**:
  - The game ensures that the player's input respects the Sudoku rules (no repetition in the row, column, or 3x3 block).
  
- **End of Game**:
  - The game ends when the grid is completely and correctly filled.

## Technologies Used
- **Python**: Main programming language for the game.
- **Command Line**: The game is played directly in the terminal.

## Installation and Launch
1. **Clone the repository**:
   ```bash
   git clone https://github.com/your-repository/Sudoku-Game.git





Welcome to Sudoku!

Select Difficulty Level:
1. Easy
2. Medium
3. Hard

Enter your choice (1-3): 2

Sudoku Grid:
5 _ _ | 3 _ 7 | _ _ 8
_ 3 _ | _ _ 1 | _ 9 _
_ 4 _ | 5 _ _ | 6 _ _
------+-------+------
2 _ _ | _ _ _ | 8 _ _
6 _ _ | _ _ _ | _ _ 5
_ _ 8 | 7 _ _ | _ _ 3
------+-------+------
_ _ 3 | _ _ 8 | 9 _ _
_ 5 _ | 4 _ _ | _ _ 7
1 _ _ | 2 _ 5 | _ _ 6

Enter the number (1-9) and position (row, column): 4 2 3
...

Sudoku Grid:
5 2 _ | 3 _ 7 | _ _ 8
_ 3 _ | _ _ 1 | _ 9 _
_ 4 _ | 5 _ _ | 6 _ _
------+-------+------
2 _ _ | _ _ _ | 8 _ _
6 _ _ | _ _ _ | _ _ 5
_ _ 8 | 7 _ _ | _ _ 3
------+-------+------
_ _ 3 | _ _ 8 | 9 _ _
_ 5 _ | 4 _ _ | _ _ 7
1 _ _ | 2 _ 5 | _ _ 6
...
