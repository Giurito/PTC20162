mtype = { msg0, msg1, ack0, ack1 };
chan    to_sndr = [2] of { mtype };
chan    to_rcvr = [2] of { mtype };
 
active proctype Sender()
{
tx1:    to_rcvr!msg1;
        to_sndr?ack1;
        if
        :: true -> printf("recebeu ack1\n")
        :: true -> 
        printf("msg corrompida\n") 
        goto tx1
        fi
tx2:    to_rcvr!msg0;
        to_sndr?ack0;
        if
        :: true -> printf("recebeu ack0\n")
        :: true -> 
        printf("msg corrompida\n") 
        goto tx2
        fi
        goto tx1
}
 
active proctype Receiver()
{
rx1:    to_rcvr?msg1
        if
        :: true -> printf("recebeu msg1\n")
        :: true -> 
        printf("msg corrompida\n")   
        goto rx1
        fi
        to_sndr!ack1;
rx2:    to_rcvr?msg0;
        if
        :: true -> printf("recebeu msg0\n")
        printf("msg corrompida\n")   
        goto rx2
        fi
        to_sndr!ack0;
        goto rx1
}
