#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 19; // n = 15 + 4 = 19

// Funktsiia dlia avtmatychnoho stvorennia failiv, yakshcho yikh nemaie
void generateFileIfMissing(const string& filename) {
    ifstream check(filename);
    if (check.is_open()) {
        check.close();
        return;
    }

    ofstream outfile(filename);
    cout << "Stvoriuiemo fail " << filename << " z malymy chyslamy..." << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            outfile << (rand() % 5 + 1) << " "; // Nebol'shi chysla vid 1 do 5
        }
        outfile << endl;
    }
    outfile.close();
}

// Funktsiia dlia obchyslennia R = 2*A + B
void addScaledMatrices(const vector<vector<long long>>& A, const vector<vector<long long>>& B, vector<vector<long long>>& R) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            R[i][j] = 2 * A[i][j] + B[i][j];
        }
    }
}

// Funktsiia dlia transponuvannia matrytsi: R = M^T
void transposeMatrix(const vector<vector<long long>>& M, vector<vector<long long>>& R) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            R[j][i] = M[i][j];
        }
    }
}

// Funktsiia dlia mnochennia dvokh matryts: R = M1 * M2 (vykorystano long long)
void multiplyMatrices(const vector<vector<long long>>& M1, const vector<vector<long long>>& M2, vector<vector<long long>>& R) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            R[i][j] = 0;
            for (int k = 0; k < N; ++k) {
                R[i][j] += M1[i][k] * M2[k][j];
            }
        }
    }
}

// Funktsiia dlia zchytannia matrytsi z failu
bool readMatrixFromFile(const string& filename, vector<vector<long long>>& M) {
    ifstream infile(filename);
    if (!infile.is_open()) {
        cout << "Pomylka vidkryttia failu: " << filename << endl;
        return false;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!(infile >> M[i][j])) {
                cout << "Pomylka zchytannia chysla u faili " << filename << endl;
                return false;
            }
        }
    }
    infile.close();
    return true;
}

// Funktsiia dlia zapysu matrytsi u fail та vyvedennia v konsol
void writeMatrixToFile(const string& filename, const vector<vector<long long>>& M) {
    ofstream outfile(filename);
    if (!outfile.is_open()) {
        cout << "Pomylka vidkryttia failu dlia zapysu: " << filename << endl;
        return;
    }

    cout << "\n=== Rezultuiucha Matrytsia C [19x19] ===" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            outfile << setw(10) << M[i][j] << " ";
            cout << setw(8) << M[i][j] << " ";
        }
        outfile << endl;
        cout << endl;
    }
    outfile.close();
    cout << "\nRezul'tat uspishno zapysano u fail: " << filename << endl;
}

int main() {
    srand(time(NULL));

    generateFileIfMissing("a.txt");
    generateFileIfMissing("b.txt");

    vector<vector<long long>> A(N, vector<long long>(N));
    vector<vector<long long>> B(N, vector<long long>(N));

    if (!readMatrixFromFile("a.txt", A) || !readMatrixFromFile("b.txt", B)) {
        return 1;
    }

    vector<vector<long long>> Temp(N, vector<long long>(N)); // 2A + B
    vector<vector<long long>> BT(N, vector<long long>(N));   // B^T
    vector<vector<long long>> C(N, vector<long long>(N));    // C = (2A + B) * B^T

    // 1. Obchyslennia (2A + B)
    addScaledMatrices(A, B, Temp);

    // 2. Obchyslennia B^T
    transposeMatrix(B, BT);

    // 3. Obchyslennia C = (2A + B) * B^T
    multiplyMatrices(Temp, BT, C);

    // 4. Zapys та vyvedennia
    writeMatrixToFile("c.txt", C);

    return 0;
}
