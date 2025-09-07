Perfect 👍 here’s the full **README.md content** you can copy–paste directly:

---

# Tic-Tac-Toe Game 🎮

A simple **console-based Tic-Tac-Toe game** implemented in **C**.
This project was created as part of a university assignment to demonstrate **modular programming** by separating functions into `.c` and `.h` files.

---

## 📖 Description

This project implements a **two-player Tic-Tac-Toe game** where players take turns to mark spaces in a 3x3 grid. The game checks for valid moves, detects winners, and declares a draw if all spaces are filled without a winner.

---

## ✨ Features

* **Two-Player Mode** – Play against a friend in turn-based gameplay.
* **Console-Based** – Lightweight game running directly in the terminal.
* **Modular Design** – Functions are organized in separate `.c` and `.h` files for better structure.
* **Error Handling** – Ensures players input valid moves.

---

## 💻 Technologies Used

* **Language:** C
* **Compiler:** GCC (or any standard C compiler)

---

## ⚙️ Setup Instructions

Clone the repository:

```bash
git clone https://github.com/your-username/Tic-Tac-Toe-Game.git
cd Tic-Tac-Toe-Game
```

Compile the program:

```bash
gcc file.c -o tictactoe
```

Run the game:

```bash
./tictactoe
```

---

## 📂 Folder Structure

```
├── file.c       # Contains main game logic and flow
├── header.h     # Function declarations and helper logic
├── README.md    # Project documentation
```

---

## 🎲 How to Play

* Player 1 uses **'X'**, Player 2 uses **'O'**.
* Players take turns entering a position number (1–9) corresponding to the grid:

```
  1 | 2 | 3
  ---------
  4 | 5 | 6
  ---------
  7 | 8 | 9
```

* The game declares a **winner** if a player aligns three marks (horizontal, vertical, or diagonal).
* If all spaces are filled without a winner, the game declares a **draw**.

---




