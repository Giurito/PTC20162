
chan canal = [4] of {int};

active proctype produtor()
{
        canal!1;
        canal!2;
        canal!3;
        canal!4;
        canal!5;
        canal!6;
        canal!7;
        canal!8;
        canal!9;
        canal!10;
}

active proctype consumidor() {
 
  // aguarda uma mensagem pelo canal
  canal1?msg
  printf("Recebeu %d\n", msg)

}
