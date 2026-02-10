#include <iostream>
#include <vector>

const double PI = 3.141592653589793;

double my_sin(double x) {

    while (x > PI) x -= 2 * PI;
    while (x < -PI) x += 2 * PI;
    
    double res = x;
    double x2 = x * x;
    double pow = x;
    
    pow *= x2; res -= pow / 6.0;
    pow *= x2; res += pow / 120.0;
    pow *= x2; res -= pow / 5040.0;
    pow *= x2; res += pow / 362880.0; 
    
    return res;
}

int main() {
    const size_t N = 10000000;
    
    std::vector<double> sin_array(N);
    
    // Заполняем массив
    for (size_t i = 0; i < N; ++i) {
        double x = 2.0 * PI * i / N;
        sin_array[i] = my_sin(x);
    }
    
    // Сумма
    double sum = 0.0;
    for (double val : sin_array) {
        sum += val;
    }
    
    std::cout << "Сумма my_sin(x): " << sum << std::endl;
    
    return 0;
}
