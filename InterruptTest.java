package com.acervus.emailer;

import org.testng.annotations.Test;

/**
 * @author Zhenfei Tai (zhenfei.tai@addepar.com)
 */
public final class InterruptTest {
  class InterruptedSleepingRunner implements Runnable {
    @Override
    public void run() {
      doAPseudoHeavyWeightJob();
    }

    private void doAPseudoHeavyWeightJob() {
      for (int i = 0; i < Integer.MAX_VALUE; i++) {
        // You are kidding me
        System.out.println(i + " " + i * 2);
        // Let me sleep <evil grin>
        if (Thread.currentThread().isInterrupted()) {
          System.out.println("Thread interrupted ...");
          //break;
        } else {
          sleepBabySleep();
        }
      }
    }

    protected void sleepBabySleep() {
      try {
        Thread.sleep(1000);
      } catch (InterruptedException e) {
        System.out.println("---got interrupt");
        Thread.currentThread().interrupt();
      }
    }
  }

  @Test
  void test() throws InterruptedException {
    Thread thread = new Thread(new InterruptedSleepingRunner());
    thread.start();
    // Giving 10 seconds to finish the job.
    Thread.sleep(5000);
    // Let me interrupt
    thread.interrupt();
    //Thread.sleep(5000);
    //thread.interrupt();
  }
}
