chan buffer = [4] of {int};

active [2] proctype produtor()
{
  int msg = 0;
  
do
:: msg <10 ->
     buffer!msg
     printf(" Enviou %d\n" , msg )
     msg++
:: else -> break
od

}

active proctype consumidor() {

do
:: buffer?m -> printf("Recebeu %d\n" , m )
:: timeout -> break
od

}
