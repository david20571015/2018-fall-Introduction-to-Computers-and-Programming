#include<stdio.h>
#include<math.h>

bool flag=1;

void chinese(int n){
	switch(n){
		case 1:
			printf("��");
			break;
		case 2:
			printf("�L");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("�v");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("��");
			break;
		case 7:
			printf("�m");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("�h");
			break;
	}
}

int tran(int n,int f,int *first){
	if(n==10)
		flag=0;
		
	if((n>=10&&n<=19)&&*first==1){
		*first=0;
		printf("�B");
		chinese(n%10);
		switch(f){
			case 1:
				printf("�U");
				break;
			case 2:
				printf("��");
		}
		return 0;
	}
	
	int a=n/1000, b=n/100%10, c=n/10%10, d=n%10;
	
	if(a){
		if(flag==0&&*first==0)
			printf("�s");
		chinese(a);
		printf("�a");
		*first=0;
	}	
	
	if(b){
		if(a==0&&*first==0)
			printf("�s");
		chinese(b);
		printf("��");
		*first=0;
	}	
	if(c){
		if(b==0&&*first==0)
			printf("�s");
		chinese(c);
		printf("�B");
		*first=0;
	}	
	if(d){
		if(c==0&&*first==0)
			printf("�s");
		chinese(d);
		*first=0;
	}
	
	if(d==0)
		flag=0;
		
	*first=0;
	
	switch(f*(bool)n){
		case 1:
			printf("�U");
			break;
		case 2:
			printf("��");
			break;
	}	
	return 0;
}

int main(void){
	int num,n,k=1;
	scanf("%d",&num);
	
	if(num>=(int)1e8)
		n=2;
	else if(num>=(int)1e4)
		n=1;
	else 
		n=0;
		
	for(int i=n;i>=0;i--)
		tran(num/(int)pow(1e4,i)%(int)1e4,i,&k);
	
	printf("����");
		
	return 0;
}
