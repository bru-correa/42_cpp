#!/bin/bash

workdir=$HOME/projects/42/cpp

createModule() {
    ex_count="$1"
    module_count=$(ls */ | grep module | wc -l)
    mkdir "${workdir}"/module0"${module_count}"
    cd "${workdir}"/module0"${module_count}"
    counter=0
    for ((i = 0; i < $ex_count; i++)); do
        read -p "Program name for ex0${i}: " program_name
        mkdir ex0"${i}"
        cd ex0"${i}"
        cp "${workdir}"/MAKEFILE_EXAMPLE  ./Makefile
        sed -i -e "s/PROGRAM_NAME/${program_name}/g" ./Makefile
        setupConfigFiles
        cd ../
    done
}

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

setupConfigFiles() {
    # setup formatter
    clang-format -style=google -dump-config > .clang-format
    # setup linter
    echo "filter=-legal/copyright" > CPPLINT.cfg
    # setup language server
    setupCompileFlags "-Wall" "-Wextra" "-Werror" "-std=c++98" "-I./"
    setupGitignore "${program_name}" "obj" "debug" ".clang-format" "CPPLINT.cfg" "compile_flags.txt"
}

# Main
echo "How many exercises this module have?"
read input;

if [[ ${input} ]] && [ ${input} -eq ${input} 2>/dev/null ]
then
    createModule ${input}
else
    echo "The input must be an integer"
fi
