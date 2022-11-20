#include "Matrix.h"
#include "TriangleMatrix.h"

int main()
{
  try
  {
     int arr[3] = {1, 0, 2};
     TTriangMatrix<int> A(3);
     TTriangMatrix<int> B;

     B = A;
     cout << B;


    
  }
  catch (const char* s)
  {
    cout << s;
  }

  return 0;
}