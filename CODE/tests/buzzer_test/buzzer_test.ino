const int BUZZER = 9;
const int nrOfNotes = 18;

char notes[nrOfNotes] = {'c', 'd', 'f', 'd', 'a', ' ', 'a', 'g', ' ', 'c', 'd', 'f', 'd', 'g', ' ', 'g', 'f', ' '};
int beats[nrOfNotes] = {1, 1, 1, 1, 1, 1, 4, 4, 2, 1, 1, 1, 1, 1, 1, 4, 4, 2};    // 2 = 1/2 note, 4 = 1/4 note
int tempo = 113;  // Beats Per Second (BPS)

void setup() {
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  int i;
  int duration;
  for (i = 0; i < nrOfNotes; i++) {
    duration = beats[i] * tempo;
    if (notes[i] == ' ')
      delay(duration);
    else {
      tone(BUZZER, freq(notes[i]), duration);
      delay(duration);
    }
    delay(tempo/10);
  }
  while(true) {};
}

int freq (char note) {
  int i;
  const int savedNotes = 8;
  char names[savedNotes] = {'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C'};
  int frequencies[savedNotes] = {262, 294, 330, 349, 392, 440, 494, 523};

  for (i = 0; i < savedNotes; i++) {
    if (names[i] == note)
      return (frequencies[i]);
  }
  return(0);
}
