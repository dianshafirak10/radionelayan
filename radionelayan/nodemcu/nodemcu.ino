int matchCount = 0;
char buffer[20];
int i = 0;
String lokasi;

void setup()
{
  Serial.begin( 115200 );
}

void loop()
{
  if (Serial.available()) {
    char c = Serial.read();

    if ((c == '0') or (c == '1') or (c == '2') or (c == '3') or (c == '4') or (c == '5') or (c == '6') or (c == '7') or (c == '8') or (c == '9') or (c == '-') or (c == '.') or (c == ',')){
      buffer[i] = c;
      matchCount = matchCount+1;
      i = i+1;
    } 
    else if ((matchCount > 0) && (c == 'v')) {
      buffer[i] = '\0';
      //Serial.println( String(buffer) ); // F macro saves RAM!
      lokasi = String(buffer);

    int index_koma = lokasi.indexOf(",");
    int index_v = lokasi.indexOf("v");
    String latitude = lokasi.substring(0, index_koma);
    String longitude = lokasi.substring(index_koma+1,index_v);
    
    Serial.print("string = "); Serial.println(lokasi);
    Serial.print("latitude = "); Serial.println(latitude);
    Serial.print("longitude = "); Serial.println(longitude);
    Serial.println();

    float a = latitude.toFloat();
    float b = longitude.toFloat();
    float c = lokasi.toFloat();
      
      matchCount = 0; // reset FSM
      i = 0;
    }
  }
}
