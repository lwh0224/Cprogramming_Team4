#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 150

typedef struct Product { // product 구조체 선언
	char name[MAX_NAME_LEN];
	int price;
} Product;

typedef struct Customer { // Customer 구조체 선언
	char name[MAX_NAME_LEN];
	char number[MAX_NAME_LEN];
} Customer;

typedef struct Order { // Order 구조체 선언
	char product[MAX_NAME_LEN];
	char name[MAX_NAME_LEN];
	char date[MAX_NAME_LEN];
} Order;

void print_menu();
void product_menu();
void customer_menu();
void order_menu();
void add_product();
void modify_product();
void print_product();
void delete_product();
void add_customer();
void modify_customer();
void print_customer();
void delete_customer();
void add_order();
void modify_order();
void print_order();
void delete_order();

int main() {
	int choice = 0;
	while (choice != 4) {
		print_menu();
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				product_menu();
				break;
			case 2:
				customer_menu();
				break;
			case 3:
				order_menu();
				break;
			case 4:
				printf("종료합니다.\n");
				break;
			default:
				printf("잘못된 입력입니다.\n");
				break;
		}
	}
	return 0;
}

void print_menu() {
	printf("1. 상품 관리\n");
	printf("2. 고객 관리\n");
	printf("3. 주문 관리\n");
	printf("4. 종료\n");
	printf("번호를 선택하세요: ");
}

void product_menu() {
	int choice = 0;
	while (choice != 5) {
		printf("1. 추가\n");
		printf("2. 수정\n");
		printf("3. 출력\n");
		printf("4. 삭제\n");
		printf("5. 돌아가기\n");
		printf("번호를 선택하세요: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				add_product();
				break;
			case 2:
				modify_product();
				break;
			case 3:
				print_product();
				break;
			case 4:
				delete_product();
				break;
			case 5:
				printf("상품 관리를 종료합니다.\n");
				break;
			default:
				printf("잘못된 입력입니다.\n");
				break;
		}
	}
}

void customer_menu() {
	int choice = 0;
	while (choice != 5) {
		printf("1. 추가\n");
		printf("2. 수정\n");
		printf("3. 출력\n");
		printf("4. 삭제\n");
		printf("5. 돌아가기\n");
		printf("번호를 선택하세요: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				add_customer();
				break;
			case 2:
				modify_customer();
				break;
			case 3:
				print_customer();
				break;
			case 4:
				delete_customer();
				break;
			case 5:
				printf("고객 관리를 종료합니다.\n");
				break;
			default:
				printf("잘못된 입력입니다.\n");
				break;
		}
	}
}

void order_menu() {
	int choice = 0;
	while (choice != 5) {
		printf("1. 추가\n");
		printf("2. 수정\n");
		printf("3. 출력\n");
		printf("4. 삭제\n");
		printf("5. 돌아가기\n");
		printf("번호를 선택하세요: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				add_order();
				break;
			case 2:
				modify_order();
				break;
			case 3:
				print_order();
				break;
			case 4:
				delete_order();
				break;
			case 5:
				printf("주문 관리를 종료합니다.\n");
				break;
			default:
				printf("잘못된 입력입니다.\n");
				break;
		}
	}
}

void add_product() { 
	Product p; // product 구조체 변수 p 선언
	printf("상품 이름을 입력하세요: ");
	scanf("%s", p.name); 
	printf("상품 가격을 입력하세요: ");
	scanf("%d", &p.price);
	FILE *fp = fopen("product.txt", "a"); // product.txt 파일 열기
	fprintf(fp, "%s %d\n", p.name, p.price); // product.txt 파일에 상품 이름과 가격 쓰기
	fclose(fp); // 파일 닫기
}

void modify_product() {
	char name[MAX_NAME_LEN];
	printf("수정할 상품 이름을 입력하세요: ");
	scanf("%s", name); 
	FILE *fp = fopen("product.txt", "r"); // product.txt 파일 읽기 전용으로 열기
	FILE *temp = fopen("temp.txt", "w"); // temp.txt 파일 쓰기 전용으로 열기
	Product p; // product 구조체 변수 p 선언
	while (fscanf(fp, "%s %d\n", p.name, &p.price) != EOF) { // product.txt 파일에서 상품 정보 한 줄씩 끝까지 읽기
		if (strcmp(p.name, name) == 0) { // 파일의 상품 이름과 사용자가 입력한 이름을 비교하여 같은 경우
			printf("새로운 상품 이름을 입력하세요: ");
			scanf("%s", p.name); // 새로운 상품 이름 입력하여 구조체 p에 저장
			printf("새로운 상품 가격을 입력하세요: ");
			scanf("%d", &p.price); // 새로운 상품 가격을 입력받아 구조체 p에 저장
		}
		fprintf(temp, "%s %d\n", p.name, p.price); // temp.txt 파일에 수정된 상품 이름과 가격 쓰기
	}
	fclose(fp); //product.txt 파일 닫기
	fclose(temp); //temp.txt 파일 닫기
	remove("product.txt"); // product.txt파일 삭제
	rename("temp.txt", "product.txt"); //temp.txt 파일 product.txt 로 이름 변경
}

void print_product() {
	FILE *fp = fopen("product.txt", "r"); // product.txt 파일 읽기 전용으로 열기
	Product p; // product 구조체 변수 p 선언
	printf("상품 이름\t상품 가격\n");
	while (fscanf(fp, "%s %d\n", p.name, &p.price) != EOF) { // product.txt파일 한 줄씩 끝까지 읽기
		printf("%s\t\t%d\n", p.name, p.price); // 상품 이름과 가격 출력
	}
	fclose(fp); //파일 닫기
}

void delete_product() {
	char name[MAX_NAME_LEN]; 
	printf("삭제할 상품 이름을 입력하세요: "); 
	scanf("%s", name); //상품 이름 입력
	FILE *fp = fopen("product.txt", "r"); // product.txt 파일 읽기 전용으로 열기
	FILE *temp = fopen("temp.txt", "w"); //temp.txt 쓰기 전용으로 열기
	Product p; // product 구조체 변수 p 선언
	while (fscanf(fp, "%s %d\n", p.name, &p.price) != EOF) { // product.txt 파일에서 상품 정보 한 줄씩 끝까지 읽기
		if (strcmp(p.name, name) != 0) { // 읽어온 상품 이름과 사용자가 입력한 이름이 다를 경우
			fprintf(temp, "%s %d\n", p.name, p.price); //temp.txt파일에 삭제할 상품을 제외한 나머지 상품 정보를 입력
		}
	}
	fclose(fp); // product.txt 파일 닫기
	fclose(temp); // temp.txt 파일 닫기
	remove("product.txt"); // product.txt파일 삭제
	rename("temp.txt", "product.txt"); // temp.txt 파일 product.txt로 이름 변경
}

void add_customer() {
	Customer c; // Customer 구조체 변수 c 선언
	printf("고객 이름을 입력하세요: "); 
	scanf("%s", c.name); //
	printf("고객 번호를입력하세요: ");
	scanf("%s", c.number);
	FILE *fp = fopen("customer.txt", "a"); // customer.txt 파일 열기
	fprintf(fp, "%s %s\n", c.name, c.number); // customer.txt 파일에 고객 이름과 번호 쓰기
	fclose(fp); // 파일 닫기
}

void modify_customer() {
	char name[MAX_NAME_LEN];
	printf("수정할 고객 이름을 입력하세요: ");
	scanf("%s", name); // 이름 입력받기
	FILE *fp = fopen("customer.txt", "r"); // customer.txt 읽기 전용으로 열기
	FILE *temp = fopen("temp.txt", "w"); // temp.txt파일 쓰기 전용으로 열기
	Customer c; // Customer 구조체 변수 c 선언
	while (fscanf(fp, "%s %s\n", c.name, c.number) != EOF) { // customer.txt 파일 한 줄씩 끝까지 읽기
		if (strcmp(c.name, name) == 0) { // 파일의 고객 이름과 사용자가 입력한 고객 이름이 같은 경우
			printf("새로운 고객 이름을 입력하세요: ");
			scanf("%s", c.name); // 이름 입력
			printf("새로운 고객 번호를 입력하세요: ");
			scanf("%s", c.number); // 번호 입력
		}
		fprintf(temp, "%s %s\n", c.name, c.number); // 수정된 이름과 번호 temp.txt 파일에 저장
	}
	fclose(fp); // 파일 닫기
	fclose(temp); // 파일 닫기
	remove("customer.txt"); // customer.txt 파일 삭제
	rename("temp.txt", "customer.txt"); // temp.txt 파일 customer.txt로 이름 변경
}

void print_customer() {
	FILE *fp = fopen("customer.txt", "r"); // customer.txt 파일 읽기전용으로 열기
	Customer c; // Customer 구조체 변수 c 선언
	printf("고객 이름\t고객 번호\n"); 
	while (fscanf(fp, "%s %s\n", c.name, c.number) != EOF) { // customer.txt 파일 한 줄씩 끝까지 읽기
		printf("%s\t\t%s\n", c.name, c.number); // 고객 이름과 번호 출력
	}
	fclose(fp); // 파일 닫기
}

void delete_customer() {
	char name[MAX_NAME_LEN];
	printf("삭제할 고객 이름을 입력하세요: ");
	scanf("%s", name); // 이름 입력받기
	FILE *fp = fopen("customer.txt", "r"); // customer.txt 파일 읽기 전용으로 열기
	FILE *temp = fopen("temp.txt", "w"); // temp.txt 파일 쓰기 전용으로 열기
	Customer c; // Customer 구조체 변수 c 선언
	while (fscanf(fp, "%s %s\n", c.name, c.number) != EOF) { // customer.txt 파일 한 줄씩 끝까지 읽기
		if (strcmp(c.name, name) != 0) { // 파일의 이름과 사용자가 입력받은 이름이 다른 경우
			fprintf(temp, "%s %s\n", c.name, c.number); // temp.txt 파일에 삭제할 고객 정보를 제외한 나머지 고객 정보 입력
		}
	}
	fclose(fp); // 파일 닫기
	fclose(temp); // 파일 닫기
	remove("customer.txt"); // customer.txt 파잃 삭제
	rename("temp.txt", "customer.txt"); // temp.txt 파일 customer.txt로 이름 변경
}

void add_order() {
	Order o; // Order 구조체 변수 o 선언
	printf("주문자 이름을 입력하세요: "); 
	scanf("%s", o.name); // 주문자 이름 입력
	printf("상품 이름을 입력하세요 :");
	scanf("%s",o.product); // 상품 이름 입력
	printf("주문 날짜를 입력하세요(YYYYMMDD): "); 
	scanf("%s", o.date); // 주문 날짜 입력
	FILE *fp = fopen("order.txt", "a"); // order.txt 파일 열기
	fprintf(fp, "%s %s %s\n", o.name, o.product, o.date); // o 구조체 변수에 저장된 정보 order.txt에 입력
	fclose(fp); // 파일 닫기
}

void modify_order() {
	char name[MAX_NAME_LEN];
	printf("수정할 주문자 이름을 입력하세요: ");
	scanf("%s", name); // 주문자 이름 입력
	FILE *fp = fopen("order.txt", "r"); // order.txt 읽기 전용으로 열기
	FILE *temp = fopen("temp.txt", "w"); // temp.txt 파일 쓰기 전용으로 읽기
	Order o; // Order 구조체 변수 o 선언
	while (fscanf(fp, "%s %s %s\n", o.name, o.product, o.date) != EOF) { // order.txt 파일 끝까지 한 줄씩 읽기
		if (strcmp(o.name, name) == 0) { // 파일에 저장된 이름과 사용자가 입력한 이름이 같을 경우
			printf("새로운 주문자 이름을 입력하세요 :");
			scanf("%s", o.name); // 주문자 이름 입력
			printf("새로운 상품 이름을 입력하세요 :");
			scanf("%s", o.product); // 상품 이름 입력
			printf("새로운 주문 날짜를 입력하세요(YYYYMMDD): ");
			scanf("%s", o.date); // 주문 날짜 입력
		}
		fprintf(temp, "%s %s %s\n", o.name, o.product, o.date); // 수정된 정보 temp.txt 파일에 저장
	}
	fclose(fp); // 파일 닫기
	fclose(temp); // 파일 닫기
	remove("order.txt"); // order.txt 삭제
	rename("temp.txt", "order.txt"); // temp.txt 파일 order.txt로 이름 변경
}

void print_order() {
	FILE *fp = fopen("order.txt", "r"); // order.txt 읽기 전용 모드로 열기
	Order o; // Order 구조체 변수 o 선언
	printf("주문자 이름\t주문한 상품\t주문 날짜\n");
	while (fscanf(fp, "%s %s %s\n", o.name, o.product, o.date) != EOF) { // order.txt 파일 한 줄씩 끝까지 읽기
		printf("%s\t\t%s\t\t%s\n", o.name, o.product, o.date); // 주문자 이름, 상품 이름, 주문 날짜 출력
	}
	fclose(fp); // 파일 닫기
}

void delete_order() {
	char name[MAX_NAME_LEN];
	printf("삭제할 주문자 이름을 입력하세요: ");
	scanf("%s", name); // 주문자 이름 입력
	FILE *fp = fopen("order.txt", "r"); // order.txt 읽기 전용 모드로 열기
	FILE *temp = fopen("temp.txt", "w"); // temp.txt 쓰기 전용 모드로 열기
	Order o; // Order 구조체 변수 o 선언
	while (fscanf(fp, "%s %s %s\n", o.name, o.product, o.date) != EOF) { // order.txt 파일 한 줄씩 끝까지 읽기
		if (strcmp(o.name, name) != 0) { //주문자 이름이 입력받은 이름과 같지 않으면
			fprintf(temp, "%s %s %s\n", o.name, o.product, o.date); // tempt.txt 파일에 삭제될 주문 정보를 제외한 나머지 쓰기
		}
	}
	fclose(fp); // 파일 닫기
	fclose(temp); // 파일 닫기
	remove("order.txt"); // order.txt 파일 삭제
	rename("temp.txt", "order.txt"); // temp.txt 파일 order.txt로 이름 변경
}

