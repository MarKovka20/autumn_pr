#include <iostream>
#include <cmath>

double * Gauss(double **a, double *y, int n)
{
  double *x, max;
  int k, index;
  x = new double[n];
  k = 0;
  while (k < n)
  {
    max = abs(a[k][k]);
    index = k;
    for (int i = k + 1; i < n; i++)
    {
      if (abs(a[i][k]) > max){
        max = abs(a[i][k]);
        index = i;
      }
    }
      
    if (max == 0 && y[k] == 0){
      std::cout << "The solution is infinity" << std::endl;
      return 0;
    } else if (max == 0 && abs(y[k]) > 0){
        std::cout << "The solution is impossible" << std::endl;
        return 0;
    }
      
      
    for (int j = 0; j < n; j++)
    {
      std::swap(a[k][j], a[index][j]);
    }

    std::swap(y[k], y[index]);
    
      
    for (int i = k; i < n; i++)
    {
      double temp = a[i][k];
        if (abs(temp) == 0){
            continue;
        }
      for (int j = 0; j < n; j++)
        a[i][j] = a[i][j] / temp;
      y[i] = y[i] / temp;
        if (i == k){
            continue;
        }
      for (int j = 0; j < n; j++)
        a[i][j] = a[i][j] - a[k][j];
      y[i] = y[i] - y[k];
    }
    k++;
  }
  for (k = n - 1; k >= 0; k--)
  {
    x[k] = y[k];
    for (int i = 0; i < k; i++)
      y[i] = y[i] - a[i][k] * x[k];
  }
    
    
    for (int i = 0; i < n; i++){
        std::cout << "x" << i << " = " << x[i] << std::endl;
    }
  return x;
}




int main()
{
  double **a, *y;
  int n;
  std::cout << "Enter the number of equations: ";
  std::cin >> n;
  a = new double*[n];
  y = new double[n];
  for (int i = 0; i < n; i++)
  {
    a[i] = new double[n];
    for (int j = 0; j < n; j++)
    {
      std::cout << "Enter element a[" << i << "][" << j << "]= ";
      std::cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++)
  {
    std::cout << "Enter element y[" << i << "]= ";
    std::cin >> y[i];
  }
    Gauss(a, y, n);
    
    for (int count = 0; count < 2; count++){
        delete [] a[count];
    }
    delete [] y;
  return 0;
}

