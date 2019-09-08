import java.util.Scanner;

public class Main {

    static class triangle {
        int size;
        String symbol;
        void printTriangle() {
            for (int i = 1; i <= size; i++) {
                for (int z = 1; z <= i; z++) {
                    System.out.print(" " + symbol);
                }
                System.out.println();
            }
        }
        triangle(int size, String symbol) {
            this.symbol = symbol;
            this.size = size;
        }
    }

    public static void main(String[] args) {

        Scanner In = new Scanner(System.in);
        System.out.print(" Введите высоту треугольника: ");
        int var = In.nextInt();
        In.nextLine();
        System.out.print(" Введите символ рисования: ");
        String sym = In.nextLine();

        triangle triangle = new triangle(var, sym);
        triangle.printTriangle();

        System.out.println(" Для продолжения нажмите любую клавишу...");
        In.nextLine();
    }
}
