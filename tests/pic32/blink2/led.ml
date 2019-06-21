let _ =
  pin_mode PIN4 OUTPUT;
  pin_mode PIN31 OUTPUT;
  while true do
    digital_write PIN4 HIGH;
    digital_write PIN31 HIGH;
    delay 1000;
    digital_write PIN4 LOW;
    digital_write PIN31 LOW;
    delay 1000;
  done
