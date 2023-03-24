bool infared(int port) {
  if (port == 12) return dread(port);
  return !dread(port);
}
long ultra(int ping, int echo) {
  long duration, distance;
  dwrite(ping, LOW);
  delayMicroseconds(2);
  dwrite(ping, HIGH);
  delayMicroseconds(10);
  dwrite(ping, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration / 2) / 29.1;
  return distance;
}