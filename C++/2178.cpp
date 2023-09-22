#include <iostream>

using namespace std;
//백준 2178번 문제
int main() {
    int n, m;
    int maze[100][100];
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }
    //가로 우선
    int l_cnt = 0;
    int l_flag = 0;
    for(int i = 0; i < n; i) {
        for(int j = 0; j < m; j) {
            if(maze[i][j+1] == 1) {
                l_cnt++;
                j++;
            }else if(maze[i+1][j] == 1) {
                l_cnt++;
                i++;
            }else if(maze[i][j-1] == 1) {
                l_cnt++;
                j--;
            }else if(maze[i-1][j] == 1) {
                l_cnt++;
                i--;
            }
            if(i == n-1 && j == m-1) {
                l_flag = 1;
                cout << l_cnt;
                break;
            }
        }
        if(l_flag == 1) {
            break;
        }
    }
    //세로 우선
    int w_cnt = 0;
    int w_flag = 0;
    for(int i = 0; i < n; i) {
        for(int j = 0; j < m; j) {
            if(maze[i+1][j] == 1) {
                w_cnt++;
                i++;
            }else if(maze[i][j+1] == 1) {
                w_cnt++;
                j++;
            }else if(maze[i-1][j] == 1) {
                w_cnt++;
                i--;
            }else if(maze[i][j-1] == 1) {
                w_cnt++;
                j--;
            }
            if(i == n-1 && j == m-1) {
                w_flag = 1;
                cout << w_cnt;
                break;
            }
        }
        if(w_flag == 1) {
            break;
        }
    }
    if(l_cnt > w_cnt) {
        cout << w_cnt;
    }else {
        cout << l_cnt;
    }
}