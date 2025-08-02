# Mathematical Function Grapher in C

🔹 **Brief Description**  
A terminal-based application that parses mathematical expressions, converts them to postfix notation, evaluates them, and plots the resulting functions as ASCII graphs. Supports basic operations, trigonometric functions, logarithms, and handles variable 'x' for graphing.

## Acquired/Improved Skills
- **Mathematical Computing**: Developed advanced skills in implementing complex mathematical operations including trigonometry, logarithms, and custom function evaluation
- **Algorithm Design**: Mastered the Postfix Polish Notation algorithm for expression parsing and efficient postfix notation conversion
- **System Architecture**: Built a modular pipeline with clear separation between parsing, calculation, and visualization components
- **Precision Programming**: Implemented robust floating-point number handling with careful attention to edge cases and domain limitations
- **Memory Management**: Developed expertise in manual memory allocation/deallocation with comprehensive error checking
- **Input Validation**: Designed rigorous syntax checking for mathematical expressions with multiple validation layers

## 🛠️ Technologies  
- **Language**: C  
- **Libraries**: Standard C Library (math.h, stdlib.h)  
- **Algorithms**: Postfix Polish Notation algorithm for expression parsing  
- **Data Structures**: Stack implementation for operations  
- **Environment**: Cross-platform (Linux/macOS/Windows with compatible C compiler)  

## ✨ Key Features  
- **Expression Parser**: Handles complex mathematical expressions with operator precedence  
- **Function Support**: sin, cos, tan, ctg, sqrt, ln, and unary minus operations  
- **Graph Visualization**: Renders function plots in terminal with adjustable precision  
- **Error Handling**: Validates input syntax and mathematical domain constraints  
- **Memory Management**: Manual memory allocation/deallocation with safety checks  

## 🚀 Launch Instructions  
### Compilation and Execution
- Clone the repository:
  ```bash
  git clone git@github.com:ehaxi/polish-notation.git
  cd polish-notation
  ```
- Compile the program:
  ```bash
  make src/graph
  ```
- Run the game:
  ```bash
  ./build/game_of_life
  ```

## 🔧 Project Structure
- calc.[h/c]: Expression evaluation engine
- parse.[h/c]: Lexical analysis and parsing
- stack.[h/c]: Stack data structure implementation
- draw.[h/c]: ASCII graph rendering
- graph.c: Main application logic

## 💡 Key Algorithms
- Postfix Polish Notation Algorithm: Converts expression to postfix notation
- Postfix Evaluation: Computes function values
- ASCII Rendering: Maps function values to terminal characters

## 🔮 Future Improvements
Here are the planned improvements and features for the project: 
### **1. Fix bugs**  
- Solve problem with memory allocation
- Solve problem with display of some functions