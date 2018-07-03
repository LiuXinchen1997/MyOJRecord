#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

#define INF (1<<30)

struct Station {
    double cost, dist;
    Station (double c, double d) : cost(c), dist(d) {}
    Station () {}
};
vector<Station> stats;

bool cmp(const Station& s1, const Station& s2)
{
    if (s1.dist != s2.dist) return s1.dist < s2.dist;
    return s1.cost < s2.cost;
}

void display()
{
    for (int i = 0; i < stats.size(); i++) {
        printf("%.2lf %.2lf\n", stats[i].cost, stats[i].dist);
    }
}

int main()
{
    double cmax, dist, davg; int n;
    scanf(" %lf %lf %lf %d", &cmax, &dist, &davg, &n);
    for (int i = 0; i < n; i++) {
        Station stat;
        scanf(" %lf %lf", &stat.cost, &stat.dist);
        if (stat.dist < dist) {
            stats.push_back(stat);
        }
    }
    stats.push_back(Station(0, dist));
    sort(stats.begin(), stats.end(), cmp);

    if (stats[0].dist != 0) {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }

    int cur_stat = 0;
    double cur_dist = 0;
    double sum_cost = 0;
    double cur_gas = 0;
    double max_dist = cmax * davg;
    n = stats.size();
    while (1) {
        if (cur_stat == stats.size()-1) { break; }

        int i = cur_stat + 1;
        int idx1 = -1; /// 第一个比当前更便宜的站
        int cheapest_cost = INF;
        int idx2 = -1; /// 最便宜的站
        for (i; i < stats.size(); i++) {
            if (stats[i].dist > max_dist + cur_dist) { break; }
            if (cheapest_cost > stats[i].cost) {
                cheapest_cost = stats[i].cost;
                idx2 = i;
            }
            if (stats[i].cost < stats[cur_stat].cost && idx1 == -1) {
                idx1 = i;
            }
        }

        if (cheapest_cost == INF) { break; } /// 这一句话存在导致上面一定要找出最便宜的加油站
        if (idx1 == -1) { /// 没有比当前还便宜的，只能去最便宜的了
            sum_cost += (cmax - cur_gas) * stats[cur_stat].cost;
            cur_gas = cmax - (stats[idx2].dist - cur_dist) / davg;
            cur_stat = idx2;
            cur_dist = stats[idx2].dist;
        } else { /// 去到比当前要便宜的那个站
            if (cur_gas * davg > stats[idx1].dist - cur_dist) {
                cur_gas -= (stats[idx1].dist - cur_dist) / davg;
            } else {
                sum_cost += ((stats[idx1].dist - cur_dist) / davg - cur_gas) * stats[cur_stat].cost;
                cur_gas = 0;
            }

            cur_stat = idx1;
            cur_dist = stats[idx1].dist;
        }
    }

    if (cur_stat == stats.size()-1) {
        printf("%.2lf\n", sum_cost);
    } else {
        printf("The maximum travel distance = %.2lf\n", cur_dist + max_dist);
    }

    return 0;
}
