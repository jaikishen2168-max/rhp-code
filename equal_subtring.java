import java.io.*;
import java.util.*;

public class equal_subtring {
    public static void main(String args[])throws IOException
    {
        Scanner sc= new Scanner(System.in);
        String str = sc.next();
        HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
    
            map. put(0, -1);
            int res =0;
            int count_0 = 0, count_1 = 0;
            for(int i=0; i<str.length();i++)
            {
                if(str.charAt(i)=='0')
                    count_0++;
                else
                    count_1++;

                if(map.containsKey(count_1-count_0))
                    res = Math.max(res, (i - map.get(count_1-count_0)));

                else
                    map.put(count_1-count_0,i);
                
            }
            
            System.out.println("Length of longest balanced sub string = "+res);
    }
}
