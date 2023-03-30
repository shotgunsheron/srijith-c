#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long n, m;
  cin >> n >> m;
  vector<string> graph;
  vector<vector<bool>> visited(n, vector<bool>(m));
  vector<vector<long long>> distance(n, vector<long long>(m, 1e6 + 1));
  long long aRow, aCol, bRow, bCol;
  for (long long i = 0; i < n; i++) {
    string x;
    cin >> x;
    graph.push_back(x);
    for (long long j = 0; j < m; j++) {
      if (graph[i][j] == 'A') {
        aRow = i;
        aCol = j;
      } else if (graph[i][j] == 'B') {
        bRow = i;
        bCol = j;
      }
    }
  }
 
  queue<vector<long long>> bfs;
  bfs.push({bRow, bCol, 0});
  visited[bRow][bCol] = true;
  long long counter = 0;
 
  while (!bfs.empty()) {
 
    long long curRow = bfs.front()[0];
    long long curCol = bfs.front()[1];
    // cout << curRow << ' ' << curCol << '\n';
    if (curRow + 1 < n and
        (graph[curRow + 1][curCol] == '.' or
         graph[curRow + 1][curCol] == 'A') and
        visited[curRow + 1][curCol] == false) {
 
      bfs.push({curRow + 1, curCol, bfs.front()[2] + 1});
      distance[curRow + 1][curCol] = bfs.front()[2] + 1;
      visited[curRow + 1][curCol] = true;
    }
    if (curRow - 1 >= 0 and
        (graph[curRow - 1][curCol] == '.' or
         graph[curRow - 1][curCol] == 'A') and
        visited[curRow - 1][curCol] == false) {
 
      bfs.push({curRow - 1, curCol, bfs.front()[2] + 1});
      distance[curRow - 1][curCol] = bfs.front()[2] + 1;
 
      visited[curRow - 1][curCol] = true;
    }
    if (curCol + 1 < m and
        (graph[curRow][curCol + 1] == '.' or
         graph[curRow][curCol + 1] == 'A') and
        visited[curRow][curCol + 1] == false) {
 
      bfs.push({curRow, curCol + 1, bfs.front()[2] + 1});
      distance[curRow][curCol + 1] = bfs.front()[2] + 1;
 
      visited[curRow][curCol + 1] = true;
    }
    if (curCol - 1 >= 0 and
        (graph[curRow][curCol - 1] == '.' or
         graph[curRow][curCol - 1] == 'A') and
        visited[curRow][curCol - 1] == false) {
 
      bfs.push({curRow, curCol - 1, bfs.front()[2] + 1});
      distance[curRow][curCol - 1] = bfs.front()[2] + 1;
 
      visited[curRow][curCol - 1] = true;
    }
    bfs.pop();
  }
  distance[bRow][bCol] = 0;
  string ans = "";
  long long curRow = aRow;
  long long curCol = aCol;
  vector<vector<bool>> tmp(n, vector<bool>(m));
  visited = tmp;
  if (distance[aRow][aCol] == 1e6 + 1) {
    cout << "NO" << '\n';
  } else {
    while (graph[curRow][curCol] != 'B') {
      long long minDistance = 1e6 + 1;
      long long minRow, minCol;
      if (curRow + 1 < n and
          (graph[curRow + 1][curCol] == '.' or
           graph[curRow + 1][curCol] == 'B') and
          !visited[curRow + 1][curCol]) {
        if (distance[curRow + 1][curCol] <= minDistance) {
          minRow = curRow + 1;
          minCol = curCol;
          minDistance = distance[curRow + 1][curCol];
        }
        visited[curRow + 1][curCol] = true;
      }
      if (curRow - 1 >= 0 and
          (graph[curRow - 1][curCol] == '.' or
           graph[curRow - 1][curCol] == 'B') and
          !visited[curRow - 1][curCol]) {
 
        if (distance[curRow - 1][curCol] <= minDistance) {
          minRow = curRow - 1;
          minCol = curCol;
          minDistance = distance[curRow - 1][curCol];
        }
        visited[curRow - 1][curCol] = true;
      }
      if (curCol + 1 < m and
          (graph[curRow][curCol + 1] == '.' or
           graph[curRow][curCol + 1] == 'B') and
          !visited[curRow][curCol + 1]) {
 
        if (distance[curRow][curCol + 1] <= minDistance) {
          minRow = curRow;
          minCol = curCol + 1;
          minDistance = distance[curRow][curCol + 1];
        }
        visited[curRow][curCol + 1] = true;
      }
      if (curCol - 1 >= 0 and
          (graph[curRow][curCol - 1] == '.' or
           graph[curRow][curCol - 1] == 'B') and
          !visited[curRow][curCol - 1]) {
 
        if (distance[curRow][curCol - 1] <= minDistance) {
          minRow = curRow;
          minCol = curCol - 1;
          minDistance = distance[curRow][curCol - 1];
        }
        visited[curRow][curCol - 1] = true;
      }
      if (minRow == curRow + 1) {
        curRow++;
        ans += 'D';
      } else if (minRow == curRow - 1) {
        curRow--;
        ans += 'U';
      } else if (minCol == curCol + 1) {
        curCol++;
        ans += 'R';
      } else {
        curCol--;
        ans += 'L';
      }
    }
    cout << "YES" << '\n';
    cout << ans.length() << '\n';
    cout << ans << '\n';
  }
}
