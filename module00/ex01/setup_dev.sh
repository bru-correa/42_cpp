#!/bin/bash

PROGRAM_NAME=phonebook

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
setupCompileFlags "-Wall" "-Wextra" "-Werror" "-std=c++98"

setupGitignore "$PROGRAM_NAME" "obj" "debug" ".clang-format" "CPPLINT.cfg" "compile_flags.txt"
