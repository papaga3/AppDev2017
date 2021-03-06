# this is my readme file
Raspberry PI acoustic sensor project

This project will turn a Raspberry PI3 into an acoustic sensor

1. Configuration

 1.1 Hardware configuration
A Raspberry PI3 is recommended. If an older version of PI is used,
correspending configuration may be changed.

The PI is mounted with an USB sound card, and plugged in a microphone.

It is recommended to have Ethernet connection for your PI.

 1.2 Software configuration
 First, we use "lusb" command to check if the USB sound card is mounted.

 The USB sound card has to be set as defaukt audio devices. To acquire this, 
you need to modify 2 files:
	a. ~/etc/asound.conf
	b. ~/.asoundrc
with the following contents:
 /*
  pcm.!default {
   type plug
   slave {
    pcm "hw:1,0"
   }
 }
 ctl.!default {
    type hw
    card 1
 }
*/
 Run "alsamixer" to check if the USB sound card is the default audio device.

2. operating instruction
....1. Plug in the power cable, Ethernet cable, USB sound card and a microphone.
....2. Run command "make" to build the project.
....3. Run command "./sound.a" to run the project.
you will see the columns which display the recorded sound.
....4. To delete excution file, to command "make clean"
....5. The recorded data is also sent to school server for storage.

3. File manifest
The list of file in the project
------- comm.c comm.h
------- screen.c screen.h
------- wave.c wave.h
------- main.c
------- README.md
------- sound.php

4. Copyright and licensing
----- This project was created by NGUYEN QUOC HUY (e1601140).
----- Contact info: 
	+email: ng.q.huy1008@gmail.com

5. Known bugs.
 There is no known bugs in this project until date: 20.04.2017
If you noticed a bug, please send me an email to this address:
ng.q.huy98@gmail.com

6. Troubleshooting
 6.1) Font error.
 If you cannot display the bar chart on the screen, you should make sure 
to have Unicode encoding, since the bar is created by Unicode characters.
To do that, Right Click on the bottom of the window>Change Setting>Translation
>Choose UTF-8.
 6.2) The waveform is not changing.
 It is probably due to the microphone's misfunction. You should check the microphone 
to make sure it is functioning correctly by running a test program.

7. Credits and acknowledgements
------- Author: NGUYEN QUOC HUY (e1601140)
------- Instructor: Mr.GAO CHAO (VAMK)

8. Changelog
------Ver 1.0 : 20.03.2017 
      first release.
      The program is capable of display data in the screen.
------Ver 1.1 : 20.04.2017
      Fixed some minor bugs.
 
9. Download project.
The project can be download or clone using the following github link:
https://github.com/papaga3/AppDev2017.git


