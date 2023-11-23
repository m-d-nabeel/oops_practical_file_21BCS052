package source_code.src;

public class Main {
    public static void main(String[] args) {
        System.out.println("-------------------START-------------------\n");
        System.out.println("-------------------SINGLE THREADED-------------------");
        SingleThreaded.main(args);
        System.out.println("-------------------MULTIPLE THREADED-------------------");
        MultipleThreaded.main(args);
        System.out.println("-------------------END-------------------\n");
    }
}
