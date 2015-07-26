##Sudoku
###求解器 Solver
---

####Human Algorithm
_Note_:
* 参考：[Sudoku.md](https://github.com/wuzhiyi/Sudoku/blob/master/Sudoku.md)
* 唯一求解函数
* 区块求解函数
* 数对删减函数
* 隐性数对删减函数
* 三链数删减函数
* 矩形顶点函数
* 关键数函数

####Computer Algorithm
[Sudoku Solver v1.0](https://github.com/wuzhiyi/Sudoku/blob/master/Sudoku_Solver_v1.0.c)</br>
[Sudoku Solver v2.0](https://github.com/wuzhiyi/Sudoku/blob/master/Sudoku_Solver_v2.0.c)</br>
_Note_:
* 输入原始数据，储存在初始化矩阵中
* 主要结构：主函数 + 数独函数 + 判断函数 + 输出函数
* 判断函数：分别判断行 + 列 + 宫
* 数独函数的核心语句：k递增与数独函数的递归，即对没有原始数据的位置初始化取 k=1，判断合理性，如成立，初始化下一位，直到合理性不成立，返回，k+1.

###生成器 Generator
---

##LICENSE
The MIT License (MIT)

Copyright (c) 2015 vinci

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
