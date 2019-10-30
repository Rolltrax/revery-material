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
    let (percentDone, pausePrecentDone, restartPercentDone, hooks) =
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

    let resetPercentDone = () => {
      restartPercentDone();
      pausePrecentDone() |> ignore;
    };

    let hooks =
      Hooks.effect(
        OnMount,
        () => {
          pausePrecentDone();
          None;
        },
        hooks,
      );

    let handleColor =
      lerp(
        color |> toReveryColor,
        materialColor(~color=Grey, ~level=P100, ()) |> toReveryColor,
        percentDone,
      );

    let slideColor =
      lerp(
        subtract(color, 2) |> toReveryColor,
        materialColor(~color=Grey, ~level=P500, ()) |> toReveryColor,
        percentDone,
      );

    (
      hooks,
      <View
        style=Style.[
          width(36),
          height(14),
          backgroundColor(slideColor),
          borderLeft(~width=7, ~color=slideColor),
          borderRight(~width=7, ~color=slideColor),
          borderRadius(7.0),
        ]
        onMouseDown={
          _ => {
            setValue(!value);
            onChange(!value);
            if (value) {
              resetPercentDone();
            } else {
              restartPercentDone();
            };
          }
        }>
        <BoxShadow
          boxShadow={
            Style.BoxShadow.make(
              ~xOffset=1.0,
              ~blurRadius=100.0,
              ~color=Colors.black,
              (),
            )
          }>
          <View
            style=Style.[
              width(0),
              height(0),
              position(`Absolute),
              left(int_of_float(percentDone *. 20. -. 8.)),
              top(-3),
              border(~width=10, ~color=handleColor),
              borderRadius(10.0),
            ]
          />
        </BoxShadow>
      </View>,
    );
  });
