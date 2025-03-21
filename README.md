# Number to fraction
Takes any number from the user and gives the fractional display of that number, both proper and improper

## Functionality 
A console applications that takes a number from the user and gives the fractional value, if a incorrect number is entered, you will be reprompted to enter the value again.

## How to Use
1. Compile: `g++ main.cpp -o NumberToFraction`
2. Run: `./NumberToFraction`
3. Enter a number (e.g., `3.14159`) and see the fraction magic!

## Features
- Mixed and improper fractions.
- Handles negative numbers.
- Error % vs. real-world constants(if user inputs value accurately upto 6 digits, the constants: pi,e,phi,sqrt2,ln2).
- Supports big decimals with precision.

## Example
**Input:** Enter a number: `3.14159263`

**Output:**
```md
3 + 99257/701004
Or: 2202269/701004
Error: 0.0000007509%
```
## Accuracy
If you want a less accuracy but shorter fraction you can change the loop **from**:

```cpp
for(int i = 0; abs(numb - midnum / midden) > 1e-12; i++){
  midnum = leftnum + rightnum;
  midden = leftden + rightden;
  if(numb == midnum / midden) break;
  else if(numb > midnum / midden) {
    leftnum = midnum;
    leftden = midden;
  }
  else{
    rightnum = midnum;
    rightden = midden;
  }
}
```
**to**:
```cpp
for(int i = 0; i < 100; i++){
  midnum = leftnum + rightnum;
  midden = leftden + rightden;
  if(numb == midnum / midden) break;
  else if(numb > midnum / midden) {
    leftnum = midnum;
    leftden = midden; 
  }
  else{
    rightnum = midnum;
    rightden = midden; 
  }
}
```

> You can also change the value of upper limit from 100 to even less or even more to get your hands directly on the accuracy.!

## License
You can use it however you want to, just mention me UnqGit/Vishesh :D.
Licensed under **MIT**-see [(LICENSE)](LICENSE) _for professionalism XD_

# Thanks for reading!
> Wish you a happy birthday...in advance and belated too... :D
