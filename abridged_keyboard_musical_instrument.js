/**
 * file: abridged_keyboard_musical_instrument.js
 * type: JavaScript
 * author: karbytes
 * date: 26_JANUARY_2025
 * license: PUBLIC_DOMAIN
 */

// Declare an audio context variable (which is a global program variable).
let audioContext = new (window.AudioContext || window.webkitAudioContext)();

/**
 * Define a global variable which is an (immutable) dictionary populated by key-value pairs (i.e. definitions)
 * where each key is the literal label of a computer keyboard key and where each value is the respective key's uniquely 
 * corresponding sound wave frequency requency (in terms of sound wave oscillations per second 
 * (i.e. hertz (abbreviated as Hz))). 
 * 
 * Each key-value pair in that dictionary is listed in ascending order in terms of sound wave frequency.
 * 
 * The musical note associated with each of those sound wave frequencies is denoted by that sound wave 
 * frequency's uniquely corresponding musical note comment.
 */
const noteFrequencies = {
    'z': 130.81,  // C3
    'x': 146.83,  // D3
    'c': 164.81,  // E3
    'v': 174.61,  // F3
    'b': 196.00,  // G3
    'n': 220.00,  // A3
    'm': 246.94,  // B3
    ',': 261.63,  // C4 (Middle C)
    '.': 293.66,  // D4
    '/': 329.63,  // E4
    'a': 349.23,  // F4
    's': 392.00,  // G4
    'd': 440.00,  // A4
    'f': 493.88,  // B4
    'g': 523.25,  // C5
    'h': 587.33,  // D5
    'j': 659.25,  // E5
    'k': 698.46,  // F5
    'l': 783.99,  // G5
    ';': 880.00,  // A5
    'q': 987.77,  // B5
    'w': 1046.50, // C6
};

// Define a global variable which represents the HTML element whose identifier (id) is "keyboard" on the web page named  abridged_keyboard_musical_instrument.
const keyboardDiv = document.getElementById('keyboard');

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
 * Respond to the event of the web page named abridged_keyboard_musical_instrument.html being loaded by a web browser.
 * 
 * This function prints a time-stamped message indicating when the web page was last 
 * loaded by the web browser in a DIV element on that web page whose identifier is "console".
 * 
 * This function also initializes the audio context (which works offline and which utilizes the
 * web browser's built-in sound-generating capabilities which correspond with the local machine's
 * operating system (to control the hardware which causes sound waves to be emitted from the machine)).
 * 
 * Assume that all three files which constitute this single web page application are located
 * in the same local file directory (and those file are 
 * karbytes_aesthetic.css, 
 * abridged_keyboard_musical_instrument.js, and 
 * abridged_keyboard_musical_instrument.html).
 */
function initialize_application() {
    // Initialize variables which are local to this function.
    let time_stamped_message = "";

    // Execute a try-catch block. If runtime exceptions are found, exit the try block and print an error message to the web browser console.
    try {
        // If the audio context has not already been defined, then define it now.
        if (!audioContext) audioContext = new (window.AudioContext || window.webkitAudioContext)();

        // Populate the div whose identifier is "console" with a time stamped message indicating that this function was called (and when it was called).
        time_stamped_message = ("The function named initialize_application() was called at time: " + generate_time_stamp());
        console.log(time_stamped_message);
        time_stamped_message = generate_paragraph_html_element(time_stamped_message);
        console_div = document.getElementById("console");
        console_div.innerHTML = time_stamped_message;
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of initialize_application(): " + exception);
    }
}

/** 
 * This function to dynamically instantiates each piano key in the piano user interface (UI) on the corresponding web page
 * (i.e. abridged_keyboard_musical_instrument.html).
 * 
 * Specifically, this function populates the HTML element whose identifier (id) is "keyboard" with the following labeled keyboard keys
 * (where each key represents a uniquely corresponding sound wave frequency (in terms of sound wave oscillations per second 
 * (i.e. hertz (abbreviated as Hz))) and the musical note name of each of that particular frequency):
 *     'z' // 130.81 Hz (C3)
 *     'x' // 146.83 Hz (D3)
 *     'c' // 164.81 Hz (E3)
 *     'v' // 174.61 Hz (F3)
 *     'b' // 196.00 Hz (G3)
 *     'n' // 220.00 Hz (A3)
 *     'm' // 246.94 Hz (B3)
 *     ',' // 261.63 Hz (C4 (Middle C))
 *     '.' // 293.66 Hz (D4)
 *     '/' // 329.63 Hz (E4)
 *     'a' // 349.23 Hz (F4)
 *     's' // 392.00 Hz (G4)
 *     'd' // 440.00 Hz (A4)
 *     'f' // 493.88 Hz (B4)
 *     'g' // 523.25 Hz (C5)
 *     'h' // 587.33 Hz (D5)
 *     'j' // 659.25 Hz (E5)
 *     'k' // 698.46 Hz (F5)
 *     'l' // 783.99 Hz (G5)
 *     ';' // 880.00 Hz (A5)
 *     'q' // 987.77 Hz (B5)
 *     'w' // 1046.50 Hz (C6)
 */
function createKeyUI(key) {
    try {
        const keyDiv = document.createElement('div');
        keyDiv.classList.add('key');
        keyDiv.textContent = key.toUpperCase();
        keyDiv.id = key;
        keyboardDiv.appendChild(keyDiv);
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of createKeyUI(key): " + exception);
    }
}

/**
 * This function adds keys to the keyboard DIV in ascending note order.
 */
Object.keys(noteFrequencies).forEach(createKeyUI);

/**
 * This function generates physical sound waves whose frequencies are the values input by this function.
 * 
 * This function also prints a time-stamped message indicating when a UI keyboard key was
 * most recently pressed in the "console" DIV.
 */
function playNote(frequency) {
    let time_stamped_message = "";
    try {
        const oscillator = audioContext.createOscillator();
        const gainNode = audioContext.createGain();
        oscillator.type = 'sine';
        oscillator.frequency.setValueAtTime(frequency, audioContext.currentTime);
        gainNode.gain.setValueAtTime(0.5, audioContext.currentTime);
        oscillator.connect(gainNode);
        gainNode.connect(audioContext.destination);
        oscillator.start();
        oscillator.stop(audioContext.currentTime + 0.5); // Stop playing the note after 0.5 seconds elapses. 

        // Append the text in the div whose identifier is "console" with a time stamped message indicating that this function was called (and when it was called).
        time_stamped_message = ("The function named playNote(frequency) (where frequency = " + frequency + ") was called at time: " + generate_time_stamp());
        console.log(time_stamped_message);
        time_stamped_message = generate_paragraph_html_element(time_stamped_message);
        console_div = document.getElementById("console");
        console_div.innerHTML += time_stamped_message;
    }
    catch(exception) {
        console.log("An exception to normal functioning occurred during the runtime of playNote(frequency): " + exception);
    }
}

/**
 * This function responds to the event of a UI keyboard key being pressed 
 * (as a consequence of the corresponding physical keyboard key being pressed down).
 */
document.addEventListener('keydown', (event) => {
    const key = event.key.toLowerCase();
    if (noteFrequencies[key]) {
        playNote(noteFrequencies[key]);
        // Add visual feedback to the key (by changing the background color of the corresponding key).
        const keyDiv = document.getElementById(key); 
        if (keyDiv) {
          keyDiv.classList.add('pressed');
        }
    }
});

/**
 * This function responds to the event of a UI keyboard key being unpressed
 * (as a consequence of the corresponding physical keyboard key being unpressed after being pressed).
 * 
 * Specifically, this function changes the background color of the respective key back to light gray 
 * (after temporarily being set to green (for 0.5 seconds)).
 */
document.addEventListener('keyup', (event) => {
    const key = event.key.toLowerCase();
    const keyDiv = document.getElementById(key);
    if (keyDiv) {
      keyDiv.classList.remove('pressed');
    }
});

/** 
 * This function responds to the event of a UI keyboard key being touched 
 * (and is logically equivalent to the physical key 'keydown' event listener function). 
 */
document.addEventListener('touchstart', (event) => {
    // Get the touched web page element.
    const target = event.target;

    // Check if the touched element is a key (with the 'key' class).
    if (target.classList.contains('key')) {
        const key = target.id.toLowerCase(); // Use the key's ID as the identifier.
        if (noteFrequencies[key]) {
            playNote(noteFrequencies[key]);
            // Add visual feedback to the key (i.e. change background to green).
            target.classList.add('pressed');
        }
    }
});

/** 
 * This function responds to the event of a UI keyboard key being untouched 
 * (and is logically equivalent to the physical key 'keyup' event listener function). 
 */
document.addEventListener('touchend', (event) => {
    // Get the touched web page element.
    const target = event.target;

    // Check if the released element is a key (with the 'key' class).
    if (target.classList.contains('key')) {
        // Remove the visual feedback from the key (i.e. change background back to original color).
        target.classList.remove('pressed');
    }
});


