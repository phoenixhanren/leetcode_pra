#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int InversePairs(vector<int> data) {
		count = 0;
		vector<int> temp(data.size());
		mergeSort(data, 0, temp.size() - 1, temp);
		return count % 1000000007;
	}
private:
	int count;
	void mergeSort(vector<int>& data, int first, int last, vector<int>& temp)
	{
		if (first < last)
		{			
			int mid = (last + first) / 2;
			//cout << "first ..." << first << " last..." << last << "mid..." << mid << endl;
			//cout << "[" << first << ", " << mid << "] [" << mid + 1 << ", " << last << "]\n";
			mergeSort(data, first, mid, temp);
			mergeSort(data, mid + 1, last, temp);
			mergeArray(data, temp, first, last, mid);
		}

	}
	void mergeArray(vector<int>& data, vector<int> &temp, int first, int last, int mid)
	{
		int i = first;
		int j = mid + 1;
		int temp_ind = 0;
		while (i <= mid && j <= last)
		{
			if (data[i] > data[j])
			{
				//++count;
				temp[temp_ind++] = data[j++];
				count = (mid - i + 1 + count) % 1000000007; //[i,mid]均比j大
			}
			else
			{
				temp[temp_ind++] = data[i++];
			}
		}
		while (i <= mid)
		{
			temp[temp_ind++] = data[i++];
		}
		while (j <= last)
		{
			temp[temp_ind++] = data[j++];
		}
		for (int k = 0; k < last - first + 1; ++k)
			data[first + k] = temp[k];
	}
};