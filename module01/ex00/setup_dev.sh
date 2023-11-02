#!/bin/bash

PROGRAM_NAME=left4dead

setupCompileFlags() {
    echo -n > compile_flags.txt
    for line in "$@"
    do
        echo "$line" >> compile_flags.txt
    done
}

setupGitignore() {
    echo -n > .gitignore
    for line in "$@"
    do
        echo "$line" >> .gitignore
    done
}

# setup formatter
clang-format -style=google -dump-config > .clang-format

# setup linter
echo "filter=-legal/copyright" > CPPLINT.cfg

# setup language server
setupCompileFlags "-Wall" "-Wextra" "-Werror" "-std=c++98" "-I./"

setupGitignore "$PROGRAM_NAME" "obj" "debug" ".clang-format" "CPPLINT.cfg" "compile_flags.txt"
