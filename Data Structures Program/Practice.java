import java.util.*;
public class Practice{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		ArrayList<String> arr = new ArrayList<String>();
		for (int i = 0; i < 5 ; i++ ) {
			arr.add(sc.next());
		}
		Collections.sort(arr);
		String ptr = sc.next();
		int index = Collections.binarySearch(arr,ptr);
		if(index < 0)
			System.out.println("Record not Found");
		else
			System.out.println("Record Found");
	}
}