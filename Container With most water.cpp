class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0;
	    int minh = 0;
	    for (int i = 0, j = height.size() - 1; i < j;) {
            minh = min(height[i], height[j]);
            maxarea = max(maxarea, minh * (j - i));
            if (height[i] < height[j])
                i++;
            else
                j--;

	    }
	    return maxarea;
    }
};
