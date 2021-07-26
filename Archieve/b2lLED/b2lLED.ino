int e,f,g,h,led[11];
int a=30;
int b=30;
int c=10;
int d=30;
void setup() {
  // put your setup code here, to run once:
    for(int z=1;z<=10;z++){
        led[z]=0;
        pinMode(z,OUTPUT);
        digitalWrite(z,LOW);
    }
    h=d;
    e=d-1;
    for(int i=c;i<=a;i++){
        for(f=1;f<=e;f++){
            printf(" ");
        }
        e--;
        g=f;//while exiting for loop spacebegin will be same as starbegin
        if (h>=b)
        {
            h=b;
        }
        for(int x=g;x<=h;x++){
            printf("*");
            if(i==a){
                led[x]=1;
            }
            else{
                led[x]=0;
            }
        }
        printf("\n");
        h=h+1;
        
    }
    for(int z=1;z<=10;z++){//Glowing LED's of last column
        printf("LED %d = %d\n",z,led[z]);
        digitalWrite(z,led[z]);
        delay(100);
    }


}
 

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);

}
