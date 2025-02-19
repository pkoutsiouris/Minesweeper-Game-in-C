# Minesweeper Game in C
A simple implementation of the Minesweeper game in C programming language.
This implementation is basic and it was developed during the first semester of my computer engineering and informatics studies as an undergraduate student.

In this segment of the README file, I will provide an analysis of the code and the functions that is consisted of:
At first:

-The necessary libraries for running the program are included.
-The functions that will be used in the program are defined:

    -The main function is the primary function of the program. Here, the check is done for the game mode to be provided, the sizes of the rows and columns (s1 and s2) are defined, and the rest of the functions         are called to run the game.
    -The welcome_message function displays a welcome message and asks the player to enter their name.
    -The gamemode function asks the player to choose one of the three game modes (8x8, 16x16, 32x16), performs a check for correct input from the user, and returns the desired game mode to the main function.

-The game function is responsible for running the game. In this function, the grid is initialized, mines are placed, cells are revealed, and the game's result is checked:
At this point in the code, the elements of the grid array are reset, and 'X' elements are placed in the revealed array to indicate the cells that have not been revealed yet.
Here, the user is asked to specify the number of mines to be placed in the game grid, input validation is performed, and random cells are selected where mines will be placed.

-In the next part of the code, a series of logical variables and counters are used.
The variables good1 and good2 are used to check the correct input of the coordinates "gram" and "sthlh" accordingly.
-After this is checked, the code continues by checking the state of the element in the grid array (whether it contains a mine or not, and whether it has been revealed):

      -If the element selected by the user contains a mine, an appropriate message is displayed, informing the player that they have lost, and the game grid is displayed with theVpositions of the mines and the empty cells that the user had chosen. Furthermore, the variable "bust" is set to 1, causing the loop to terminate, and the user is asked whether they want to continue with a new game or exit the program.
      
      -If the cell has already been revealed, an appropriate message is displayed, and the user is prompted to re-enter the coordinates.
      
      -If the cell does not contain a mine and has not been revealed, its state is updated in the grid array, and the number of mines surrounding it (top, bottom, left, right, and diagonally) is placed in the corresponding cell in the revealed array instead of 'X', and 10 points are added to the score. Additionally, 1 is added to the "cor" (Count Of Revealed) counter. Once the "cor" counter reaches the total number of cells minus the number of mines (s1*s2-mines), it means the player has successfully revealed all the cells that do not contain mines, signaling their victory, and the loop is exited using           the break statement from the do-while loop with the condition bust != 1. Outside of this loop, a control condition triggers a victory message, asking the player if they want to continue the game.
-Additionally, the ability to quit the round has been added by entering the number 555 in the "gram" variable. By entering 555, the user terminates the current round of the game and a message is displayed asking whether they want to continue the game or not.
The countMines function calculates the number of mines around a cell, in the order mentioned earlier.

Please note that the code as a first project is functional but not optimized meaning that some features could be developed in more optimal ways.For instance, the printing of the arrays "revealed" and "grid" could be accomplished with the use of a function but instead to keep it functional they have been put plainly in the code. 
