#****************************************************************************
from itertools import islice
import numpy as np

# Adam Prieto
# Professor Ranjidha Rajan
# CS 3600 - Operating Systems
# 1 April 2022


# Variables and declarations
numProcesses = int(input("Please enter the number of processes: "))
allocationValues = []
maxValues = []
needValues = []
availableValues = []

# Get allocation values
print("Now I need the allocation and max values for the processes.\n"
      "Please enter those values now.\n")

for i in range(numProcesses):
    x = int(input(f"Allocation Value {i+1}: "))
    allocationValues.append(x)

#****************************************************************************

# Get maximum values
print("\nNow I need the respective max values.\n")

for i in range(numProcesses):
    x = int(input(f"Maximum Value {i+1}: "))
    maxValues.append(x)

#****************************************************************************

# Set need values
for i in range(numProcesses):
    x = maxValues[i]-allocationValues[i]
    needValues.append(x)

#****************************************************************************

# Get and set available values
y = int(input("\nPlease input the first available value: "))
availableValues.append(y)

print("Beginning calculation of available values.\n")
for i in range(numProcesses):
    # Check to see if need <= available and increment
    if needValues[i] <= availableValues[i]:
        print(f"Incrementing {availableValues[i]} by {allocationValues[i]}")
        availableValues.append(availableValues[i]+allocationValues[i])

    else:
        print(f"{needValues[i]} > {availableValues[i]} "
              f"\nBeginning next process.")

#****************************************************************************

# Quick Check
for i in range(numProcesses):
    print(f"Allocation value: {allocationValues[i]}, "
          f"Max value: {maxValues[i]}, "
          f"Need value: {needValues[i]}, "
          f"Available value: {availableValues[i]}")

#****************************************************************************

# Interactive Session
while True:
    # Get input
    x = int(input("Please enter the allocation number: "))
    y = int(input("Please enter the resource number (need): "))
    z = int(
        input(
            "Please enter the number of units the process is requesting "
            "(work): "))
    print(f"Your request: request({x}, {y}, {z})")

    # Granted or not
    if y <= z:
        z += x
        print(f"Request granted. \nwork value: {z}\n")
    else:
        print("Request not granted.\n")

    # Check if user wants to run the program again; if not, end.
    doAgain = input("Would you like to run another request? [Y/N]: "
                    "").upper()
    if doAgain == 'N':
        print("Goodbye.")
        break

    print("Continuing Program.\n")
# End while loop

print("End Banker Project.")
