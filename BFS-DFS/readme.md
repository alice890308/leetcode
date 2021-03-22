# BFS & DFS
## advanced topic
### 記憶化
走過的地方就把結果記起來，下次走到的時候就可以直接拿結果
### IDDFS(iterative deepening DFS)
1. D = 1->2->3->...
2. DFS(u)->D
- 雖然看起來看BFS很像，但是DFS比BFS還要省記憶體
- 和BFS一樣第一次找到的就是最佳解
- IDDFS的概念就是，他主要把時間都花在最底下的幾層(步數最多的那幾層)，所以上面幾層花的時間並不算什麼，就給他算
### 15 puzzle
- heuristic：用一個值來為當前的狀態評分，越接近最佳解，分數會越好
  - 可以用來放棄明顯很差的路線
  - 和IDDFS很好搭配
