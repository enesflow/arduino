void __don(int SPEED, bool move_forward, int s1, int s2, int f1, int f2) {
  awrite(f1, 0);
  awrite(f2, SPEED);
  if (!move_forward) {
    awrite(s1, SPEED);
    awrite(s2, 0);
  } else {
    awrite(s1, 0);
    awrite(s2, 0);
  }
}

void go_right(int SPEED, bool move_forward) {
  __don(SPEED, move_forward, right1, right2, left1, left2);
}

void go_left(int SPEED, bool move_forward) {
  __don(SPEED, move_forward, left1, left2, right1, right2);
}
