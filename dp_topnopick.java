import java.util.Scanner;
public class dp_topnopick {
    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int r=sc.nextInt();
    int c=sc.nextInt();
    int grid[][]=new int[r][c];
    long dp[][]=new long[r][c];
    


    for(int row=0;row<r;row++){
        for(int col=0;col<c;col++){
            grid[row][col]=sc.nextInt();
            if(row==0){
                dp[row][col]=grid[row][col];
            }
        }
    }
    //
    long fmax=0L,smax=0L;
    
    for(int row=1;row<r;row++){
        long fsmax[]=getFSmax(dp,row-1,c);
        for(int col=0;col<c;col++){
            dp[row][col]=grid[row][col]+(dp[row-1][col]==fsmax[0]?fsmax[1]: fsmax[0]);

            /*if(dp[row-1][col]==fsmax[0]){
                dp[row][col]=fsmax[1]+grid[row][col];
            }else{
                dp[row][col]=fsmax[0]+grid[row][col]
            }*/

        }
    }
    System.out.println(getFSmax(dp,r-1,c)[0]);
    }
public static long[] getFSmax(long [][] dp,int row,int c){
    long fmax=Math.max(dp[row][0],dp[row][1]);
    long smax=Math.min(dp[row][0],dp[row][1]);
    for(int col=2;col<c;col++){
        if(dp[row][col]>fmax){
            smax=fmax;
            fmax=dp[row][col];
        }else if(dp[row][col]>smax){
            smax=dp[row][col];
        }
    }
    return new long[] {fmax,smax};
}
    
}
