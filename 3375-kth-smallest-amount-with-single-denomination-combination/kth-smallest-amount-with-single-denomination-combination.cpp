#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    long long gcd(long long a, long long b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        vector<long long> lcms(1 << n);
        lcms[0] = 1;
        for (int mask = 1; mask < (1 << n); ++mask) {
            int lsb = __builtin_ctz(mask);
            lcms[mask] = lcm(lcms[mask ^ (1 << lsb)], coins[lsb]);
        }

        long long low = 1;
        long long min_coin = *min_element(coins.begin(), coins.end());
        long long high = min_coin * k;
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long count = 0;
            for (int mask = 1; mask < (1 << n); ++mask) {
                long long term = mid / lcms[mask];
                if (__builtin_popcount(mask) & 1) {
                    count += term;
                } else {
                    count -= term;
                }
            }
            if (count >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};