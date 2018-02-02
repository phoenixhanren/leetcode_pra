#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minSteps(int n) {
		vector<int> dp(n + 1, INT_MAX);
		dp[1] = 0;

		for (int k = 2; k <= n; ++k)
		{
			for (int i = 1; i < k; ++i)
			{
				if (k % i != 0)
					continue;
				dp[k] = min(dp[k], dp[i] + k / i);
			}
		}
		return dp[n];

	}
};

/*
https://leetcode.com/problems/2-keys-keyboard/discuss/105932/Java-solutions-from-naive-DP-to-optimized-DP-to-non-DP
As usual, for DP problems, we need to identify the optimal substructures for the original problem and relate its solution to its subproblems. To begin with, let¡¯s define T(k) as the minimum number of steps to get exactly k ¡®A¡¯ on the notepad. Then the original problem will be T(n) and we have the following termination conditions: T(1) = 0, since there is already one ¡®A¡¯ on the notepad initially. Now the key part is how to relate T(k) to its subproblems.

Apparently T(k) will depend on the sequence of operations performed to get k ¡®A¡¯ on the notepad. Now ask yourself these questions:

Can this sequence of operations end with Copy All? The answer is NO, because if this is the case, the last operation can always be removed without changing the number of ¡®A¡¯ on the notepad yet yielding a smaller number of steps.

Can this sequence of operations contain only ? The answer is again NO, because at the beginning there is no character being copied so pasting along won¡¯t change the number of ¡®A¡¯ on the notepad (a special case is when n = 1, but then we don¡¯t even need any operations).

So we conclude the sequence of operations must end with Paste with at least one Copy All in the middle. However, from the point of the last Paste, it only cares about characters which are copied last time, that is, the first Copy All operation from the end of the sequence. Assume the number of ¡®A¡¯ on the notepad is i when this Copy All operation is performed. Then how many more steps do we need to get k ¡®A¡¯ on the notepad by pasting only? The answer is (k-i)/i, where k - i is the remaining number of ¡®A¡¯ and i is the number of ¡®A¡¯ we can print on the notepad for each Paste. So the total number of steps from getting i ¡®A¡¯ to k ¡®A¡¯ is k / i, that is, one Copy All plus (k-i)/i Paste. Since we aim to minimize number of steps to get k ¡®A¡¯, we surely want to minimize the number of steps to i ¡®A¡¯, which by definition is T(i), therefore the total number of steps getting k ¡®A¡¯ for this case is given by T(i) + k/i.

Since we don¡¯t really know when to perform the last Copy All operation, we can try each options and choose the one that produces the least number of steps. Here each option corresponds to a different value of i and if there are no additional restrictions, we have a total of k - 1 such choices (i running from 1 to k - 1). Fortunately, we do require that the number of steps be integers, therefore i must be a divisor of k. In summary, we have:

T(k) = min(T(i) + k/i) where 1 <= i < k && k % i == 0.
*/