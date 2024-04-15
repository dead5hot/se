#include <bits/stdc++.h>

#define println(x) std::cout << #x << " = " << (x) << std::endl;

double phasewise(double a, double b, double up, double lp, double x, double Tkloc)
{
  return (a + ((b - a) * Tkloc) / (up - lp)) * x / 100.0;
}

int32_t main()
{

  double Tkloc, EAF, Effort, Tdev, ai, bi, ci, di;
  ai = 3.2;
  bi = 1.05;
  ci = 2.5;
  di = 0.38;

  /*------------------------------------------------------------------------------------------*/
  printf("/*------------------------------------------------------------------------------------------*/\n");
  Tkloc = 1.0 + 2.0 + 1.5 + 2.0 + 0.5;
  EAF = 1.16 * 0.82 * 0.91 * 1.06 * 1.10 * 0.87;
  Effort = ai * pow(Tkloc, bi) * EAF;
  Tdev = ci * pow(Effort, di);

  println(EAF);
  println(Effort);
  println(Tdev);

  /*------------------------------------------------------------------------------------------*/
  printf("/*------------------------------------------------------------------------------------------*/\n");
  double planEffort, designEffort, detailDesignEffort, codeEffort, InteEffort;

  planEffort = phasewise(6.0, 6.0, 32.0, 2, Effort, Tkloc);
  designEffort = phasewise(16.0, 16.0, 32.0, 2, Effort, Tkloc);
  detailDesignEffort = phasewise(24.0, 26.0, 32.0, 2, Effort, Tkloc);
  codeEffort = phasewise(38.0, 42.0, 32.0, 2, Effort, Tkloc);
  InteEffort = phasewise(22.0, 16.0, 32.0, 2, Effort, Tkloc);

  printf("Phase Wise Development Effort\n");
  println(planEffort);
  println(designEffort);
  println(detailDesignEffort);
  println(codeEffort);
  println(InteEffort);

  /*------------------------------------------------------------------------------------------*/
  printf("/*------------------------------------------------------------------------------------------*/\n");
  double planTime, designTime, detailDesignTime, codeTime, InteTime;

  planTime = phasewise(12.0, 10.0, 32.0, 2, Tdev, Tkloc);
  designTime = phasewise(19.0, 19.0, 32.0, 2, Tdev, Tkloc);
  detailDesignTime = phasewise(21.0, 24.0, 32.0, 2, Tdev, Tkloc);
  codeTime = phasewise(34.0, 39.0, 32.0, 2, Tdev, Tkloc);
  InteTime = phasewise(26.0, 18.0, 32.0, 2, Tdev, Tkloc);

  printf("Phase Wise Development Time\n");
  println(planTime);
  println(designTime);
  println(detailDesignTime);
  println(codeTime);
  println(InteTime);
  return 0;
}

/*
EAF = 0.878074

Effort = 21.6787

Time = 8.04698

Phase Wise Development
Effort planE: 1.30072
designE: 3.4686
detailDesignE: 5.30406
codeE: 8.44025 InteE: 4.46582
Phase Wise Development
Time planTime: 0.928085
designTime: 1.52893
detailDesignTime : 1.74619
code Time: 2.82985
InteTime: 1.942
*/