Problem description: 
A subarray is any contiguos block an arrays element. 
For example, a three element array[4,5,6] can be made into the following subarray_sum

	1 element subarrays:[4],[5],[6]
	2 element subarrays:[4,5],[5,6]
	3 element subarrays:[4,5,6]
Given an array of integers, find the sum of all elments of all subarrays of that array

Constraints: 1≤2 x 10^5;
1≤arr[i]≤ 10^3, where 0≤i<n

naive method will be TLE, so...

method:

1   2   3   4  ----- [1],[2],[3],[4]


1   22  33  4  ----- [1,2],[2,3],[3,4],[4,5]

				= n*sum(arr)+(n-2)*(arr-arr[0]-arr[last_num])+(n-4)*............
1   22  33  4  ----- [1,2,3],[2,3,4]


1   2   3   4  ----- [1,2,3,4,5]




int subarray_sum(vector<int> arr)
{
	int cnt = 0;
	int sum = 0;
	for (int i = 0; i < arr.size(); i++)
		sum += arr[i];
	int a = 0;
	int b = arr.size() - 1;
	while (a <= b)
	{
		cnt += (b - a + 1)*sum;
		sum = sum - arr[a] - arr[b];
		a++;
		b--;
	}
	return cnt;
}