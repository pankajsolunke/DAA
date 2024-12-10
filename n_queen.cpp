#include <iostream> 
using namespace std; 
 
int board[15][15]; 
bool isSafe(int r, int c, int n) { 
    for (int i = 0; i < c; ++i) 
        if (board[r][i]) return false; 
    for (int i = r, j = c; i >= 0 && j >= 0; --i, --j) 
        if (board[i][j]) return false; 
    for (int i = r, j = c; i < n && j >= 0; ++i, --j) 
        if (board[i][j]) return false; 
    return true;
} 
bool solve(int c, int n) { 
    if (c == n) return true; 
    for (int r = 0; r < n; ++r) { 
        if (isSafe(r, c, n)) { 
            board[r][c] = 1;
            if (solve(c + 1, n)) return true;
            board[r][c] = 0;
        } 
    } 
    return false; 
}  
int main() { 
    int n; 
    cout << "Enter the number of queens (n): "; 
    cin >> n;  
    if (solve(0, n)) { 
        for (int i = 0; i < n; ++i) { 
            for (int j = 0; j < n; ++j) 
                cout << (board[i][j] ? " Q " : " . "); 
            cout << endl; 
        } 
    } else { 
        cout << "No solution"; 
    } 
    return 0; 
}