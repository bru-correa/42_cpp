module=$(find . -maxdepth 1 -type d | grep module | sort | fzf)

cp -r $module ../evals_cpp
cd ../evals_cpp
module_count=$(ls */ | grep module | wc -l)
cd ./module0${module_count}

git init
setup-personal
git add .
git commit -m "First commit"
