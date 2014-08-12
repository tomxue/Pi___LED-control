import java.io.IOException;

class ThreadTesterA implements Runnable
{
    private int counter;
    private String cmds[] = new String[1];
    private Process pcs;

    @Override
    public void run()
    {
        cmds[0] = "./gpio-interrupt";

        try {
            pcs = Runtime.getRuntime().exec(cmds);
            if(pcs.waitFor() != 0) {
                System.out.println("error");
            } else {
                ThreadTesterB.setClosed(true);
            }
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        } catch (InterruptedException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }
}

class ThreadTesterB implements Runnable
{
    private int i;
    private static boolean closed=false;

    public static void setClosed(boolean closed)
    {
        closed = closed;
    }

    @Override
    public void run()
    {
        // replace it with what you need to do
        while (!closed) {
            System.out.println("i = " + i);
            i++;
            try {
                Thread.sleep(20);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println();
    }
}

public class ThreadTester
{
    public static void main(String[] args) throws InterruptedException
    {
        Thread t1 = new Thread(new ThreadTesterA());
        Thread t2 = new Thread(new ThreadTesterB());
        t1.start();
        t1.setPriority(Thread.MAX_PRIORITY);
        //t1.join(); // wait t1 to be finished
        t2.start();
        //t2.join();
    }
}
