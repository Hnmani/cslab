#include <iostream>
#include <vector>

int searchRotatedSortedArray(const std::vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }

        if (nums[left] <= nums[mid])
        {
            // Left half is sorted
            if (nums[left] <= target && target < nums[mid])
            {
                // Target is in the left half
                right = mid - 1;
            }
            else
            {
                // Target is in the right half
                left = mid + 1;
            }
        }
        else
        {
            // Right half is sorted
            if (nums[mid] < target && target <= nums[right])
            {
                // Target is in the right half
                left = mid + 1;
            }
            else
            {
                // Target is in the left half
                right = mid - 1;
            }
        }
    }

    return -1; // Target not found
}

int main()
{
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int result = searchRotatedSortedArray(nums, target);

    if (result != -1)
    {
        std::cout << "Target found at index: " << result << std::endl;
    }
    else
    {
        std::cout << "Target not found." << result << std::endl;
    }

    return 0;
}
