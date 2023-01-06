# CYURD127doorStrike

## description
### components
[Door strike](https://www.amazon.com/dp/B071HBR584?psc=1&ref=ppx_yo2ov_dt_b_product_details) for 255 Chestnut Ave front door. Strike is operated through a 12 DC relay. Other components include an [ACDC switching power supply w dual 5V 1A, 12V 8A output](https://www.ebay.com/itm/383719573513), a [NC magnetic contact door](https://www.amazon.com/dp/B075Q4NJBB?psc=1&ref=ppx_yo2ov_dt_b_product_details) and a [4pin multicolor LED](https://www.amazon.com/gp/product/B077XGF3YR/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1)

### operation
When the door is closed, with contacts closed and the strike is locked (not powered, fail secure) the LED is red.  When the button is pushed on the app the strike is released and the LED goes green. Once the door is opened the LED turns blue, which signals the app to turn unpush the button and lock the stike. Once the door closes and the contacts connect, the led turnd red.

### configuration
The device has: 

- 1 input: the magnetic door contact
  - D2 - sr0 contact
- 4 outputs: the strike and the red, green and blue LED. \
  - D6 - sr1 redLED
  - D7 - sr2 greenLED
  - D8 - sr3 blueLED
  - D1 - sr4 strike

