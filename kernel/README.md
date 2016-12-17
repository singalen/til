Wikipedia
=========

In computer science, the thundering herd problem occurs when a large number of processes waiting for an event are awoken when that event occurs, but only one process is able to proceed at a time. After the processes wake up, they all demand the resource and a decision must be made as to which process can continue. After the decision is made, the remaining processes are put back to sleep, only to all wake up again to request access to the resource.
This occurs repeatedly, until there are no more processes to be woken up. Because all the processes use system resources upon waking, it is more efficient if only one process was woken up at a time.
This may render the computer unusable, but it can also be used as a technique if there is no other way to decide which process should continue (for example when programming with semaphores).

https://en.wikipedia.org/wiki/Thundering_herd_problem

SO
==
http://stackoverflow.com/questions/2213779/does-the-thundering-herd-problem-exist-on-linux-anymore

0xfe (http://stackoverflow.com/a/2215149/207791): "That said, the select system has a number of scalability issues simply by way of its API. When you have a large number of file descriptors, the cost of a select call is very high. This is primarily due to having to build, check, and maintain the FD sets that are passed to and from the system call.

Now days, the preferred way to do asynchronous IO is with epoll."

I had to rewrite an example (https://gist.github.com/kazuho/10436253) in a language I know.

