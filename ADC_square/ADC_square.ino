// the folllowing code is a controll system to operate a ping distance detector, using two Transducers 
// the code, sends a short ping from the Transmitting Transducer, the Recieving Transducer listens 
// the time lapsed between ping and revieving, is counted and the distance is calculated.

int DCACOUT=13;             //DC to  AC Ping driving signal 
int ACIN=0;              // AC Ping recieving signal 
int traveltime;           // Time calculated ising PulseIN
int measure;              // calculated distance measured 
int count = 0;            // set count = 0 counts to length of desired ping length each count =12.5 microseconds
int DCstate = false;      // set initial state for output to be low
void squareWave40kHz();   // prototyping squarewave function to avoid mess 

void setup() {
pinMode(DCACOUT,OUTPUT);    // set pin13 as output 
pinMode(ACIN,INPUT);      // set pin12 as input 
analogReference(DEFAULT); // JUST INCASE
Serial.begin(9600);       // start converstion
}
void loop() {
  squareWave40kHz();                        // call squareWave function
      return 0;                            // return nothing 
  Serial.println(analogRead(ACIN));
}
void squareWave40kHz(){
int DCstate = false;   
      while(1)                            // infite while loop
      {
       while (count <=100)                // duration of ping
       {
         if (DCstate==true){              // if ON
          digitalWrite(DCACOUT,LOW);      // turn OFF
          DCstate=false;                  // note OFF
         }else{                           // if OFF
          digitalWrite(DCACOUT,HIGH);     // turn ON
          DCstate=true;                   // Note ON
         }
         delayMicroseconds(6.75);         // set frequancy to 40khz 12.5 microseconds between off and on 
         count++;                         // count for duration of ping if count choice is 10 ==> 10*12.5 microsecond ping 
       }
       delay(100);                        // delay between pings
       count=0;                           // re initialize count 
      }
  }
