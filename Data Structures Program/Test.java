import java.util.*;
import edu.princeton.cs.algs4.*;
public class Test{
    public static void main(String[] args){
        Stopwatch st = new Stopwatch();
        Scanner sc = new Scanner(System.in);
        List<Integer> list = new ArrayList<Integer>();
        int t = sc.nextInt();
        while(t-->0){
            int n = sc.nextInt();
            int k = sc.nextInt();
            for(int i = 0; i<n; i++){
                list.add(sc.nextInt());
            }
            for(int i = 0; i<k; i++){
                for (int j = 0; j<=list.size()-1 ; j++ ) {
                    if(j==list.size()-1)
                        break;
                    if(list.get(j) < list.get(j+1)){
                        list.remove(j);
                }   
                }
            }   
            System.out.println(list.toString().replace("[","").replace("]","").replace(",",""));
            list.clear();
        }
        System.out.println(st.elapsedTime());
    }
}