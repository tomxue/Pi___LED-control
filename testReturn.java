// the code is from link: http://blog.csdn.net/tengdazhang770960436/article/details/12014839
import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class testReturn {
	public static void main(String[] args) throws Exception {
		// 定义传入shell脚本的参数，将参数放入字符串数组里
		String cmds[] = new String[9];
		// cmds[0] = "./return.sh";
		cmds[0] = "./button";
		cmds[1] = "1"; // 任务省Id
		cmds[2] = "2";// 插入任务人所属的纳税主体标识
		cmds[3] = "3";// 任务期间
		cmds[4] = "4";// 统计表单类型 (1：计算表,2：申报表)
		cmds[5] = "5";// 插入任务人的二级公司Id
		cmds[6] = "6";// 表名
		cmds[7] = "7";
		cmds[8] = "8";// 库名

		// 执行shell脚本
		Process pcs = Runtime.getRuntime().exec(cmds);

		// 定义shell返回值
		String result = null;

		// 获取shell返回流
		BufferedInputStream in = new BufferedInputStream(pcs.getInputStream());
		// 字符流转换字节流
		BufferedReader br = new BufferedReader(new InputStreamReader(in));
		// 这里也可以输出文本日志

		String lineStr;
		while ((lineStr = br.readLine()) != null) {
			result = lineStr;
		}
		// 关闭输入流
		br.close();
		in.close();

		System.out.println(result);
	}
}

