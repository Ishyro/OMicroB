open Pic32

let _ =
  init ();
  pin_mode A1 OUTPUT;
  while true do
    schedule_task ();
    digital_write A1 HIGH;
    delay 1000;
    digital_write A1 LOW;
    delay 1000;
  done
