



// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int totalStudents, successfulStudents;
//     cin >> totalStudents >> successfulStudents;

//     vector<vector<int>> superiorTo(totalStudents);
//     vector<int> indegree(totalStudents, 0);

//     // Read constraints
//     for (int student = 0; student < successfulStudents; student++) {
//         int wishesCount;
//         cin >> wishesCount;

//         while (wishesCount--) {
//             int subordinate;
//             cin >> subordinate;
//             subordinate--;

//             superiorTo[student].push_back(subordinate);
//             indegree[subordinate]++;
//         }
//     }

//     // Topological sort (Kahn's algorithm)
//     queue<int> q;

//     for (int i = 0; i < totalStudents; i++) {
//         if (indegree[i] == 0)
//             q.push(i);
//     }

//     vector<int> topoOrder;

//     while (!q.empty()) {
//         int current = q.front();
//         q.pop();

//         topoOrder.push_back(current);

//         for (int next : superiorTo[current]) {
//             if (--indegree[next] == 0)
//                 q.push(next);
//         }
//     }

//     // Build a chain (boss assignment)
//     vector<int> boss(totalStudents, -1);

//     for (int i = 1; i < totalStudents; i++) {
//         boss[topoOrder[i]] = topoOrder[i - 1];
//     }

//     // first node becomes main boss
//     boss[topoOrder[0]] = 0;

//     // output
//     for (int i = 0; i < totalStudents; i++) {
//         cout << boss[i] + 1 << "\n";
//     }
// }

#include <iostream>
#include <vector> 
#include <algorithm> 
#include <utility>

using namespace std;

vector<vector<int>> wishingList;
vector<pair<int,int>> Edges_in_out;
vector<int> bosses;
vector<bool> visited;

int mainBoss = 0;
int iterations = 0;

void dfs_remove(int node);

void checkEmpty(int iterations) {
    for (int i = 0; i < iterations; ++i) {
        if (Edges_in_out[i].first == 0 && !visited[i]) {
            dfs_remove(i);
            break;
        }
    }
}

void dfs_remove(int node) {
    visited[node] = true;

    for (int i = 0; i < wishingList[node].size(); ++i) {
        int child = wishingList[node][i];
        bosses[child] = node;
        Edges_in_out[node].second--;
        Edges_in_out[child].first--;
    }

    checkEmpty(iterations);
}

int main () {

    int studentsNO, s_studentsNO;
    cin >> studentsNO >> s_studentsNO;

    iterations = studentsNO;

    wishingList.resize(studentsNO);
    Edges_in_out.resize(studentsNO, {0,0});
    bosses.assign(studentsNO, -1);
    visited.assign(studentsNO, false);

    for (int i = 0; i < s_studentsNO; ++i) {
        int n;
        cin >> n;
        for (int j = 0; j < n; ++j) {
            int c;
            cin >> c;
            c--;
            wishingList[i].push_back(c);
            Edges_in_out[i].second++;
            Edges_in_out[c].first++;
        }
    }

   bool firstBoss = true;

    for (int i = 0; i < studentsNO; ++i) {
        if (Edges_in_out[i].first == 0 && !visited[i]) {
            if (firstBoss) {
                mainBoss = i;
                firstBoss = false;
            }
            else {
                bosses[i] = mainBoss;
            }
            dfs_remove(i);
        }
    }
    for (int i = 0; i < studentsNO; ++i) {

        if (i == mainBoss) {
            cout << i + 1 << " -> 0\n";
        }
        else {
            cout << i + 1 << " -> " << bosses[i] + 1 << '\n';
        }
    }
} 
