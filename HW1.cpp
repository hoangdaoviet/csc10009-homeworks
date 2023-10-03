#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <cmath>

void print(std::vector<bool> num) {
    for (int i = 0; i < num.size(); ++i) {
        std::cout << num[i];
    }
    std::cout << '\n';
}

std::vector<bool> sign_magnitude(int8_t n) {
    bool neg = false;
    if (n < 0) {
        n = -n;
        neg = true;
    }
    std::vector<bool> res(8, 0);
    int8_t a = 1;
    for (int i = 0; i < 8; ++i, a <<= 1) {
        res[i] = n & a;
    }
    std::reverse(res.begin(), res.end());
    if (neg) res[0] = 1;
    return res;
}

std::vector<bool> ones_complement(int8_t n) {
    bool neg = false;
    if (n < 0) {
        n = -n;
        neg = true;
    }
    std::vector<bool> res(8, 0);
    int8_t a = 1;
    for (int i = 0; i < 8; ++i, a <<= 1) {
        res[i] = n & a;
        if (neg) res[i] = !res[i];
    }
    std::reverse(res.begin(), res.end());
    return res;
}

std::vector<bool> twos_complement(int8_t n) {
    std::vector<bool> res(8, 0);
    int8_t a = 1;
    for (int i = 0; i < 8; ++i, a <<= 1) {
        res[i] = (n & a);
    }
    std::reverse(res.begin(), res.end());
    return res;
}

int main() {
    int N;
    std::cin >> N;
    if (N < -128 || N > 127) {
        std::cout << "Overflow. Inputted integer is not 8-bit.";
        return 0;
    }
    int8_t n = N;
    
    std::cout << "Sign-magnitude representation of " << int(n) << ": ";
    if (n >= -127 && n <= 127) {
        std::vector<bool> sign_mag = sign_magnitude(n);
        print(sign_mag);
    }
    else {
        std::cout << "overflow\n";
    }

    std::cout << "One's complement representation of " << int(n) << ": ";
    if (n >= -127 && n <= 127) {
        std::vector<bool> sign_mag = ones_complement(n);
        print(sign_mag);
    }
    else {
        std::cout << "overflow\n";
    }

    std::cout << "Two's complement representation of " << int(n) << ": ";
    std::vector<bool> sign_mag = twos_complement(n);
    print(sign_mag);
}