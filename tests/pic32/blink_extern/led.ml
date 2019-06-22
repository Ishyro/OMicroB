let _ =
  let pin = PIN10 in
  pin_mode pin OUTPUT;
  while true do
    digital_write pin HIGH;
    delay 1000;
    digital_write pin LOW;
    delay 1000;
  done
