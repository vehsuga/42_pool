## Sudoku Solver
---
This algorithm solves [**__valid__**] 9x9 Sudoku puzzles.
---
__The program takes 9 argument eachof which represents a puzzle line consisting of numbers and '.' for empty squares__

**To compile:** `gcc -Wall -Werror -Wextra src/main.c src/solver.c -o sudoku`

**To run:** `./sudoku [9 lines here]`

**Example input grids:**

`...7.2... 1...4...7 65.....94 47.8.1.62 ......... 58.2.9.13 86.....75 9...6...8 ...9.8...`
![solution](http://article.sapub.org/image/10.5923.j.jgt.20140301.01_028.gif)

`.....4.9. 8.297.... 9.12..3.. ....49157 .13.5.92. 57912.... ..7..26.3 ....382.5 .2.5.....`
![original](https://anysudokusolver.com/images/Sudoku-Solving.png)
![solution](https://anysudokusolver.com/images/Sudoku-Solved.png)

`..78.52.. 8..6.4..5 .1..9..8. 4..289..7 ......... 5..761..2 .7..3..6. 3..1.6..4 ..25.81..`
![solution](http://article.sapub.org/image/10.5923.j.jgt.20140301.01_028.gif)

