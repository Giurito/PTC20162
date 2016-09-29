mtype = { msg0, msg1, ack0, ack1 };
chan    to_sndr = [2] of { mtype };
chan    to_rcvr = [2] of { mtype };
 
active proctype Sender()
{
do
tx1:    
    atomic{ 
    to_rcvr!msg1;
    printf("Enviei msg1\n")
    }
    do  
    :: to_sndr?ack1;
        if
          :: true -> printf("recebeu ack1\n")
          break
          :: true -> 
          printf("ack1 corrompida\n") 
        fi
        
    :: timeout ->
        printf("timeout tx1\n") 
        goto tx1
    od

        
tx2:   
    atomic{
    to_rcvr!msg0;
    printf("Enviei msg0\n")
    }
    do  :: to_sndr?ack0;
        if
          :: true -> printf("recebeu ack0\n")
          break
          :: true -> 
          printf("ack0 corrompida\n") 
        fi
        :: timeout -> 
        printf("timeout tx2\n") 
        goto tx2
    od
 od       
}
 
active proctype Receiver()
{
do
rx1:   
     do 
     ::  to_rcvr?msg1
        if
        :: true -> printf("recebeu msg1\n")
        atomic{
        to_sndr!ack1;
        printf("Enviei ack1\n")
        }
        break
        :: true -> 
        printf("msg1 corrompida\n")   
        fi
     :: timeout -> 
        printf("timeout rx1\n") 
        goto rx2
     od
rx2:        
     do 
     ::  to_rcvr?msg0
        if
        :: true -> printf("recebeu msg0\n")
        atomic{
        to_sndr!ack0;
        printf("Enviei ack0\n")
        }
        break
        :: true -> 
        printf("msg0 corrompida\n")   
        fi
     :: timeout -> 
        printf("timeout rx2\n") 
        goto rx1
     od
od     

}
