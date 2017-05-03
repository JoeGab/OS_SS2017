Write a program in which the parent creates exactly 1 child process. The child
process should print its
pid
to the standard output and then finish. The parent
process waits until it is sure that the child has terminated. For this students are
required to check in the man page of fork to see whether a parent is notified of
child termination via any signal. The parent terminates after it has waited for
the child process.
