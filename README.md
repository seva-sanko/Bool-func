# Bool-func

Discrete Mathematics 2 lab — a console tool for analyzing 4-variable Boolean functions. The user enters a 16-bit truth table string and can then query all standard Boolean function representations.

**4 variables:** `x`, `y`, `z`, `h` — 16 rows in the truth table.

## Features

| Option | Operation |
|--------|-----------|
| 1 | Build and print the **Zhegalkin polynomial** (algebraic normal form) |
| 2 | Evaluate a point using the **Zhegalkin polynomial** |
| 3 | Build and print **SDNF** (perfect disjunctive normal form) |
| 4 | Build and print **SKNF** (perfect conjunctive normal form) |
| 5 | Evaluate a point using the **BDR** (binary decision diagram) |
| 6 | Print the full **truth table** |
| 7 | Evaluate a point using **SDNF** |

## Implementation

### Input

On startup the user enters the function as a 16-character binary string (e.g. `0011010000011111`), validated with `std::regex`.

### Zhegalkin polynomial

Built using the triangle method (Pascal's triangle over GF(2)): the truth table column is XOR-reduced iteratively. Coefficients are stored in a 2D `vector<vector<bool>>`. The polynomial is printed in algebraic notation, e.g. `F = 1 ⊕ x ⊕ xz ⊕ xyzh`.

### SDNF / SKNF

- **SDNF**: collect all minterms (rows where F = 1), write each as a conjunction of literals.
- **SKNF**: collect all maxterms (rows where F = 0), write each as a disjunction of literals.

Evaluation (`Search_SDNF`) encodes the query point as an index into the truth table.

### Binary Decision Diagram (BDR)

Implemented as a binary tree of `data` nodes:

```cpp
struct data {
    char name;      // variable: 'x', 'y', 'z', 'h', '0', '1'
    data* False;    // branch taken when variable = 0
    data* True;     // branch taken when variable = 1
};
```

The tree has depth 4 (one level per variable). Leaf nodes are shared `BDR_F` (0) and `BDR_T` (1) singletons. `SearchBDR` traverses from root to leaf by following the input bits.

## Build

```
Visual Studio — open Dismath(2).sln
```

## Files

| File | Description |
|------|-------------|
| `Dismath(2).cpp` | `main()` — menu loop and input validation |
| `BulIst.h` | Class declaration + `data` struct |
| `BulIst.cpp` | All algorithm implementations |
| `dismath2.pdf` | Full lab report |
