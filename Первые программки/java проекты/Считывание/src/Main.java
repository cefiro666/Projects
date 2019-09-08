import java.io.*;

public class Main {
    public static void Writer (String message, String path) {
        try {
            FileWriter writer = new FileWriter(path,true);
            BufferedWriter bufferWriter = new BufferedWriter(writer);
            String text = "\n" + message;
            bufferWriter.write(text);
            bufferWriter.close();
        }
        catch (IOException exception){
            System.out.println(exception.getMessage());
        }
    }
    private static int countLines(String str){
        String[] lines = str.split("\r\n|\r|\n");
        return  lines.length;
    }

    public static String Reader (String path, int offset, int length) {
        String string = "";

        try {
            FileReader reader = new FileReader(path);
            char[] buf = new char[length];
            reader.skip(offset);
            reader.read(buf,0,length);
            for (int i=0; i<length; i++) {
                string += buf[i];
            }
        }
        catch (IOException exception){
            System.out.println(exception.getMessage());
        }
        return string;
    }

    public static void main(String[] args) {
        String date = "12.05.2019";
        String time = "13:45:34";
        String wer = "0003455.6";
        String var = date + " " + time + " " + wer;

        System.out.println(Reader("D:/daile.txt",0,10));
        System.out.println(Reader("D:/daile.txt",11,8));
        System.out.println(Reader("D:/daile.txt",20,9));
        Writer (var, "D:/daile.txt");
    }
}