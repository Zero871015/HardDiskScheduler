# HardDiskScheduler

## Computer Organization Final Project – Hard Disk Scheduler
## Due: 23:55, June 6, 2019
>> Hard disk is a mechanical storage system, which stores data on the surface of a magnetic platter, to provide a mass non-volatile storage environment in a computer system. A program and its data will be loaded from a hard disk to dynamic random access memory (DRAM) before being accessed by a microprocessor. However, the speed of a mechanical system is much slower than the speed of a microprocessor. The overall performance of a computer system could be strongly related to the disk access time. The disk access time consists of the seek time, the rotation delay and the data transfer delay. Empirically, the disk seek time contributes a significant part among the above three major factors. The disk seek time is related to the seek distance from the original position of disk read/write head to the new position of requested disk address. To minimize the disk seek time, we often exploit the benefit of locality by scheduling neighboring requested addresses together. However, the requested addresses should be scheduled within a certain of tolerance timing window to prevent from starvation condition. This is so-called the quality of service (QoS) constraint. For more details, please read Chapter 6. 
>> In this project, you are going to invent a minimal seek distance disk scheduler under a given QoS constraint t. We formulate this problem as a one-to-one mapping problem below. Assume that the total number of disk references is N. There are two sequences, the requested sequence, {A1, A2, …, AN}, and the scheduled sequence, {R1, R2, …, RN}. In the requested sequence, the i-th element Ai represents the disk address of the ith requested access. In the scheduled sequence, the j-th element Rj represents that the j-th scheduled access is the Rj-th requested access in the requested sequence. According to the given QoS constraint t, both inequalities, 1 ≤ 𝑅𝑅𝑗𝑗 ≤ 𝑁𝑁 and 𝑗𝑗 − 𝑡𝑡 ≤ 𝑅𝑅𝑗𝑗 ≤ 𝑗𝑗 + 𝑡𝑡, must be satisfied for all 1 ≤ 𝑗𝑗 ≤ 𝑁𝑁. Therefore, the objective function of the minimal seek distance disk scheduler is:

![](http://latex.codecogs.com/gif.latex?min%20%5Csum_%7Bj%3D1%7D%5E%7BN%7D%20%5Cleft%20%7C%20A_%7BR_%7Bj%7D%7D%20-%20A_%7BR_%7Bj-1%7D%7D%20%5Cright%20%7C%2Cassume%20R_%7B0%7D%3D0%2CA_%7BR_%7B0%7D%7D%3DA_%7B0%7D%3D0)

>> There are two inputs in your program, the requested sequence file (ex: "filename.in")
and the QoS constraint t. There are also two outputs in your program, the scheduled
sequence file ("access.out") and the total seek distance.

---
## How to use it in Liunx?
* Download the file in your computer(OS:Linux).
* Type "make" in your CMD.
  * Remember you need to use cd change your directory where **main.cpp** and **makefile** is.
  * If it succeed, you will see **hds.out** added in the folder.
* And type "./hds.out FILE.in" to execute the program.
* If it works, you will see the result on CMD, and there are files named access.out in the folder.

## Contact
* If there is any bug or question, you can use email contact me:
  * zero871015@gmail.com

Thank you.</br>
-Zero871015 05/29/2019
