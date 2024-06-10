#include <bits/stdc++.h>
using namespace std;

// Function to convert IEEE 754 single-precision binary to float
float binaryToFloat(uint32_t binary) {
    if (binary == 0x7F800000) return INFINITY;       // +Infinity
    if (binary == 0xFF800000) return -INFINITY;      // -Infinity
    if ((binary >= 0x7F800001 && binary <= 0x7FFFFFFF) ||
        (binary >= 0xFF800001 && binary <= 0xFFFFFFFF)) return NAN;  // NaN

    int sign = (binary >> 31) & 1;
    int exponent = (binary >> 23) & 0xFF;
    int mantissa = binary & 0x7FFFFF;

    float value;
    if (exponent == 0) {
        // Subnormal number
        value = mantissa * pow(2, -126 - 23);
    } else {
        // Normalized number
        value = (1 + mantissa * pow(2, -23)) * pow(2, exponent - 127);
    }

    if (sign == 1) value = -value;
    return value;
}

// Function to compute the result based on Sel value
float computeResult(float A, float B, int Sel) {
    switch (Sel) {
        case 0: return A + B;   // Add
        case 1: return A - B;   // Subtract
        case 2: return A * B;   // Multiply
        case 3: return A / B;   // Divide
        default: return NAN;    // Invalid Sel value
    }
}

int main() {
    ifstream inputFile("output.txt");
    if (!inputFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int index;
    string A_str, B_str, Sel_str, Y_str, Overflow_str, Error_str;

    cout << fixed << setprecision(8);  // Set fixed-point notation and precision

    while (inputFile >> index >> A_str >> B_str >> Sel_str >> Y_str >> Overflow_str >> Error_str) {
        // Check if any of the inputs are "x"
        if (A_str.find('x') != string::npos || B_str.find('x') != string::npos || 
            Sel_str.find('x') != string::npos || Y_str.find('x') != string::npos) {
            cout << "Index: " << index << ", A: " << A_str 
                 << ", B: " << B_str << ", Sel: " << Sel_str 
                 << ", Y: " << Y_str << ", Computed Result: x"
                 << ", Overflow: " << Overflow_str << ", Error: " << Error_str << endl;
            continue;
        }

        uint32_t A_bin = bitset<32>(A_str).to_ulong();
        uint32_t B_bin = bitset<32>(B_str).to_ulong();
        uint32_t Y_bin = bitset<32>(Y_str).to_ulong();
        int Sel = bitset<2>(Sel_str).to_ulong();

        float A = binaryToFloat(A_bin);
        float B = binaryToFloat(B_bin);
        float Y = binaryToFloat(Y_bin);

        float computedResult = computeResult(A, B, Sel);

        cout << "Index: " << index << ", A: " << scientific << A 
             << ", B: " << B << ", Sel: " << Sel << ", Y: " << Y
             << ", Computed Result: " << computedResult 
             << ", Overflow: " << Overflow_str << ", Error: " << Error_str << endl;
    }

    inputFile.close();
    return 0;
}
