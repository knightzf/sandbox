import java.util.function.*;

class Func {
    public static <R> void test(BiFunction<String,Integer,R> f) {
        f.apply("a", 1);
    }
    public static Integer func(String a, Integer b) {
        System.out.println("aaa");
        return 0;
    }
    public static void main(String[] args) {
        test(Func::func);
    }
}
