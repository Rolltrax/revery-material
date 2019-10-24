open Revery;
open Revery.UI;

/* Source: https://material.io/design/motion/speed.html#easing */
let standardEasing = Easing.cubicBezier(0.4, 0.0, 0.2, 1.);
let decelerateEasing = Easing.cubicBezier(0.0, 0.0, 0.2, 1.);
let accelerateEasing = Easing.cubicBezier(0.4, 0.0, 1., 1.);
