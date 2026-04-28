#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);
const double RANGE_MAX = PI / 2.0;

struct Interval{
  double l,r;

  bool operator < (const Interval& other) const{
    return l < other.l;
  }
};

Interval get_danger_interval(double x, double y, double r){
  double d = sqrt(x * x + y * y);
  double alpha = atan2(y, x);
  double delta = asin(r / d);

  double left = alpha - delta;
  double right = alpha + delta;

  return {max(0.0, left), min(RANGE_MAX, right)};
}

double solve_merged_length(vector<Interval>& intervals){
  if(intervals.empty()) return 0.0;

  sort(intervals.begin(),intervals.end());

  double total_len = 0;
  double cur_l = intervals[0].l;
  double cur_r = intervals[0].r;

  for (size_t i = 1; i < intervals.size(); ++i) {
        if (intervals[i].l <= cur_r) {
            cur_r = max(cur_r, intervals[i].r);
        } else {
            total_len += (cur_r - cur_l);
            cur_l = intervals[i].l;
            cur_r = intervals[i].r;
        }
    }
    total_len += (cur_r - cur_l);
    return total_len;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
    if (!(cin >> n)) return 0;

    vector<Interval> intervals;
    for (int i = 0; i < n; i++) {
        double x, y, r;
        cin >> x >> y >> r;
        intervals.push_back(get_danger_interval(x, y, r));
    }

    double bad_angle = solve_merged_length(intervals);

    double safe_angle = RANGE_MAX - bad_angle;

    cout << fixed << setprecision(3) << (max(0.0, safe_angle) / RANGE_MAX) << endl;
  return 0;
}
