//recursive approach
int func(int index, vector<int>&nums) {
	
	if(index == 0) return nums[index];
	if(index < 0) return 0;
	
	int pick = nums[index] + func(index-2,nums);
	int noPick = 0 + func(index-1,nums);
	
	return max(pick, noPick);
}

//memorization approach
int func2(int index, vector<int>&nums,vector<int>&dp) {
	
	if(index == 0) return nums[index];
	if(index < 0) return 0;
	
	if(dp[index] != -1) return dp[index];
	
	int pick = nums[index] + func(index-2,nums,dp);
	int noPick = 0 + func(index-1,nums,dp);
	
	return dp[index] = max(pick, noPick);
}

//Tabular method
int func3(int index, vector<int>&nums,vector<int>&dp) {
	
	dp[0] = nums[0];
	
	for(int i = 1; i <= index; i++){
		int take = nums[i];
		if(i > 1) take += dp[i-2];
		
		int nonTake = 0 + dp[i-1];
		
		dp[i] = max(take,nonTake);
	}
	return dp[index];
}

//space optimized code
int func(int index, vector<int>&nums) {
    int prev = nums[0];
	int prev2 = 0;
	
	for( int i = 1; i < nums.size(); i++) {
		int take = nums[i];
		if(i > 1) take += prev2;
	
		int nonTake = 0 + prev;
		int curr = max(take, nonTake);
		prev2 = prev;
		prev = curr;
	}
	return prev;
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
	int n = nums.size();
	return func(n-1, nums);
}