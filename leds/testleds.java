import java.io.IOException;

public class testleds {
        public static void main(String[] args)
        {
            Runtime rt = Runtime.getRuntime();
            try {
                Process p = rt.exec("/home/pi/tomxue/leds.sh");
                if(p.waitFor() != 0)
                System.out.println("error");
            } catch (IOException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            } catch (InterruptedException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }
}
