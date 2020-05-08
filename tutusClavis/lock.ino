







int lock = 13; // Lock signal connected to digital 13.

void lockInit()
{
  pinMode(lock, OUTPUT); //Initialize lock as output pin.
}


void openLock()
{
  // The door lock opens when calling this function. It closes after 2s, enough for the hatch to fall down.
  digitalWrite(lock, HIGH);
  delay (2000);
  digitalWrite(lock, LOW);
}
