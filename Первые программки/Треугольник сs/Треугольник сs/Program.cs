using System;

namespace ConsoleApp1
{
    class Triangle
    {
        protected int size;
        public string symbol;
        public void PrintTreangle()
        {
            for (int i = 1; i <= size; i++)
            {
                for (int z = 1; z <= i; z++)
                {
                    Console.Write(" " + symbol);
                }
                Console.WriteLine();
            }
        }
        public Triangle(int size, string symbol)
        {
            this.size = size;
            this.symbol = symbol;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Console.Write(" Введите размер основания треугольника: ");
            int var = Convert.ToInt32(Console.ReadLine());
            Console.Write(" Введите символ рисования: ");
            string sym = Console.ReadLine();

            Triangle one = new Triangle(var, sym);
            one.PrintTreangle();

            Console.Write(" Нажмите любую клавишу...");
            Console.ReadKey();
        }
    }
}
