# C++ Command-Line Solitaire

Welcome to a classic game of Klondike Solitaire, brought to life in your command-line interface! This project is a C++ implementation of the beloved card game, offering a challenging and engaging experience for programmers and gamers alike.

## 🌟 Features

* **Classic Klondike Gameplay**: The familiar rules of Solitaire, right in your terminal.
* **Interactive Piles**: Move cards between the seven main piles.
* **Foundation Piles**: Build up your four collection piles from Ace to King to win.
* **Scoring System**: Earn points as you successfully move cards to the foundation piles.
* **Help/Draw Pile**: Draw cards from the stock pile when you're stuck.
* **Difficulty Modes**: Choose your challenge level: Easy, Medium, or Hard.
* **Dynamic Interface**: The console view updates after every move, showing visible cards, pile sizes, and your current score.

## 📋 Requirements

* A C++ compiler (e.g., g++, MinGW)
* **Operating System**: Windows only

This program uses the `<windows.h>` library for console manipulation, such as cursor positioning and text coloring, and is therefore not compatible with Linux or macOS without modification.

## 🚀 Getting Started

### Compilation

1.  Open a terminal or command prompt on your Windows machine.
2.  Navigate to the directory containing the project files.
3.  Compile the program using the following `g++` command:

    ```bash
    g++ solitaire/main.cpp -o solitaire.exe
    ```

### Running the Game

1.  After successful compilation, run the game by executing the generated file:

    ```bash
    .\solitaire.exe
    ```

2.  The game will start, and you can begin playing immediately!

## 🎮 How to Play

The game is controlled through simple numerical inputs.

1.  **Select a Card**: When prompted, enter the **pile number** and then the **card number** (from the visible cards in that pile) that you wish to move.
2.  **Move to Foundation**: After selecting a card, the game will ask if you want to move it to a "winner slot" (the foundation piles). Type `y` for yes if it's a legal move.
3.  **Move to Another Pile**: If you don't move the card to the foundation, you will be prompted to select a **destination pile number** to move the card(s) to.
4.  **Draw from Stock**: At the start of your turn, you can choose to draw a "helping card" from the stock pile by typing `y`. You can then choose to move one of these cards to a pile.

The goal is to move all 52 cards into the four foundation piles, ordered by suit from Ace to King.

## 📂 Code Structure

The project is organized into several files, each with a specific responsibility:

* `main.cpp`: Contains the main game loop, handles the overall program flow, and prints the game state.
* `card.h`: Defines the `card` class, which includes properties like suit, color, number, and character (A, K, Q, J). It also contains the Windows-specific functions for console UI manipulation.
* `Header.h`: Defines the `Stack` class, which is used to represent and manage the various piles of cards on the game board.
* `leagality.h`: Houses the core game logic. This includes functions for validating moves, transferring cards between piles, handling user input for card selection, and managing the help/draw pile.
* `start.txt`: A simple data file that contains the definitions for all 52 cards, which are loaded at the start of the game.
* `s.h`: An older, unreferenced version of the Stack class definition that is not used in the final program.