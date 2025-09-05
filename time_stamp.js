/**
 * file: time_stamp.js
 * type: JavaScript
 * date: 10_JULY_2023
 * author: karbytes
 * license: PUBLIC_DOMAIN
 */

/**
 * Get the Number of milliseconds which have elapsed since the Unix Epoch.
 * The Unix Epoch is 01_JANUARY_1970 at midnight (Coordinated Universal Time (UTC)).
 * 
 * @return {String} message displaying the time at which this function was called.
 */
function generate_time_stamp() {
 	const milliseconds_elapsed_since_unix_epoch = Date.now();
 	return  milliseconds_elapsed_since_unix_epoch + " milliseconds since midnight on 01_JANUARY_1970.";
}
