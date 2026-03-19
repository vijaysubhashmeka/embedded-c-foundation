#include <stdio.h>
#include <stdint.h>

// Simulated GPIO Output Data Register (ODR)
// In real embedded systems, this would be a hardware register.
// 'volatile' tells the compiler not to optimize it away, because
// hardware registers can change unexpectedly.
volatile uint8_t GPIO_ODR = 0x00;

// ---------------- Utility Functions ----------------

// Check if the given pin number is valid (0–7).
// Since GPIO_ODR is 8 bits wide, only pins 0–7 exist.
int isValidPin(uint8_t pin) {
    return (pin <= 7);
}

// Set (turn ON) a specific pin by writing '1' to its bit position.
void setPin(uint8_t pin) {
    if (!isValidPin(pin)) return;          // Ignore invalid pins
    GPIO_ODR |= (1 << pin);                // Bitwise OR sets the bit
}

// Clear (turn OFF) a specific pin by writing '0' to its bit position.
void clearPin(uint8_t pin) {
    if (!isValidPin(pin)) return;          // Ignore invalid pins
    GPIO_ODR &= ~(1 << pin);               // Bitwise AND with NOT clears the bit
}

// Toggle (flip) the state of a specific pin.
// If it was ON, it becomes OFF. If it was OFF, it becomes ON.
void togglePin(uint8_t pin) {
    if (!isValidPin(pin)) return;          // Ignore invalid pins
    GPIO_ODR ^= (1 << pin);                // Bitwise XOR flips the bit
}

// Read and print the state of a specific pin.
// Shows whether the pin is ON (1) or OFF (0).
void readPin(uint8_t pin) {
    if (!isValidPin(pin)) {
        printf("Invalid pin %d\n", pin);   // Handle invalid pin numbers
        return;
    }

    if (GPIO_ODR & (1 << pin)) {           // Check if bit is set
        printf("Pin %d is ON\n", pin);
    } else {
        printf("Pin %d is OFF\n", pin);
    }
}

// Reset the entire register (all pins OFF).
void resetRegister() {
    GPIO_ODR = 0x00;
    printf("Register reset\n");
}

// ---------------- Main Program ----------------
int main() {
    setPin(3);         // Turn ON pin 3
    readPin(3);        // Should print "Pin 3 is ON"

    togglePin(3);      // Flip pin 3 (ON → OFF)
    readPin(3);        // Should print "Pin 3 is OFF"

    readPin(190);      // Invalid pin, should print "Invalid pin 190"

    resetRegister();   // Reset all pins to OFF

    return 0;
}
// this program is written by me
#include<stdio.h>
#include<stdint.h>

int main()
{
    uint8_t reg = 0;

    // Step 1: Clear bits 2 and 3
    reg &= ~((1 << 2) | (1 << 3));

    // Step 2: Set value '10' into bits [3:2]
    reg |= (2 << 2);

    printf("reg = %u\n", reg);

    return 0;
}
