/**
 * file: count_down_timer.js
 * type: JavaScript
 * author: karbytes
 * date: 10_JULY_2023
 * license: PUBLIC_DOMAIN
 */

/**
 * Generate the HTML code for the portion of the web page interface display
 * which outputs the quantity of temporal units elapsed starting at
 * the time at which the start button was clicked and ending at the 
 * time at which the selected number of time units is decremented
 * to zero.
 * 
 * @return {String} the HTML for defining a SPAN element whose id is "nonnegative_integer_display"
 */
function generate_nonnegative_integer_display_span() {
	return ('<' + 'span id="nonnegative_integer_display"' + '>') + '0' + ('<' + '/' + 'span' + '>');
}

/**
 * Display a time-stamped message inside the DIV element whose identifier (id) 
 * is "application_status_messages_display".
 * which denotes the point in time at which the web page application was 
 * either opened or else reloaded by a web browser.
 *
 * Display "0" inside the SPAN element whose identifier is "seconds_elapsed_display".
 *
 * Set the input element whose identifier is "timer_session_start_button" 
 * to visible rather than to hidden.
 * 
 * Assume that this function is called when a web broswer opens count_down_timer.html 
 * or else reloads that web page.
 */
function initialize_application() {
	try {
		const message = ("The web page was opened at time: " + generate_time_stamp());
		console.log(message);
		document.getElementById("timer_start_button").style.visibility = "block";
		document.getElementById("seconds_elapsed_display").innerHTML = (('<' + 'p' + '>') + "seconds_remaining: " + generate_nonnegative_integer_display_span() + ('<' + '/' + 'p' + '>'));
		document.getElementById("application_status_messages_display").innerHTML = (('<' + 'p' + '>') + message + ('<' + '/' + 'p' + '>'));
	}
	catch(e) {
		console.log("An exception to normal functioning occurred during the runtime of initialize_application(): " + e);
	}
}

/**
 * Return the value of the selected menu OPTION of a SELECT menu element.
 * 
 * @param {String} select_menu_identifier is the id of a select HTML element.
 * 
 * @return {String} the value of the selected menu option.
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
	catch(e) {
		console.log("An exception to normal functioning occurred during the runtime of get_selected_menu_option(select_menu_identifier): " + e);
	}
}

/**
 * Play exactly one sound file exactly one time 
 * (i.e. for a finite duration of time there will 
 * be a sequence of auditory phenomena).
 *
 * Assume that the sound file, alert_sound_effect.wav, 
 * exists in the same file directory as this JavaScript file(s)
 * and the web page deploying this JavaScript file(s) and the
 * referenced audio file.
 */
function play_sound_file() {
	try {
		var audio = new Audio("alert_sound_effect.wav");
		audio.play();
	}
	catch(e) {
		console.log("An exception to normal functioning occurred during the runtime of play_sound_file(): " + e);
	}
}

/**
 * Terminate the timer session.
 * 
 * Assume that this function is called after the 
 * decrement_timer_display_by_one_second(simulation)
 * function is called N times.
 *
 * Print a time-stamped status message to the DIV element 
 * whose id is "application_status_messages_display"
 * which indicates that the timer session of N seconds 
 * is finished.
 * 
 * Attempt to play a sound which signifies that the timer
 * session has completed.
 */
function finish_simulation() {
	try {
		const message = ("The timed simulation finished at time: " + generate_time_stamp());
		console.log(message);
		document.getElementById("application_status_messages_display").innerHTML += (('<' + 'p' + '>') + message + ('<' + '/' + 'p' + '>'));
		document.getElementById("timer_start_button").style.display = "block";
		play_sound_file();
	}
	catch(e) {
		console.log("An exception to normal functioning occurred during the runtime of finish_simulation(): " + e);
	}
}

/**
 * Decrement the number of seconds remaining by one second.
 * If the number of seconds is less than one, then terminate the timer session.
 * 
 * Assume that there is a text HTML element whose id is "seconds_elapsed_display"
 * (and that the inner HTML of that element is an integer value).
 * 
 * @param {Object} simulation - an instance of some temporally finite process 
 */
function decrement_timer_display_by_one_second(simulation) {
	try {
		let timer_display, seconds_remaining;
		timer_display = document.getElementById("seconds_elapsed_display");
		seconds_remaining = parseInt(timer_display.innerHTML);
		seconds_remaining -= 1;
		timer_display.innerHTML = seconds_remaining;
 	    if (seconds_remaining < 1) {
 	    	/**
 	    	 * The native JavaScript clearInterval() function stops 
 	    	 * recurring function calls (such that the simulation object
 	    	 * represents a call to a particular function once per fixed
 	    	 * number of milliseconds).
 	    	 */
 	    	clearInterval(simulation);
 	    	finish_simulation();
 	    }
	}
	catch(e) {
		console.log("An exception to normal functioning occurred during the runtime of decrement_timer_display_by_one_second(simulation): " + e);
	}
}

/**
 * Print a time-stamped message to the web browser console window 
 * and to the web page element whose identifier is "seconds_elapsed_display" which
 * indicates the time at which the start() button was clicked.
 *
 * Hide the start() button to prevent overlapping timer processes.
 *
 * Set the span element whose identifier is "seconds_elapsed_display" 
 * to display the nonnegative integer, N, which was most recently selected
 * inside of the select menu whose identifier is "nonnegative_integer_interval_selector".
 *
 * If no menu option was selected, set N to 30 by default.
 *
 * For N consecutive seconds, decrement the nonnegative integer value stored
 * in the span element whose identifier is "seconds_elapsed_display"
 * by exactly 1 until that value becomes 0.
 *
 * After the N-second timer interval completes, display the hidden start()
 * button so that it can be clicked again.
 */
function start() {
	try {
		// Display the time at which the START button was clicked on the web page and in the browser console.
		let message = ("The start() button was clicked at time: " + generate_time_stamp()), N = 0, simulation = undefined;
		console.log(message);
		document.getElementById("application_status_messages_display").innerHTML += (('<' + 'p' + '>') + message + ('<' + '/' + 'p' + '>'));

		// Disable the start() button by hiding it until the simulation is finished.
		document.getElementById("timer_start_button").style.display = "none";

		N = parseInt(get_selected_menu_option_value("nonnegative_integer_interval_selector"));

		// Ensure that N is an Number type datum, integer, and value no smaller than 30 and no larger than 999.
		N = ((typeof N !== "number") || (N !== Math.floor(N)) || (N < 30) || (N > 999)) ? 30 : N;

		// Display the selected menu option on the web page and in the browser console.
		message = ("The selected value of N is " + N + ".");
		console.log(message);
		document.getElementById("application_status_messages_display").innerHTML += (('<' + 'p' + '>') + message + ('<' + '/' + 'p' + '>'));

		// Set the timer interval to N seconds and begin the incremental count down to 0 (in increments 1 second in length).
		document.getElementById("seconds_elapsed_display").innerHTML = N;

		// Begin updating the timer display once per second (and 1 second is equal to 1000 milliseconds).
		simulation = setInterval( function() { decrement_timer_display_by_one_second(simulation); }, 1000);
	}
	catch(e) {
		// Note: try-catch blocks are for "exception handling" (i.e. runtime error detection).
		console.log("An exception to normal functioning occurred during the runtime of start(): " + e);
	}
}
