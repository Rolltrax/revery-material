open Revery;
open Revery.UI;
open Revery.UI.Components;

open ReveryMaterial.MaterialStyles;
open ReveryMaterial.MaterialComponents;
open ReveryMaterial.MaterialColor;

let render = () =>
  <View style=Style.[margin(12)]>
    <Text style={TextStyle.heading1()} text="Controls Examples" />
    <Text style={TextStyle.heading3()} text="Slide Toggle" />
    <SlideToggle />
  </View>;
