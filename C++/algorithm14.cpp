#include <iostream>
#include <vector>
using namespace std;
#define MAXSIZE 9
#define MARK 1
#define UNMARK 0
typedef struct Point {int x, y;} point;
point direction[8] = {{1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};
int chessboard[MAXSIZE][MAXSIZE], chesspath[MAXSIZE][MAXSIZE];
int knightTour(int m, int n, point pos, int counter) {
    point next;
    if(counter == m * n) return 1;
    for(int i = 0; i < 8; i++) {
        next.x = pos.x + direction[i].x;
        next.y = pos.y + direction[i].y;
        if(next.x > 0 && next.x <= m && next.y > 0 && next.y <= n && chessboard[next.x][next.y] != MARK) {
            chessboard[next.x][next.y] = MARK;
            chesspath[next.x][next.y] = counter + 1;
            if(knightTour(m, n, next, counter + 1)) return 1;
            chessboard[next.x][next.y] = UNMARK;
        }
    }
    return 0;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        point start;
        int m, n;
        cin >> m >> n >> start.x >> start.y;
        for(int i = 1; i <= m; i++) for(int j = 1; j <= n; j++) chessboard[i][j] = UNMARK;
        chessboard[start.x][start.y] = MARK;
        chesspath[start.x][start.y] = 1;
        if(knightTour(m, n, start, 1)) {
            cout << 1 << endl;
            for(int i = 1; i <= m; i++) {
                for(int j = 1; j <= n; j++) {
                    cout << chesspath[i][j] << " ";
                }
                cout << endl;
            }
        }
        else cout << 0 << endl;
    }
    return 0;
}
