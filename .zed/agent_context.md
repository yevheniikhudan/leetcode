PROJECT_ROOT: leetcode/
LANGUAGES: [python, java, cpp]
DEFAULT_PYTHON: python3

BUILD:
  CPP: "clang++ -std=c++17 -g -O0 $ZED_FILE -o $ZED_DIRNAME/$ZED_STEM"
  JAVA: "javac -g $ZED_FILE"
TEST:
  PY: "pytest -q"

REPO_IGNORE_PATHS: [".git/", ".venv/", "node_modules/"]
SAFE_BRANCH_PREFIX: "fix/"
PATCH_FORMAT: "unified diff"
DEFAULT_TIMEOUT_MS: 300000
MAX_FILES_CHANGE: 100

AUTO_RULES:
  NO_SUMMARY: true               # do not summarize actions unless requested
  AUTO_CREATE_LEETCODE: true     # on LeetCode link, auto-create skeleton set
  FILES_PER_PROBLEM: 5
  SKELETON_FILES: ["problem.md","tutorial.md","{snake}.py","{snake}.cpp","{Pascal}.java"]

RULES:
  - do_not_modify_CI_LICENSE
  - prompt_if_exceeds_MAX_FILES_CHANGE
  - prompt_if_modifying_repo_root_or_CI

TEST_OUTPUT_FORMAT: "actual | expected | PASS/FAIL"

CODING_STANDARDS:
  python:
    - "Optional[TreeNode] for nullable types"
    - "heapq for min-heap"
    - "use pass for unimplemented methods"
    - "helper/test functions outside Solution"
  java:
    - "PascalCase for classes"
    - "private for helper methods, public for API"
    - "return null for unimplemented methods"
    - "Solution class for algorithm; separate class for main/tests"
  cpp:
    - "use nullptr"
    - "use -> for pointer access"
    - "delete dynamic memory when used"
    - "priority_queue is max-heap by default"

CONTACT_ON:
  - modify_repo_root
  - exceed_MAX_FILES_CHANGE

# Minimal human note (kept short):
# - This file is machine-readable; move long docs to .zed/agent_policy.md if needed.