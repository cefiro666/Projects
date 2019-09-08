using System;
using System.IO;

namespace Считывание_cs
{
    class Program
    { 
        static string ReadLine (string path, int offset, int length)
        {
            string Line = "";
            try
            {
                StreamReader read = new StreamReader(path, System.Text.Encoding.Default);
                char[] buffer = new char[length];
                char[] offs = new char[offset];
                read.Read(offs, 0, offset);
                read.Read(buffer, 0, length);
                for (int i = 0; i < length; i++)
                {
                    Line += buffer[i];
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
            return Line;
        }

        static void Main(string[] args)
        {
            Console.WriteLine(ReadLine("D:/daile.txt", 0, 10));
            Console.WriteLine(ReadLine("D:/daile.txt", 11, 8));
            Console.WriteLine(ReadLine("D:/daile.txt", 20, 9));
            Console.Write(" Нажмите любую клавишу...");
            Console.ReadKey();
        }
    }
}
