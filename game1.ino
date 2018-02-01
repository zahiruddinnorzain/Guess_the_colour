
//declare button input

int button_merah = 2;
int button_kuning = 3;
int button_biru = 4;

//declare condition button
int conditdion_button_merah=0;
int conditdion_button_kuning=0;
int conditdion_button_biru=0;

void setup() {
  // put your setup code here, to run once:

pinMode(button_merah, INPUT);
pinMode(button_kuning, INPUT);
pinMode(button_biru, INPUT);

Serial.begin(9600);
}


void loop() {

conditdion_button_merah = digitalRead(button_merah);
conditdion_button_kuning = digitalRead(button_kuning);
conditdion_button_biru = digitalRead(button_biru);

if(conditdion_button_merah == HIGH){  
  Serial.println("correctm");
  
  conditdion_button_merah = LOW;
  delay(1000);
  }
  
else if(conditdion_button_kuning == HIGH){  
  Serial.println("correctk");

  conditdion_button_kuning = LOW;
  delay(1000);
  }

else if(conditdion_button_biru == HIGH){  
  Serial.println("correctb");

  conditdion_button_biru = LOW;
  delay(1000);
  }
 else{
  conditdion_button_merah = LOW;
  conditdion_button_kuning = LOW;
  conditdion_button_biru = LOW;
   }
 }
