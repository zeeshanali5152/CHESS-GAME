# ♟️ C++ Console Chess Game Engine
**OOP Semester Project | Spring 2026**

A fully functional, object-oriented console-based Chess game implemented from scratch in C++. This project was developed to demonstrate the practical application of core Object-Oriented Programming (OOP) principles by managing complex game states, dynamic piece movement, and board simulations without the use of external game engines.

---

## 👥 Authors
* **Zeeshan Ali** 
* **Hafiz Asad**
* **Ammar Ahmad**

---

## ✨ Features
* **Full Move Validation:** Every piece (`Pawn`, `Rook`, `Knight`, `Bishop`, `Queen`, `King`) follows its precise standard movement and capture rules.
* **Path & Collision Checking:** Detects if sliding pieces (like Bishops, Rooks, and Queens) are blocked by friendly or enemy pieces.
* **Advanced Game State Detection:** * **Check:** Automatically detects if a King is under attack and restricts the player from making illegal moves that endanger their King.
  * **Checkmate Engine:** Uses a look-ahead simulation to verify if a player has any legal moves left, properly ending the game.
* **Dynamic User Interface:** Clean command-line grid displaying algebraic-style notation for easy input.

---

## 🛠️ Technical Implementation
This project deeply integrates the following OOP concepts:

* **Abstraction:** The `Piece` base class utilizes pure virtual functions (e.g., `virtual bool isValidMove(...) = 0;`) to create a strict template that all pieces must follow.
* **Inheritance:** Specific chess pieces inherit coordinates, colors, and basic properties from the parent `Piece` class, ensuring clean, DRY (Don't Repeat Yourself) code.
* **Polymorphism:** The game board relies on a 2D array of generic `Piece` pointers. Functions like move validation are resolved via dynamic binding at runtime depending on what piece occupies a specific square.
* **Composition & Encapsulation:** The `Board` class acts as the central manager, encapsulating the 8x8 grid and handling memory management (creating and deleting objects safely) away from the user's view.

---

## 📂 Project Structure

```text
├── main.cpp            # Game entry point and core turn loop
├── board.h / .cpp      # 8x8 Grid management, Check/Checkmate engine
├── piece.h / .cpp      # Abstract base class for all board entities
├── pawn.h / .cpp       # Derived class: Pawn directional logic and captures
├── rook.h / .cpp       # Derived class: Rook horizontal/vertical logic
├── knight.h / .cpp     # Derived class: Knight L-shape jump logic
├── bishop.h / .cpp     # Derived class: Bishop diagonal logic
├── queen.h / .cpp      # Derived class: Queen omnidirectional logic
└── king.h / .cpp       # Derived class: King movement rules




🚀 How to Build and Run
Prerequisites
Ensure you have a modern C++ compiler installed
Compilation
Open your terminal in the project directory and compile all source files together:

Execution
Run the compiled executable:

Windows: chess.exe

Mac/Linux: ./chess




🎮 How to Play
The game relies on standard Algebraic Notation (Column Row) to move pieces across the grid.

Columns: A through H

Rows: 0 through 7

When prompted, input your starting coordinate and destination coordinate separated by spaces.

Example Inputs:

To move the piece at E1 to E3: e 1 e 3

To capture a piece at F7 using your piece at F3: f 3 f 7
