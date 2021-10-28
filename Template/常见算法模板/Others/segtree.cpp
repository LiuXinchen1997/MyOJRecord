#include <vector>

using namespace std;

vector<int> nums = {3, 4, 1, 66, 33, 4, 38, 11};
int len = nums.size();

vector<int> tree(2*len, 0);

void build_tree()
{
    for (int i = len, j = 0; i < 2*len; i++, j++) {
        tree[i] = nums[j];
    }
    for (int i = len - 1; i > 0; i--) {
        tree[i] = tree[2*i] + tree[2*i+1];
    }
}

void update(int pos, int val)
{
    pos += len;
    tree[pos] = val;
    pos /= 2;
    while (pos > 0) { // tree[0]是多余的
        tree[pos] = tree[2*pos] + tree[2*pos+1];
        pos /= 2;
    }
}

int range_sum(int left, int right)
{
    int sum = 0;
    left += len;
    right += len;
    while (left <= right) {
        if (left % 2 == 1) {
            sum += tree[left];
            left += 1;
        }
        if (right % 2 == 0) {
            sum += tree[right];
            right -= 1;
        }

        left /= 2;
        right /= 2;
    }

    return sum;
}
