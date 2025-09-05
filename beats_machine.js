/**
 * file: beats_machine.js
 * type: JavaScript
 * author: karbytes
 * date: 10_SEPTEMBER_2024
 * license: PUBLIC_DOMAIN
 */
    
// global program variables    
let audioContext;
let intervalIds = [];

/**
 * Start playing all three beat tracks with the pitch and duration parameters specified on
 * the web page named beats_machine.html. Play all three of those tracks for an indefinitely
 * long time period.
 * 
 * Assume that this function is called in response to the event of the START_BUTTON being clicked on
 * the web page named beats_machine.html (which is assumed to be in the same local directory as
 * this file (i.e. beats_machine.js) and the file named karbytes_aesthetic.css).
 * 
 * This function also prints a time-stamped message indicating when the START_BUTTON was last 
 * clicked in a DIV element on that web page whose identifier is "console" (and that time-stamped
 * message is appended to the message that should already be printed in that DIV during the
 * most recent web page load).
 */
function startBeats() {
    let time_stamped_message = "", console_div = undefined;
    try {
        // Populate the div whose identifier is "console" with a time stamped message indicating that this function was called (and when it was called).
        time_stamped_message = ("The function named startBeats() was called at time: " + generate_time_stamp());
        console.log(time_stamped_message);
        time_stamped_message = generate_paragraph_html_element(time_stamped_message);
        console_div = document.getElementById("console");
        console_div.innerHTML += time_stamped_message;
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of startBeats(): " + exception);
    }

    /**
     * Initialize the audio context if it has not already been created.
     * Note that the audio context makes it possible to play the beats offline.
     * That is because the web browser has built-in sound generating capabilities.
     * 
     * According to ChatGPT-4o, the AudioContext manages a flow of audio data buffers, 
     * which are processed and sent to the output device (e.g., speakers). When creating an 
     * AudioContext, the browser communicates with the system's sound hardware, requesting 
     * access to manage audio streams.
     */
    if (!audioContext) {
	audioContext = new (window.AudioContext || window.webkitAudioContext)();
    }
    // Begin playing all three tracks (for an indefinitely long period of time).
    startTrack(0);
    startTrack(1);
    startTrack(2);
}

/**
 * Stop playing all three beat tracks simultaneously.
 * 
 * Assume that this function is called in response to the event of the STOP_BUTTON being clicked on
 * the web page named beats_machine.html (which is assumed to be in the same local directory as
 * this file (i.e. beats_machine.js) and the file named karbytes_aesthetic.css).
 * 
 * This function also prints a time-stamped message indicating when the STOP_BUTTON was last 
 * clicked in a DIV element on that web page whose identifier is "console" (and that time-stamped
 * message is appended to the message that should already be printed in that DIV during the
 * most recent web page load).
 */
function stopBeats() {
    let time_stamped_message = "", console_div = undefined;
    try {
        // Populate the div whose identifier is "console" with a time stamped message indicating that this function was called (and when it was called).
        time_stamped_message = ("The function named stopBeats() was called at time: " + generate_time_stamp());
        console.log(time_stamped_message);
        time_stamped_message = generate_paragraph_html_element(time_stamped_message);
        console_div = document.getElementById("console");
        console_div.innerHTML += time_stamped_message;
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of stopBeats(): " + exception);
    }
    intervalIds.forEach(id => clearInterval(id)); // Clear all intervals.
    intervalIds = []; // Reset interval ids array.
}

/**
 * Start playing an individual track (whose trackNumber is assumed to be 0, 1, or 2).
 */
function startTrack(trackNumber) {
    const durationSelect = document.getElementById(`track_${trackNumber}_duration`);
    const pitchSelect = document.getElementById(`track_${trackNumber}_pitch`);
    const beatDuration = parseFloat(durationSelect.value);
    const beatPitch = parseFloat(pitchSelect.value);

    // If the "Do Not Play" option is selected, then do not play the respective track.
    if (beatPitch === 0) return; 

    /**
     * Play the respective track using the built-in sound generating capabilities of the web browser.
     * 
     * According to ChatGPT-4o, the oscillator generates a periodic waveform (like a sine wave). 
     * Physically, an oscillator in sound represents variations in air pressure over time, which, 
     * when processed digitally, corresponds to a series of numerical samples. These samples are 
     * fed into the system's audio buffer, which is sent to the speakers to produce sound.
     * 
     * According to ChatGPT-4o, the gain node adjusts the volume of the sound by scaling the 
     * amplitude of the waveform. At the machine level, this means multiplying each sample in 
     * the audio buffer by a constant factor before sending it to the output device.
     * 
     * The GainNode controls the amplitude of the tone, creating a short beat that ramps up and down in volume.
     */
    function playBeat() {
        const oscillator = audioContext.createOscillator();
	    const gainNode = audioContext.createGain();
	    oscillator.frequency.value = beatPitch;
	    oscillator.connect(gainNode);
	    gainNode.connect(audioContext.destination);
	    gainNode.gain.setValueAtTime(0, audioContext.currentTime);
	    gainNode.gain.linearRampToValueAtTime(1, audioContext.currentTime + 0.01);
	    gainNode.gain.linearRampToValueAtTime(0, audioContext.currentTime + beatDuration);
	    oscillator.start(audioContext.currentTime);
	    oscillator.stop(audioContext.currentTime + beatDuration);
    }
    // Set the interval to play the beat at the selected duration.
    const intervalId = setInterval(playBeat, beatDuration * 1000);
    intervalIds.push(intervalId);
}

/**
 * Return a String type value which describes the number of milliseconds which have elapsed since the Unix Epoch.
 * 
 * Note that the Unix Epoch is 01_JANUARY_1970 at 0 hours, 0 minutes, 0 seconds, and 0 seconds 
 * (i.e. 00:00:00) (i.e. midnight) (Coordinated Universal Time (UTC)).
 * 
 * @return {String} text which denotes the number of milliseconds which have elapsed since the Unix Epoch.
 */
function generate_time_stamp() {
    const milliseconds_elapsed_since_unix_epoch = Date.now();
    return milliseconds_elapsed_since_unix_epoch + " milliseconds since midnight on 01_JANUARY_1970.";
}

/**
 * Return a String type value which is used to instantiate a paragraph type web page element such that
 * the String type value which is passed into this function as its only input is that paragraph element's 
 * inner HTML content.
 * 
 * Note that the String type constant variable values are broken up into single-character String type values 
 * to avoid causing the WordPress web page editor to interpret HTML tags in the web page body with 
 * source code which is hosted on that web page inside of PRE (preformatted) web page elements.
 * 
 * @param {String} inner_HTML is assumed to be plain text or HTML content.
 * 
 * @return {String} a sequence of text characters which is used to instantiate a paragraph (P) web page element.
 */
function generate_paragraph_html_element(inner_html) {
    const opening_paragraph_tag = ('<' + 'p' + '>'), closing_paragraph_tag = ('<' + '/' + 'p' + '>');
    try {
        if (typeof inner_html.length !== "number") throw 'The expression (typeof inner_html.length !== "number") was evaluated to be true.';
        return opening_paragraph_tag + inner_html + closing_paragraph_tag;
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of generate_paragraph_html_element(inner_html): " + exception);
    }
}

/**
 * Generate a drop-down menu of various pitches (and a pitch is a particular sound wave frequency).
 * 
 * Return a String type value which is used to instantiate a select type web page element such that
 * the String type value which is passed into this function as its only input is that select menu element's
 * id property value.
 * 
 * When clicked on, the select menu interface element will expand to display a list of all sound frequencies
 * (in units named hertz (which is abreviated as Hz (and which indicates some number of cycles per second)))
 * which are nonnegative integers denoting the number of oscillations per second for each of those twenty beat frequencies.
 * 
 * Each of the twenty beat pitch frequencies listed in the drop-down menu are arranged in acending order 
 * starting with the menu option at the top of the list (which is 0 Hz) 
 * and then, starting with the second option in the list (which is 200 Hz),
 * incrementing the beat pitch frequency value by some constant positive integer number of Hz (i.e. 45)
 * until the menu option at the bottom of the list (which is 1010 Hz) is reached.
 * 
 * @param {String} select_id is assumed to be either 
 *                 "track_0_pitch" or else
 *                 "track_1_pitch" or else
 *                 "track_2_pitch".
 * 
 * @return {String} a sequence of text characters which is used to instantiate an expandable list menu (SELECT) web page element.
 */
function generate_pitch_menu_select_html_element(select_id) {
    let select_menu = '', option = '', i = 0, N = 200;
    let default_menu_option_label = "Do Not Play (i.e. 0 Hz)";
    try {
        if (typeof select_id.length !== "number") throw 'The expression (typeof select_id.length !== "number") was evaluated to be true.';
        if ((select_id !== "track_0_pitch") &&
            (select_id !== "track_1_pitch") &&
            (select_id !== "track_2_pitch"))
        throw 'select_id must either be "track_0_pitch" or else "track_1_pitch" or "track_2_pitch".';
        select_menu = ('<' + 'select id="' + select_id + '" style="text-align:left"' + '>');
        for (i = 0; i < 20; i += 1) {
            if (i === 0) option = (('<' + 'option value="0" selected' + '>') + default_menu_option_label + ('<' + '/' + '>'));
            else {
            	option = ('<' + 'option value="' + N + '"' + '>');
            	option += (N + ' Hz' + ('<' + '/' + 'option' + '>'));
        	}
        	select_menu += option;
        	if (i > 0) N += 45;
        }
        select_menu += ('<' + '/' + 'select' + '>');
        return select_menu;
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of generate_pitch_menu_select_html_element(select_id): " + exception);
    } 
}

/**
 * Generate a drop-down menu of various beat durations (and a beat duration is the time interval 
 * in which the same tone is played immediately in succession).
 * 
 * Return a String type value which is used to instantiate a select type web page element such that
 * the String type value which is passed into this function as its only input is that select menu element's
 * id property value.
 * 
 * When clicked on, the select menu interface element will expand to display a list of all beat durations
 * (in units named seconds (and, according to the International System of Units (SI), the second is defined 
 * scientifically as the duration of 9,192,631,770 periods of the radiation corresponding to the transition 
 * between the two hyperfine levels of the ground state of the cesium-133 atom)).
 * 
 * Each of the ten beat durations listed in the drop-down menu are arranged in acending order 
 * starting with the menu option at the top of the list (which is 1/16 second (i.e. 0.0625 second)) 
 * and then incrementing the beat duration by some positive number of seconds (between 0.0625 seconds and 1 second)
 * until the menu option at the bottom of the list (which is 2 seconds) is reached.
 * 
 * @param {String} select_id is assumed to be either 
 *                 "track_0_duration" or else
 *                 "track_1_duration" or else
 *                 "track_2_dutation".
 * 
 * @return {String} a sequence of text characters which is used to instantiate an expandable list menu (SELECT) web page element.
 */
function generate_beat_duration_menu_select_html_element(select_id) {
    let select_menu = '', option = '', i = 0;
    let default_menu_option_label = "1/16 second (i.e. 0.0625 second)";
    let menu_option_values = [0.0625, 0.25, 0.5, 0.75, 1, 1.0625, 1.25, 1.5, 1.75, 2];
    let menu_option_label_prefaces = ["1/16", "1/4", "1/2", "3/4", "1", "17/16", "5/4", "3/2", "7/4", "2"];
    try {
        if (typeof select_id.length !== "number") throw 'The expression (typeof select_id.length !== "number") was evaluated to be true.';
        if ((select_id !== "track_0_duration") &&
            (select_id !== "track_1_duration") &&
            (select_id !== "track_2_duration"))
        throw 'select_id must either be "track_0_duration" or else "track_1_duration" or "track_2_duration".';
        select_menu = ('<' + 'select id="' + select_id + '" style="text-align:left"' + '>');
        for (i = 0; i < 10; i += 1) {
            if (i === 0) option = (('<' + 'option value="' + menu_option_values[0] + '" selected' + '>') + default_menu_option_label + ('<' + '/' + '>'));
            else {
            	option = ('<' + 'option value="' + menu_option_values[i] + '"' + '>');
            	option += menu_option_label_prefaces[i];
            	if (i > 4) option += (' seconds (' + menu_option_values[i] + ' seconds)');
            	else option += (' second (' + menu_option_values[i] + ' second)');
            	option += ('<' + '/' + 'option' + '>');
        	}
        	select_menu += option;
        }
        select_menu += ('<' + '/' + 'select' + '>');
        return select_menu;
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of generate_beat_duration_menu_select_html_element(select_id): " + exception);
    } 
}

/**
 * Respond to the event of the web page named beats_machine.html being loaded by a web browser.
 * 
 * This function populates the six select menus on that web page with their respective menu options
 * (and those select menus have the HTML element identifiers (ids) are as follows:
 * 		"track_0_duration",
 * 		"track_0_pitch",
 * 		"track_1_duration",
 * 		"track_1_pitch",
 * 		"track_2_duration", and
 * 		"track_2_pitch").
 * 
 * This function also prints a time-stamped message indicating when the web page was last 
 * loaded by the web browser in a DIV element on that web page whose identifier is "console".
 * 
 * Assume that all three files which constitute this single web page application are located
 * in the same local file directory (and those file are 
 * karbytes_aesthetic.css, beats_machine.js, and beats_machine.html).
 */
function initialize_application() {
    // Initialize variables which are local to this function.
    let time_stamped_message = "";
    let duration_0_container = undefined, pitch_0_container = undefined;
    let duration_1_container = undefined, pitch_1_container = undefined;
    let duration_2_container = undefined, pitch_2_container = undefined;

    // Execute a try-catch block. If runtime exceptions are found, exit the try block and print an error message to the web browser console.
    try {
        // Populate the div whose identifier is "console" with a time stamped message indicating that this function was called (and when it was called).
        time_stamped_message = ("The function named initialize_application() was called at time: " + generate_time_stamp());
        console.log(time_stamped_message);
        time_stamped_message = generate_paragraph_html_element(time_stamped_message);
        console_div = document.getElementById("console");
        console_div.innerHTML = time_stamped_message;

        // Populate the "duration_0_container" span element with a select menu for choosing a duration for TRACK_0.
        duration_0_container_span = document.getElementById("duration_0_container");
        duration_0_container_span.innerHTML = generate_beat_duration_menu_select_html_element("track_0_duration"); 

        // Populate the "pitch_0_container" span element with a select menu for choosing a pitch for TRACK_0.
        pitch_0_container_span = document.getElementById("pitch_0_container");
        pitch_0_container_span.innerHTML = generate_pitch_menu_select_html_element("track_0_pitch"); 

        // Populate the "duration_1_container" span element with a select menu for choosing a duration for TRACK_1.
        duration_1_container_span = document.getElementById("duration_1_container");
        duration_1_container_span.innerHTML = generate_beat_duration_menu_select_html_element("track_1_duration"); 

        // Populate the "pitch_1_container" span element with a select menu for choosing a pitch for TRACK_1.
        pitch_1_container_span = document.getElementById("pitch_1_container");
        pitch_1_container_span.innerHTML = generate_pitch_menu_select_html_element("track_1_pitch"); 

        // Populate the "duration_2_container" span element with a select menu for choosing a duration for TRACK_2.
        duration_2_container_span = document.getElementById("duration_2_container");
        duration_2_container_span.innerHTML = generate_beat_duration_menu_select_html_element("track_2_duration"); 

        // Populate the "pitch_2_container" span element with a select menu for choosing a pitch for TRACK_2.
        pitch_2_container_span = document.getElementById("pitch_2_container");
        pitch_2_container_span.innerHTML = generate_pitch_menu_select_html_element("track_2_pitch"); 
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of initialize_application(): " + exception);
    }
}
