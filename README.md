## 求解器 Solver

#### Human Algorithm

_Note_:

- 参考日志：[Sudoku.md](https://github.com/wuzhiyi/Sudoku/blob/master/Sudoku.md)
- 唯一求解函数：[Unique.c](https://github.com/wuzhiyi/Sudoku/blob/master/Unique.c)
- 区块求解函数
- 数对删减函数
- 隐性数对删减函数
- 三链数删减函数
- 矩形顶点函数
- 关键数函数

#### Computer Algorithm

[Backtracking Sudoku Solver v1.0](https://github.com/wuzhiyi/Sudoku/blob/master/Sudoku_Solver_v1.0.c)<br/>
[Backtracking Sudoku Solver v2.0](https://github.com/wuzhiyi/Sudoku/blob/master/Sudoku_Solver_v2.0.c)<br/>

_Note_:

- 输入原始数据，储存在初始化矩阵中
- 主要结构：主函数 + 数独函数 + 判断函数 + 输出函数
- 判断函数：分别判断行 + 列 + 宫
- 数独函数的核心语句：k递增与数独函数的递归，即对没有原始数据的位置初始化取 k=1，判断合理性，如成立，初始化下一位，直到合理性不成立，返回，k+1.

## 生成器 Generator


## [LICENSE](https://github.com/wuzhiyi/Sudoku/blob/master/LICENSE)
