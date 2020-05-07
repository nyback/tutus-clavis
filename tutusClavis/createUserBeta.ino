#include <EEPROM.h>
#define USER_SIZE 31

int nrUsers = 0;

typedef struct userData
{
  byte id; // 0-255 (We can have no more than 255 users.)
  char namn[10];
  word pass; // 0000-9999
  int options; // room for many options, for now all that is needed is admin true or false. so maybe LSB determins
  int access[8]; // Each bit represents one key. eg: MSB=1 -> access granted to first key.
};

void createUser(char namn[], word pass, int options, int access[]){

EEPROM.get(1023, nrUsers);
nrUsers++;
EEPROM.put(1023, nrUsers);
int idu = (nrUsers-1);
userData user = {idu, {}, pass, options, {}};

Serial.println(sizeof(userData));

for (int i = 0; i < 8; i++){
  user.namn[i]=namn[i];
}
for (int i = 0; i < 8; i++){
  user.access[i]=access[i];
}
Serial.println(user.id);
Serial.println(user.namn);
Serial.println(user.pass);
Serial.println(user.options);

for (int i = 0; i < 8; i++){
  Serial.print(user.access[i]);
}
  Serial.println();

  EEPROM.put((user.id*sizeof(userData)), user);

}





void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  char namn[] = "per";
  word pass = 1235;
  int options = 8;
  int access[] = {1,0,1,1,1,1,0,1};
  
  createUser(namn, pass, options, access);

  Serial.println("User0:");
  userData readUser;
  EEPROM.get((0*sizeof(userData)), readUser);

  Serial.println(readUser.id);
  Serial.println(readUser.namn);
  Serial.println(readUser.pass);
  Serial.println(readUser.options);

  for (int i = 0; i < 8; i++){
    Serial.print(readUser.access[i]);
  }
    Serial.println();

  Serial.println("User1:");
  EEPROM.get((1*sizeof(userData)), readUser);

  Serial.println(readUser.id);
  Serial.println(readUser.namn);
  Serial.println(readUser.pass);
  Serial.println(readUser.options);

  for (int i = 0; i < 8; i++){
    Serial.print(readUser.access[i]);
  }
    Serial.println();

  Serial.println("User2:");
  EEPROM.get((2*sizeof(userData)), readUser);

  Serial.println(readUser.id);
  Serial.println(readUser.namn);
  Serial.println(readUser.pass);
  Serial.println(readUser.options);

  for (int i = 0; i < 8; i++){
    Serial.print(readUser.access[i]);
  }
    Serial.println();

}

void loop() {
  // put your main code here, to run repeatedly:

}
