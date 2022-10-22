class Solution {
    public boolean isPerfectSquare(int num) {
        if (num == 1)
            return true;
        int l=1,r=num/2;

        while(l<=r)
        {
            int mid=l+(r-l)/2;
            long sq=mid*(long)mid;
            if(sq==num)
                return true;
            if(sq>num)
                r=mid-1;
            else
                l=mid+1;
        }
        return false;
    }
}
