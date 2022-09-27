import java.util.*;
public class sum {
    public static void main(String[] args) {
        Scanner var = new Scanner(System.in);
        HashMap<Integer,Integer> map = new HashMap<>();

        Integer temp = var.nextInt();

        int[] array = new int[temp];
        for(int i = 0; i < temp; i++)
            array[i] = var.nextInt();

        var.close();
        for(int i = 0; i < temp; i++)
            if(map.containsKey(array[i])) {
                map.put(array[i], map.get(array[i]) + 1);
            } else
                map.put(array[i],1);
        int sz = map.size();
        while(sz-- > 0) {
            int num = 0,current = 0;
            for(Map.Entry<Integer,Integer> iterator : map.entrySet()) {
                if(iterator.getValue() > current) {
                    num = iterator.getKey();
                    current = iterator.getValue();
                }
            }
            System.out.print(num + " ");
            map.remove(num);

        }

    }
}