#include <TaskScheduler.h>

void t1Callback();
void t2Callback();
void t3Callback();
void t4Callback();
void t5Callback();

Task t1(2000, 10, &t1Callback);
Task t2(3000, TASK_FOREVER, &t2Callback);
Task t3(5000, TASK_FOREVER, &t3Callback);
Task t4(8000, 5, &t4Callback);
Task t5(4000, TASK_FOREVER, &t5Callback);

Scheduler runner;

void t1Callback() {
 Serial.print("t1: ");
 Serial.println(millis());
 if (t1.isFirstIteration()) {
 runner.addTask(t4);
 runner.addTask(t5);
 t4.enable();
 t5.enable();
 Serial.println("t1: enabled t4 & t5 and added to the chain");
 }
 if (t1.isLastIteration()) {
 t3.disable();
 runner.deleteTask(t3);
 t2.setInterval(4500);
 Serial.println("t1: disable t3 and delete it from the chain. t2 interval set to 4500");
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
void t4Callback() {
 Serial.print("t4: ");
 Serial.println(millis());
 if (t4.isLastIteration()) {
 t2.disable();
 runner.deleteTask(t2);
 t5.setInterval(2000);
 Serial.println("t4: disable t2 and delete it from the chain. t5 interval set to 2000");
 } 
}
void t5Callback() {
 Serial.print("t5: ");
 Serial.println(millis());
}

void setup () {
 Serial.begin(115200);
 Serial.println("Scheduler TEST");
 runner.init();
 Serial.println("Initialized scheduler");
 runner.addTask(t1);
 Serial.println("added t1");
 runner.addTask(t2);
 Serial.println("added t2");
 runner.addTask(t3);
 Serial.println("added t3");
 delay(3000);
 
 t1.enable();
 Serial.println("Enabled t1");
 t2.enable();
 Serial.println("Enabled t2");
 t3.enable();
 Serial.println("Enabled t3");
}

void loop () {
 runner.execute();
}
