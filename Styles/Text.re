open Revery;
open Revery.UI;

open ReveryMaterial_Colors;

let regular = (~color as c={color: Black, level: P500}, ()) =>
  Style.[
    fontFamily("Roboto-Regular.ttf"),
    color(c |> toReveryColor),
    fontSize(14),
  ];
let medium = (~color as c={color: Black, level: P500}, ()) =>
  Style.[
    fontFamily("Roboto-Medium.ttf"),
    color(c |> toReveryColor),
    fontSize(14),
  ];
let heading1 = (~color as c={color: Black, level: P500}, ()) =>
  Style.[
    fontFamily("Roboto-Medium.ttf"),
    color(c |> toReveryColor),
    fontSize(28),
  ];
let heading2 = (~color as c={color: Black, level: P500}, ()) =>
  Style.[
    fontFamily("Roboto-Medium.ttf"),
    color(c |> toReveryColor),
    fontSize(24),
  ];
let heading3 = (~color as c={color: Black, level: P500}, ()) =>
  Style.[
    fontFamily("Roboto-Medium.ttf"),
    color(c |> toReveryColor),
    fontSize(20),
  ];
let heading4 = (~color as c={color: Black, level: P500}, ()) =>
  Style.[
    fontFamily("Roboto-Medium.ttf"),
    color(c |> toReveryColor),
    fontSize(16),
  ];
let heading5 = (~color as c={color: Black, level: P500}, ()) =>
  Style.[
    fontFamily("Roboto-Medium.ttf"),
    color(c |> toReveryColor),
    fontSize(14),
  ];
