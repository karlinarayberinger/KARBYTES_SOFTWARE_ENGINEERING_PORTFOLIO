/**
 * file: base_converter_arithmetic.js
 * type: JavaScript
 * date: 10_JULY_2023
 * author: karbytes
 * license: PUBLIC_DOMAIN
 */

/**
 * Get the result of the following calculation: base ^ exponent (i.e. base to the power of exponent (i.e. base multiplied by itself exponent times))
 * .
 * @param {Number} base is assumed to be a base-ten natural number which is no smaller than two and no larger than sixteen.
 * 
 * @param {Number} exponent is assumed to be a base-ten natural number which is no smaller than zero and no larger than seven.
 * 
 * @return {Number} base multiplied by itself exponent times if no exception is thrown; otherwise 1.
 */
function compute_power(base, exponent) {
    try {
        let result = 1;
        if (arguments.length !== 2) throw "exactly two function arguments are required.";
        if (typeof base !== "number") throw "base is required to be a Number type value.";
        if (typeof exponent !== "number") throw "exponent is required to be a Number type value.";
        if (Math.floor(base) !== base) throw "base is required to be a whole number.";
        if (Math.floor(exponent) !== exponent) throw "exponent is required to be a whole number.";
        if ((base < 2) || (base > 16)) throw "base is required to be no smaller than two and no larger than sixteen.";
        if ((exponent < 0) || (exponent > 7)) throw "exponent is required to be no smaller than zero and no larger than seven.";
        while (exponent > 0) {
            result *= base;
            exponent -= 1;
        }
        return result;
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of compute_power(base, exponent): " + exception);
        return 1;        
    }
}

/**
 * Determine whether or not the given function arguments represents a valid input_sequence with whose digits are in the input_base.
 * 
 * @param {Number} input_base is assumed to be a base-ten integer which is no smaller than two and no larger than sixteen.
 * 
 * @param {String} input_sequence is assumed to be a sequence of exactly eight characters such that each character is a digit whose numeric base is input_base.
 * 
 * @return {Boolean} true if input_sequence is a string comprised of exactly eight characters such that each character is a digit whose numeric base is input_base; false otherwise.
 */
function validate_input_sequence(input_base, input_sequence) {
    try {
        let hexidecimal_digit_set = "0123456789ABCDEF", i = 0, k = 0, is_valid_input_sequence_digit = false;
        if (arguments.length !== 2) throw "exactly two function arguments are required.";
        if (typeof input_base !== "number") throw "input_base is required to be a Number type value.";
        if (typeof input_sequence !== "string") throw "input_sequence is required to be a String type value.";
        if (Math.floor(input_base) !== input_base) throw "input_base is required to be a whole number.";
        if ((input_base < 2) || (input_base > 16)) throw "input_base is required to be no smaller than two and no larger than sixteen.";
        if (input_sequence.length !== 8) throw "input_sequence is required to have a length of exactly eight characters.";
        for (i = 0; i < 8; i++) {
            for (k = 0; k < input_base; k++) if (input_sequence[i] === hexidecimal_digit_set[k]) is_valid_input_sequence_digit = true;
            if (!is_valid_input_sequence_digit) throw "at least one character in input_sequence is not a valid digit (i.e. a digit whose base is input_base).";
            is_valid_input_sequence_digit = false;
        }
        return true;
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of convert_to_decimal(input_base, input_sequence): " + exception);
        return false;
    }
}

/**
 * Return the decimal integer index of the hexidecimal digit which H represents where hexidecimal digits 
 * are the following set of characters arranged in the following permutation: 
 * ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F']
 * 
 * @param {String} H is assumed to be a single hexidecimal digit.
 * 
 * @return {Number} the decimal integer index of the hexidecimal digit which H represents.
 */
function get_decimal_value_of_hexidecimal_digit(H) {
    if (H === '0') return 0;
    if (H === '1') return 1;
    if (H === '2') return 2;
    if (H === '3') return 3;
    if (H === '4') return 4;
    if (H === '5') return 5;
    if (H === '6') return 6;
    if (H === '7') return 7;
    if (H === '8') return 8;
    if (H === '9') return 9;
    if (H === 'A') return 10;
    if (H === 'B') return 11;
    if (H === 'C') return 12;
    if (H === 'D') return 13;
    if (H === 'E') return 14;
    if (H === 'F') return 15;
    return 0;
}

/**
 * Get the decimal number representation of input_sequence by converting input_sequence from input_base to decimal (i.e. base-ten).
 * 
 * @param {Number} input_base is assumed to be a base-ten integer which is no smaller than two and no larger than sixteen.
 * 
 * @param {String} input_sequence is assumed to be a sequence of exactly eight characters such that each character is a digit whose numeric base is input_base.
 * 
 * @return {Number} the base-ten number which input_sequence in the input_base represents; zero if an exception to normal functioning is thrown.
 */
function convert_to_decimal(input_base, input_sequence) {
    try {
        let decimal_output = 0, i = 0;
        if (!validate_input_sequence(input_base, input_sequence)) throw "input_base or input_sequence appears to be an invalid function argument.";
        for (i = 0; i < 8; i++) decimal_output += (get_decimal_value_of_hexidecimal_digit(input_sequence[i]) * compute_power(input_base, 7 - i));
        return decimal_output;
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of convert_to_decimal(input_base, input_sequence): " + exception);
        return 0;
    }
}

/**
 * Get the hexidecimal equivalent of a single decimal digit.
 * 
 * @param {Number} D is assumed to be a single base-ten digit (i.e. exactly one element within the following array: 
 *                 [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]).
 * 
 * @return {String} the element of the following array whose index in the array is D: 
 *                  ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'] if D is a valid decimal digit; 
 *                  '0' otherwise.
 */
function convert_decimal_digit_to_hexidecimal(D) {
    try {
        let hexidecimal_digit_set = "0123456789ABCDEF";
        if (arguments.length !== 1) throw "exactly one function argument is required.";
        if (typeof D !== "number") throw "D is required to be a Number type value.";
        if (Math.floor(D) !== D) throw "D is required to be a whole number.";
        if ((D < 0) || (D > 9)) "D is required to be no smaller than zero and no larger than nine.";
        return hexidecimal_digit_set[D];
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of convert_decimal_digit_to_hexidecimal(D): " + exception);
        return '0';
    }
}

/**
 * Return a string whose constituent characters are identical to the characters in S except for the fact that 
 * the output string characters are in reverse order from those in S.
 * 
 * @param {String} S is assumed to be a sequence of characters.
 * 
 * @return {String} S in reverse order.
 */
function reverse_string(S) {
    try {
        let output_string = "", i = 0;
        if (arguments.length !== 1) throw "exactly one function argument is required.";
        if (typeof S !== "string") throw "output_string is required to be a String type value.";
        for (i = (S.length - 1); i >= 0; i--) output_string += S[i];
        return output_string;
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of reverse_string(S): " + exception);
        return "ERROR";
    }
}

/**
 * Get the output_base representation of decimal_number by converting decimal_number from decimal (i.e. base-ten) to output_base.
 * 
 * @param {Number} output_base is assumed to be a base-ten integer which is no smaller than two and no larger than sixteen.
 * 
 * @param {Number} decimal_number is assumed to be a base-ten integer no smaller than zero and no larger than the following sum: 
 *                 (16 * (16 ^ 7)) + (16 * (16 ^ 6)) + (16 * (16 ^ 5)) + (16 * (16 ^ 4)) + (16 * (16 ^ 3)) + (16 * (16 ^ 2)) + (16 * (16 ^ 1)) + (16 * (16 ^ 0)) = 4581298448.
 * 
 * @return {String} a sequence of one ore more hexidecimal digits which represents the value of decimal_number in the given output_base.
 */
function convert_from_decimal(output_base, decimal_number) {
    try {
        let maximum_decimal_number_value = 0, i = 0, output_base_result = "";
        if (arguments.length !== 2) throw "exactly two function arguments are required.";
        if (typeof output_base !== "number") throw "output_base is required to be a Number type value.";
        if (typeof decimal_number !== "number") throw "decimal_number is required to be a Number type value.";
        if (Math.floor(output_base) !== output_base) throw "output_base is required to be a whole number.";
        if (Math.floor(decimal_number) !== decimal_number) throw "decimal_number is required to be a whole number.";
        if ((output_base < 2) || (output_base > 16)) throw "output_base is required to be no smaller than two and no larger than sixteen.";
        for (i = 7; i >= 0; i -= 1) maximum_decimal_number_value += (16 * compute_power(16, i));
        if ((decimal_number < 0) || (decimal_number > maximum_decimal_number_value)) throw "decimal_number is required to be larger than zero and no larger than " + maximum_decimal_number_value + ".";
        while (decimal_number > 0) {
            output_base_result += convert_decimal_digit_to_hexidecimal(decimal_number % output_base);
            decimal_number = Math.floor(decimal_number / output_base);
        }
        return reverse_string(output_base_result);
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of convert_from_decimal(output_base, decimal_number): " + exception);
        return '0';
    }
}

/**
 * Convert an INPUT_SEQUENCE (i.e. an unsigned integer consisting of no more than eight digits) 
 * whose base is INPUT_BASE to its equivalent representation as an unsigned integer whose base is OUTPUT_BASE.
 * 
 * This is the "main function" of this JavaScript file (i.e. the "macro function" which implements each of the arithmetic functions defined above).
 * 
 * @param {Number} input_base is assumed to be a base-ten integer which is no smaller than two and no larger than sixteen.
 * 
 * @param {String} input_sequence is assumed to be a sequence of exactly eight characters such that each character is a digit whose numeric base is input_base.
 * 
 * @param {Number} output_base is assumed to be a base-ten integer which is no smaller than two and no larger than sixteen.
 * 
 * @return {String} input_sequence in its output_base representation if no exception to normal functioning is thrown; "0" otherwise.
 */
function perform_base_conversion(input_base, input_sequence, output_base) {
    try {
        let decimal_number = convert_to_decimal(input_base, input_sequence);
        return convert_from_decimal(output_base, decimal_number);
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of perform_base_conversion(input_base, input_sequence, output_base): " + exception);
        return '0';
    }
}
