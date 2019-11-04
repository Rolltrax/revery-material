open Revery;
open Revery.UI;
open Revery.UI.Components;

open ReveryMaterial_Colors;

let component = React.component("TextField");

let createElement =
    (
      ~children as _,
      ~activeColor=materialColor(~color=Orange, ~level=P500, ()),
      ~inactiveColor=materialColor(~color=Blue, ~level=P500, ()),
      ~hintText="",
      ~fontSize as fs=14,
      (),
    ) =>
  component(hooks => {
    let (active, setActive, hooks) = Hooks.state(false, hooks);
    let currentColor = activeColor |> toReveryColor;
    (
      hooks,
      <View style=Style.[borderBottom(~width=1, ~color=currentColor)]>
        <Input
          cursorColor={inactiveColor |> toReveryColor}
          style=Style.[
            border(~width=0, ~color=Colors.transparentWhite),
            backgroundColor(Colors.transparentWhite),
            height(1.5 *. float_of_int(fs) |> int_of_float),
            fontSize(fs),
          ]
        />
      </View>,
    );
  });
