#define merah 0 
#define kuning 1 
#define hijau 2 
#define p_merah 8 
#define p_hijau 9 
#define pintombol 10 
#define tekan 0 
#define lepas 1 

int state = 0; 
int tombol = lepas; 
static unsigned long t_awal; 
static unsigned long t_setelah; 
static unsigned long t = 1000; 

void tes_awal(); 
void state1(); 
void state2(); 
void state3(); 
void state4(); 
void state5(); 
void state6(); 
void state7();

void setup() { 
pinMode(merah, OUTPUT); 
pinMode(kuning, OUTPUT); 
pinMode(hijau, OUTPUT); 
pinMode(p_merah, OUTPUT); 
pinMode(p_hijau, OUTPUT); 
pinMode(pintombol, INPUT_PULLUP); 
t_awal = millis(); 
}

void loop() { 
t_setelah = millis()-t_awal; 
tombol = digitalRead(pintombol); 
switch(state){ 
case 0: 
tes_awal(); 
if(tombol == tekan){state = 1; t_awal = millis();}
break; 

case 1: 
state1(); 
if(t_setelah>t){state = 2; t_awal = millis();} 
if(tombol == tekan){state = 4; t_awal = millis();} 
break; 

case 2: 
state2(); 
if(t_setelah>t){state = 3; t_awal = millis();} 
if(tombol == tekan){state = 4; t_awal = millis();} 
break; 

case 3: 
state3(); 
if(t_setelah>t){state = 1; t_awal = millis();} 
if(tombol == tekan){state = 4; t_awal = millis();} 
break; 

case 4: 
state4(); 
if(t_setelah>t){state = 5; t_awal = millis();} 
break; 

case 5: 
state5();
if(tombol == tekan){state = 6; t_awal = millis();} 
break; 

case 6: 
state6(); 
if(t_setelah>t){state = 7; t_awal = millis();} 
break; 

case 7: 
state7(); 
if(t_setelah>t){state = 1; t_awal = millis();} 
break; 
} 
}

void tes_awal(){ 
digitalWrite(merah, HIGH); 
digitalWrite(kuning, HIGH); 
digitalWrite(hijau, HIGH); 
digitalWrite(p_merah, HIGH); 
digitalWrite(p_hijau, HIGH); 
delay(500); 
digitalWrite(merah, LOW); 
digitalWrite(kuning, LOW); 
digitalWrite(hijau, LOW); 
digitalWrite(p_merah, LOW); 
digitalWrite(p_hijau, LOW); 
delay(500); 
}

void state1(){ 
digitalWrite(merah, HIGH); 
digitalWrite(kuning, LOW); 
digitalWrite(hijau, LOW); 
digitalWrite(p_merah, HIGH); 
digitalWrite(p_hijau, LOW);
delay(500); 
}

void state2(){ 
digitalWrite(merah, LOW); 
digitalWrite(kuning, LOW); 
digitalWrite(hijau, HIGH); 
digitalWrite(p_merah, HIGH); 
digitalWrite(p_hijau, LOW); 
}

void state3(){ 
digitalWrite(merah, LOW);
digitalWrite(kuning, HIGH); 
digitalWrite(hijau, LOW); 
digitalWrite(p_merah, HIGH); 
digitalWrite(p_hijau, LOW); 
}

void state4(){ 
digitalWrite(merah, LOW); 
digitalWrite(kuning, HIGH); 
digitalWrite(hijau, LOW); 
digitalWrite(p_merah, HIGH); 
digitalWrite(p_hijau, LOW); 
}
void state5(){ 
digitalWrite(merah, HIGH); 
digitalWrite(kuning, LOW); 
digitalWrite(hijau, LOW); 
digitalWrite(p_merah, HIGH); 
digitalWrite(p_hijau, LOW); 
}
void state6(){ 
digitalWrite(merah, HIGH); 
digitalWrite(kuning, LOW); 
digitalWrite(hijau, LOW); 
digitalWrite(p_merah, LOW); 
digitalWrite(p_hijau, HIGH); 
}
void state7(){ 
digitalWrite(merah, HIGH); 
digitalWrite(kuning, LOW); 
digitalWrite(hijau, LOW); 
digitalWrite(p_merah, LOW); 
digitalWrite(p_hijau, HIGH); 
delay(500); 

digitalWrite(merah, HIGH); 
digitalWrite(kuning, LOW); 
digitalWrite(hijau, LOW); 
digitalWrite(p_merah, LOW); 
digitalWrite(p_hijau, LOW); 
delay(500); 
}
