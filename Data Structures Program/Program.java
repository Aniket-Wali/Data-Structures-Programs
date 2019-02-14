import java.util.*;
public class Program{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Queue<String> list = new LinkedList<>();
		String str = sc.nextLine();
		list.add(str);
		System.out.println(str);
		System.out.println(list.size());
	}
}