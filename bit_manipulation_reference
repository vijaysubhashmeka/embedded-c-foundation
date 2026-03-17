#include <stdio.h>
#include <stdint.h>

/*
    ============================================
    EMBEDDED C FUNDAMENTALS - REFERENCE PROGRAM
    ============================================

    Concepts covered:
    1. Fixed width data types (stdint.h)
    2. Bit setting (|)
    3. Bit clearing (& ~)
    4. Bit toggling (^)
    5. Bit shifting (<<)
    6. Field manipulation (multiple bits)
*/

int main()
{
    /*
        --------------------------------------------
        SECTION 1: DATA TYPES (HARDWARE REPRESENTATION)
        --------------------------------------------
    */

    uint8_t reg = 0;  
    // 8-bit register simulation (like GPIO/ODR register)

    printf("Initial reg = %u\n\n", reg);

    /*
        --------------------------------------------
        SECTION 2: SETTING A BIT (TURN ON PIN)
        --------------------------------------------
    */

    reg |= (1 << 3);
    // Set bit 3 → turns ON pin 3
    // 1 << 3 = 00001000

    printf("After setting bit 3: %u\n", reg);

    /*
        --------------------------------------------
        SECTION 3: CLEARING A BIT (TURN OFF PIN)
        --------------------------------------------
    */

    reg &= ~(1 << 3);
    // Clear bit 3 → turns OFF pin 3
    // ~(1 << 3) creates mask with bit 3 = 0

    printf("After clearing bit 3: %u\n", reg);

    /*
        --------------------------------------------
        SECTION 4: TOGGLING A BIT
        --------------------------------------------
    */

    reg ^= (1 << 2);
    // Toggle bit 2
    // If 0 → becomes 1
    // If 1 → becomes 0

    printf("After toggling bit 2: %u\n", reg);

    reg ^= (1 << 2);
    // Toggle again → returns to original state

    printf("After toggling bit 2 again: %u\n", reg);

    /*
        --------------------------------------------
        SECTION 5: SET MULTIPLE BITS
        --------------------------------------------
    */

    reg |= (1 << 1) | (1 << 4);
    // Set bit 1 and bit 4 simultaneously

    printf("After setting bits 1 and 4: %u\n", reg);

    /*
        --------------------------------------------
        SECTION 6: FIELD PROGRAMMING (MULTIPLE BITS)
        Example: 2 bits per pin (like STM32 MODER)
        --------------------------------------------
    */

    /*
        Assume:
        Pin 2 → bits [5:4]
        We want to set mode = 11 (Analog)
    */

    reg &= ~(3 << (2 * 2));
    // Clear bits [5:4]
    // 3 = 11 (binary mask for 2-bit field)

    reg |= (3 << (2 * 2));
    // Set bits [5:4] = 11

    printf("After setting Pin 2 mode (11): %u\n", reg);

    /*
        --------------------------------------------
        SECTION 7: FINAL REGISTER STATE
        --------------------------------------------
    */

    printf("\nFinal register value = %u\n", reg);

    return 0;
}
