#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <limits>

struct Activity
{
  char label;
  int from, to;

  int t_optimistic;
  int t_most_likely;
  int t_pessimistic;

  double t_mean;
  double variance;

  Activity(char label, int from, int to, int t_optimistic, int t_most_likely, int t_pessimistic) :
  label { label },
  from { from }, to { to },
  t_optimistic { t_optimistic },
  t_most_likely { t_most_likely },
  t_pessimistic { t_pessimistic },
  t_mean { (t_optimistic + 4 * t_most_likely + t_pessimistic) / 6.0 },
  variance { std::pow((t_pessimistic - t_optimistic) / 6.0, 2) } {}
};

template<typename _Tp>
  void max_self(_Tp& a, const _Tp& b) { if(a < b) { a = b; } }

template<typename _Tp>
  void min_self(_Tp& a, const _Tp& b) { if(a > b) { a = b; } }

int main()
{
  std::vector<Activity> activities;

  activities.emplace_back('A', 1, 2, 5, 6,  7);
  activities.emplace_back('B', 1, 3, 1, 3,  5);
  activities.emplace_back('C', 1, 4, 1, 4,  7);
  activities.emplace_back('D', 2, 5, 1, 2,  3);
  activities.emplace_back('E', 3, 6, 1, 2,  9);
  activities.emplace_back('F', 4, 6, 1, 5,  9);
  activities.emplace_back('G', 4, 7, 2, 2,  8);
  activities.emplace_back('H', 6, 7, 4, 4, 10);
  activities.emplace_back('I', 5, 8, 2, 5,  8);
  activities.emplace_back('J', 7, 8, 2, 2,  8);
  
  int n_nodes = 9; /* 1 to 9 */
  int n_activities = static_cast<int>(activities.size());

  std::vector<double> earliest_start(n_nodes);  
  earliest_start[0] = 0.0;

  for(int i = 1; i < n_nodes; i++)
  {
    earliest_start[i] = 0.0;
    
    for(const Activity& a : activities)
    {
      if(a.to == i) { max_self(earliest_start[a.to], earliest_start[a.from] + a.t_mean); }
    }
  }

  std::vector<double> latest_finish(n_nodes);
  latest_finish[n_nodes - 1] = earliest_start[n_nodes - 1];

  for(int i = n_nodes - 2; i >= 0; i--)
  {
    latest_finish[i] = std::numeric_limits<double>::max();

    for(const Activity& a : activities)
    {
      if(a.from == i) { min_self(latest_finish[a.from], latest_finish[a.to] - a.t_mean); }
    }
  }

  std::vector<double> earliest_finish(n_activities), latest_start(n_activities),
    total_float(n_activities), free_float(n_activities);
  
  for(int i = 0; const Activity& a : activities)
  {
    earliest_finish[i] = earliest_start[a.from] + a.t_mean;
    latest_start[i] = latest_finish[a.to] - a.t_mean;

    total_float[i] = latest_finish[a.to] - earliest_start[a.from] - a.t_mean;
    free_float[i] = earliest_start[a.to] - earliest_start[a.from] - a.t_mean;

    i++;
  }

  double sum_of_variances = 0;
  std::vector<Activity> critical_path;

  for(const Activity& a : activities)
  {
    if(earliest_start[a.to] == latest_finish[a.to]
    && earliest_start[a.from] == latest_finish[a.from]
    && earliest_start[a.to] - earliest_start[a.from] == a.t_mean
    ) {
      critical_path.push_back(a);
      sum_of_variances += a.variance;
    }
  }

  double project_std_deviation = std::sqrt(sum_of_variances);

  // std::cout << "Abhijeet Adarsh, 20JE0020\n";
  // std::cout << "Romeo Sarkar, 20JE0814\n";
  std::cout << "Sonu Kumar, 20JE0961\n";

  std::cout << "┌────────┬" << "──┬" << "──┬" << "──┬" << "──┬" << "──┬" << "──┬" << "─────────────────┬" << "────────┐\n"; 
  std::cout << "│Activity│" << "ES│" << "EF│" << "LS│" << "LF│" << "TF│" << "FF│" << "Expected Duration│" << "Variance│\n"; 
  std::cout << "├────────┼" << "──┼" << "──┼" << "──┼" << "──┼" << "──┼" << "──┼" << "─────────────────┼" << "────────┤\n"; 
  for(int i = 0; const Activity& a : activities)
  {
    std::cout << "│    " << a.label << "   │" << std::setw(2) << earliest_start[a.from] << "│" << std::setw(2)
    << earliest_finish[i] << "│" << std::setw(2) << latest_start[i] << "│" << std::setw(2) << latest_finish[a.to]
    << "│" << std::setw(2) << total_float[i] << "│" << std::setw(2) << free_float[i] << "│" << "        " << a.t_mean
    << "        │" << std::setw(8) << a.variance << "│\n";
    
    i++;
  }
  std::cout << "└────────┴" << "──┴" << "──┴" << "──┴" << "──┴" << "──┴" << "──┴" << "─────────────────┴" << "────────┘\n"; 

  std::cout << "Total Duration: " << earliest_start[n_nodes - 1] << " weeks \n";
  std::cout << "Total Variance: " << sum_of_variances << ", Project Standard Deviation: " << project_std_deviation << "\n";
  std::cout << "Critical Path: ";

  for(const Activity& a : critical_path) { std::cout << a.from << "⇢ "; }
  std::cout << critical_path.back().to << "\n";

  double t_due = 22, t_expected = earliest_start[n_nodes - 1];
  double z = (t_due - t_expected) / project_std_deviation;

  std::cout << "z: " << z << "\n";

  double calculated_probability = 0.9987; /// from z-table

  std::cout << "P(z ≤ " << z << ") = " << calculated_probability << "\n";
  return 0;    
}
