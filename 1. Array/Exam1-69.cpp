//Find ways to calculate a target from elements of the specified array
Function coutWays(num[],n,target){
    if (target == 0) {
        return 1;
    }
    if (n < 0) {
        return 0;
    }
    int exclude = countWays(nums, n - 1, target);
    int include = countWays(nums, n - 1, target - nums[n]) +
                countWays(nums, n - 1, target + nums[n]);
 
   
    return exclude + include;
}
