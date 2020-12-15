#include <iostream>
using namespace std;
#include <chrono>
using namespace std::chrono;
#include <string>
#include <OpenSimplexNoise.h>

#define N 10000000


static void printResults(const std::string & name,
                         high_resolution_clock::time_point start,
                         high_resolution_clock::time_point end) {

    auto delta = duration_cast<milliseconds>(end - start).count();
    cout << name << " with " << N << " iterations took " << delta << " ms" << endl;

    auto per = duration_cast<microseconds>(end - start).count() / (double)N;
    cout << per << " us per call" << endl;
}

int main() {

    high_resolution_clock::time_point start, end;

    OpenSimplexNoise::Noise noise(0);

    start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        double val = noise.eval(i, i * 2);
    }
    end = high_resolution_clock::now();
    printResults("OpenSimplexNoise::eval(x, y)", start, end);

    start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        double val = noise.eval(i, i * 2, i * 3);
    }
    end = high_resolution_clock::now();
    printResults("OpenSimplexNoise::eval(x, y, z)", start, end);

    start = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        double val = noise.eval(i, i * 2, i * 3, i * 4);
    }
    end = high_resolution_clock::now();
    printResults("OpenSimplexNoise::eval(x, y, z, w)", start, end);

    return 0;
}

