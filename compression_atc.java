import java.util.Scanner;
import java.util.*;
import java.util.Collections;
public class compression_atc {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int N=sc.nextInt();
        Set<Integer> arr = new TreeSet<>();

        for (int i=0; i<N;i++){
            int b=sc.nextInt();
            arr.add(b);
        }
        System.out.println(arr.size());
        for(int c: arr){
            System.out.print(c+" ");
            }
        }
        }
