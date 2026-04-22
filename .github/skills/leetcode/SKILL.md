---
name: leetcode
description: Creates leetcode problem setup. Use when leetcode link is provided
allowed-tools: shell
---

## Quick Start for New Problems

When given a LeetCode link or problem, do not ask for confirmation. Parse the link and create the complete setup automatically.

### Directory Structure
```
src/{ProblemNumber}_{problem_title}/
├── {problem_title}.py          (Python implementation)
├── {problem_title}.cpp         (C++ implementation)
├── {ProblemTitle}.java         (Java implementation)
├── problem.md                  (Problem description & constraints)
└── {problem_title}_tutorial.md (No-code tutorial)
```

### Naming Conventions
- **Directory:** `{ProblemNumber}_{problem_title}` (snake_case with number prefix)
  - Example: `226_invert_binary_tree`
- **Python file:** `{problem_title}.py` (snake_case)
- **C++ file:** `{problem_title}.cpp` (snake_case)
- **Java file:** `{ProblemTitle}.java` (PascalCase)
- **Markdown files:** `{problem_title}_tutorial.md`, `{problem_title}.md`

## File Content Guidelines

### `problem.md`
- Problem title and difficulty level
- Topics/tags
- Full problem description
- Examples with clear input/output
- Constraints
- Related problems (if applicable)

### `{problem_title}_tutorial.md`
- Understanding the problem (conceptual explanation)
- Visual examples and diagrams
- Multiple approaches (explain strategies WITHOUT code)
- Time/Space complexity analysis
- Key concepts and patterns
- Edge cases and common pitfalls
- **Important:** NO code implementations in this file

### Language Implementations

All three language files should follow the same structure:

#### Python (`{problem_title}.py`)
- Class `Solution` with method signature only
- Method body returns `pass` (no implementation)
- Test cases at the bottom with 5+ test examples
- Tests compare output and print results
- Ready to run with `python {problem_title}.py`

#### C++ (`{problem_title}.cpp`)
- Class `Solution` with method signature only
- Method body returns `nullptr` or appropriate default
- Helper functions for testing (with memory cleanup)
- Test cases in `main()` with 5+ test examples
- Compile with: `g++ -o {problem_title} {problem_title}.cpp`
- Run with: `./{problem_title}`

#### Java (`{ProblemTitle}.java`)
- Class `Solution` with method signature only
- Method body returns `null` or appropriate default
- Separate class `{ProblemTitle}` with `main()` method
- Helper methods for testing
- Test cases in `main()` with 5+ test examples
- Compile with: `javac {ProblemTitle}.java`
- Run with: `java {ProblemTitle}`

## Test Output Format

All test cases should print results in this format:
```
actual | expected | PASS (if actual == expected)
actual | expected | FAIL (if actual != expected)
```

Examples:
```
[0,1] | [0,1] | PASS
[1,2,4] | [1,2,3] | FAIL
true | true | PASS
```

## Running Tests Locally

### Python
```bash
cd src/{problem_directory}
python {problem_title}.py
```

### C++
```bash
cd src/{problem_directory}
g++ -o {problem_title} {problem_title}.cpp
./{problem_title}
```

### Java
```bash
cd src/{problem_directory}
javac {ProblemTitle}.java
java {ProblemTitle}
```

## High-Level Architecture

This repository organizes LeetCode problems by problem number and name. Each problem is self-contained with:
- **Tutorial:** Conceptual understanding without implementations
- **Problem file:** Full problem specification
- **Implementations:** Skeleton code with tests in three languages (Python, C++, Java)

The focus is on learning the problem-solving approach first (via tutorials) before attempting implementations.

## Key Conventions

1. **No implementations in skeletons:** Skeleton files contain ONLY method signatures and test code
2. **Tutorial is code-free:** Strategies and approaches explained conceptually, no code snippets
3. **Test scaffolding included:** Each language file has 5+ test cases ready to run
4. **Language-specific defaults:** Python uses `pass`, C++ uses `nullptr`, Java uses `null`
5. **Immediate test execution:** All language files can be run directly without additional setup
6. **Separate test format:** Tests check actual vs expected and print pass/fail status

## Code Style

- **C++:** Uses `.clang-format` configuration (see `.clang-format` in repo root)
- **Java:** PascalCase class names, camelCase method names
- **Python:** snake_case functions and variables
- **Editor config:** All languages respect `.editorconfig` settings

## Git Ignore

The repository ignores:
- Compiled binaries: `.o`, `.exe`, `.out`, `.class`, `.jar`
- C++ executables: files without extensions in problem directories
- Python cache: `__pycache__/`, `*.pyc`
- IDE settings: `.vscode/settings.json`, `.idea/`
- OS files: `.DS_Store`, `Thumbs.db`
