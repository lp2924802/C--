# PostlethwaiteLauren_CIS5_40562

Version History Summary

V1.0: First attempt at creating Yahtzee game. Largely centered around
creating a proper dice-rolling mechanism that allowed the player to
save dice as they wished, which it did not succeed in doing.

V1.1: Dice were now able to be held in this version, but the die
status was "invisible" in that the user could not see whether or not
the die was held as there were no brackets. Also the status did not
reset between turns.

V1.1.1: A small misstep in trying to fix the die-holding status that
resulted in the dice not being held at all. This version was quickly
abandoned.

V1.2: The idea of brackets came up, but now there was the problem of
trying to pass a string into and out of a function. Technically it was
still possible to avoid calling functions at all, but this specific
pathway would be called so frequently that it was deemed unreasonable
to write and rewrite the code over and over again.

V1.2.1/1.2.2: Brackets were successfully added by appending strings
onto the die values, but unfortunately this resulted in a strange
outcome where the die values would continually add onto one
another (i.e. [2] --> [23] --> [232]) although this did not affect
the actual value of each die. This problem resulted in the program
needing to be completely redone.

V1.3-1.4: The brackets method was briefly abandoned at this point
and instead the scorecard was focused on for the time being, which
again brought up the problem of trying to pass strings into functions.

V1.5: The brackets problem was finally figured out after learning how
to use pointers, which quickly led to the scorecard prohblems being
solved as well. 

V2.0: Added file opening/closing to project.

V2.1: Final version for Project 1. Scorecard is called from a function,
then written to a file that is read throughout the program. The
program works consistently and displays sufficient error-handling.