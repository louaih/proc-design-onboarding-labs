# Onboarding Lab 3 Notes and Answers

## Make Note: What testing strategy did you adopt for this Exercise2? What decisions did you have to make and how did you come up with your answers?

I adopted a strategy of testing the reset behavior and then testing the state transitions for all possible initial values. For the reset behavior, I set the reset signal to 1 and provided a specific initial value, then checked that the output was the bitwise negation of the initial value. For the state transitions, I iterated through all possible 16-bit initial values, applied the reset, and then ticked and tocked the model 16 times while checking that the output matched the expected value based on the given logic. This approach ensures that we are thoroughly testing both the reset functionality and the state transition logic for a wide range of inputs.

## Make Note: How does testing a Don’t Care work? What must be done to ensure the input truly has no effect on output?

Testing a Don't Care condition involves ensuring that the output remains unaffected regardless of the value of the input in question. To ensure that the input truly has no effect on the output, you can set the input to various values (including edge cases) while keeping all other inputs constant, and then verify that the output does not change. In this exercise, for example, when sel is set to 3 (the default case), we can test with different values of alpha, beta, and gamma to confirm that the output is always computed as alpha & (beta | gamma) regardless of the specific values of alpha, beta, and gamma.