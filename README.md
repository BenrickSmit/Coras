# Coras
[Coras](www.github.com/BenrickSmit/Coras) is a hardware monitor similar to the
linux alternative "sensors". It is, however, made to be far more encompassing.
It displays the following:
    -   System Information
    -   Memory Information
    -   CPU Information
    -   GPU Information

See the below for more details

# Features
Coras is meant to interact directly with the Operating System and Kernel to 
provide the user with the required information. At this point in time Coras is
only a CLI client, and can be built (with CMake) and run with a simple ./coras
command. The executable will be under "/bin/exec..." where you will find
one of many possible compilations. Each characterised by their compiler, and 
platform of execution.

At this point in time Coras interacts mainly with the sysinfo on Linux. Later
version will work directly with the kernel to provide more detailed information.

At present Coras only support Linux -- I'm working on making it as
cross-platform as possible by working on any *nix, Windows, and Mac device.

# Future Changes
Immediate Changes:
    -   Coras will move away from an almost complete dependency on sys and will
        instead work on implementing lower-lever solutions which are faster,
        less processor intensive, and precise (i.e. it will internact with
        the kernel).
    -   Addition of Unit tests where possible to ensure program functionality.
        More tests will be added as the Coras expands in size.

Future Changes:
    -   Coras will work with Windows APIs to access data that isn't possible
        at the current point in time

# How to Run
Coras will run as soon as it's built. The executables can be found in 
"bin/exec/" where different directories indicate different compiler and OS
compilations. Simply navigate to the required file ( or open a terminal directly
via nautilus - or similar file manager ) and type in the program command.

# How to Run Unit Tests
Coras contains a shell script "run_tests.sh" which can be run to ensure all
tests pass. Should you wish to run tests in conjunction with the program 
execution and documentation creation, run "run_all.sh" in the terminal.

A more tedious method would be to navigate to the "build/tests/" directory
where you will find "Coras_test" which can be executed in a similar manner to
Coras found in "bin/exec/..."

# Key Dependencies
At this point in time the main Coras library requires the "filesystem" library
found in the experimental namespace std::experimental which is only available
from C++11 and onwards.

# How to contribute
At this point in time you can contribute by informing me of any bugs found in 
the current software, and I'll work to remedy the situation as soon as possible.

If, however, you wish to work on the project and contribute your code, feel free
to email me or apply in any other method in which you can contact me.

Future Monetary Contributions might also be welcome in the near future.

# License
Coras is licensed under the [Apache 2.0 License](LICENSE)

