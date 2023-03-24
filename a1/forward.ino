void go_forward(int SPEED) {
  awrite(right1, 0);
  awrite(right2, SPEED);
  awrite(left1, 0);
  awrite(left2, SPEED);
}