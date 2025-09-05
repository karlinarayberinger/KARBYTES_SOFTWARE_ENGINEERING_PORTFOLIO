/**
 * file: word_counter.js
 * type: JavaScript
 * date: 10_JULY_2023
 * author: karbytes
 * license: PUBLIC_DOMAIN
 */

/**
 * Get the Number of milliseconds which have elapsed since the Unix Epoch.
 * 
 * The Unix Epoch is 01_JANUARY_1970 at midnight (Coordinated Universal Time (UTC)).
 * 
 * @return {String} message displaying the time at which this function was called.
 */
function generate_time_stamp() {
    const milliseconds_elapsed_since_unix_epoch = Date.now();
    return milliseconds_elapsed_since_unix_epoch + " milliseconds since midnight on 01_JANUARY_1970.";
}

/**
 * Determine whether or not T is a valid word separator token (i.e. delimiter).
 * 
 * If T is not a valid delimiter, then T is assumed to be a character within a word.
 * 
 * A word is a sequence of some natural number of non-delimiter text characters.
 * 
 * @param {String} T is assumed to be exactly one text character (i.e. a String whose length is one).
 * 
 * @return {Boolean} true if T is a valid delimiter; false otherwise.
 */
function is_delimiter(T) {
    try {
        let D = [' ', '.', ',', '"', '?', '!', ';'], i = 0;
        if (arguments.length !== 1) throw "Exactly one function argument is required.";
        if (typeof T !== "string") throw "T must be a string type value.";
        if (T.length !== 1) throw "T must have a length property whose value is exactly 1.";
        for (i = 0; i < D.length; i += 1) if (T === D[i]) return true;
        return false;
    }
    catch(e) {
        console.log("An exception to normal functioning occurred during the runtime of is_delimiter(T): " + e);
        return false;
    }
}

/**
 * Create an array whose elements are the words which occur in the input string S.
 * 
 * The first element of the output array is the first word in S.
 * 
 * The last element of the output array is the last word in S.
 * 
 * Each the element of the output array is listed in the same order as its corresponding word occurs in S.
 * 
 * A word is a sequence of some natural number of non-delimiter text characters.
 * 
 * Words are separated by delimiter characters.
 * 
 * If there are only delimiter characters in S, then return an empty array.
 * 
 * @param {String} S is assumed to be a string comprised of some natural number of text characters.
 * 
 * @return {Object} an array of zero or more string type values.
 */
function get_words(S) {
    try {
        let words_array = [], word = '', i = 0;
        if (arguments.length !== 1) throw "Exactly one function argument is required.";
        if (typeof S !== "string") throw "S must be a string type value.";
        if ((S.length < 1) || (S.length !== Math.floor(S.length))) throw "S must have a length property whose value is a natural number.";
        for (i = 0; i < S.length; i += 1) {
            if (!is_delimiter(S[i])) word += S[i];
            if (is_delimiter(S[i]) && (word.length !== 0)) {
                words_array.push(word);
                word = '';
            }
            if ((i === (S.length - 1)) && (word.length !== 0)) words_array.push(word);
        }
        if (words_array.length === 0) throw "S appears to only contain delimiters. Hence, an empty array is returned.";
        return words_array;
    }
    catch(e) {
        console.log("An exception to normal functioning occurred during the runtime of function get_words(S): " + e);
        return [];
    }
}

/**
 * Create an array whose elements are the unique words occurring in the input string S.
 * 
 * The first element of the output array is the first word in S.
 * 
 * If there are only delimiter characters in S, then return an empty array.
 * 
 * Each element of the returned array is unique with respect to every other element of that array.
 * In other words, each element of the returned array occurs exactly one time throughout that array.
 * 
 * @param {String} S is assumed to be a string comprised of some natural number text characters.
 * 
 * @return {Object} an array of zero or more string type values.
 */
function get_unique_words(S) {
    try {
        let all_words_array = [], unique_words_array = [], i = 0, k = 0, duplicate_word_found = false;
        if (arguments.length !== 1) throw "Exactly one function argument is required.";
        if (typeof S !== "string") throw "S must be a string type value.";
        if ((S.length < 1) || (S.length !== Math.floor(S.length))) throw "S must have a length property whose value is a natural number.";
        all_words_array = get_words(S);
        if (all_words_array.length === 0) throw "S appears to only contain delimiters. Hence, an empty array is returned.";
        unique_words_array.push(all_words_array[0]);
        for (i = 0; i < all_words_array.length; i += 1) {
            for (k = 0; k < unique_words_array.length; k += 1) {
                if (all_words_array[i] === unique_words_array[k]) duplicate_word_found = true;
            }
            if (!duplicate_word_found) unique_words_array.push(all_words_array[i]);
            duplicate_word_found = false;
        }
        return unique_words_array;
    }
    catch(e) {
        console.log("An exception to normal functioning occurred during the runtime of get_unique_words(S): " + e);
        return [];
    }
}

/**
 * Create an array whose elements are objects consisting of the following key-value pairs:
 * 
 * - unique_word: a string representing exactly one element of the array returned by get_unique_words(S).
 * 
 * - unique_word_frequency: a nonnegative integer representing the number of times unique_word occurs as a value in the array returned by get_words(S).
 * 
 * If there are only delimiter characters in S, then return an empty array.
 * 
 * Arrange the output array in descending order in terms of unique_word_frequency values for each of the array elements using the Bubble Sort algorithm.
 * In other words, set the first element of the returned array to be the key-value pair associated with the most frequent word which occurs in S.
 * 
 * @param {String} S is assumed to be a string comprised of some natural number of text characters.
 * 
 * @return {Object} an array of zero or more object type values.
 */
function get_unique_word_counts(S) {
    try {
        let all_words_array = [], unique_words_array = [], unique_words_and_frequencies_array = [], i = 0, k = 0, placeholder = {}, adjacent_elements_were_swapped = false, array_is_sorted = false;
        if (arguments.length !== 1) throw "Exactly one argument is required.";
        if (typeof S !== "string") throw "S must be a string type value.";
        if ((S.length < 1) || (S.length !== Math.floor(S.length))) throw "S must have a length property whose value is a natural number.";
        all_words_array = get_words(S);
        if (all_words_array.length === 0) throw "S appears to only contain delimiters. Hence, an empty array is returned.";
        unique_words_array = get_unique_words(S);
        for (i = 0; i < unique_words_array.length; i += 1) unique_words_and_frequencies_array.push({unique_word:unique_words_array[i],unique_word_frequency:0});
        for (i = 0; i < unique_words_array.length; i += 1) for (k = 0; k < all_words_array.length; k += 1) if (unique_words_array[i] === all_words_array[k]) unique_words_and_frequencies_array[i].unique_word_frequency += 1;
        if (unique_words_and_frequencies_array.length === 1) return unique_words_and_frequencies_array;
        while (!array_is_sorted) {
            for (i = 1; i < unique_words_and_frequencies_array.length; i += 1) {
                if (unique_words_and_frequencies_array[i].unique_word_frequency > unique_words_and_frequencies_array[i - 1].unique_word_frequency) {
                    placeholder = unique_words_and_frequencies_array[i];
                    unique_words_and_frequencies_array[i] = unique_words_and_frequencies_array[i - 1];
                    unique_words_and_frequencies_array[i - 1] = placeholder;
                    adjacent_elements_were_swapped = true;
                }
            }
            if (!adjacent_elements_were_swapped) array_is_sorted = true;
            adjacent_elements_were_swapped = false;
        }
        return unique_words_and_frequencies_array;
    }
    catch(e) {
        console.log("An exception to normal functioning occurred during the runtime of get_unique_word_counts(S): " + e);
        return [];
    }
}

/**
 * Populate the DIV whose id is "output" with program results:
 * 
 *       1. A read-only copy of S (i.e. the input string).
 * 
 *       2. The total number of characters in S (including delimiters).
 * 
 *       3. The total number of words in S.
 * 
 *       4. A list of each word in S.
 * 
 *       5. The total number of unique words in S.
 * 
 *       6. A list of each unique word in S.
 * 
 *       7. The total number of rows in the table which displays the frequency of each unique word (listed in descending order of frequency).
 * 
 *       8. A table showing the count for each unique word in S.
 */
function print_results() {
    try {
        let output_div, input_text_field, S_string = '', all_words_array = [], unique_words_array = [], unique_words_and_frequencies_array = [], p0 = ('<' + 'p' + '>'), p1 = ('<' + '/' + 'p' + '>'), p0_green = ('<' + 'p class="console"' + '>'), i = 0;
        output_div = document.getElementById("output");
        input_text_field = document.getElementById("S_field");
        S_string = input_text_field.value;
        all_words_array = get_words(S_string);
        unique_words_array = get_unique_words(S_string);
        unique_words_and_frequencies_array = get_unique_word_counts(S_string);
        output_div.innerHTML = (p0 + "WORD COUNTER RESULTS" + p1);
        output_div.innerHTML += (p0 + "1. S (input string): " + p1 + p0_green + S_string + p1);
        output_div.innerHTML += (p0 + "2. S length: " + S_string.length + " characters total" + p1);
        output_div.innerHTML += (p0 + "3. S word count: " + all_words_array.length + " words total" + p1);
        output_div.innerHTML += (p0 + "4. All words in S: " + p1);
        for (i = 0; i < all_words_array.length; i += 1) output_div.innerHTML += (p0_green + all_words_array[i] + p1);
        output_div.innerHTML += (p0 + "5. Number of unique words in S: " + unique_words_array.length + p1);
        output_div.innerHTML += (p0 + "6. All unique words in S: " + p1);
        for (i = 0; i < unique_words_array.length; i += 1) output_div.innerHTML += (p0_green + unique_words_array[i] + p1);
        output_div.innerHTML += (p0 + "7. Number of rows in the table of unique words and their respective frequencies: " + unique_words_and_frequencies_array.length + p1);
        for (i = 0; i < unique_words_and_frequencies_array.length; i += 1) output_div.innerHTML += (p0_green + unique_words_and_frequencies_array[i].unique_word + " (" + unique_words_and_frequencies_array[i].unique_word_frequency  + ")" + p1);
        output_div.innerHTML += (p0 + "END OF WORD COUNTER RESULTS" + p1);
    }
    catch(e) {
        console.log("Runtime exception occurred in function print_results(): " + e);
    }
}

/**
 * Append a time-stamped message to the bottom of the web page indicating that the RESET button was clicked or that the web page was opened or else refreshed by the web browser.
 * 
 * Clear the input text field (the textarea HTML element whose id is "S_field").
 * 
 * Set the input text field to visible rather than to hidden.
 * 
 * Set the SUBMIT button to visible rather than to hidden.
 * 
 * Set the RESET button to hidden rather than visible.
 * 
 * Set the inner HTML of the DIV element whose id is "output" to some placeholder sentence.
 */
function initialize_page() {
    try {
        const time_stamped_message = "The initialize_page() function was called at time: " + generate_time_stamp(), p0 = ('<' + 'p' + '>'), p1 = ('<' + '/' + 'p' + '>');
        console.log(time_stamped_message);
        document.getElementById("time_stamped_messages").innerHTML = p0 + time_stamped_message + p1;
        document.getElementById("S_field").value = '';
        document.getElementById("S_field_display").style.display = "block";
        document.getElementById("submit_button").style.display = "block";
        document.getElementById("reset_button").style.display = "none";
        document.getElementById("output").innerHTML = (p0 + "This sentence will disappear in response to the event of a SUBMIT button click." + p1);
    }
    catch(e) {
        console.log("An exception to normal functioning occurred during the runtime of function initialize_page(): " + e);
    }
}

/**
 * Append a time-stamped message to the bottom of the web page indicating that the SUBMIT button was clicked.
 * 
 * Hide the input text field.
 * 
 * Hide the SUBMIT button.
 * 
 * Display the RESET button.
 * 
 * Set the inner HTML of the DIV element whose id is "output" to the word count statistics generated by analyzing input string S.
 */
function submit() {
    try {
        const time_stamped_message = "The submit() function was called at time: " + generate_time_stamp(), p0 = ('<' + 'p' + '>'), p1 = ('<' + '/' + 'p' + '>');
        console.log(time_stamped_message);
        document.getElementById("time_stamped_messages").innerHTML += p0 + time_stamped_message + p1;
        document.getElementById("S_field_display").style.display = "none";
        document.getElementById("submit_button").style.display = "none";
        document.getElementById("reset_button").style.display = "block";
        print_results();
    }
    catch(e) {
        console.log("Runtime exception occurred in function submit(): " + e);
    }
}
