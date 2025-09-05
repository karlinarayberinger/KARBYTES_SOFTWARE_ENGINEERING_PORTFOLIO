/**
 * file: base_converter_interface.js
 * type: JavaScript
 * date: 10_JULY_2023
 * author: karbytes
 * license: PUBLIC_DOMAIN
 */

/**
 * Make a particular HTML element on the web page whose source code file is base_converter.html invisible (without deleting that element).
 * 
 * @param {String} element_id is assumed to be the id value of an existing HTML element on the web whose source code file is base_converter.html.
 */
function hide_page_element(element_id) {
    try {
        let web_page_element;
        if (arguments.length !== 1) throw "exactly one function argument is required.";
        if (typeof element_id !== "string") throw "element_id is required to be a String type value.";
        if (element_id.length < 1) throw "element_id is required to be a non-empty string.";
        web_page_element = document.getElementById(element_id);
        web_page_element.style.display = "none";
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of hide_page_element(element_id): " + exception);
    }
}

/**
 * Make a particular HTML element on the web page defined by base_converter.html visible rather than hidden.
 * 
 * @param {String} element_id is assumed to be the id value of an existing HTML element on the web page whos source code file is base_converter.html.
 */
function unhide_page_element(element_id) {
    try {
        let web_page_element;
        if (arguments.length !== 1) throw "exactly one function argument is required.";
        if (typeof element_id !== "string") throw "element_id is required to be a String type value.";
        if (element_id.length < 1) throw "element_id is required to be a non-empty string.";
        web_page_element = document.getElementById(element_id);
        web_page_element.style.display = "block";
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of unhide_page_element(element_id): " + exception);
    }
}

/**
 * Generate the name of a particular numeric base in the following format: "[base_name] (base-[base_number])".
 * 
 * @param {Number} cardinality_of_base is assumed to be a base-ten integer which is no smaller than two and no larger than sixteen.
 * 
 * @return {String} the inner HTML component of an option for a base select menu; undefined if an exception to normal functioning occurs.
 */
function get_numeric_base_option_label(cardinality_of_base) {
    try {
        if (arguments.length !== 1) throw "exactly one function argument is required.";
        if (typeof cardinality_of_base !== "number") throw "cardinality_of_base is required to be a Number type value.";
        if (cardinality_of_base !== Math.floor(cardinality_of_base)) throw "cardinality_of_base is required to be a whole number.";
        if ((cardinality_of_base < 2) || (cardinality_of_base > 16)) throw "cardinality_of_base is required to be no smaller than two and no larger than sixteen.";
        if (cardinality_of_base === 2) return "BINARY (base-2)";
        if (cardinality_of_base === 3) return "TERNARY (base-3)";
        if (cardinality_of_base === 4) return "QUATERNARY (base-4)";
        if (cardinality_of_base === 5) return "QUINARY (base-5)";   
        if (cardinality_of_base === 6) return "SENARY (base-6)"; 
        if (cardinality_of_base === 7) return "SEPTENARY (base-7)";  
        if (cardinality_of_base === 8) return "OCTAL (base-8)";  
        if (cardinality_of_base === 9) return "NONARY (base-9)"; 
        if (cardinality_of_base === 10) return "DECIMAL (base-10)"; 
        if (cardinality_of_base === 11) return "UNDECIMAL (base-11)"; 
        if (cardinality_of_base === 12) return "DUODECIMAL (base-12)"; 
        if (cardinality_of_base === 13) return "TRIDECIMAL (base-13)"; 
        if (cardinality_of_base === 14) return "TETRADECIMAL (base-14)";
        if (cardinality_of_base === 15) return "PENTADECIMAL (base-15)"; 
        if (cardinality_of_base === 16) return "HEXIDECIMAL (base-16)"; 
        if (true) throw "some unexpected runtime error occurred.";
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of get_numeric_base_option_label(cardinality_of_base): " + exception);
        return undefinied; 
    }
 }

/**
 * Define a select element whose options are the following natural number bases: 
 * 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16.
 * 
 * Note that the option whose value is "2" is set to be automatically selected if the application user does not click on the select menu.
 * 
 * @param {String} select_id is assumed to be the id of an existing select HTML element on the corresponding web page.
 * 
 * @return {String} an HTML string which is used to instantiate a select element whose options are the following natural number bases: 
 *                  2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16; 
 *                  undefined if an exception to normal functioning occurs.
 */
function generate_html_string_for_base_select_menu(select_id) {
    try {
        let html_string = "", option_value = 0;
        if (arguments.length !== 1) throw "exactly one function argument is required.";
        if (typeof select_id !== "string") throw "select_id is required to be a String type value.";
        if (select_id.length < 1) throw "select_id is required to be a non-empty string.";
        html_string += '<' + 'select id="' + select_id + '"' + '>';
        html_string += '<' + 'option value="2" selected' + '>' + get_numeric_base_option_label(2) + '<' + '/' + 'option' + '>';
        for (option_value = 3; option_value <= 16; option_value += 1) html_string += '<' + 'option value="' + option_value + '"' + '>' + get_numeric_base_option_label(option_value) + '<' + '/' + 'option' + '>';
        html_string += '<' + '/' + 'select' + '>';
        return html_string;
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of generate_html_string_for_base_select_menu(select_id): " + exception);
        return undefined;
    }
 }

 /**
 * Return the value of the selected menu option of a select menu element.
 * 
 * @param {String} select_menu_identifier is assumed to be the id of an existing select HTML element on the corresponding web page.
 * 
 * @return {String} the value of the selected menu option; undefined if an exception to normal functioning occurs.
 */
function get_selected_menu_option_value(select_menu_identifier) {
    try {
        let menu_object = {}, options_array = [], selected_option_index = 0, selected_option_object = {}, selected_option_value;
        menu_object = document.getElementById(select_menu_identifier);
        options_array = menu_object.options;
        selected_option_index = menu_object.selectedIndex;
        selected_option_object = options_array[selected_option_index];
        selected_option_value = selected_option_object.value
        return selected_option_value;
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of get_selected_menu_option(select_menu_identifier): " + exception);
        return undefined;
    }
}

/**
 * Generate the digit key buttons which are used to enter digits whose base is cardinality_of_base.
 * 
 * For example, if cardinality_of_base is 16, then all sixteen digit key buttons will be generated.
 * 
 * By contrast, if cardinality_of_base is 10, then only the first ten of sixteen digit key buttons will be generated.
 * 
 * The digit key buttons are arranged vertically in descending order (where each digit button is encapsulated inside of its own paragraph element).
 * 
 * @param {Number} cardinality_of_base is assumed to be a base-ten integer which is no smaller than two and no larger than sixteen.
 * 
 * @return {String} the HTML string which is used to substantiate the content of the div element whose id is "input_sequence_digit_keys_div"; 
 *                  undefined if an exception to normal functioning occurs. 
 */
function generate_html_string_for_input_sequence_digit_buttons(cardinality_of_base) {
    try {
        let html_string = "", p0 = '<' + 'p' + '>', p1 = '<' + '/' + 'p' + '>', i = 0, hexidecimal_digit_set = "0123456789ABCDEF";
        if (arguments.length !== 1) throw "exactly one function argument is required.";
        if (typeof cardinality_of_base !== "number") throw "cardinality_of_base is required to be a Number type value.";
        if (cardinality_of_base !== Math.floor(cardinality_of_base)) throw "cardinality_of_base is required to be a whole number.";
        if ((cardinality_of_base < 2) || (cardinality_of_base > 16)) throw "cardinality_of_base is required to be no smaller than two and no larger than sixteen.";
        for (i = 0; i < cardinality_of_base; i += 1) html_string += p0 + '<' + 'input type="button" value="' + hexidecimal_digit_set[i] + '" onclick="append_digit_' + hexidecimal_digit_set[i] + '()"' + '>' + p1;
        return html_string;
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of generate_html_string_for_input_sequence_digit_buttons(cardinality_of_base): " + exception);
        return undefined;   
    }
}

/**
 * Determine whether or not hexidecimal_digit is an element of the following set: 
 * ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' ].
 * 
 * @param {String} hexidecimal_digit is assumed to be an element of the following set: 
 *                 ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' ].
 * 
 * @return {Boolean} true if hexidecimal is a valid hexidecimal digit as defined above; false otherwise.
 */
function is_valid_hexidecimal_digit(hexidecimal_digit) {
    try {
        let i = 0, hexidecimal_digit_set = "0123456789ABCDEF";
        if (arguments.length !== 1) throw "exactly one function argument is required.";
        if (typeof hexidecimal_digit !== "string") throw "hexidecimal_digit is required to be a String type value.";
        if (hexidecimal_digit.length !== 1) throw "hexidecimal_digit is required to have a length of exactly one character.";
        for (i = 0; i < 16; i += 1) if (hexidecimal_digit === hexidecimal_digit_set[i]) return true;
        return false;
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of is_valid_hexidecimal_digit(hexidecimal_digit): " + exception);
        return false;
    }
}

/**
 * Remove the leftmost character from the inner HTML string of the span HTML element whose id is "input_sequence_span".
 * 
 * Append hexidecimal_digit to right end of that string (such that the total number of characters enclosed by the input sequence span is always eight).
 * 
 * @param {String} hexidecimal_digit is assumed to be an element of the following set: 
 *                 ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' ].
 */
function append_digit(hexidecimal_digit) {
    try {
        let i = 0, input_sequence_span, old_input_sequence = "", new_input_sequence = "";
        if (!is_valid_hexidecimal_digit(hexidecimal_digit)) throw "hexidecimal_digit is required to be an element of the following set: ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' ].";
        input_sequence_span = document.getElementById("input_sequence_span");
        old_input_sequence = input_sequence_span.innerHTML;
        for (i = 1; i < 8; i += 1) new_input_sequence += old_input_sequence[i];
        new_input_sequence += hexidecimal_digit;
        input_sequence_span.innerHTML = new_input_sequence;
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of append_digit_1(): " + exception);
    }
}

/**
 * Remove the leftmost character from the inner HTML string of the span HTML element whose id is "input_sequence_span".
 * 
 * Append '0' to right end of that string (such that the total number of characters enclosed by the input sequence span is always eight).
 */
function append_digit_0() {
    append_digit('0');
}

/**
 * Remove the leftmost character from the inner HTML string of the span HTML element whose id is "input_sequence_span".
 * 
 * Append '1' to right end of that string (such that the total number of characters enclosed by the input sequence span is always eight).
 */
function append_digit_1() {
    append_digit('1');
}

/**
 * Remove the leftmost character from the inner HTML string of the span HTML element whose id is "input_sequence_span".
 * 
 * Append '2' to right end of that string (such that the total number of characters enclosed by the input sequence span is always eight).
 */
function append_digit_2() {
    append_digit('2');
}

/**
 * Remove the leftmost character from the inner HTML string of the span HTML element whose id is "input_sequence_span".
 * 
 * Append '3' to right end of that string (such that the total number of characters enclosed by the input sequence span is always eight).
 */
function append_digit_3() {
    append_digit('3');
}

/**
 * Remove the leftmost character from the inner HTML string of the span HTML element whose id is "input_sequence_span".
 * 
 * Append '4' to right end of that string (such that the total number of characters enclosed by the input sequence span is always eight).
 */
function append_digit_4() {
    append_digit('4');
}

/**
 * Remove the leftmost character from the inner HTML string of the span HTML element whose id is "input_sequence_span".
 * 
 * Append '5' to right end of that string (such that the total number of characters enclosed by the input sequence span is always eight).
 */
function append_digit_5() {
    append_digit('5');
}

/**
 * Remove the leftmost character from the inner HTML string of the span HTML element whose id is "input_sequence_span".
 * 
 * Append '6' to right end of that string (such that the total number of characters enclosed by the input sequence span is always eight).
 */
function append_digit_6() {
    append_digit('6');
}

/**
 * Remove the leftmost character from the inner HTML string of the span HTML element whose id is "input_sequence_span".
 * 
 * Append '7' to right end of that string (such that the total number of characters enclosed by the input sequence span is always eight).
 */
function append_digit_7() {
    append_digit('7');
}

/**
 * Remove the leftmost character from the inner HTML string of the span HTML element whose id is "input_sequence_span".
 * 
 * Append '8' to right end of that string (such that the total number of characters enclosed by the input sequence span is always eight).
 */
function append_digit_8() {
    append_digit('8');
}

/**
 * Remove the leftmost character from the inner HTML string of the span HTML element whose id is "input_sequence_span".
 * 
 * Append '9' to right end of that string (such that the total number of characters enclosed by the input sequence span is always eight).
 */
function append_digit_9() {
    append_digit('9');
}

/**
 * Remove the leftmost character from the inner HTML string of the span HTML element whose id is "input_sequence_span".
 * 
 * Append 'A' to right end of that string (such that the total number of characters enclosed by the input sequence span is always eight).
 */
function append_digit_A() {
    append_digit('A');
}

/**
 * Remove the leftmost character from the inner HTML string of the span HTML element whose id is "input_sequence_span".
 * 
 * Append 'B' to right end of that string (such that the total number of characters enclosed by the input sequence span is always eight).
 */
function append_digit_B() {
    append_digit('B');
}

/**
 * Remove the leftmost character from the inner HTML string of the span HTML element whose id is "input_sequence_span".
 * 
 * Append 'C' to right end of that string (such that the total number of characters enclosed by the input sequence span is always eight).
 */
function append_digit_C() {
    append_digit('C');
}

/**
 * Remove the leftmost character from the inner HTML string of the span HTML element whose id is "input_sequence_span".
 * 
 * Append 'D' to right end of that string (such that the total number of characters enclosed by the input sequence span is always eight).
 */
function append_digit_D() {
    append_digit('D');
}

/**
 * Remove the leftmost character from the inner HTML string of the span HTML element whose id is "input_sequence_span".
 * 
 * Append 'E' to right end of that string (such that the total number of characters enclosed by the input sequence span is always eight).
 */
function append_digit_E() {
    append_digit('E');
}

/**
 * Remove the leftmost character from the inner HTML string of the span HTML element whose id is "input_sequence_span".
 * 
 * Append 'F' to right end of that string (such that the total number of characters enclosed by the input sequence span is always eight).
 */
function append_digit_F() {
    append_digit('F');
}

/**
 * Set the content displayed inside of the span HTML element whose id is "input_sequence_span" to "00000000".
 */
function initialize_input_sequence_span() {
    try {
        document.getElementById("input_sequence_span").innerHTML = "00000000";
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of initialize_input_sequence_span(): " + exception);
    }
}

/**
 * Set the inner HTML of the span element whose id is "input_sequence_span_2" and 
 * "input_sequence_span_3" to the inner HTML of the span element whose id is "input_sequence_span".
 */
function update_input_sequence_span() {
    try {
        let input_sequence_span, input_sequence_span_2, input_sequence_span_3;
        input_sequence_span = document.getElementById("input_sequence_span");
        input_sequence_span_2 = document.getElementById("input_sequence_span_2");
        input_sequence_span_3 = document.getElementById("input_sequence_span_3");
        input_sequence_span_2.innerHTML = input_sequence_span.innerHTML;
        input_sequence_span_3.innerHTML = input_sequence_span.innerHTML;
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of update_input_sequence_span_2(): " + exception);
    }
}

/**
 * Set the content displayed inside of 
 * the span element whose id is "input_base_span", 
 * the span element whose id is "input_base_span_2", and 
 * the span element whose id is "input_base_span_3" to the 
 * input base option which is currently selected from the list of options 
 * displayed inside the select HTML element whose id is "input_base_menu".
 */
function update_input_base_span() {
    try {
        let input_base_value = 0, input_base_span, input_base_span_2, input_base_span_3;
        input_base_span = document.getElementById("input_base_span");
        input_base_span_2 = document.getElementById("input_base_span_2");
        input_base_span_3 = document.getElementById("input_base_span_3");
        input_base_value = get_selected_menu_option_value("input_base_menu");
        input_base_span.innerHTML = input_base_value;
        input_base_span_2.innerHTML = input_base_value;
        input_base_span_3.innerHTML = input_base_value;
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of update_input_base_span(): " + exception);
    }
}

/**
 * Set the content displayed inside of the HTML element whose id is "digit_buttons_div" 
 * to display the digit buttons which correspond with the input base option 
 * which is currently selected from the list of options displayed inside the select HTML element whose id is "input_base_menu".
 */
function update_digit_buttons_div() {
    try {
        let input_base_value = 0, digit_buttons_div, digit_buttons_for_selected_base;
        digit_buttons_div = document.getElementById("digit_buttons_div");
        input_base_value = parseInt(get_selected_menu_option_value("input_base_menu"));
        digit_buttons_for_selected_base = generate_html_string_for_input_sequence_digit_buttons(input_base_value);
        digit_buttons_div.innerHTML = digit_buttons_for_selected_base;
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of update_input_base_span(): " + exception);
    }
}

/**
 * Set the content displayed inside of the span element whose id is "output_base_span_2" 
 * to the output base option which is currently selected from the list of options displayed 
 * inside the select HTML element whose id is "output_base_menu".
 */
function update_output_base_span_2() {
    try {
        let output_base_value = 0, output_base_span_2;
        output_base_span_2 = document.getElementById("output_base_span_2");
        output_base_value = get_selected_menu_option_value("output_base_menu");
        output_base_span_2.innerHTML = output_base_value;
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of update_output_base_span_2(): " + exception);
    }
}

/**
 * Progress from STEP_0 to STEP_1 of the base converter application's input form (which is substantiated using the web page file named base_converter.html).
 * 
 * Assume that this function is called in response to the event of a button click of the NEXT button displayed inside of the div whose id is "step_0_div".
 * 
 * Submit the input base option which is currently selected from the list of options displayed inside the select HTML element whose id is "input_base_menu".
 * 
 * Display the digit buttons which correspond with the selected input base in the next step.
 * 
 * Append a time stamped message to the bottom of the web page indicating that this function was called.
 */
function step_0_next() {
    const time_stamp = generate_time_stamp(), p0 = '<' + 'p' + '>', p1 = '<' + '/' + 'p' + '>';
    let message = "step_0_next() was called at time: " + time_stamp;
    console.log(message);
    document.getElementById("time_stamped_messages").innerHTML += p0 + message + p1;
    update_input_base_span();
    update_digit_buttons_div();
    hide_page_element("step_0_div");
    unhide_page_element("step_1_div");
}

/**
 * Regress from STEP_1 to STEP_0 of the base converter application's input form (which is substantiated using the web page file named base_converter.html).
 * 
 * Assume that this function is called in response to the event of a button click of the BACK button displayed inside of the div whose id is "step_1_div".
 * 
 * Reset the text displayed inside of the span element whose id is "input_sequence_span" to its initial state: 00000000.
 * 
 * Append a time stamped message to the bottom of the web page indicating that this function was called.
 */
function step_1_back() {
    const time_stamp = generate_time_stamp(), p0 = '<' + 'p' + '>', p1 = '<' + '/' + 'p' + '>';
    let message = "step_1_back() was called at time: " + time_stamp;
    console.log(message);
    document.getElementById("time_stamped_messages").innerHTML += p0 + message + p1;
    initialize_input_sequence_span();
    hide_page_element("step_1_div");
    unhide_page_element("step_0_div");
}

/**
 * Progress from STEP_1 to STEP_2 of the base converter application's input form (which is substantiated using the web page file named base_converter.html).
 * 
 * Assume that this function is called in response to the event of a button click of the NEXT button displayed inside of the div whose id is "step_1_div".
 * 
 * Update the input base and input sequence displays inside of the STEP_2 div.
 * 
 * Append a time stamped message to the bottom of the web page indicating that this function was called.
 */
function step_1_next() {
    const time_stamp = generate_time_stamp(), p0 = '<' + 'p' + '>', p1 = '<' + '/' + 'p' + '>';
    let message = "step_1_next() was called at time: " + time_stamp;
    console.log(message);
    document.getElementById("time_stamped_messages").innerHTML += p0 + message + p1;
    update_input_sequence_span();
    hide_page_element("step_1_div");
    unhide_page_element("step_2_div");
}

/**
 * Regress from STEP_2 to STEP_1 of the base converter application's input form (which is substantiated using the web page file named base_converter.html).
 * 
 * Assume that this function is called in response to the event of a button click of the BACK button displayed inside of the div whose id is "step_2_div".
 * 
 * Append a time stamped message to the bottom of the web page indicating that this function was called.
 */
function step_2_back() {
    const time_stamp = generate_time_stamp(), p0 = '<' + 'p' + '>', p1 = '<' + '/' + 'p' + '>';
    let message = "step_2_back() was called at time: " + time_stamp;
    console.log(message);
    document.getElementById("time_stamped_messages").innerHTML += p0 + message + p1;
    initialize_input_sequence_span();
    hide_page_element("step_2_div");
    unhide_page_element("step_1_div");
}

/**
 * Progress from STEP_2 to STEP_3 of the base converter application's input form (which is substantiated using the web page file named base_converter.html).
 * 
 * Assume that this function is called in response to the event of a button click of the NEXT button displayed inside of the div whose id is "step_2_div".
 * 
 * Submit the output base option which is currently selected from the list of options displayed inside the select HTML element whose id is "input_base_menu".
 * 
 * Update the input_base, input_sequence, and output_base values which are displayed inside the STEP_3 div.
 * 
 * Append a time stamped message to the bottom of the web page indicating that this function was called.
 */
function step_2_next() {
    const time_stamp = generate_time_stamp(), p0 = '<' + 'p' + '>', p1 = '<' + '/' + 'p' + '>';
    let message = "step_2_next() was called at time: " + time_stamp;
    console.log(message);
    document.getElementById("time_stamped_messages").innerHTML += p0 + message + p1;
    update_output_base_span_2();
    hide_page_element("step_2_div");
    unhide_page_element("step_3_div");
}

/**
 * Regress from STEP_3 to STEP_2 of the base converter application's input form (which is substantiated using the web page file named base_converter.html).
 * 
 * Assume that this function is called in response to the event of a button click of the BACK button displayed inside of the div whose id is "step_3_div".
 * 
 * Reset the text displayed inside of the div element whose id is "output" to its initial state: "This sentence will be replaced with base conversion results when the CONVERT button is clicked."
 * 
 * Append a time stamped message to the bottom of the web page indicating that this function was called.
 */
function step_3_back() {
    const time_stamp = generate_time_stamp(), p0 = '<' + 'p' + '>', p1 = '<' + '/' + 'p' + '>';
    let message = "step_3_back() was called at time: " + time_stamp;
    console.log(message);
    document.getElementById("time_stamped_messages").innerHTML += p0 + message + p1;
    initialize_output_div();
    hide_page_element("step_3_div");
    unhide_page_element("step_2_div");
}

/**
 * Define the application interface component (to be displayed on the web page whose source code file is base_converter.html) 
 * which enables the user to select an INPUT_BASE.
 * 
 * @return {String} an HTML string which is used to instantiate a DIV page element whose id is "step_0_div".
 */
function generate_html_string_for_step_0_div() {
    let html_string = '<' + 'div class="module input_step" id="step_0_div"' + '>', p0 = '<' + 'p' + '>', p1 ='<' + '/' + 'p' + '>';
    html_string += p0 + "STEP_0: Select an INPUT_BASE from the expandable menu. Then click the NEXT button to proceed to the INPUT_SEQUENCE step." + p1;
    html_string += p0 + "INPUT_BASE := " + generate_html_string_for_base_select_menu("input_base_menu") + p1;
    html_string += p0 + '<' + 'input type="button" value="NEXT" onclick="step_0_next()"' + '>';
    html_string += '<' + '/' + 'div' + '>';
    return html_string;
}

/**
 * Define the application interface component (to be displayed on the web page whose source code file is base_converter.html) 
 * which enables the user to enter an INPUT_SEQUENCE.
 * 
 * @return {String} an HTML string which is used to instantiate a DIV page element whose id is "step_1_div".
 */
function generate_html_string_for_step_1_div() {
    let html_string = '<' + 'div class="module input_step" id="step_1_div"' + '>', p0 = '<' + 'p' + '>', p1 = '<' + '/' + 'p' + '>', input_sequence_span;
    input_base_value = get_selected_menu_option_value("input_base_menu");
    html_string += p0 + "STEP_1: Use the digit keys to enter no more than eight digits. Then click the NEXT button to proceed to the INPUT_SEQUENCE step. To re-select the INPUT_BASE, click the BACK button." + p1;
    html_string += p0 + "INPUT_BASE := " + '<' + 'span style="background:#000000;color:#ffff00" id="input_base_span"' + '>' + input_base_value + '<' + '/' + 'span' + '>' + p1;
    html_string += p0 + "INPUT_SEQUENCE := " + '<' + 'span style="background:#000000;color:#ffff00" id="input_sequence_span"' + '>' + "00000000" + '<' + '/' + 'span' + '>' + p1;
    html_string += '<' + 'div id="digit_buttons_div"' + '>' + generate_html_string_for_input_sequence_digit_buttons(parseInt(input_base_value)) + '<' + '/' + 'div' + '>';
    html_string += p0 + '<' + 'input type="button" value="BACK" onclick="step_1_back()"' + '>';
    html_string += " " + '<' + 'input type="button" value="NEXT" onclick="step_1_next()"' + '>' + p1;
    html_string += '<' + '/' + 'div' + '>';
    return html_string;
}

/**
 * Define the application interface component (to be displayed on the web page whose source code file is base_converter.html) 
 * which enables the user to review input values before initiating the base conversion.
 * 
 * @return {String} an HTML string which is used to instantiate a DIV page element whose id is "step_2_div".
 */
function generate_html_string_for_step_2_div() {
    let html_string = '<' + 'div class="module input_step" id="step_2_div"' + '>', p0 = '<' + 'p' + '>', p1 ='<' + '/' + 'p' + '>';
    html_string += p0 + "STEP_2: Select an OUTPUT_BASE from the expandable menu. Then click the NEXT button to proceed to the BASE_CONVERSION step. To re-enter the INPUT_SEQUENCE, click the BACK button." + p1;
    html_string += p0 + "INPUT_BASE := " + '<' + 'span style="background:#000000;color:#ffff00" id="input_base_span_2"' + '>' + "???" + '<' + '/' + 'span' + '>' + p1;
    html_string += p0 + "INPUT_SEQUENCE := " + '<' + 'span style="background:#000000;color:#ffff00" id="input_sequence_span_2"' + '>' + "???" + '<' + '/' + 'span' + '>' + p1;
    html_string += p0 + "OUTPUT_BASE := " + '<' + 'span style="background:#000000;color:#ffff00" id="output_base_span"' + '>' + generate_html_string_for_base_select_menu("output_base_menu") + '<' + '/' + 'span' + '>' + p1;
    html_string += p0 + '<' + 'input type="button" value="BACK" onclick="step_2_back()"' + '>';
    html_string += " " + '<' + 'input type="button" value="NEXT" onclick="step_2_next()"' + '>' + p1;
    html_string += '<' + '/' + 'div' + '>';
    return html_string;    
}

/**
 * Define the application interface component (to be displayed on the web page whose source code file is base_converter.html) 
 * which enables the user to click the CONVERT button.
 * 
 * @return {String} an HTML string which is used to instantiate a DIV page element whose id is "step_3_div".
 */
function generate_html_string_for_step_3_div() {
    let html_string = '<' + 'div class="module input_step" id="step_3_div"' + '>', p0 = '<' + 'p' + '>', p1 ='<' + '/' + 'p' + '>';
    html_string += p0 + "STEP_3: Click the CONVERT button to convert INPUT_SEQUENCE to its OUTPUT_BASE representation. To re-select the OUTPUT_BASE, click the BACK button." + p1;
    html_string += p0 + "INPUT_BASE := " + '<' + 'span style="background:#000000;color:#ffff00" id="input_base_span_3"' + '>' + "???" + '<' + '/' + 'span' + '>' + p1;
    html_string += p0 + "INPUT_SEQUENCE := " + '<' + 'span style="background:#000000;color:#ffff00" id="input_sequence_span_3"' + '>' + "???" + '<' + '/' + 'span' + '>' + p1;
    html_string += p0 + "OUTPUT_BASE := " + '<' + 'span style="background:#000000;color:#ffff00" id="output_base_span_2"' + '>' + "???" + '<' + '/' + 'span' + '>' + p1;
    html_string += p0 + '<' + 'input type="button" value="BACK" onclick="step_3_back()"' + '>';
    html_string += " " + '<' + 'input type="button" value="CONVERT" onclick="convert()"' + '>' + p1;
    html_string += '<' + '/' + 'div' + '>';
    return html_string;
}

/**
 * Set the content displayed inside of the div HTML element whose id is "output" to its initial placeholder text.
 */
function initialize_output_div() {
    try {
        let p0 = '<' + 'p class="module output_step"' + '>', p1 = '<' + '/' + 'p' + '>';
        document.getElementById("output").innerHTML = p0 + "This sentence will be replaced with base conversion results when the CONVERT button is clicked." + p1;
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of initialize_output_div(): " + exception);
    }
}

/**
 * Set the web page interface (i.e. base_converter.html) to its intial state.
 * 
 * Assume that this function is called in response the event of the web page being loaed by the web browser.
 */
function initialize_application() {
    try {
        const time_stamp = generate_time_stamp(), p0 = '<' + 'p' + '>', p1 = '<' + '/' + 'p' + '>';
        let message = "The web page, base_converter.html, was loaded at time: " + time_stamp;
        let input_form_div = undefined;
        console.log(message);
        document.getElementById("time_stamped_messages").innerHTML = p0 + message + p1;
        input_form_div = document.getElementById("input_form");
        initialize_output_div();
        input_form_div.innerHTML = generate_html_string_for_step_0_div();
        input_form_div.innerHTML += generate_html_string_for_step_1_div();
        input_form_div.innerHTML += generate_html_string_for_step_2_div();
        input_form_div.innerHTML += generate_html_string_for_step_3_div();
        hide_page_element("step_1_div");
        hide_page_element("step_2_div");
        hide_page_element("step_3_div");
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of initialize_application(): " + exception);
    }
}

/**
 * Perform the base converion using the input values which were submitted by the application user via the web page interface.
 * 
 * Convert an INPUT_SEQUENCE (i.e. an unsigned integer consisting of no more than eight digits) 
 * whose base is INPUT_BASE to its equivalent representation as an unsigned integer whose base is OUTPUT_BASE.
 * 
 * Append a time stamped message to the bottom of the web page indicating that this function was called.
 */
function convert() {
    try {
        const time_stamp = generate_time_stamp();
        let message = "convert() was called at time: " + time_stamp;
        let INPUT_BASE = 0, INPUT_SEQUENCE = "", OUTPUT_BASE = 0, OUTPUT_SEQUENCE = "";
        let  p00 = '<' + 'p class="module" style="border-color: #00ffff; border-width: 1px;border-style: solid;"' + '>', p0 = '<' + 'p' + '>', p1 = '<' + '/' + 'p' + '>';
        console.log(message);
        document.getElementById("time_stamped_messages").innerHTML += p0 + message + p1;
        INPUT_BASE = parseInt(document.getElementById("input_base_span").innerHTML);
        INPUT_SEQUENCE = document.getElementById("input_sequence_span").innerHTML;
        OUTPUT_BASE = parseInt(document.getElementById("output_base_span_2").innerHTML);
        OUTPUT_SEQUENCE = perform_base_conversion(INPUT_BASE, INPUT_SEQUENCE, OUTPUT_BASE);
        document.getElementById("output").innerHTML = p00 + INPUT_SEQUENCE + " (in base-" + INPUT_BASE + ") is equal to " + OUTPUT_SEQUENCE + " (in base-" + OUTPUT_BASE + ")." + p1
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of convert(): " + exception); 
    }
}
