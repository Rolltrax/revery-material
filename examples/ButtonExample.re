open Revery;
open Revery.UI;
open Revery.UI.Components;

open ReveryMaterial.MaterialStyles;
open ReveryMaterial.MaterialComponents;
open ReveryMaterial.MaterialColor;

let render = () =>
  <View style=Style.[margin(12)]>
    <Text style={TextStyle.heading1()} text="Button Examples" />
    <Text style={TextStyle.heading4()} text="Raised Button" />
    <RaisedButton>
      <Center>
        <Text
          style={
            TextStyle.medium(
              ~color=materialColor(~color=White, ~level=P500, ()),
              (),
            )
          }
          text="ABC"
        />
      </Center>
    </RaisedButton>
  </View>;
