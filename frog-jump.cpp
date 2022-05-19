//https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?leftPanelTab=1

//memorization approach
int func(int n, vector<int> &heights, vector<int>&dp) {
	
	if(n == 0) return 0;
	if(dp[n] != -1) return dp[n];
	int left = func(n-1,heights,dp) + abs(heights[n-1]-heights[n]);
	int right = INT_MAX;
	if(n > 1){
	   right = func(n-2,heights,dp) + abs(heights[n-2] - heights[n]);
	}
	return dp[n] = min(left,right);
}

//tabular method
int func2(vector<int>&dp, int n, vector<int>&heights) {
	
	dp[0] = 0;
	for(int i = 1; i < n; i++) {
		int left = dp[i-1] + abs(heights[i] - heights[i-1]);
		int right = INT_MAX;
		if(i > 1){
			right = dp[i-2] + abs(heights[i] - heights[i-2]);
		}
		dp[i] = min(left,right);
	}
	return dp[n-1];
}

//futher space optimization
int spaceOptimized(int n, vector<int> &heights)
{
    // Write your code here.
	int prev = 0;
	int prev2 = 0;

	for( int i = 1; i < n; i++) {
		int left = prev + abs(heights[i] - heights[i-1]);
		int right = INT_MAX;
		if(i > 1){
			right = prev2 + abs(heights[i] - heights[i-2]);
		}
		int curr = min(left,right);
		prev2 = prev;
		prev = curr;
	}
	return prev;
}

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
	vector<int>dp(n,-1);
    int memorization = func(n-1,heights,dp);
    int tabular = func2(dp,n,heights);
	return 
}