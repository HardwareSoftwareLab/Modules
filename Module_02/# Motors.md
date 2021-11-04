# Motors

In this module you'll learn about different kinds of motors / actuators and you'll learn about how to use them

## DC motors

The most common type of motor is the (brushed) [DC motor](https://en.wikipedia.org/wiki/DC_motor). A DC motor has a stator with permanent magnets, a armature with the motor windings and a commutator which switches the polarity of the motor windings so that the motor keeps moving. A DC motor has two terminals. By applying a voltage across the terminals the motor will start spinning. If you reverse the polarity the motor will spin in the other direction.

### Using a DC Motor

If you want to use a DC motor you have to do a few things:

First you have to find out the maximum voltage that the motor can handle. To know this you have to look at the motor specifications. If you don't have the specifications of the motor you can hook the motor up to a [Lab bench power supply](https://en.wikipedia.org/wiki/Power_supply). This allows you to slowly increase the voltage to the motor. The higher the voltage to the motor, the bigger the current thats flowing through the motor gets. If the current is to big the motor will get too hot and the motor will break. So when you're increasing the voltage keep a close eye on the current and make sure the motor doesn't get too hot. A good rule of thump when dealing with motors: If you can touch the motor for 5 seconds without burning yourself its probably fine. 

If you know the voltage that the motor needs you will need to find out the current that the motor consumes. If the power supply that you're using isn't big enough the profide sufficient current the power supply can overheat and/or the motor won't work well. You can measure the current that the motor consumes with a [multimeter](https://nl.wikipedia.org/wiki/Multimeter), or you can check the motor specifications.

The required voltage and current will determine the power supply that you can use. The voltage of the power supply has to excacly match the voltage that the motor needs, the current that the power supply can profide has to be at least the amount that the motor needs. For excample: If you have a motor that needs 3V and needs a current of 3A you can't use a 3V - 1500mA power supply but a 3V - 5A power supply will work.

### On/Off switch
If you connect a basic toggle switch in series with the motor you can switch the motor on and off

### DPDT switch
You can use a DPDT (double pole double throw) switch to be able to reverse the direction of the motor. You have to hook up the motor in the following way:

### Relais
If you want to controll the motor with another circuit or with a microcontroller you can use a relais. If you have a DPDT relais you can control the direction and turn on and off the motor!

###Speed control
If you want to controll the speed of the motor you can use a transistor and a PWM signal. With a PWM (pulse width modulation) signal you can switch the motor on and off with a very high frequency. Depening on the amount of time the motor spend in a ON position versus the amount of the the motor spends in the OFF position you can effectively controll the speed of the motor. A PWM signal has a duty-cycle. The duty-cycle determines how much time the signal is high versus low. A 50% duty-cycle spends a equal amount of time on and off. Because the PWM signal frequency is quite high (usually more that 20kHz) it bassilcy controll the voltage the motor sees. If you have a power supply of 12V and you drive a transistor with a 10% duty cycle the effective voltage across the motor is 1.2V. 

###H-Bridge controller
If you want to controll the speed and the direction the motor is spinning you have to use a H-Bridge or motor-controller. A H-Bridge is a circuit that consists of four transistors. By switching specific transistors on and off the motor can spin in two directions. A breaking action can also be achieved by switching Q3 and Q4 on an thereby shoring out the motor.

##Stepper motors
Stepper motors are motors that need to be controlled in a very specific way. There are two catagories of stepper motors, bipolar and unipolar motors. Bipolar stepper motors are a bit more difficult to controll but usually have higher performance in terms of power and efficiency. Stepper motors are used in applycations where the position of the motor needs to be controlled (such as in 3D printers and other CNC machines).

###Unipolar stepper motors
A very common unipolar stepper motor is the 28byj-48 motor. This motor has 5 wire leads. The woundings are wired like this:

The red wire is the center tab of both coils. By connecting this wire to +5v and by sequencicly connecting the other wires to ground the motor starts spinning. There are a few different step-sequences that you can use: Wave drive, full step and half step. Full-step profides the most torque while half-step gives the smallest step angle. Wave drive is the worst in terms of performance but its the easiest to program.

###Bipolar stepper motors
Bipolar stepper drivers don't have the center tap like the unipolar steppers. In order to make the motor work you don't only have to switch on and of the windings of the motor but you also have to reverse the polarity with every step. Luckily there are a lot of stepper drivers available that are specificly designed to take care of the step sequincing. Most stepper drivers have the availability to do microstepping. With microstepping the step angle of every step can be decreased. Microstepping also makes the motor turn more smoothly but the maximum speed gets decreased. 

###Open-loop vs closed-loop
A common issue with stepper motors is "losing steps". If you're driving the motor at it's max speed or torque it can happen that the load is to big and that the motor will lose some steps. In a open-loop system the driver doesn't know that the motor has lost some steps and it can't correct this issue. A closed loop system is constantly monitoring the motor shaft position and it will know when the motor lost a step. If the system detects such a fault it can correct itself. 

##Servo motors
Servo motors are motors that have a closed-loop design. Hobby grade servo motors are usually controlled with a PWM signal. The duty cycle of this signal is translated to a shaft position of the servo motor. There is some controll circuitry inside the servo-motor that monitors the shaft position and depending on the desired shaft position the motor is driven forward or in reverse. More advanced servo motors might use high power brushless motors in combination with precision gearboxes and high quality encoders (instead of potentiometers) the driver the output shaft with high speed, torque and accuarcy. These high performance servo motors are what are uses in industrial robots arms. 








