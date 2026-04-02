# 数据结构与算法练习

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Language: C](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))

个人数据结构与算法学习仓库，用 C 语言实现基础数据结构和常见面试题。

## 📁 目录结构

```
.
├── algorithm/              # 算法面试题实现
│   └── interview-questions/
│       ├── Arrange-meeting-room/   # 会议室安排（贪心算法）
│       └── island-problem/         # 岛屿系列问题（DFS/BFS/并查集）
├── src/                    # 基础数据结构实现（开发中）
│   ├── linear-table/       # 线性表：数组、链表、栈、队列
│   ├── tree/               # 树：二叉树、BST、AVL树
│   ├── graph/              # 图：邻接表/矩阵、遍历算法
│   └── sorting/            # 排序：快排、归并、堆排序等
├── docs/                   # 学习笔记与文档
└── README.md               # 项目说明
```

## 🚀 快速开始

### 环境要求
- GCC 编译器
- VS Code（推荐）

### 编译运行

```bash
# 编译单个文件
gcc -o output filename.c

# 运行
./output

# 或者一步完成
gcc filename.c && ./a.out
```

## 📝 已完成的题目

### 岛屿问题系列
| 题目 | 算法 | 文件 |
|------|------|------|
| 岛屿数量 | DFS/BFS/并查集 | `numIslands.c` |
| 岛屿最大面积 | DFS | `maxAreaOfIslands.c` |
| 封闭岛屿数量 | DFS | `closedIsland.c` |
| 不同岛屿数量 | DFS+哈希 | `numDistinctIslands.c` |

### 贪心算法
| 题目 | 算法 | 文件 |
|------|------|------|
| 会议室安排 II | 贪心+优先队列 | `minMeetingRoomsl.c` |

## 📚 学习资源

- [《数据结构（C语言版）》](https://book.douban.com/subject/2024655/) - 严蔚敏
- [LeetCode](https://leetcode.cn/) - 在线刷题平台
- [labuladong 的算法小抄](https://github.com/labuladong/fucking-algorithm) - 算法学习指南

## 🎯 学习计划

- [x] 基础数据结构框架搭建
- [x] 岛屿问题系列
- [ ] 线性表实现
- [ ] 树与二叉树
- [ ] 图算法
- [ ] 排序算法合集

## 📄 License

MIT License - 详见 [LICENSE](LICENSE) 文件

---

> 💡 提示：本仓库持续更新中，欢迎 Star ⭐ 关注学习进度！
