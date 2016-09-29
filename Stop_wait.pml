mtype = { msg0, msg1, ack0, ack1 };
chan    to_sndr = [2] of { mtype };
chan    to_rcvr = [2] of { mtype };
 
active proctype Sender()
{
tx1:    
    to_rcvr!msg1;
    do  :: to_sndr?ack1;
        if
          :: true -> printf("recebeu ack1\n")
          break
          :: true -> 
          printf("msg corrompida\n") 
        fi
        :: timeout -> goto tx1
    od
        
tx2:   
    to_rcvr!msg0;
    do  :: to_sndr?ack0;
        if
          :: true -> printf("recebeu ack0\n")
          break
          :: true -> 
          printf("msg corrompida\n") 
        fi
        :: timeout -> goto tx2
    od
        
}
 
active proctype Receiver()
{
rx1:   
     do ::  to_rcvr?msg1
        if
        :: true -> printf("recebeu msg1\n")
        to_sndr!ack1;
        break
        :: true -> 
        printf("msg corrompida\n")   
        fi
        :: timeout -> goto rx1
     od
        
rx2:  
     do ::  to_rcvr?msg0
        if
        :: true -> printf("recebeu msg0\n")
        to_sndr!ack0;
        break
        :: true -> 
        printf("msg corrompida\n")   
        fi
        :: timeout -> goto rx2
     od
     

}
