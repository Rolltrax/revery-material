open Revery;

type level =
  | P50
  | P100
  | P200
  | P300
  | P400
  | P500
  | P600
  | P700
  | P800
  | P900
  | A100
  | A200
  | A400
  | A700;

let levelIntMap = Hashtbl.create(14);
Hashtbl.add(levelIntMap, P50, 0);
Hashtbl.add(levelIntMap, P100, 1);
Hashtbl.add(levelIntMap, P200, 2);
Hashtbl.add(levelIntMap, P300, 3);
Hashtbl.add(levelIntMap, P400, 4);
Hashtbl.add(levelIntMap, P500, 5);
Hashtbl.add(levelIntMap, P600, 6);
Hashtbl.add(levelIntMap, P700, 7);
Hashtbl.add(levelIntMap, P800, 8);
Hashtbl.add(levelIntMap, P900, 9);
Hashtbl.add(levelIntMap, A100, 10);
Hashtbl.add(levelIntMap, A200, 11);
Hashtbl.add(levelIntMap, A400, 12);
Hashtbl.add(levelIntMap, A700, 13);

let intLevelMap = Hashtbl.create(14);
Hashtbl.add(intLevelMap, 0, P50);
Hashtbl.add(intLevelMap, 1, P100);
Hashtbl.add(intLevelMap, 2, P200);
Hashtbl.add(intLevelMap, 3, P300);
Hashtbl.add(intLevelMap, 4, P400);
Hashtbl.add(intLevelMap, 5, P500);
Hashtbl.add(intLevelMap, 6, P600);
Hashtbl.add(intLevelMap, 7, P700);
Hashtbl.add(intLevelMap, 8, P800);
Hashtbl.add(intLevelMap, 9, P900);
Hashtbl.add(intLevelMap, 10, A100);
Hashtbl.add(intLevelMap, 11, A200);
Hashtbl.add(intLevelMap, 12, A400);
Hashtbl.add(intLevelMap, 13, A700);

type color =
  | Red
  | Pink
  | Purple
  | DeepPurple
  | Indigo
  | Blue
  | LightBlue
  | Cyan
  | Teal
  | Green
  | LightGreen
  | Lime
  | Yellow
  | Amber
  | Orange
  | DeepOrange
  | Brown
  | Grey
  | BlueGrey;

type materialColor = {
  color,
  level,
};

let materialColor = (~color, ~level) => {color, level};

let toReveryColor = (c: materialColor) =>
  switch (c) {
  | {color: Red, level: P50} => Color.hex("#ffebee")
  | {color: Red, level: P100} => Color.hex("#ffcdd2")
  | {color: Red, level: P200} => Color.hex("#ef9a9a")
  | {color: Red, level: P300} => Color.hex("#e57373")
  | {color: Red, level: P400} => Color.hex("#ef5350")
  | {color: Red, level: P500} => Color.hex("#f44336")
  | {color: Red, level: P600} => Color.hex("#e53935")
  | {color: Red, level: P700} => Color.hex("#d32f2f")
  | {color: Red, level: P800} => Color.hex("#c62828")
  | {color: Red, level: P900} => Color.hex("#b71c1c")
  | {color: Red, level: A100} => Color.hex("#ff8a80")
  | {color: Red, level: A200} => Color.hex("#ff5252")
  | {color: Red, level: A400} => Color.hex("#ff1744")
  | {color: Red, level: A700} => Color.hex("#d50000")
  | {color: Pink, level: P50} => Color.hex("#fce4ec")
  | {color: Pink, level: P100} => Color.hex("#f8bbd0")
  | {color: Pink, level: P200} => Color.hex("#f48fb1")
  | {color: Pink, level: P300} => Color.hex("#f06292")
  | {color: Pink, level: P400} => Color.hex("#ec407a")
  | {color: Pink, level: P500} => Color.hex("#e91e63")
  | {color: Pink, level: P600} => Color.hex("#d81b60")
  | {color: Pink, level: P700} => Color.hex("#c2185b")
  | {color: Pink, level: P800} => Color.hex("#ad1457")
  | {color: Pink, level: P900} => Color.hex("#880e4f")
  | {color: Pink, level: A100} => Color.hex("#ff80ab")
  | {color: Pink, level: A200} => Color.hex("#ff4081")
  | {color: Pink, level: A400} => Color.hex("#f50057")
  | {color: Pink, level: A700} => Color.hex("#c51162")
  | {color: Purple, level: P50} => Color.hex("#f3e5f5")
  | {color: Purple, level: P100} => Color.hex("#e1bee7")
  | {color: Purple, level: P200} => Color.hex("#ce93d8")
  | {color: Purple, level: P300} => Color.hex("#ba68c8")
  | {color: Purple, level: P400} => Color.hex("#ab47bc")
  | {color: Purple, level: P500} => Color.hex("#9c27b0")
  | {color: Purple, level: P600} => Color.hex("#8e24aa")
  | {color: Purple, level: P700} => Color.hex("#7b1fa2")
  | {color: Purple, level: P800} => Color.hex("#6a1b9a")
  | {color: Purple, level: P900} => Color.hex("#4a148c")
  | {color: Purple, level: A100} => Color.hex("#ea80fc")
  | {color: Purple, level: A200} => Color.hex("#e040fb")
  | {color: Purple, level: A400} => Color.hex("#d500f9")
  | {color: Purple, level: A700} => Color.hex("#aa00ff")
  | {color: DeepPurple, level: P50} => Color.hex("#ede7f6")
  | {color: DeepPurple, level: P100} => Color.hex("#d1c4e9")
  | {color: DeepPurple, level: P200} => Color.hex("#b39ddb")
  | {color: DeepPurple, level: P300} => Color.hex("#9575cd")
  | {color: DeepPurple, level: P400} => Color.hex("#7e57c2")
  | {color: DeepPurple, level: P500} => Color.hex("#673ab7")
  | {color: DeepPurple, level: P600} => Color.hex("#5e35b1")
  | {color: DeepPurple, level: P700} => Color.hex("#512da8")
  | {color: DeepPurple, level: P800} => Color.hex("#4527a0")
  | {color: DeepPurple, level: P900} => Color.hex("#311b92")
  | {color: DeepPurple, level: A100} => Color.hex("#b388ff")
  | {color: DeepPurple, level: A200} => Color.hex("#7c4dff")
  | {color: DeepPurple, level: A400} => Color.hex("#651fff")
  | {color: DeepPurple, level: A700} => Color.hex("#6200ea")
  | {color: Indigo, level: P50} => Color.hex("#e8eaf6")
  | {color: Indigo, level: P100} => Color.hex("#c5cae9")
  | {color: Indigo, level: P200} => Color.hex("#9fa8da")
  | {color: Indigo, level: P300} => Color.hex("#7986cb")
  | {color: Indigo, level: P400} => Color.hex("#5c6bc0")
  | {color: Indigo, level: P500} => Color.hex("#3f51b5")
  | {color: Indigo, level: P600} => Color.hex("#3949ab")
  | {color: Indigo, level: P700} => Color.hex("#303f9f")
  | {color: Indigo, level: P800} => Color.hex("#283593")
  | {color: Indigo, level: P900} => Color.hex("#1a237e")
  | {color: Indigo, level: A100} => Color.hex("#8c9eff")
  | {color: Indigo, level: A200} => Color.hex("#536dfe")
  | {color: Indigo, level: A400} => Color.hex("#3d5afe")
  | {color: Indigo, level: A700} => Color.hex("#304ffe")
  | {color: Blue, level: P50} => Color.hex("#e3f2fd")
  | {color: Blue, level: P100} => Color.hex("#bbdefb")
  | {color: Blue, level: P200} => Color.hex("#90caf9")
  | {color: Blue, level: P300} => Color.hex("#64b5f6")
  | {color: Blue, level: P400} => Color.hex("#42a5f5")
  | {color: Blue, level: P500} => Color.hex("#2196f3")
  | {color: Blue, level: P600} => Color.hex("#1e88e5")
  | {color: Blue, level: P700} => Color.hex("#1976d2")
  | {color: Blue, level: P800} => Color.hex("#1565c0")
  | {color: Blue, level: P900} => Color.hex("#0d47a1")
  | {color: Blue, level: A100} => Color.hex("#82b1ff")
  | {color: Blue, level: A200} => Color.hex("#448aff")
  | {color: Blue, level: A400} => Color.hex("#2979ff")
  | {color: Blue, level: A700} => Color.hex("#2962ff")
  | {color: LightBlue, level: P50} => Color.hex("#e1f5fe")
  | {color: LightBlue, level: P100} => Color.hex("#b3e5fc")
  | {color: LightBlue, level: P200} => Color.hex("#81d4fa")
  | {color: LightBlue, level: P300} => Color.hex("#4fc3f7")
  | {color: LightBlue, level: P400} => Color.hex("#29b6f6")
  | {color: LightBlue, level: P500} => Color.hex("#03a9f4")
  | {color: LightBlue, level: P600} => Color.hex("#039be5")
  | {color: LightBlue, level: P700} => Color.hex("#0288d1")
  | {color: LightBlue, level: P800} => Color.hex("#0277bd")
  | {color: LightBlue, level: P900} => Color.hex("#01579b")
  | {color: LightBlue, level: A100} => Color.hex("#80d8ff")
  | {color: LightBlue, level: A200} => Color.hex("#40c4ff")
  | {color: LightBlue, level: A400} => Color.hex("#00b0ff")
  | {color: LightBlue, level: A700} => Color.hex("#0091ea")
  | {color: Cyan, level: P50} => Color.hex("#e0f7fa")
  | {color: Cyan, level: P100} => Color.hex("#b2ebf2")
  | {color: Cyan, level: P200} => Color.hex("#80deea")
  | {color: Cyan, level: P300} => Color.hex("#4dd0e1")
  | {color: Cyan, level: P400} => Color.hex("#26c6da")
  | {color: Cyan, level: P500} => Color.hex("#00bcd4")
  | {color: Cyan, level: P600} => Color.hex("#00acc1")
  | {color: Cyan, level: P700} => Color.hex("#0097a7")
  | {color: Cyan, level: P800} => Color.hex("#00838f")
  | {color: Cyan, level: P900} => Color.hex("#006064")
  | {color: Cyan, level: A100} => Color.hex("#84ffff")
  | {color: Cyan, level: A200} => Color.hex("#18ffff")
  | {color: Cyan, level: A400} => Color.hex("#00e5ff")
  | {color: Cyan, level: A700} => Color.hex("#00b8d4")
  | {color: Teal, level: P50} => Color.hex("#e0f2f1")
  | {color: Teal, level: P100} => Color.hex("#b2dfdb")
  | {color: Teal, level: P200} => Color.hex("#80cbc4")
  | {color: Teal, level: P300} => Color.hex("#4db6ac")
  | {color: Teal, level: P400} => Color.hex("#26a69a")
  | {color: Teal, level: P500} => Color.hex("#009688")
  | {color: Teal, level: P600} => Color.hex("#00897b")
  | {color: Teal, level: P700} => Color.hex("#00796b")
  | {color: Teal, level: P800} => Color.hex("#00695c")
  | {color: Teal, level: P900} => Color.hex("#004d40")
  | {color: Teal, level: A100} => Color.hex("#a7ffeb")
  | {color: Teal, level: A200} => Color.hex("#64ffda")
  | {color: Teal, level: A400} => Color.hex("#1de9b6")
  | {color: Teal, level: A700} => Color.hex("#00bfa5")
  | {color: Green, level: P50} => Color.hex("#e8f5e9")
  | {color: Green, level: P100} => Color.hex("#c8e6c9")
  | {color: Green, level: P200} => Color.hex("#a5d6a7")
  | {color: Green, level: P300} => Color.hex("#81c784")
  | {color: Green, level: P400} => Color.hex("#66bb6a")
  | {color: Green, level: P500} => Color.hex("#4caf50")
  | {color: Green, level: P600} => Color.hex("#43a047")
  | {color: Green, level: P700} => Color.hex("#388e3c")
  | {color: Green, level: P800} => Color.hex("#2e7d32")
  | {color: Green, level: P900} => Color.hex("#1b5e20")
  | {color: Green, level: A100} => Color.hex("#b9f6ca")
  | {color: Green, level: A200} => Color.hex("#69f0ae")
  | {color: Green, level: A400} => Color.hex("#00e676")
  | {color: Green, level: A700} => Color.hex("#00c853")
  | {color: LightGreen, level: P50} => Color.hex("#f1f8e9")
  | {color: LightGreen, level: P100} => Color.hex("#dcedc8")
  | {color: LightGreen, level: P200} => Color.hex("#c5e1a5")
  | {color: LightGreen, level: P300} => Color.hex("#aed581")
  | {color: LightGreen, level: P400} => Color.hex("#9ccc65")
  | {color: LightGreen, level: P500} => Color.hex("#8bc34a")
  | {color: LightGreen, level: P600} => Color.hex("#7cb342")
  | {color: LightGreen, level: P700} => Color.hex("#689f38")
  | {color: LightGreen, level: P800} => Color.hex("#558b2f")
  | {color: LightGreen, level: P900} => Color.hex("#33691e")
  | {color: LightGreen, level: A100} => Color.hex("#ccff90")
  | {color: LightGreen, level: A200} => Color.hex("#b2ff59")
  | {color: LightGreen, level: A400} => Color.hex("#76ff03")
  | {color: LightGreen, level: A700} => Color.hex("#64dd17")
  | {color: Lime, level: P50} => Color.hex("#f9fbe7")
  | {color: Lime, level: P100} => Color.hex("#f0f4c3")
  | {color: Lime, level: P200} => Color.hex("#e6ee9c")
  | {color: Lime, level: P300} => Color.hex("#dce775")
  | {color: Lime, level: P400} => Color.hex("#d4e157")
  | {color: Lime, level: P500} => Color.hex("#cddc39")
  | {color: Lime, level: P600} => Color.hex("#c0ca33")
  | {color: Lime, level: P700} => Color.hex("#afb42b")
  | {color: Lime, level: P800} => Color.hex("#9e9d24")
  | {color: Lime, level: P900} => Color.hex("#827717")
  | {color: Lime, level: A100} => Color.hex("#f4ff81")
  | {color: Lime, level: A200} => Color.hex("#eeff41")
  | {color: Lime, level: A400} => Color.hex("#c6ff00")
  | {color: Lime, level: A700} => Color.hex("#aeea00")
  | {color: Yellow, level: P50} => Color.hex("#fffde7")
  | {color: Yellow, level: P100} => Color.hex("#fff9c4")
  | {color: Yellow, level: P200} => Color.hex("#fff59d")
  | {color: Yellow, level: P300} => Color.hex("#fff176")
  | {color: Yellow, level: P400} => Color.hex("#ffee58")
  | {color: Yellow, level: P500} => Color.hex("#ffeb3b")
  | {color: Yellow, level: P600} => Color.hex("#fdd835")
  | {color: Yellow, level: P700} => Color.hex("#fbc02d")
  | {color: Yellow, level: P800} => Color.hex("#f9a825")
  | {color: Yellow, level: P900} => Color.hex("#f57f17")
  | {color: Yellow, level: A100} => Color.hex("#ffff8d")
  | {color: Yellow, level: A200} => Color.hex("#ffff00")
  | {color: Yellow, level: A400} => Color.hex("#ffea00")
  | {color: Yellow, level: A700} => Color.hex("#ffd600")
  | {color: Amber, level: P50} => Color.hex("#fff8e1")
  | {color: Amber, level: P100} => Color.hex("#ffecb3")
  | {color: Amber, level: P200} => Color.hex("#ffe082")
  | {color: Amber, level: P300} => Color.hex("#ffd54f")
  | {color: Amber, level: P400} => Color.hex("#ffca28")
  | {color: Amber, level: P500} => Color.hex("#ffc107")
  | {color: Amber, level: P600} => Color.hex("#ffb300")
  | {color: Amber, level: P700} => Color.hex("#ffa000")
  | {color: Amber, level: P800} => Color.hex("#ff8f00")
  | {color: Amber, level: P900} => Color.hex("#ff6f00")
  | {color: Amber, level: A100} => Color.hex("#ffe57f")
  | {color: Amber, level: A200} => Color.hex("#ffd740")
  | {color: Amber, level: A400} => Color.hex("#ffc400")
  | {color: Amber, level: A700} => Color.hex("#ffab00")
  | {color: Orange, level: P50} => Color.hex("#fff3e0")
  | {color: Orange, level: P100} => Color.hex("#ffe0b2")
  | {color: Orange, level: P200} => Color.hex("#ffcc80")
  | {color: Orange, level: P300} => Color.hex("#ffb74d")
  | {color: Orange, level: P400} => Color.hex("#ffa726")
  | {color: Orange, level: P500} => Color.hex("#ff9800")
  | {color: Orange, level: P600} => Color.hex("#fb8c00")
  | {color: Orange, level: P700} => Color.hex("#f57c00")
  | {color: Orange, level: P800} => Color.hex("#ef6c00")
  | {color: Orange, level: P900} => Color.hex("#e65100")
  | {color: Orange, level: A100} => Color.hex("#ffd180")
  | {color: Orange, level: A200} => Color.hex("#ffab40")
  | {color: Orange, level: A400} => Color.hex("#ff9100")
  | {color: Orange, level: A700} => Color.hex("#ff6d00")
  | {color: DeepOrange, level: P50} => Color.hex("#fbe9e7")
  | {color: DeepOrange, level: P100} => Color.hex("#ffccbc")
  | {color: DeepOrange, level: P200} => Color.hex("#ffab91")
  | {color: DeepOrange, level: P300} => Color.hex("#ff8a65")
  | {color: DeepOrange, level: P400} => Color.hex("#ff7043")
  | {color: DeepOrange, level: P500} => Color.hex("#ff5722")
  | {color: DeepOrange, level: P600} => Color.hex("#f4511e")
  | {color: DeepOrange, level: P700} => Color.hex("#e64a19")
  | {color: DeepOrange, level: P800} => Color.hex("#d84315")
  | {color: DeepOrange, level: P900} => Color.hex("#bf360c")
  | {color: DeepOrange, level: A100} => Color.hex("#ff9e80")
  | {color: DeepOrange, level: A200} => Color.hex("#ff6e40")
  | {color: DeepOrange, level: A400} => Color.hex("#ff3d00")
  | {color: DeepOrange, level: A700} => Color.hex("#dd2c00")
  | {color: Brown, level: P50} => Color.hex("#efebe9")
  | {color: Brown, level: P100} => Color.hex("#d7ccc8")
  | {color: Brown, level: P200} => Color.hex("#bcaaa4")
  | {color: Brown, level: P300} => Color.hex("#a1887f")
  | {color: Brown, level: P400} => Color.hex("#8d6e63")
  | {color: Brown, level: P500} => Color.hex("#795548")
  | {color: Brown, level: P600} => Color.hex("#6d4c41")
  | {color: Brown, level: P700} => Color.hex("#5d4037")
  | {color: Brown, level: P800} => Color.hex("#4e342e")
  | {color: Brown, level: P900} => Color.hex("#3e2723")
  | {color: Grey, level: P50} => Color.hex("#fafafa")
  | {color: Grey, level: P100} => Color.hex("#f5f5f5")
  | {color: Grey, level: P200} => Color.hex("#eeeeee")
  | {color: Grey, level: P300} => Color.hex("#e0e0e0")
  | {color: Grey, level: P400} => Color.hex("#bdbdbd")
  | {color: Grey, level: P500} => Color.hex("#9e9e9e")
  | {color: Grey, level: P600} => Color.hex("#757575")
  | {color: Grey, level: P700} => Color.hex("#616161")
  | {color: Grey, level: P800} => Color.hex("#424242")
  | {color: Grey, level: P900} => Color.hex("#212121")
  | {color: BlueGrey, level: P50} => Color.hex("#eceff1")
  | {color: BlueGrey, level: P100} => Color.hex("#cfd8dc")
  | {color: BlueGrey, level: P200} => Color.hex("#b0bec5")
  | {color: BlueGrey, level: P300} => Color.hex("#90a4ae")
  | {color: BlueGrey, level: P400} => Color.hex("#78909c")
  | {color: BlueGrey, level: P500} => Color.hex("#607d8b")
  | {color: BlueGrey, level: P600} => Color.hex("#546e7a")
  | {color: BlueGrey, level: P700} => Color.hex("#455a64")
  | {color: BlueGrey, level: P800} => Color.hex("#37474f")
  | {color: BlueGrey, level: P900} => Color.hex("#263238")
  };

let add = (materialColor, addend) => {
  let {color, level} = materialColor;
  let i = Hashtbl.find(levelIntMap, level);
  let i2 =
    i + addend > Hashtbl.length(levelIntMap) - 1 ?
      Hashtbl.length(levelIntMap) - 1 : i;
  Hashtbl.find(intLevelMap, i2);
};

let subtract = (materialColor, subtractend) => {
  let {color, level} = materialColor;
  let i = Hashtbl.find(levelIntMap, level);
  let i2 = i - subtractend < 0 ? 0 : i;
  Hashtbl.find(intLevelMap, i2);
};
