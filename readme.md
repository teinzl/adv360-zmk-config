# Custom Kinesis Advantage 360 pro ZMK config


This is a custom config built off off [urob's demo config](https://github.com/urob/adv360-demo-config) with many features borrowed from his [zmk-config](https://github.com/urob/zmk-config) as well

The keymap contains 8 layers:
- Colemak base layer
  - includes brightness and volume controls, caps word/lock, num word, and hyper keys in the bottom row
- Qwerty layer
- Number layer
  - accessible via left thumb key or num-word toggles
  - places a num pad on the right hand with 0 on the right thumb
  - right hand pinky is a command/$ hold/tap
  - left hand includes most symbols that are often combined with numbers
    - nearly the same as the sym layer left hand, but adds `,` and `.` in place of `|` and `&`
  - double tapping space on the num layer outputs comma + space
- Symbol layer
  - accessible via left thumb key
  - places brackets, macro and vim-relevant symbols on the right hand
  - left and right pinkies are `^` and `$` for vim line navigation
  - left hand symbols are optimized for combinations with `=`
- Function layer
  - accessible via right thumb cluster
  - places function keys on the right hand in the same layout as the num layer, plus across the top
  - alternative access to brightness controls and screen lock on left thumb cluster
- Mod/Media layer
  - accessible through a hold on M or dedicated layer hold keys
  - places media controls on left home row and right thumb cluster
  - includes controls for switching bluetooth profiles, bootloader access, and adjusting keyboard brightness
- Mouse layer
  - accessible via left thumb cluster
  - places mouse movement and scroll controls on the right hand slong withc clipboard controls
  - includes home row mod keys and hold/taps for command shortcuts on the left hand for easy one handed command usage
- Navigation layer
  - accessible via right thumb key
  - places arrows and tab controls on the right hand, spectacle controls, and app/window switchers on the left
  - previous and next tab on the outer pinky keys
  - also includes same clipboard controls as mouse layer


<img src="https://github.com/cosmicbuffalo/adv360-zmk-config/blob/main/keymap.jpg?raw=true">
