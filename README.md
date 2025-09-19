# CST 426 TicTacToe

This folder contains the files for the TicTacToe assignment for CST 426

## Assignment 1: Making the game

All of my changes to the initial code was in the `TicTacToe.cpp` file

I noticed that the pieces were flipped according to the instructions, so I made a change to the `PieceForPlayer()` function in `TicTacToe.cpp` despite the comments saying not to change it. This was done because the mismatch in the pieces for each player was bothering me. This change was just making the comparison from 1 to 0;

``` C++
// original
bit->LoadTextureFromFile(playerNumber == 1 ? "x.png" : "o.png");
// my changeed function
bit->LoadTextureFromFile(playerNumber == 0 ? "x.png" : "o.png");
```

I just followed the instructions from the comments and managed to get everything working, I then started to work on/think about efficiency. Specifically with how I handle my `stateString()` function.

## Side Quest 1: In search of (a little) efficiency

Originally, I was handling it according to the instructions, by starting with an empty string and then appending as I read the board state. This is incredibly inefficient as appending to strings are slow.

So after talking with the professor, I intialized a string with all zeros like this: `"000000000"` and just edited by index, which is more efficient.

Right after was the next class, in which we implemented an AI for the game using the negamax algorithm.

## Side Quest 2: AI extra credit!!!

As my final feature so far, I quickly implemented the ability to toggle playing against the AI with a button.

I did this with a public access bool called `vsAI` in `TicTacToe.h` and had the `gameHasAI()` function return that instead. The reason why I did that is to have this integrate with the codebase smoothly since the function is used to figure out whether to call `AIUpdate()` or not. Then, in `Application.cpp`, I created an if else statement that will display what is currently being played against. `vsAI` is currently only being used for the if statement below. 

```C++
if(game->vsAI) // grabbing the public access bool
{
    if(ImGui::Button("Playing Against: AI"))
        game->vsAI = false;
}
else
{
    if(ImGui::Button("Playing Against: Human"))
        game->vsAI = true;
}
```