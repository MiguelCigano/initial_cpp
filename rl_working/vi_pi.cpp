#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

const int SIZE = 3;
const double GAMMA = 0.99; // Factor de descuento
const double EPSILON = 1e-6;

// Recompensas: [0,0,0], [0,-10,0], [0,0,10 (META)]
double R[SIZE][SIZE] = {
    {0,  0,   0},
    {0, -10,  0},
    {0,  0,  10}
};

// --- ITERACIÓN DE VALOR ---
// Aquí solo actualizamos V hasta que sea óptima.
void valueIteration() {
    vector<vector<double>> V(SIZE, vector<double>(SIZE, 0.0));
    
    while (true) {
        double delta = 0;
        vector<vector<double>> nextV = V;

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (R[i][j] != 0) continue; // Saltamos estados terminales

                // Bellman: V(s) = max_a [ R(s,a) + gamma * V(s') ]
                double bestV = -1e9;
                // Acciones: Arriba, Abajo, Izquierda, Derecha
                int dx[] = {-1, 1, 0, 0};
                int dy[] = {0, 0, -1, 1};

                for (int a = 0; a < 4; a++) {
                    int ni = clamp(i + dx[a], 0, SIZE - 1);
                    int nj = clamp(j + dy[a], 0, SIZE - 1);
                    bestV = max(bestV, R[ni][nj] + GAMMA * V[ni][nj]);
                }
                
                nextV[i][j] = bestV;
                delta = max(delta, abs(nextV[i][j] - V[i][j]));
            }
        }
        V = nextV;
        if (delta < EPSILON) break;
    }
    
    cout << "--- Resultado Iteracion de Valor (V*) ---" << endl;
    for(auto row : V) {
        for(double val : row) cout << setw(8) << fixed << setprecision(2) << val << " ";
        cout << endl;
    }
}

// --- ITERACIÓN DE POLÍTICA ---
// Alterna entre evaluar el manual y mejorarlo.
void policyIteration() {
    vector<vector<double>> V(SIZE, vector<double>(SIZE, 0.0));
    vector<vector<int>> policy(SIZE, vector<int>(SIZE, 1)); // 0:Arr, 1:Abj, 2:Izq, 3:Der

    bool policyStable = false;
    while (!policyStable) {
        // 1. Evaluación de Política (Calcular V para la política actual)
        for (int k = 0; k < 100; k++) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    if (R[i][j] != 0) continue;
                    int a = policy[i][j];
                    int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
                    int ni = clamp(i + dx[a], 0, SIZE - 1);
                    int nj = clamp(j + dy[a], 0, SIZE - 1);
                    V[i][j] = R[ni][nj] + GAMMA * V[ni][nj];
                }
            }
        }

        // 2. Mejora de Política (Hacerla greedy respecto a la nueva V)
        policyStable = true;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (R[i][j] != 0) continue;
                int oldAction = policy[i][j];
                double bestVal = -1e9;
                int bestAction = 0;
                int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

                for (int a = 0; a < 4; a++) {
                    int ni = clamp(i + dx[a], 0, SIZE - 1);
                    int nj = clamp(j + dy[a], 0, SIZE - 1);
                    double val = R[ni][nj] + GAMMA * V[ni][nj];
                    if (val > bestVal) { bestVal = val; bestAction = a; }
                }
                policy[i][j] = bestAction;
                if (oldAction != bestAction) policyStable = false;
            }
        }
    }

    cout << "\n--- Resultado Iteracion de Politica (Mejor Manual) ---" << endl;
    for(auto row : policy) {
        for(int a : row) {
            char icons[] = {'^', 'v', '<', '>'};
            cout << setw(8) << icons[a] << " ";
        }
        cout << endl;
    }
}

int main() {
    valueIteration();
    policyIteration();
    return 0;
}