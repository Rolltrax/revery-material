open Revery;
open Revery.UI;
open Revery.UI.Components;

open ReveryMaterial.MaterialStyles;
open ReveryMaterial.MaterialComponents;
open ReveryMaterial.MaterialColor;

let render = () =>
  <View
    style=Style.[
      margin(12),
      position(`Absolute),
      top(0),
      left(0),
      bottom(0),
      right(0),
    ]>
    <ScrollView
      style=Style.[
        position(`Absolute),
        top(0),
        left(0),
        bottom(0),
        right(0),
        backgroundColor(Colors.white),
      ]>
      <View>
        <Text style={TextStyle.heading1()} text="Icons Examples" />
        <View>
          ...{
               List.map(
                 x =>
                   <View
                     style=Style.[flexDirection(`Row), alignItems(`Center)]>
                     <MaterialIcon icon=x size=24 />
                     <Text
                       style={TextStyle.medium()}
                       text={" " ++ MaterialIcon.getIconName(x)}
                     />
                   </View>,
                 MaterialIcon.iconList,
               )
             }
        </View>
      </View>
    </ScrollView>
  </View>;
