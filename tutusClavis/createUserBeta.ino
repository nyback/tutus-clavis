#include <EEPROM.h>
#define USER_SIZE 30

int users = 0; //för att hålla koll på hur många användare de finns

typedef struct userData
{
  byte id; // 0-255 (We can have no more than 255 users.)
  char namn[9];
  word pass; // 0000-9999
  int options; // room for many options, for now all that is needed is admin true or false. so maybe LSB determins
  int access[8]; // Each bit represents one key. eg: MSB=1 -> access granted to first key.
};


void createUser(char namn[9], word pass, int options, int access[8]){
  int preusers; 
  EEPROM.get(1023, preusers);
  users = preusers + 1;

  EEPROM.put(1023, users);

  userData user = {users, namn, pass, options, access};

  EEPROM.put(users, user);
   
}


void userInit() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  int eeAddress = 0;


  userData user1 = {0, "kalle", 9901, 8, {1,1,1,1,1,1,1,0}};
  userData user2 = {1, "pelle", 1234, 7, {0,0,0,0,0,0,0,0}};

  Serial.println("Written custom user.");
  
  Serial.println(user1.id, DEC);
  Serial.println(user1.namn);
  Serial.println(user1.pass, DEC);
  Serial.println(user1.options);

  for (int i = 0 ; i < 8 ; i++) {
    Serial.print(user1.access[i]);
  }
  Serial.println();

  Serial.println("Written custom user2.");
  
  Serial.println(user2.id, DEC);
  Serial.println(user2.namn);
  Serial.println(user2.pass, DEC);
  Serial.println(user2.options);
  
  for (int i = 0 ; i < 8 ; i++) {
    Serial.print(user2.access[i]);
  }
  Serial.println();
  



  EEPROM.put(eeAddress, user1);

  eeAddress += sizeof(userData);

  EEPROM.put(eeAddress, user2);

  Serial.println("Written custom data type!");
  
  Serial.println(sizeof(userData));

  userData readUser;

  EEPROM.get((user1.id*USER_SIZE), readUser);

  Serial.println("Read user:");
  Serial.println(readUser.id, DEC);
  Serial.println(readUser.namn);
  Serial.println(readUser.pass, DEC);
  Serial.println(readUser.options);
  
  for (int i = 0 ; i < 8 ; i++) {
    Serial.print(readUser.access[i]);
  }
  Serial.println();


  EEPROM.get((user2.id*USER_SIZE), readUser);

  Serial.println("Read user:");
  Serial.println(readUser.id);
  Serial.println(readUser.namn);
  Serial.println(readUser.pass);
  Serial.println(readUser.options);
  
  for (int i = 0 ; i < 8 ; i++) {
    Serial.print(readUser.access[i]);
  }
  Serial.println();
  
}

void someloop() {
  // put your main code here, to run repeatedly:

}
