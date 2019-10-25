open Revery;

open Revery.UI;
open Revery.UI.Components;

open ReveryMaterial_Colors;
open ReveryMaterial_Utils;

let component = React.component("RaisedButton");

let createElement =
    (
      ~children,
      ~onClick=() => (),
      ~disabled=false,
      ~color as c=materialColor(~color=Blue, ~level=P500, ()),
      ~disabledColor=materialColor(~color=Grey, ~level=P200, ()),
      (),
    ) =>
  component(hooks => {
    let (isHovered, setIsHovered, hooks) = Hooks.state(false, hooks);
    let (shadow, pauseShadow, restartShadow, hooks) =
      Hooks.animation(
        Animated.floatValue(2.),
        Animated.options(
          ~toValue=8.0,
          ~duration=Seconds(0.2),
          ~easing=Easing.easeInOut,
          (),
        ),
        hooks,
      );

    let (circleRadius, pauseCircleRadius, restartCircleRadius, hooks) =
      Hooks.animation(
        Animated.floatValue(0.),
        Animated.options(
          ~toValue=1000.0,
          ~duration=Seconds(0.4),
          ~easing=MaterialEasing.standardEasing,
          (),
        ),
        hooks,
      );

    let (circleOpacity, pauseCircleOpacity, restartCircleOpacity, hooks) =
      Hooks.animation(
        Animated.floatValue(0.),
        Animated.options(
          ~toValue=1.,
          ~duration=Seconds(0.6),
          ~delay=Seconds(0.5),
          (),
        ),
        hooks,
      );

    let resetShadow = () => {
      restartShadow();
      pauseShadow() |> ignore;
    };

    let resetCircleRadius = () => {
      restartCircleRadius();
      pauseCircleRadius() |> ignore;
    };

    let resetCircleOpacity = () => {
      restartCircleOpacity();
      pauseCircleOpacity() |> ignore;
    };

    let hooks =
      Hooks.effect(
        OnMount,
        () => {
          resetShadow();
          resetCircleRadius();
          resetCircleOpacity();
          None;
        },
        hooks,
      );

    let bgColor = (isHovered ? subtract(c, 1) : c) |> toReveryColor;

    let calculateCircleColor = () => {
      let (r1, g1, b1, _) = subtract(c, 3) |> toReveryColor |> Color.toRgba;
      let (r2, g2, b2, _) = bgColor |> Color.toRgba;
      let (diffR, diffG, diffB) = (r2 -. r1, g2 -. g1, b2 -. b1);
      let c =
        Color.rgb(
          r1 +. diffR *. circleOpacity,
          g1 +. diffG *. circleOpacity,
          b1 +. diffB *. circleOpacity,
        );
      c;
    };

    let borderWidth = 4;
    (
      hooks,
      <Clickable onClick={disabled ? () => () : onClick}>
        <BoxShadow
          boxShadow={
            Style.BoxShadow.make(
              ~xOffset=(-1.) *. shadow,
              ~yOffset=shadow,
              ~blurRadius=shadow *. 2.,
              ~color=Colors.lightGrey,
              (),
            )
          }>
          <View
            onMouseEnter={
              _ => {
                setIsHovered(true);
                restartShadow();
              }
            }
            onMouseLeave={
              _ => {
                setIsHovered(false);
                resetShadow();
                resetCircleRadius();
              }
            }
            onMouseDown={
              _ => {
                restartCircleRadius();
                restartCircleOpacity();
              }
            }
            style=Style.[
              backgroundColor(bgColor),
              border(~color=bgColor, ~width=borderWidth),
              borderRadius(float_of_int(borderWidth)),
              padding(4),
              overflow(`Hidden),
            ]>
            <View
              style=Style.[
                position(`Absolute),
                justifyContent(`Center),
                alignItems(`Center),
                right(0),
                bottom(0),
                top(0),
                left(0),
              ]>
              <View
                style=Style.[
                  border(
                    ~color=calculateCircleColor(),
                    ~width=int_of_float(circleRadius),
                  ),
                  borderRadius(circleRadius),
                ]
              />
            </View>
            <View> ...children </View>
          </View>
        </BoxShadow>
      </Clickable>,
    );
  });
