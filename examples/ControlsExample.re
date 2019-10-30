open Revery;
open Revery.UI;
open Revery.UI.Components;

open ReveryMaterial.MaterialStyles;
open ReveryMaterial.MaterialComponents;
open ReveryMaterial.MaterialColor;

module Example = {
  let component = React.component("ControlsExample");

  let createElement = (~children as _, ()) =>
    component(hooks => {
      let (toggleState, setToggleState, hooks) = Hooks.state(false, hooks);
      (
        hooks,
        <View style=Style.[margin(12)]>
          <Text style={TextStyle.heading1()} text="Controls Examples" />
          <Text style={TextStyle.heading3()} text="Slide Toggle" />
          <View style=Style.[flexDirection(`Row)]>
            <SlideToggle onChange={b => setToggleState(b)} />
            <Text
              style={TextStyle.regular()}
              text={toggleState ? "ON :)" : "OFF :("}
            />
          </View>
        </View>,
      );
    });
};

let render = () => <Example />;
