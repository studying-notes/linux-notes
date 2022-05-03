#include <signal.h>
#include <sys/select.h>

int child_events = 0;

/*信号处理函数*/
void child_sig_handler(int x) {
  child_events++;                     /*调用次数+1*/
  signal(SIGCHLD, child_sig_handler); /*重新设定信号回调函数*/
}

int main(int argc, char **argv) {
  /*设定的信号掩码sigmask和原始的信号掩码orig sigmask*/
  sigset_t sigmask, orig_sigmask;
  sigemptyset(&sigmask);        /*清空信号*/
  sigaddset(&sigmask, SIGCHLD); /*将SIGCHLD信号加入sigmask*/

  /*设定信号SIG BLOCK的掩码sigmask,并将原始的掩码保存到orig sigmask中*/
  sigprocmask(SIG_BLOCK, &sigmask, &orig_sigmask);

  /*挂接对信号SIGCHLD的处理函数child sig handler()*/
  signal(SIGCHLD, child_sig_handler);

  for (;;) {                                   /*主循环*/
    for (; child_events > 0; child_events--) { /*判断是否退出*/
      /*处理动作*/
    }

    /*pselect I0复用*/
    r = pselect(nfds, &rd, &wr, &er, 0, &orig_sigmask);
    /*主程序*/
  }
}
