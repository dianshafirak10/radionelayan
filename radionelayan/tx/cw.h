
class CW{
    public:
      CW ( int pin , int wpm, int frequenz); 
      void sende_text( char s[] );
      void sende_zeichen( char zeichen);
      void zeichen_abstand();
      void carrier(int t);
      
    private:
      int t_dit;
      int pin_ton;
      int hertz; 
      void dit();
      void dah();
};



