class RotateArray {
    public void reverse(int[] nums, int low, int high){
        while(low < high){
            nums[low] = nums[low] + nums[high] - (nums[high] = nums[low]);
            low++;
            high--;
        }
    }
    
    public void rotate(int[] nums, int k) {
        k %= nums.length;
        
        // reverse first half i.e. N - 1 - k
        reverse(nums, 0, nums.length - 1 - k);
        
        // reverse second half
        reverse(nums, nums.length - k, nums.length - 1);
        
        // reverse whole array
        reverse(nums, 0, nums.length - 1);
        
        // display the result array
        toString(nums);
    }
    
    public void toString(int[] nums){
        System.out.print("[");
        for(int i = 0; i < nums.length; i++){
            System.out.print(nums[i]);
            
            if(i < nums.length - 1) System.out.print(", ");
        }
        System.out.print("]");
    }

    public static void main(String[] args){
        int[] nums = {1,2,3,4,5,6,7};
        int k = 3;

        // Output must be: [5,6,7,1,2,3,4]
        new RotateArray().rotate(nums, k);
    }
}