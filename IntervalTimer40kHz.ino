IntervalTimer wave1;                        //start timer for wave generator
IntervalTimer Pulse;                        // star timer for length of pulse

    int sqwave=10;                          // delcare variable, this will be HIGH or LOW       
          void setup() {   
            pinMode(sqwave,OUTPUT);         //set variable as output      
            Serial.begin(9600);             /* begin compunication with operator (datastorage)
                                               not sure if this is the best method yet*/
            Pulse.begin(starter,5000000);   // call pulse to occur every 5 seconds 
          }
          void starter(){                   
            wave1.begin(sqwaveGen,12.5);   //call wave generator to occur at 12.5 uS=40kHz
          }
   
    volatile boolean onORoff = false;     // declare on or off relates to sqwave.
          void sqwaveGen (){              // function turns 
            onORoff != onORoff;           //on if off and off if on 
            digitalWrite(sqwave, onORoff);// and wriets to pin 10(sqwave)  
          }
    int i;                                 //declare matrix index
    int CurrentInputValue;                 //declare variable
    int AnalogueInput=A14;                 //decalre variable
    int analogueDataArray[256]={0};        //declare array
          void listen(){                   //stores analogue input in an array 
             for(i=0; i<256; i++){
               CurrentInputValue = analogRead(AnalogueInput);
               analogueDataArray[i] = CurrentInputValue;
               }
         }
          void loop() {                   //main loop function 
            listen();
         }
