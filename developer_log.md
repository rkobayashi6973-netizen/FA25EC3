# Developer Log

## December 8, 2025

### What I worked on
- Read through README.md to understand the project requirements
- Analyzed main.cpp to see how the Tree class would be used
- Started planning the structure for Node and Tree template classes

### Issues encountered
- Wasn't sure how to handle multiple parents pointing to the same child node
- Needed to figure out how to prevent memory leaks with shared children

### How I solved it
- Decided to use a vector called `allNodes` to track all created nodes
- This way I can delete each node only once in the destructor

### Notes
- No code written yet, just planning

---

## December 9, 2025

### What I worked on
- Started implementing Node constructor
- Worked on Tree constructor and createRoot()
- Tried different approaches for findNode()

### Issues encountered
- First tried using DFS with recursion for findNode, but ran into infinite loops because of shared children

### How I solved it
- Realized I could just iterate through allNodes vector instead of DFS
- Much cleaner and avoids the cycle problem

### Notes
- Still testing locally, not ready to commit yet

---

## December 10, 2025

### What I worked on
- Finished implementing all Tree methods
- Implemented addNode() to connect parent and child nodes
- Added logic to reuse existing child nodes if they already exist
- Implemented printAll() with DFS traversal and visited tracking
- Implemented playGame() for interactive gameplay
- Implemented destructor to free all allocated memory
- Final testing and cleanup

### Issues encountered
- printAll() was printing the same node multiple times due to shared children
- playGame() needed input validation for invalid choices

### How I solved it
- Used a set to track visited nodes in printAll() helper function
- Added bounds checking in playGame() for user input

### Files modified
- tree.h

### Commit
- "Completed Tree class implementation with all required methods"

---

## Final Notes
- All required methods implemented in tree.h
- Memory management handled by storing all nodes in allNodes vector
- Destructor deletes each node exactly once to prevent double-free errors
- Tested locally with sample story data before committing
