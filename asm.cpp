
//assembly delay opperation

void static delay(uint_16 times){

  while (times > 0){
    __asm__ __volatile__ ("nop");
    times--;
  }
  
}