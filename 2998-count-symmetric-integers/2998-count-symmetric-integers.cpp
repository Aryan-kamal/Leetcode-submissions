class Solution {
public:
    int countDigits(int num) {
        int count = 0;
        while (num > 0) {
            count++;
            num /= 10;
        }
        return count;
    }
    int sumOfDigits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for (int i = low; i <= high; i++) {
            if (countDigits(i) % 2 == 0) {
                int sum = sumOfDigits(i);
                int digits = countDigits(i) / 2;
                int halfSum = 0;
                int temp = i;
                while (digits--) {
                    halfSum += temp % 10;
                    temp /= 10;
                }
                if (sum == 2 * halfSum)
                    cnt++;
            }
        }
        return cnt;
    }
};