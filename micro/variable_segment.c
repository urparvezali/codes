char arr[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void main() {
    char mplx[]={0x0E,0x0D,0x0B,0x07};
    int num[4],i=0,j=0;
    for(i=0;i<4;i++){num[i]=0;}
    i=0;


    trisb=0x00;
    trisc=0x00;

    portb=0x00;
    portc=0xff;
    while(1){
             if(i==25){
                       i=0;
                       for(j=0;j<4;j++){
                                        if(num[j]==9){
                                                      num[j]=0;
                                        } else {
                                                      num[j]++;
                                                      break;
                                        }
                       }
             }
        portc.f0=0;
        portb=arr[num[3]];
        delay_ms(10);
        portc.f0=1;

        portc.f1=0;
        portb=arr[num[2]];
        delay_ms(10);
        portc.f1=1;

        portc.f2=0;
        portb=arr[num[1]];;
        delay_ms(10);
        portc.f2=1;

        portc.f3=0;
        portb=arr[num[0]];
        delay_ms(10);
        portc.f3=1;
        
        i+=1;
    }
}