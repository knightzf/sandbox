import java.util.function.*;
import java.util.*;

class OptionalTest {
    public static void main(String[] args) {
        List<Integer> l = new ArrayList<>();
        Optional<Integer> x = l.stream().max((a, b) -> a.compareTo(b));
        if (x == null)
            System.out.println("Hello, World!");
        else
            System.out.println(x.isPresent());
    }
}
