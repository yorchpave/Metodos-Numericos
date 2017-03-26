#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

double eval(double alpha, double beta, double x){
  return alpha*exp(beta*x);
}

double *exponential_regression(double *X, double *Y, unsigned size) {
  double x_sum, y_sum, x2_sum, logy_sum, xlogy_sum;

  for (size_t i = 0; i < size; i++) {
    x_sum += X[i];
    y_sum += Y[i];
    x2_sum += X[i] * X[i];

    logy_sum += log(Y[i]);
    xlogy_sum += X[i] * log(Y[i]);
  }

  double mu_x = x_sum / size;
  double mu_y = y_sum / size;
  double mu_logy = logy_sum / size;

  double a1 = (size * xlogy_sum - x_sum * logy_sum) / (size * x2_sum - x_sum * x_sum);
  double a0 = (mu_logy - a1 * mu_x);

  printf("Equation: Y_guess = exp(%f) * exp(%f * X)\n", a0, a1);

  // correlation coeficient
  double st, sr;
  for (size_t i = 0; i < size; i++) {
    sr += pow(Y[i] - exp(a0) * exp(a1 * X[i]), 2);
    st += pow(Y[i] - mu_y, 2);
  }

  // standard error
  double std_err = sqrt(sr / (size - 2));
  std::cout << "Standard error: " << std_err << '\n';

  // Determination coefficient
  double r2 = (st - sr) / st;
  std::cout << "Determination coefficient: " << r2 << '\n';
  std::cout << "Correlation coefficient: " << sqrt(r2) << '\n';

  cout << "a1: " << a1 << "\t" << "a0: " << a0 << endl;

  return new double[2] {a0, a1};
}

int main(int argc, char const *argv[]) {
  if (argc < 4) {
    std::cerr << "Invalid number of arguments" << '\n';
    return -1;
  }

  ifstream x_stream(argv[1], ios::in);
  ifstream y_stream(argv[2], ios::in);

  istringstream ss(argv[3]);
  int size;
  if (!(ss >> size)) {
    std::cerr << "Invalid number " << argv[3] << '\n';
  }

  cout << size << '\n';

  if (!x_stream.is_open() | !y_stream.is_open()) {
    cerr << "Unable to open file\n";
    return -1;
  }

  double *X = new double[size];
  double *Y = new double[size];

  // Read files
  cout << "--- Big Data ---" << '\n';
  cout << "  X\t|  Y" << '\n';
  cout << "----------------" << '\n';
  for (int i = 0; x_stream && y_stream && i < size; i++) {
    double x, y;
    x_stream >> x;
    y_stream >> y;

    X[i] = x;
    Y[i] = y;

    cout << x << "\t" << y << endl;
  }
  x_stream.close();
  y_stream.close();

  exponential_regression(X, Y, size);

  return 0;
}
