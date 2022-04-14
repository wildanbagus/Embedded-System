#include <TaskScheduler.h> 
#include <avr/wdt.h>

void t1Callback(); 
void t2Callback(); 
void t3Callback();

Task t1(2000, 5, &t1Callback);
Task t2(3000, TASK_FOREVER, &t2Callback); 
Task t3(4500, TASK_FOREVER, &t3Callback);
Scheduler runner; 

void t1Callback() {
Serial.print("t1: "); 
Serial.print(millis()); 
Serial.println(" (Feed the dog)"); 
wdt_reset();
if (t1.isFirstIteration()) { 
runner.addTask(t3); 
t3.enable();
Serial.println("t1: enabled t3 and added to the chain");
}
if (t1.isLastIteration()) { 
t3.disable();
runner.deleteTask(t3); 
t2.setInterval(1000);
Serial.println("t1: disable t3 and delete it from the chain. t2 interval set to 1000");
} 
}

void t2Callback() { 
Serial.print("t2: "); 
Serial.println(millis());
}

void t3Callback() { 
Serial.print("t3: "); 
Serial.println(millis());
}

void setup () {
MCUSR &= ~(1 << WDRF);
wdt_disable(); 

Serial.println("===BOOTING===");
Serial.begin(115200); 
Serial.println("Scheduler with Watchdog"); 
runner.init(); 
Serial.println("Initialized scheduler"); 
runner.addTask(t1);//add task 1 to chain 
Serial.println("added t1"); 
runner.addTask(t2);//add task 2 to chain 
Serial.println("added t2");
delay(3000);

wdt_enable(WDTO_8S); 
Serial.println("success enabling wdt");

t1.enable();//enable task 1 
Serial.println("Enabled t1"); 
t2.enable();//enable task 2 
Serial.println("Enabled t2");
}

void loop () {
runner.execute();//execute task scheduler
}
