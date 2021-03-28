import java.io.File;
import java.io.FileOutputStream;
import java.lang.Thread;


class Test {
	public static void main(String[] args) throws Exception {
		var c = new FileOutputStream(new File(args[0])).getChannel();
		System.out.println("Trying to acquire lock ...");
		c.lock();
		System.out.println("Success! Dominating from Java for 3 seconds");
		Thread.sleep(3000L);

	}
}
