---
name: leetcode
description: Creates a comfortable LeetCode problem setup for solving and storing problems. Use when a LeetCode link, problem number, or problem title is provided. Do not solve the problem unless the user explicitly asks for an implementation or solution.
allowed-tools: shell
---

## Quick Start for New Problems

When given a LeetCode link, problem number, or problem title, do not ask for confirmation. Parse or look up the problem metadata and create the complete setup automatically.

**Default behavior is setup-only.** Prepare the problem directory, prompt notes, tutorial guidance, runnable files, and test scaffolding for future solving. Do not implement the algorithm or fill in the final solution unless the user directly asks to solve, implement, complete, or provide the answer.

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
- Method body uses `pass` or an appropriate placeholder return
- Test cases at the bottom with 5+ test examples
- Tests compare output and print results
- Ready to run with `python {problem_title}.py`

#### C++ (`{problem_title}.cpp`)
- Class `Solution` with method signature only
- Method body returns an appropriate placeholder/default value
- Helper functions for testing (with memory cleanup)
- Test cases in `main()` with 5+ test examples
- Compile with: `g++ -o {problem_title} {problem_title}.cpp`
- Run with: `./{problem_title}`

#### Java (`{ProblemTitle}.java`)
- Class `Solution` with method signature only
- Method body returns an appropriate placeholder/default value
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

1. **Setup first:** The skill creates a comfortable workspace for solving and storing the problem, not the final answer
2. **No implementations unless requested:** Skeleton files contain method signatures, placeholder returns, and test code only
3. **Tutorial is code-free:** Strategies and approaches explained conceptually, no code snippets
4. **Test scaffolding included:** Each language file has 5+ test cases ready to run
5. **Language-specific placeholders:** Use `pass`, `None`, `nullptr`, `false`, `0`, empty containers, or other appropriate defaults
6. **Immediate test execution:** All language files can be run directly without additional setup
7. **Separate test format:** Tests check actual vs expected and print pass/fail status

If the user explicitly asks to solve or implement the problem, then replace placeholders with working solutions and update tests as needed.

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
