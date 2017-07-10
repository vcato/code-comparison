Performance comparison of returning an int by value or by reference.

Compilating is optimized with -O2, but functions are separated into a separate
object files to inhibit link-time optimization.

Timing with gcc 5.4.0 on Linux x86_64.

minimum user time over three runs:
- baseline:            0m1.08s
- return by reference: 0m1.80s
- return by value:     0m1.80s
