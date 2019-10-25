open Revery;
open Revery.UI;
open Revery.UI.Components;

open ReveryMaterial.MaterialStyles;
open ReveryMaterial.MaterialComponents;
open ReveryMaterial.MaterialColor;

let render = () =>
  <View style=Style.[margin(12)]>
    <Text style={TextStyle.heading1()} text="Button Examples" />
    <Text style={TextStyle.heading3()} text="Raised Button" />
    <RaisedButton>
      <Center>
        <Text
          style={
            TextStyle.medium(
              ~color=materialColor(~color=White, ~level=P500, ()),
              (),
            )
          }
          text="CLICK ME"
        />
      </Center>
    </RaisedButton>
    <Text style={TextStyle.heading3()} text="Flat Button" />
    <FlatButton>
      <Center>
        <Text
          style={
            TextStyle.medium(
              ~color=materialColor(~color=Blue, ~level=P500, ()),
              (),
            )
          }
          text="CLICK ME"
        />
      </Center>
    </FlatButton>
    <Text style={TextStyle.heading3()} text="Icon Flat Button" />
    <FlatButton>
      <View
        style=Style.[
          justifyContent(`Center),
          alignItems(`Center),
          flexDirection(`Row),
        ]>
        <MaterialIcon
          icon=Bookmark
          color={materialColor(~color=Blue, ~level=P500, ())}
        />
        <Text
          style={
            TextStyle.medium(
              ~color=materialColor(~color=Blue, ~level=P500, ()),
              (),
            )
          }
          text="BOOKMARK THIS PAGE"
        />
      </View>
    </FlatButton>
  </View>;
