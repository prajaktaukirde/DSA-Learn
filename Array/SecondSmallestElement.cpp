1.Brute Force (Sorting)TC: O(n log n) & SC: O(1)
class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int largest = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] != largest) {
                return nums[i];
            }
        }
        return -1;
    }
};

2. Better Approach (Two Pass) TC: O(n) & SC: O(1)
class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        int n = nums.size();

        int largest = nums[0];

        // find largest
        for (int i = 1; i < n; i++) {
            if (nums[i] > largest) {
                largest = nums[i];
            }
        }

        int second = -1;

        // find second largest
        for (int i = 0; i < n; i++) {
            if (nums[i] != largest && nums[i] > second) {
                second = nums[i];
            }
        }

        return second;
    }
};


3. Optimal Approach (One Pass) TC: O(n) & SC: O(1)
class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        int n = nums.size();

        int largest = nums[0];
        int second = -1;

        for (int i = 1; i < n; i++) {
            if (nums[i] > largest) {
                second = largest;
                largest = nums[i];
            }
            else if (nums[i] < largest && nums[i] > second) {
                second = nums[i];
            }
        }

        return second;
    }
};