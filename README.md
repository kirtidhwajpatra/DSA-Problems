# DSA-Problems

C++ repository of algorithm and data-structure problem solutions (LeetCode and practice problems). Implementations prioritize correctness, asymptotic efficiency, and clear, maintainable logic.

## Structure
- /<problem-folder>/
  - solution.cpp        — primary, self-contained implementation
  - README.md / notes.md — (optional) approach, complexity, edge cases, sample I/O
  - test.txt            — (optional) sample input for quick runs
- utils/ (optional)     — reusable helpers (fast I/O, small utilities)

Folder names use the problem ID and/or title for fast discovery (e.g., `1_Two_Sum`, `200_Number_of_Islands`).

## What recruiters should look for
- Breadth: solutions across arrays, strings, trees, graphs, DP, greedy, sorting, and search.
- Correctness: attention to edge cases and defensive handling.
- Efficiency: asymptotically optimal approaches where applicable, with complexity notes.
- C++ proficiency: idiomatic STL usage, performance-aware code (C++17), and clean function decomposition.
- Communication: per-problem notes explaining approach and trade-offs where provided.

## Languages & tools
- Language: C++ (targeting C++17)
- Build: g++ / clang++
- Recommended tooling: clang-format, sanitizers/valgrind for memory checks, Git for VCS

## Quick navigation & usage
- Find a problem: browse folders or use repository search (by ID, title, or algorithm keyword).
- Compile a solution:
  g++ -std=c++17 -O2 -Wall path/to/problem/solution.cpp -o solution
- Run with sample input:
  ./solution < path/to/problem/test.txt
- Review notes: open per-problem README.md or notes.md for complexity and reasoning.

Contributions: focused pull requests with a single problem addition/update, include complexity notes and sample tests.
