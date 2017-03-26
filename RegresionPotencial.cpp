#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

double eval(double alpha, double beta, double x){
  return alpha*pow(x, beta);
}

double *power_regression(double *X, double *Y, unsigned size) {
  double y_sum, logx_sum, logy_sum, logxlogy_sum, logx2_sum;

  for (size_t i = 0; i < size; i++) {
    y_sum += Y[i];

    logx_sum += log10(X[i]);
    logy_sum += log(Y[i]);
    logxlogy_sum += log10(X[i]) * log10(Y[i]);
    logx2_sum += pow(log10(X[i]), 2);
  }

  double mu_y = y_sum / size;
  double mu_logx = logx_sum / size;
  double mu_logy = logy_sum / size;

  double a1 = (size * logxlogy_sum - logx_sum * logy_sum) / (size * logx2_sum - logx_sum * logx_sum);
  double a0 = (mu_logy - a1 * mu_logx);

  printf("Equation: Y_guess = 10^%f * X.^%f\n", a0, a1);

  // correlation coeficient
  double st, sr;
  for (size_t i = 0; i < size; i++) {
    sr += pow(Y[i] - pow(10, a0) * pow(X[i], a1), 2);
    st += pow(Y[i] - mu_y, 2);
  }

  cout << "ST: " << st << endl;
  cout << "SR: " << sr << endl;

  // standard error
  double std_err = sqrt(sr / (size - 2));
  cout << "Standard error: " << std_err << '\n';

  // Determination coefficient
  double r2 = (st - sr) / st;
  cout << "Determination coefficient: " << r2 << '\n';
  cout << "Correlation coefficient: " << sqrt(r2) << '\n';

  cout << "a1: " << a1 << "\t" << "a0: " << a0 << endl;

  return new double[2] {a0, a1};
}

int main(int argc, char const *argv[]) {
  if (argc < 4) {
    cerr << "Invalid number of arguments" << '\n';
    return -1;
  }

  ifstream x_stream(argv[1], ios::in);
  ifstream y_stream(argv[2], ios::in);

  istringstream ss(argv[3]);
  int size;
  if (!(ss >> size)) {
    cerr << "Invalid number " << argv[3] << '\n';
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

  power_regression(X, Y, size);

  return 0;
}
