#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>

using namespace std;

double *linear_regression(double *xs, double *ys, unsigned size) {
  double s_x, s_y, s_x2, s_p;

  for (size_t i = 0; i < size; i++) {
    s_x += xs[i];
    s_y += ys[i];
    s_x2 += xs[i] * xs[i];
    s_p += xs[i] * ys[i];
  }

  double mu_x = s_x / size;
  double mu_y = s_y / size;

  double a1 = (size * s_p - s_x * s_y) / (size * s_x2 - s_x * s_x);
  double a0 = (mu_y - a1 * mu_x);

  // correlation coeficient
  double st, sr;
  for (unsigned i = 0; i < size; i++) {
    sr += pow(ys[i] - a0 - a1 * xs[i], 2);
    st += pow(ys[i] - mu_y, 2);
  }

  // standard error
  double std_err = sqrt(sr / (size - 2));
  std::cout << "Standard error: " << std_err << '\n';

  // Determination coefficient
  double r2 = (st - sr) / st;
  std::cout << "Determination coefficient: " << r2 << '\n';
  std::cout << "Correlation coefficient: " << sqrt(r2) << '\n';

  printf("Equation: Y_guess = %f + %f * X\n", a0, a1);
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

  linear_regression(X, Y, size);

  return 0;
}
