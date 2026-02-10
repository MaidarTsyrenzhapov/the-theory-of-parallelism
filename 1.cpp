#include <iostream>
#include <vector>

const double PId = 3.141592653589793;
const float PIf = 3.141592653589793;

double my_sin_double(double x) {

    while (x > PId) x -= 2 * PId;
    while (x < -PId) x += 2 * PId;
    
    double res = x;
    double x2 = x * x;
    double pow = x;
    
    pow *= x2; res -= pow / 6.0;
    pow *= x2; res += pow / 120.0;
    pow *= x2; res -= pow / 5040.0;
    pow *= x2; res += pow / 362880.0; 
    
    return res;
}
double my_sin_float(float x) {

    while (x > PIf) x -= 2 * PIf;
    while (x < -PIf) x += 2 * PIf;
    
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
    
    std::vector<double> sin_array1(N);
    std::vector<float> sin_array2(N);

    // Заполняем массив
    for (size_t i = 0; i < N; ++i) {
        double x1 = 2.0 * PId * i / N;
        sin_array1[i] = my_sin_double(x1);
    }

    for (size_t i = 0; i < N; ++i) {
        float x2 = 2.0 * PIf * i / N;
        sin_array2[i] = my_sin_float(x2);
    }
    
    // Сумма
    double sum1 = 0.0;
    for (double val : sin_array1) {
        sum1 += val;
    }
    float sum2 = 0.0;
    for (float val : sin_array2) {
        sum2 += val;
    }
    
    std::cout << "Сумма my_sin_double(x): " << sum1 << std::endl;
    std::cout << "Сумма my_sin_float(x): " << sum2 << std::endl;
    
    return 0;
}
