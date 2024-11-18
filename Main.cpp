#include <iostream>
#include <iomanip>

template <typename T>
void initMatrix(T matrix[][100], int size, T value = 1) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = value++;
        }
    }
}

template <typename T>
void printMatrix(const T matrix[][100], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << std::setw(5) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
void findMinMaxDiagonal(const T matrix[][100], int size, T& max, T& min) {
    if (size <= 0) return; // Обработка пустой матрицы

    max = matrix[0][0];
    min = matrix[0][0];

    for (int i = 1; i < size; ++i) {
        if (matrix[i][i] > max) {
            max = matrix[i][i];
        }
        if (matrix[i][i] < min) {
            min = matrix[i][i];
        }
    }
}

template <typename T>
void sortRows(T matrix[][100], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - 1; ++j) {
            for (int k = j + 1; k < size; ++k) {
                if (matrix[i][j] > matrix[i][k]) {
                    std::swap(matrix[i][j], matrix[i][k]);
                }
            }
        }
    }
}


int main() {
    setlocale(LC_ALL, "Rus");
    int size = 5;
    int intMatrix[100][100];
    double doubleMatrix[100][100];
    char charMatrix[100][100];

    initMatrix(intMatrix, size, 1); // Инициализация целых чисел
    std::cout << "Целочисленная матрица:\n";
    printMatrix(intMatrix, size);

    initMatrix(doubleMatrix, size, 1.2);  //Инициализация вещественных чисел
    std::cout << "\nМатрица с вещественными числами:\n";
    printMatrix(doubleMatrix, size);

    initMatrix(charMatrix, size, 'A'); //Инициализация символов
    std::cout << "\nМатрица с символами:\n";
    printMatrix(charMatrix, size);


    int intMax, intMin;
    findMinMaxDiagonal(intMatrix, size, intMax, intMin);
    std::cout << "\nМаксимальный и минимальный элементы на диагонали (целые): " << intMax << ", " << intMin << std::endl;

    double doubleMax, doubleMin;
    findMinMaxDiagonal(doubleMatrix, size, doubleMax, doubleMin);
    std::cout << "Максимальный и минимальный элементы на диагонали (вещественные): " << doubleMax << ", " << doubleMin << std::endl;

    sortRows(intMatrix, size);
    std::cout << "\nОтсортированная целочисленная матрица:\n";
    printMatrix(intMatrix, size);

    sortRows(doubleMatrix, size);
    std::cout << "\nОтсортированная вещественная матрица:\n";
    printMatrix(doubleMatrix, size);

    return 0;
}