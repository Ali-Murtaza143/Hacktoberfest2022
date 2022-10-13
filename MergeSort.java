

public class MergeSort {

    public static void main(String[] args) {
       int[] a={12,4,5,6,3,2};
        divide(0,5,a);
        for(int i=0;i<6;i++)
          System.out.print(" " +a[i]);
    }
    public static void divide(int l,int r,int[] arr)
    {
        if(l<r)
        {
            int mid=(l+r)/2;
            divide(l,mid,arr);
            divide(mid+1,r,arr);

            merge(l,mid,r,arr);
        }

    }
    public static void merge(int l ,int mid ,int r,int[] arr)
    {

        System.out.println("l="+l);
        System.out.println("mid="+mid);
        System.out.println("r="+r);
        //Calculate then length then 2 arrays
        int n1=mid+1-l;
        int n2=r-mid;
        //declaration of 2 arrays
        int[] a=new int[n1];
        int[] b=new int[n2];
        int k=0;
        //Assigning values in the 2 arrays
        for(int i=l;i<=mid;i++)
        {   a[k]=arr[i];
            System.out.print(" " +a[k]);
            k++;}


        System.out.println();
        k=0;
        for(int i=mid+1;i<=r;i++)
        {
            b[k]=arr[i];
            System.out.print(" " +b[k]);

            k++;
        }
        System.out.println();


        //The 2 Arrays are ready to be merged
        int i=0,j=0;
        k=l;
        while(i<n1 && j<n2)
        { if(a[i]<b[j])
        {
            arr[k]=a[i];
             k++;
             i++;
        }
        else if(a[i]>b[j])
        {
            arr[k]=b[j];
            k++;
            j++;
        }
        else  if(a[i]==a[j])
        {
            arr[k]=b[j];
            k++;
            j++;
            arr[k]=b[i];
            k++;
            i++;
        }
        }
        while(i<n1 )
        {
            arr[k]=a[i];
            k++;
            i++;
        }
        while(j<n2 )
        {
            arr[k]=a[j];
            k++;
            j++;
        }
        for(int m=0;m<6;m++)
            System.out.print(" " +arr[m]);
        System.out.println();
     }
}
