# Generates the switch statement for the material design

import json

file = open("./assets/mdi.json")

icon_map = json.loads(file.read())
file.close()

switch = ""
type_ = ""

for key, value in icon_map["icons"].items():
  character = chr(int(key, 16))
  name = value["name"].replace(" ", "")
  switch += str.format("| {} => \"{}\" \n", name, character)
  type_ += str.format("| {}\n", name)


with open("./switch_icons.txt", "w") as f:
  f.write(switch)

with open("./type_icons.txt", "w") as f:
  f.write(type_)

