open Revery;

open Revery.UI;
open Revery.UI.Components;

open ReveryMaterial_Colors;
open ReveryMaterial_Utils;

let component = React.component("SlideToggle");

let createElement =
    (
      ~children as _,
      ~initialValue=false,
      ~onChange: bool => unit=_ => (),
      ~color=materialColor(~color=Blue, ~level=P500, ()),
      (),
    ) =>
  component(hooks => {
    let (value, setValue, hooks) = Hooks.state(initialValue, hooks);
    let (percentDone, transitionPercentDoneTo, hooks) =
      Hooks.transition(0.0, ~duration=Seconds(0.1), hooks);
    let (percentDone1, pausePrecentDone1, restartPercentDone1, hooks) =
      Hooks.animation(
        Animated.floatValue(0.0),
        Animated.options(
          ~toValue=1.0,
          ~duration=Seconds(0.1),
          ~easing=MaterialEasing.standardEasing,
          (),
        ),
        hooks,
      );

    let handleColor =
      lerp(
        color |> toReveryColor,
        materialColor(~color=Grey, ~level=P100, ()) |> toReveryColor,
        percentDone /. 100.,
      );

    let slideColor =
      lerp(
        subtract(color, 2) |> toReveryColor,
        materialColor(~color=Grey, ~level=P500, ()) |> toReveryColor,
        percentDone /. 100.,
      );

    (
      hooks,
      <View
        onMouseDown={
          _ => {
            if (value) {
              transitionPercentDoneTo(0.0);
            } else {
              transitionPercentDoneTo(100.0);
            };
            setValue(!value);
            onChange(!value);
          }
        }>
        <View
          style=Style.[
            width(36),
            height(14),
            backgroundColor(slideColor),
            borderLeft(~width=7, ~color=slideColor),
            borderRight(~width=7, ~color=slideColor),
            borderRadius(7.0),
          ]>
          <View
            style=Style.[
              width(0),
              height(0),
              position(`Absolute),
              left(int_of_float(percentDone /. 100. *. 20. -. 10.)),
              top(-2),
              border(
                ~width=10,
                ~color=
                  materialColor(~color=Grey, ~level=P500, ()) |> toReveryColor,
              ),
              borderRadius(10.0),
            ]
          />
          <View
            style=Style.[
              width(0),
              height(0),
              position(`Absolute),
              left(int_of_float(percentDone /. 100. *. 20. -. 10.)),
              top(-3),
              border(~width=10, ~color=handleColor),
              borderRadius(10.0),
            ]
          />
        </View>
      </View>,
    );
  });
