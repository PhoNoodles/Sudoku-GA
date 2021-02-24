# Sudoku-AOCGA
This is a collaborate AI project. We will be comparing AOC to GA algorithms for solving sudoku

This is a group project for a psu CS441 course.

to get code locally:
git clone https://github.com/PhoNoodles/Sudoku-AOC-GA.git
set your git remote:
git init 
git remote set-url origin https://github.com/PhoNoodles/Sudoku-AOC-GA.git
to create your own branch:
git checkout -b <branch-name> 
to add / commit changes:
git add *   
or

git add file1 file2 etc...
git commit -m "your commit comment here"
to push to your branch:
git push origin <branch-name>
How to build on the linux terminal
start by making a directory named build for all the build files

mkdir build && cd build
Then run cmake for the directory above; it will place all of the build files inside the current directory

cmake ..
Once it's done, you can then run make

make
If the build is successful, it will then make an executable named "cs300-wi20" which you can then run
