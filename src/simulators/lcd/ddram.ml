
open Types

(* 128 * 8 pages of 1 byte(here : a char)  *)

let size = 128*8

let create () = Array.make size 0

let fill c display =
   Array.fill display.ddram 0 (Array.length display.ddram) c

let write =
  let i = ref 0 in
  fun c display ->
    display.ddram.(!i) <- c;
    incr i;
    i := !i mod size

let to_matrix display =
  let ddram = display.ddram in
  let matrix = display.matrix in
  for i = 0 to size-1 do
    let col = i mod 128 in (* 128 is col 0 *)
    let row = (i / 128)*8 in (* 128 is row 8 *)
    (* Probably shoudn't be hard-coded this way but there's no time ..  *)
    matrix.(col).(row+7) <- if ddram.(i) land 0b00000001 = 1 then true else false;
    matrix.(col).(row+6) <- if ddram.(i) land 0b00000010 = 0b10 then true else false;
    matrix.(col).(row+5) <- if ddram.(i) land 0b00000100 = 0b100 then true else false;
    matrix.(col).(row+4) <- if ddram.(i) land 0b00001000 = 0b1000 then true else false;
    matrix.(col).(row+3) <- if ddram.(i) land 0b00010000 = 0b10000 then true else false;
    matrix.(col).(row+2) <- if ddram.(i) land 0b00100000 = 0b000100000 then true else false;
    matrix.(col).(row+1) <- if ddram.(i) land 0b01000000 = 0b001000000 then true else false;
    matrix.(col).(row) <- if ddram.(i) land 0b10000000 = 0b10000000 then true else false;
  done

let print_ddram display =
  for i = 0 to size-1 do
      Printf.printf "%d" display.ddram.(i)
    done;
  print_newline ()

let print_matrix display =
  let print_bool = function
      true -> print_string "#"
    | false -> print_string "_"
  in
  let matrix = display.matrix in
  for i = 0 to 64-1 do
    for j = 0 to 128-1 do
      print_bool matrix.(j).(i)
    done;
    print_newline ();
  done