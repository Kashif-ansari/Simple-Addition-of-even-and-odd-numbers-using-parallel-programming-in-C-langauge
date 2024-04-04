#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
int mod;
int sum =0;
int array[10];
for (int i = 0; i<10 ; i++){
printf("Enter number of array %d : ",i);
scanf("%d",&array[i]);}
pid_t pid = fork();
if( pid == 0){
for (int i =0 ; i< 10 ; i++){
mod = array[i] % 2;
if (mod == 0){
sum = sum + array[i];}}
printf("Hello from Child!\n");
printf("Sum of Even Numbers : %d",sum);
printf("\nChild Pid : %d\n", getpid());
printf("Child PPid : %d\n", getppid());}
else{
for (int i =0 ; i< 10 ; i++){
mod = array[i] % 2;
if (mod == 1){
sum = sum + array[i];}}
printf("Hello from Parent!\n");
printf("Sum of Odd Numbers : %d",sum);
printf("\nParent Pid : %d\n", getpid());}
return 0;
}