#include <bits/stdc++.h>
template <typename _Tp> void max_self(_Tp &a, const _Tp &b)
{
  if (a < b)
  {
    a = b;
  }
}
template <typename _Tp> void min_self(_Tp &a, const _Tp &b)
{
  if (a > b)
  {
    a = b;
  }
}
struct Edge
{
  char label;
  int weight, from, to;
};
int main()
{
  std::vector<Edge> edges;
  int n = 6;
  edges.emplace_back('A', 3, 0, 1);
  edges.emplace_back('B', 5, 1, 2);
  edges.emplace_back('C', 7, 1, 3);
  edges.emplace_back('D', 10, 2, 4);
  edges.emplace_back('E', 5, 3, 4);
  edges.emplace_back('F', 4, 4, 5);
  std::vector<int> earliest_start(n), latest_finish(n, INT_MAX);
  for (int i = 0; i < n; i++)
  {
    earliest_start[i] = 0;
    for (const Edge &edge : edges)
    {
      if (edge.to == i)
      {
        max_self(earliest_start[i], earliest_start[edge.from] + edge.weight);
      }
    }
  }
  latest_finish[n - 1] = earliest_start[n - 1];
  for (int i = n - 2; i >= 0; i--)
  {
    for (const Edge &edge : edges)
    {
      if (edge.from == i)
      {
        min_self(latest_finish[i], latest_finish[edge.to] - edge.weight);
      }
    }
  }
  std::vector<int> earliest_finish(n), latest_start(n);
  std::vector<int> total_float(n), free_float(n);
  for (int i = 0; auto [_, weight, from, to] : edges)
  {
    earliest_finish[i] = earliest_start[from] + weight;
    latest_start[i] = latest_finish[to] - weight;
    total_float[i] = latest_finish[to] - earliest_start[from] - weight;
    free_float[i] = earliest_start[to] - earliest_start[from] - weight;
    i++;
  }
  std::vector<Edge> critical_path;
  for (int i = 0; auto [label, weight, from, to] : edges)
  {
    if (earliest_start[to] == latest_finish[to] && earliest_start[from] == latest_finish[from] &&
        earliest_start[to] - earliest_start[from] == weight)
    {
      critical_path.emplace_back(label, weight, from, to);
    }
    i++;
  }
  std::cout << "Abhijeet Adarsh, 20JE0020\n";
  for (int i = 0; auto [label, _, from, to] : edges)
  {
    std::cout << "Activity: " << label << ", ES: " << std::setw(2) << earliest_start[from] << ", EF: " << std::setw(2)
              << earliest_finish[i] << ", LS: " << std::setw(2) << latest_start[i] << ", LF: " << std::setw(2)
              << latest_finish[to] << ", TF: " << total_float[i] << ", FF: " << free_float[i] << "\n";
    i++;
  }
  std::cout << "Total Duration: " << earliest_start[n - 1] << "\n";
  std::cout << "Critical Path: ";
  for (int i = 0; i < static_cast<int>(critical_path.size()); i++)
  {
    std::cout << critical_path[i].label;
    if (i != static_cast<int>(critical_path.size()) - 1)
    {
      std::cout << "⇢ ";
    }
  }
  std::cout << "\n";
  return 0;
}