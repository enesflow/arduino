void __don(int hiz, bool ilerle, int f1, int f2, int s1, int s2) {
  awrite(f1, 0);
  awrite(f2, 0);
  if (!ilerle) {
    awrite(s1, hiz);
    awrite(s2, 0);
  } else {
    awrite(s1, 0);
    awrite(s2, 0);
  }
}

void sag(int hiz, bool ilerle) {
  __don(hiz, ilerle, sag1, sag2, sol1, sol2);
}

void sol(int hiz, bool ilerle) {
  __don(hiz, ilerle, sol1, sol2, sag1, sag2);
}
