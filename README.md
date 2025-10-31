# Integration Branch

## Purpose
The Integration branch combines feature branches for testing and verification before changes go to `main`. It helps ensure the code works together and passes CI checks.

## Workflow

1. **Create a feature branch from Integration:**
    ```bash
    git checkout -b feature/<feature-name> Integration
    ```

2. **Develop your changes and commit:**
    ```bash
    git add .
    git commit -m "Add <feature-name>"
    ```

3. **Push your feature branch and open a PR against Integration.**

4. **Merge only after CI checks pass and the PR is approved.**

## Rules

- No direct pushes to `Integration`.
- Resolve conflicts in your branch before submitting a PR.
- Follow code style and run tests locally.
