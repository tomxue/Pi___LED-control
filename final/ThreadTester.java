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
        // 执行shell脚本
        try {
            pcs = Runtime.getRuntime().exec(cmds);
            if(pcs.waitFor() != 0)
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

class ThreadTesterB implements Runnable
{
    private int i;

    @Override
    public void run()
    {
        // replace it with what you need to do
        while (i != -1) {
            System.out.print("i = " + i + " ");
            i++;
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
        //t1.join(); // wait t1 to be finished
        t2.start();
        //t2.join();
    }
}
