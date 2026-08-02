import java.util.*;
import java.util.Scanner;
public class min_max {
    public static void main(String[] args) {
        // Your Code goes here!
        Scanner sc = new Scanner (System.in);
        int N = sc.nextInt();
        int [] a = new int[N+1];
        for (int i=1;i<=N;i++){
            a[i]=sc.nextInt();
        }
        int smc=0; int exc=0;
        for(int i=1;i<=N;i++){
            if(i==a[i]){
                smc++;
            }else if(i==a[a[i]]){
                exc++;
            }
        }
        System.out.println((exc/2)+ smc*(smc-1)/2);
        
    }
}
