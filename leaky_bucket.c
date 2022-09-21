#include<stdio.h>
int buck_size,out_rate,out_rate_2,n_packets,i,pack_size,drop=0,rem=0,flag =0,a[100];
void leaky(){

            if(rem+pack_size > buck_size){
                drop = pack_size;
                flag =1;

            }
            else if(rem+pack_size < out_rate){
                out_rate = pack_size+rem;

            }
            else{
                drop = 0;
            }

            if(flag == 1){
                rem = rem-out_rate;
                flag=0;
            }
            else{
                rem = rem+pack_size-out_rate;
            }

    printf("\n %d \t \t %d \t\t %d \t\t %d \t\t %d",i+1,pack_size,out_rate,drop,rem);
    out_rate = out_rate_2;
}
void main(){
    printf("enter bucket size:");
    scanf("%d",&buck_size);
    printf("\n enter rate of output:");
    scanf("%d",&out_rate);
    out_rate_2 = out_rate;
    printf("\n enter number of packets to send:");
    scanf("%d",&n_packets);
    for(i=0;i<n_packets;i++){
        printf("\n enter the size of packet at %d sec:",i+1);
        scanf("%d",&a[i]);
    }
    printf("\n Time \t Packet Recived \t Packet send \t Dropped \t Remaining");
    for(i=0;i<n_packets;i++){
        pack_size = a[i];
        if(buck_size >= pack_size){
            leaky();
        }
        else{
            printf("\n packet size is higher than bucket size");
        }
    }
    while(rem > 0){
       pack_size =0;
       leaky();
       i++;
    }

}
