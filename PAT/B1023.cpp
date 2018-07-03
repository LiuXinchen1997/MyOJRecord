#include <cstdio>

int nums[15];

int main()
{
    for (int i = 0; i < 10; i++) {
        scanf(" %d", &nums[i]);
    }

    bool hasZero = true;
    if (nums[0] == 0) { hasZero = false; }

    if (!hasZero) {
        for (int i = 1; i < 10; i++) {
            for (int j = 1; j <= nums[i]; j++) {
                printf("%d", i);
            }
        }
        printf("\n");
    } else {
        for (int i = 1; i < 10; i++) {
            if (nums[i] != 0) { printf("%d", i); --nums[i]; break; }
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 1; j <= nums[i]; j++) {
                printf("%d", i);
            }
        }
        printf("\n");
    }

    return 0;
}
