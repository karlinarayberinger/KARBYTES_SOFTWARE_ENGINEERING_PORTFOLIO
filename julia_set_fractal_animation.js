/**
 * file: julia_set_fractal_animation.js
 * type: JavaScript
 * date: 12_JULY_2025
 * author: karbytes
 * license: PUBLIC_DOMAIN
 */

/***************************************************************
 * Note that this JavaScript file's contents can be 
 * copy-pasted into a <script> element placed at the 
 * bottom of the <body> element of julia_set_fractal.html
 * (while replacing the script element which links to this file).
 **************************************************************/

// global program variables
const canvas = document.getElementById("fractalCanvas");
const ctx = canvas.getContext("2d");
const info = document.getElementById("info");
let width, height;

/**
 * This function resizes the canvas to fill the entire browser window and
 * updates the global width and height variables to match the new canvas dimensions.
 */
function resizeCanvas() {
  canvas.width = width = window.innerWidth;
  canvas.height = height = window.innerHeight;
}

/**
 * Attach the resizeCanvas() function to the "resize" event of the window object.
 * 
 * The window object represents the top-level browser environment which encapsulates the entire web page.
 * 
 * The addEventListener() method sets up a link between a specific event type (i.e. "resize")
 * and a function to execute whenever that event occurs.
 * 
 * In this case, whenever the browser window is resized by the user,
 * the browser will automatically invoke the resizeCanvas() function in response.
 */
window.addEventListener("resize", resizeCanvas);

/**
 * Call the resizeCanvas() function immediately after the web page is loaded by the web browser
 * so that the canvas matches the current dimensions of the browser window before any drawing begins.
 */
resizeCanvas(); 

/**
 * Declare a variable named config and initialize it as an empty object.
 * 
 * This object will later store the parameters which define the current Julia set,
 * such as the complex constant c, color palette, zoom rate, and max iteration count.
 */
let config = {};

/**
 * Initialize the zoom level to 1 (i.e. no magnification).
 * 
 * This value will be progressively increased to create the 
 * visual effect of continuous zooming into the fractal.
 */
let zoom = 1;

/**
 * Define the initial center point of the zoomed fractal in terms of complex-plane coordinates,
 * where (x: 0.0, y: 0.0) corresponds to the center of the canvas in pixel space.
 * 
 * Each pixel on the canvas will be mapped to a point in the complex plane relative to this center,
 * allowing the fractal to be drawn and zoomed around this focal point.
 */
let center = { x: 0.0, y: 0.0 };

/**
 * Declare a variable named targetCenter and assign it the initial complex-plane coordinate (0.0, 0.0).
 * 
 * This variable represents the point toward which the fractal’s zoom center (i.e., the center variable)
 * will gradually interpolate over successive animation frames until center and targetCenter are approximately equal.
 * 
 * When the user clicks on the canvas, targetCenter is updated to reflect the complex-plane coordinate
 * corresponding to the clicked pixel location (based on the current zoom level and center).
 * 
 * The center variable will then incrementally approach targetCenter
 * to produce a relatively smooth zoom-pan effect.
 */
let targetCenter = { x: 0.0, y: 0.0 };

/**
 * Declare a variable named easingFactor and assign it the value 0.05.
 * 
 * This value determines the rate at which the center variable 
 * interpolates toward targetCenter during each animation frame. 
 * 
 * A smaller easingFactor results in slower, smoother transitions,
 * while a larger value makes the zoom center move more quickly (but potentially less smoothly)
 * toward the clicked target point in the complex plane.
 */
let easingFactor = 0.05; 

/**
 * Define a function named generateRandomConfig() which returns a new object literal
 * whose properties determine how the next Julia set fractal will be computed and displayed.
 * 
 * The returned object contains the following key-value pairs:
 * 
 * - c: An object representing a randomly selected complex constant (c = re + i·im),
 *      where both the real (re) and imaginary (im) components are floating-point numbers
 *      uniformly distributed within the interval [-1.0, 1.0]. This value defines the
 *      specific Julia set to render.
 * 
 * - maxIter: A randomly selected integer between 50 and 149 (inclusive),
 *       specifying the maximum number of iterations to perform for each point in the complex plane
 *       before deciding whether that point escapes to infinity.
 * 
 * - zoomRate: A floating-point value between approximately 1.01 and 1.03 which determines
 *      how quickly the fractal zooms in with each successive animation frame.
 * 
 * - palette: An object specifying a randomly generated RGB color palette.
 *      Each color channel (r, g, b) is a floating-point number between 0 and 255.
 *      This palette is used to colorize points based on how many iterations they undergo
 *      before escaping the bounded region.
 */
function generateRandomConfig() {
  return {
    c: {
      re: -1 + 2 * Math.random(),
      im: -1 + 2 * Math.random()
    },
    maxIter: Math.floor(50 + Math.random() * 100),
    zoomRate: 1.01 + Math.random() * 0.02,
    palette: {
      r: Math.random() * 255,
      g: Math.random() * 255,
      b: Math.random() * 255
    }
  };
}

/**
 * Define a function named regenerateFractal() which resets the fractal configuration
 * and restarts the zoom animation with a newly randomized Julia set.
 *
 * This function performs the following operations:
 *
 * - Assigns a new randomly generated configuration object (including a new complex constant c,
 *   iteration limit, zoom rate, and color palette) to the global config variable.
 *
 * - Resets the zoom level to 1 (i.e. no magnification).
 *
 * - Resets both the center and targetCenter coordinates to (0.0, 0.0) in complex-plane space,
 *   ensuring that the initial focal point is centered at the origin.
 *
 * - Invokes the draw() function to begin rendering and continuously animating
 *   the newly generated Julia set.
 */
function regenerateFractal() {
  config = generateRandomConfig();
  zoom = 1;
  center = targetCenter = { x: 0.0, y: 0.0 };
  draw();
}

/**
 * Register an event listener on the canvas element which responds to "click" events.
 * 
 * When the user clicks on the canvas:
 * 
 * - Determine the pixel coordinates (px, py) of the mouse click relative to the canvas
 *   (and the canvas is visually depicted as a rectangular grid of pixels).
 * 
 * - Convert those pixel coordinates into a corresponding point (clickedX, clickedY)
 *   in the complex plane by accounting for the current zoom level, canvas dimensions,
 *   and center position.
 * 
 * - The scale factor (1.5) ensures the complex plane is normalized to fit within
 *   the visible canvas area, matching the coordinate system used for rendering the fractal.
 * 
 * - Update the targetCenter variable to the complex-plane coordinate corresponding to the click,
 *   so that the fractal zoom center will begin transitioning relatively smoothly towards that point
 *   on subsequent animation frames.
 */
canvas.addEventListener("click", function (e) {
  const rect = canvas.getBoundingClientRect();
  const px = e.clientX - rect.left;
  const py = e.clientY - rect.top;
  const scale = 1.5;
  const clickedX = scale * (px - width / 2) / (0.5 * zoom * width) + center.x;
  const clickedY = scale * (py - height / 2) / (0.5 * zoom * height) + center.y;
  targetCenter = { x: clickedX, y: clickedY };
});

/**
 * Define a function named juliaColor() which determines the RGB (Red-Green-Blue) color
 * to assign to a given complex-plane coordinate (x, y) based on how that point behaves
 * under iteration of the Julia set function: zₙ₊₁ = zₙ² + c.
 *
 * Parameters:
 * 
 * - x: the real part of the initial complex number z₀.
 * 
 * - y: the imaginary part of the initial complex number z₀.
 *
 * The function performs the following operations:
 * 
 * - Initialize zx and zy to the input (x, y), representing the current z-value.
 * 
 * - Extract the maximum iteration count (maxIter) and the real and imaginary parts
 *   of the constant complex parameter c from the global config object.
 * 
 * - Iteratively apply the Julia set formula, tracking how many iterations it takes
 *   for the magnitude of z (i.e. sqrt(zx² + zy²)) to exceed 2.
 * 
 * - If the point never escapes within maxIter steps, return solid black [0, 0, 0],
 *   indicating that the point is likely within the filled-in Julia set.
 * 
 * - Otherwise, return a color derived from the escape time ratio (t = iter / maxIter),
 *   linearly scaled across the RGB color palette defined in the config.
 */
function juliaColor(x, y) {
  let zx = x;
  let zy = y;
  let iter = 0;
  const maxIter = config.maxIter;
  const cx = config.c.re;
  const cy = config.c.im;
  while (zx * zx + zy * zy < 4 && iter < maxIter) {
    let xtemp = zx * zx - zy * zy + cx;
    zy = 2 * zx * zy + cy;
    zx = xtemp;
    iter++;
  }
  if (iter === maxIter) return [0, 0, 0];
  const t = iter / maxIter;
  return [
    Math.floor(t * config.palette.r),
    Math.floor(t * config.palette.g),
    Math.floor(t * config.palette.b)
  ];
}

/**
 * Define a function named drawFractal() which renders the current frame of the Julia set
 * onto the HTML canvas element using the current configuration settings (zoom level, center point, palette, etc.).
 * 
 * The function performs the following operations:
 * 
 * - Create a new ImageData object named image with the same dimensions as the canvas.
 * 
 * - Set a constant scale factor (1.5) which defines the size of the visible complex-plane region.
 * 
 * - For each pixel (px, py) in the canvas:
 * 
 *   ~ Convert the pixel coordinate to its corresponding complex-plane coordinate (x, y)
 *     by accounting for the current zoom level and the center offset.
 * 
 *   ~ Evaluate the juliaColor(x, y) function to determine the RGB color for the corresponding
 *     complex-plane point.
 * 
 *   ~ Compute the index of the current pixel in the 1-dimensional image.data array and assign the RGB
 *     values and an alpha value of 255 (fully opaque) to the respective entries.
 * 
 * - After all pixels have been updated, use ctx.putImageData() to draw the completed image onto the canvas.
 */
function drawFractal() {
  const image = ctx.createImageData(width, height);
  const zoomed = zoom;
  const scale = 1.5;
  for (let px = 0; px < width; px++) {
    for (let py = 0; py < height; py++) {
      const x = scale * (px - width / 2) / (0.5 * zoomed * width) + center.x;
      const y = scale * (py - height / 2) / (0.5 * zoomed * height) + center.y;
      const [r, g, b] = juliaColor(x, y);
      const index = (py * width + px) * 4;
      image.data[index] = r;
      image.data[index + 1] = g;
      image.data[index + 2] = b;
      image.data[index + 3] = 255;
    }
  }
  ctx.putImageData(image, 0, 0);
}

/**
 * Define a function named interpolate() which performs linear interpolation between two values.
 * 
 * Parameters:
 *
 * - current: the starting value (e.g., the current position or zoom level).
 *
 * - target: the destination value toward which current should move.
 * 
 * - factor: a number between 0 and 1 representing how far to move toward the target
 *           (e.g. 0.05 means move 5% of the remaining distance).
 * 
 * The function returns a value that is proportionally closer to target than current was,
 * allowing for relatively smooth transitions over successive animation frames.
 */
function interpolate(current, target, factor) {
  return current + (target - current) * factor;
}

/**
 * Define the draw() function which is repeatedly called to render each animation frame
 * of the zooming Julia set visualization.
 * 
 * This function performs the following steps:
 * 
 * - Smoothly (as possible digitally) update the center coordinates by interpolating between the current center
 *   and the targetCenter using the easingFactor. This creates a (relatively) smooth panning effect
 *   as the "camera" gradually shifts toward the user-selected location in the complex plane.
 * 
 * - Invoke drawFractal() to render the current state of the fractal onto the canvas
 *   based on the current center, zoom level, and fractal configuration.
 * 
 * - Incrementally increase the zoom level by multiplying it by the zoomRate factor
 *   specified in the config object, creating the effect of "continuous" zooming into the fractal.
 * 
 * - Update the onscreen informational text to reflect the current center coordinates,
 *   zoom level, and complex constant c.
 * 
 * - Use requestAnimationFrame(draw) to schedule the next animation frame,
 *   ensuring the draw() function is called again as soon as the browser is ready to repaint.
 */
function draw() {
  center.x = interpolate(center.x, targetCenter.x, easingFactor);
  center.y = interpolate(center.y, targetCenter.y, easingFactor);
  drawFractal();
  zoom *= config.zoomRate;
  updateInfo();
  requestAnimationFrame(draw);
}

/**
 * Define a function named updateInfo() which updates the contents of the onscreen info panel
 * to reflect the current state of the fractal rendering parameters.
 * 
 * This function sets the innerText of the HTML element named info to display:
 *  
 * - The current value of the complex constant c (formatted as "a + bi"),
 *   where a = config.c.re and b = config.c.im, each rounded to 5 decimal places.
 * 
 * - The current zoom level, rounded to 3 decimal places.
 * 
 * - The current center coordinates (x, y) of the view in complex-plane space,
 *   each rounded to 5 decimal places.
 * 
 * This live-updating panel helps the user understand the current position and zoom depth
 * of the fractal view and the specific Julia set being visualized.
 */
function updateInfo() {
  info.innerText =
  `c = ${config.c.re.toFixed(5)} + ${config.c.im.toFixed(5)}i\n` +
  `zoom = ${zoom.toFixed(3)}\n` +
  `center = (${center.x.toFixed(5)}, ${center.y.toFixed(5)})`;
}

/**
 * Immediately invoke regenerateFractal() to initialize the fractal visualization.
 * 
 * This sets up a random configuration (complex constant, color palette, etc.),
 * resets the zoom and center coordinates, and begins rendering the initial frame.
 */
regenerateFractal();
