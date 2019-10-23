open Revery;
open Revery.UI;
open Revery.UI.Components;

open ReveryMaterial;
open ReveryMaterial.MaterialColor;

type example = {
  name: string,
  render: Window.t => React.syntheticElement,
  source: string,
};

type examples =
  | Button
  | Test;

let getExample = (x: examples) =>
  switch (x) {
  | Button => {
      name: "ButtonExample",
      render: _ => ButtonExample.render(),
      source: "ButtonExample.re",
    }
  | Test => {name: "[nothing]", render: _ => <View />, source: "[nothing]"}
  };

module ExampleButton = {
  let component = React.component("ExampleButton");

  let createElement = (~children as _, ~isActive, ~name, ~onClick, ()) =>
    component(hooks => {
      let bgColor =
        isActive ?
          MaterialColor.toReveryColor(
            materialColor(~color=Grey, ~level=P200),
          ) :
          Colors.white;
      let textStyle =
        Style.[
          color(Colors.black),
          fontFamily("Roboto-Regular.ttf"),
          fontSize(14),
          margin(14),
        ];
      (
        hooks,
        <Opacity>
          <Clickable style=Style.[backgroundColor(bgColor)]>
            <Text style=textStyle text=name />
          </Clickable>
        </Opacity>,
      );
    });
};

module ExampleHost = {
  let component = React.component("ExampleHost");

  let createElement = (~children as _, ~win, ()) =>
    component(hooks => {
      let (currentExample, setCurrentExample, hooks) =
        Hooks.state(Button, hooks);

      let example = getExample(currentExample);

      let renderButton = (x: examples) => {
        let isActive = x == currentExample;
        let example = getExample(x);
        <ExampleButton
          isActive
          name={example.name}
          onClick={
            _ => {
              Window.setTitle(win, "Example :: " ++ example.name);
              setCurrentExample(x);
            }
          }
        />;
      };

      let borderColor =
        materialColor(~color=Grey, ~level=P400) |> toReveryColor;

      let renderButtons = buttons => List.map(x => renderButton(x), buttons);
      let buttons = renderButtons([Button, Test]);

      (
        hooks,
        <View
          onMouseWheel={_ => ()}
          style=Style.[
            position(`Absolute),
            backgroundColor(Colors.white),
            bottom(0),
            top(0),
            left(0),
            right(0),
            flexDirection(`Row),
          ]>
          <ScrollView
            style=Style.[
              position(`Absolute),
              top(0),
              left(0),
              width(175),
              bottom(0),
              backgroundColor(Colors.white),
              borderRight(~width=1, ~color=borderColor),
            ]>
            <View> ...buttons </View>
          </ScrollView>
          <View
            style=Style.[
              position(`Absolute),
              top(0),
              left(175),
              right(0),
              bottom(0),
              backgroundColor(Colors.white),
            ]>
            {example.render(win)}
          </View>
        </View>,
      );
    });
};

let init = app => {
  let _ignore = Log.listen((_, msg) => print_endline(msg));

  let maximized = Environment.webGL;

  let windowWidth = 800;
  let windowHeight = 480;

  let win =
    App.createWindow(
      ~createOptions=
        WindowCreateOptions.create(
          ~width=windowWidth,
          ~height=windowHeight,
          ~maximized,
          ~icon=Some("revery-icon.png"),
          (),
        ),
      app,
      "ReveryMaterial",
    );

  if (Environment.webGL) {
    Window.maximize(win);
    ();
  } else {
    Window.center(win);
    ();
  };

  let _ignore = UI.start(win, <ExampleHost win />);
  ();
};

App.start(init);
