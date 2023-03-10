bool kizil(int port) {
  if (port == 12) return dread(port);
  else return !dread(port);
}
