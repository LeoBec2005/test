#include <iostream>
#include <vector>

using namespace std;

vector<int> decimalToBinary(int num, int n) {
    vector<int> binary(n, 0);
    if (num < 0) {
        num = (1 << n) + num;
    }
    for (int i = 0; i < n; ++i) {
        binary[n - 1 - i] = (num >> i) & 1;
    }
    return binary;
}

int binaryToDecimal(const vector<int>& bin) {
    int n = bin.size();
    int result = 0;
    for (int i = 0; i < n; ++i) {
        result += bin[n - 1 - i] * (1 << i);
    }
    if (bin[0] == 1) {
        result -= (1 << n);
    }
    return result;
}

vector<int> binaryAdd(const vector<int>& A, const vector<int>& B) {
    int n = A.size();
    vector<int> result(n, 0);
    int carry = 0;

    for (int i = n - 1; i >= 0; --i) {
        int sum = A[i] + B[i] + carry;
        result[i] = sum % 2;
        carry = sum / 2;
    }

    return result;
}

vector<int> binaryTwosComplement(const vector<int>& bin) {
    int n = bin.size();
    vector<int> complement(n, 0);
    for (int i = 0; i < n; ++i) {
        complement[i] = bin[i] == 0 ? 1 : 0;
    }
    vector<int> one(n, 0);
    one[n - 1] = 1;
    return binaryAdd(complement, one);
}

void arithmeticRightShift(vector<int>& A, vector<int>& Q, int& Q_1) {
    int n = A.size();
    Q_1 = Q[n - 1];
    for (int i = n - 1; i > 0; --i) {
        Q[i] = Q[i - 1];
    }
    Q[0] = A[n - 1];
    for (int i = n - 1; i > 0; --i) {
        A[i] = A[i - 1];
    }
}

vector<int> boothMultiplication(int M, int Q, int n) {
    vector<int> A(n, 0);
    vector<int> M_bin = decimalToBinary(M, n);
    vector<int> Q_bin = decimalToBinary(Q, n);
    int Q_1 = 0;

    vector<int> M_neg = binaryTwosComplement(M_bin);

    for (int i = 0; i < n; ++i) {
        if (Q_bin[n - 1] == 1 && Q_1 == 0) {
            A = binaryAdd(A, M_neg);
        }
        else if (Q_bin[n - 1] == 0 && Q_1 == 1) {
            A = binaryAdd(A, M_bin);
        }
        arithmeticRightShift(A, Q_bin, Q_1);
    }

    vector<int> AQ(2 * n, 0);
    for (int i = 0; i < n; ++i) {
        AQ[i] = A[i];
        AQ[n + i] = Q_bin[i];
    }

    return AQ;
}

int main() {
    int M, Q, n;

    cout << "Ingrese el multiplicando (M): ";
    cin >> M;
    cout << "Ingrese el multiplicador (Q): ";
    cin >> Q;
    cout << "Ingrese la cantidad de bits (n): ";
    cin >> n;

    vector<int> result_bin = boothMultiplication(M, Q, n);
    int result_dec = binaryToDecimal(result_bin);

    cout << "Resultado en binario: ";
    for (int bit : result_bin) {
        cout << bit;
    }
    cout << endl;

    cout << "Resultado en decimal: " << result_dec << endl;

    return 0;
}
