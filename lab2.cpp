#include <cmath>
#include <iostream>

/*
  Halstead Software Metrics

  1.Program Length (N)
  N = N1 + N2

  2.Vocabulary Size (n)
  n = n1 + n2

  3.Estimated Program Length (N')
  N' = n1log2(n1) + n2log2(n2)

  4.Program Volume (V)
  V = Nlog2(n)

  5.Potential minimum volume (V*)
  V* = (2 + n2)log2(2 + n2)

  6.Language level ()
  lambda = L * (V*)

  L = Program Level = V* / V
  L^ = Estimated Program Level = 2*n2 / (n1 * N2)

  7.Program difficulty (D)
  D = 1 / L^

  8.Program Effort (E)
  E = V / L = D * V

  9.Intelligence content (I)
  I = V / D

  10. Programming time (T)
  T = E / (f * S)
  S = Stroud Number (5 <= S <= 20)
*/
using namespace std;

#define print(x) cout << #x << ": " << x << endl;

class HalsteadMetrics
{
public:
  HalsteadMetrics(int uniqueOperators, int uniqueOperands, int totalOperators, int totalOperands)
      : n1(uniqueOperators), n2(uniqueOperands), N1(totalOperators), N2(totalOperands)
  {
  }

  void calculateMetrics()
  {
    Program_Length = N1 + N2;
    Vocabulary_Size = n1 + n2;
    Estimated_Program_Length = n1 * log2(n1) + n2 * log2(n2);
    Program_Volume = Program_Length * log2(Vocabulary_Size);
    Potential_Minimum_Volume = (2 + n2) * log2(2 + n2);
    Program_Level = Potential_Minimum_Volume / Program_Volume;
    Program_Effort = Program_Volume / Program_Level;
    Programming_Time = Program_Effort / (18.0);
  }

  void displayMetrics()
  {
    print(Program_Length);
    print(Vocabulary_Size);
    print(Estimated_Program_Length);
    print(Program_Volume);
    print(Program_Effort);
    print(Programming_Time);
  }

private:
  int n1, n2; // Unique operators and operands
  int N1, N2; // Total operators and operands
  double Program_Length, Vocabulary_Size, Estimated_Program_Length, Program_Volume, Potential_Minimum_Volume,
      Program_Level, Program_Effort, Programming_Time;
};

int main()
{
  int uniqueOperators = 12; // n1
  int uniqueOperands = 13;  // n2
  int totalOperators = 40;  // N1
  int totalOperands = 45;   // N2

  HalsteadMetrics metrics(uniqueOperators, uniqueOperands, totalOperators, totalOperands);
  metrics.calculateMetrics();
  metrics.displayMetrics();

  return 0;
}
