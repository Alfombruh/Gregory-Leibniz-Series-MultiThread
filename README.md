<html>
 <head>
 </head>
 <body>
  <h1 style="text-align: center;">Gregory-Leibniz-Series-MultiThread</h1>
  <p>This is a project I did for fun, to learn about multithreading uses and to put to use my skills with threads (wich are little to no)</p>
  <p>What this program does is: calculate pi with 10 digits (last one is rounded) using the six cores of my processor</p>
  <p>To achive this I'm using <a href="https://en.wikipedia.org/wiki/Leibniz_formula_for_%CF%80">Gregory-Leibniz's Series</a>, this is a series of sums that when reaching infinite sum up to pi/4</p>
  <img src="https://i.ytimg.com/vi/Qy42mIzLbHA/hqdefault.jpg"></img>
  <p>I really would love to get more than 10 digits, but due to me not being very smart it doesn't seem likely</p>
  <p>If, for some unknown reason, you wanna run this at home I suggest you check how many cores your CPU has and then change ,in the includes/pi.h file, the #define NUM_THREADS from 6 to your name of cores</p>
  <p>If you want to get a bigger value just change the srcs/main.c 42th lines printf's 0.N (N being the value to change. EX: printf("%0.15LF\n", pi.total); to get 15 digits</p>
  <h2 style="text-align: center;"> <3 </h2>
 </body>
</html>
