# Repository Guidelines

## Project Structure & Module Organization

This repository stores LeetCode practice problems under `src/`. Each problem is self-contained in a directory named `{number}_{snake_case_title}`, for example `src/1_two_sum/` or `src/226_invert_binary_tree/`.

Typical files in a problem directory are:

- `{snake_case_title}.py` for Python.
- `{snake_case_title}.cpp` for C++.
- `{PascalCaseTitle}.java` for Java.
- `problem.md` or `{camelCaseTitle}.md` for the prompt.
- `tutorial.md` or `{camelCaseTitle}_tutorial.md` for explanatory notes.
- Optional `.excalidraw` files for diagrams.

There is no shared application package; avoid cross-problem dependencies unless a reusable helper is explicitly introduced.

## Build, Test, and Development Commands

Run solutions from their problem directory:

```bash
cd src/1_two_sum
python two_sum.py
g++ -std=c++17 -Wall -Wextra -o two_sum two_sum.cpp && ./two_sum
javac TwoSum.java && java TwoSum
```

The repository has no root-level build system or unified test runner. Use direct language commands to validate the file you changed. Remove generated binaries and `.class` files before committing; they are ignored but should not be part of reviews.

## Coding Style & Naming Conventions

Follow the existing naming pattern: snake_case directories and Python/C++ files, PascalCase Java files and classes, camelCase methods where matching LeetCode signatures. Use 4-space indentation. C++ formatting is defined by `.clang-format` using Google style, attached braces, and a 100-column limit. Keep code focused on the problem solution plus lightweight local test cases.

## Testing Guidelines

Tests live inside each solution file, usually in a Python script body, C++ `main()`, or Java `main()`. Add representative examples, edge cases, and expected outputs when changing a solution. Prefer output that clearly compares actual and expected values, for example `actual | expected | PASS`.

## Commit & Pull Request Guidelines

Recent commits are short and usually reference the problem number, such as `1133` or `2452`; keep that convention for single-problem changes. For broader changes, use a concise imperative summary, for example `update formatting guidance`.

Pull requests should state which problem directories changed, list the commands run, and mention any generated assets or diagrams. Include screenshots only when updating visual `.excalidraw` material.

## Agent-Specific Instructions

Keep edits scoped to the requested problem or documentation file. Do not rewrite unrelated solutions for style. When adding a new problem, create all expected language and markdown files in one matching `src/{number}_{title}/` directory.
