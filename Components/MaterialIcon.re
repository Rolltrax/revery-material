open Revery;

open Revery.UI;
open Revery.UI.Components;

open ReveryMaterial_Colors;

include IconTypes;

let component = React.component("MaterialIcon");

let createElement =
    (
      ~children as _,
      ~size=16,
      ~icon,
      ~color as c=materialColor(~color=Black, ~level=P500, ()),
      (),
    ) =>
  component(hooks =>
    (
      hooks,
      <Text
        style=Style.[
          color(c |> toReveryColor),
          fontSize(size),
          fontFamily("MaterialIcons-Regular.ttf"),
        ]
        text={iconToString(icon)}
      />,
    )
  );
