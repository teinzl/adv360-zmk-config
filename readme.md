# Custom Kinesis Advantage 360 pro ZMK config


This is a custom config built off off [urob's demo config](https://github.com/urob/adv360-demo-config) with many features borrowed from his [zmk-config](https://github.com/urob/zmk-config) as well

The keymap contains 10 layers:
- Colemak base layer
  - includes brightness and volume controls, caps word/lock, num word, and hyper keys in the bottom row
- Qwerty layer
- Number layer
  - accessible via left and right thumb keys or num-word toggles
  - places numbers in a two row format on the left hand
  - places hjkl on the right hand home row for ease of use in vim
- Symbols layer
  - accessible via left thumb key
  - places brackets and vim-navigation related symbols on the right hand
    - caret and dollar mapped over left and right nav locations
    - slash on the pinky for search
  - places comparison and arithmetic operators on the left
    - GT & LT are on R and G, mirroring nav directions on the right hand
    - dash and equals, the two most often used symbols, are on two strongest fingers in the home row
    - @ on the pinky for vim macros
- Function layer
  - accessible via right thumb cluster
  - places function keys on the left hand in the same layout as the num layer, plus across the top
- Mod layer
  - for switching bluetooth profiles, bootloader access, and keyboard brigtness controls
- Mouse layer
  - accessible via left thumb cluster
  - places mouse movement and scroll controls on the right hand
- Navigation layer
  - accessible via right thumb key
  - places arrows and tab controls on the right hand, spectacle controls, and app/window switchers on the left
- Media layer
  - accessible through a hold on M
  - places media controls on the left hand
- Command layer
  - accessible via both thumb clusters
  - turns every key into a command+click on tap, shift+command+click on hold


<img src="https://github.com/cosmicbuffalo/adv360-zmk-config/blob/main/keymap.jpg?raw=true">
