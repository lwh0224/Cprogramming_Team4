#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 150

typedef struct Product { // product ����ü ����
	char name[MAX_NAME_LEN];
	int price;
} Product;

typedef struct Customer { // Customer ����ü ����
	char name[MAX_NAME_LEN];
	char number[MAX_NAME_LEN];
} Customer;

typedef struct Order { // Order ����ü ����
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
				printf("�����մϴ�.\n");
				break;
			default:
				printf("�߸��� �Է��Դϴ�.\n");
				break;
		}
	}
	return 0;
}

void print_menu() {
	printf("1. ��ǰ ����\n");
	printf("2. �� ����\n");
	printf("3. �ֹ� ����\n");
	printf("4. ����\n");
	printf("��ȣ�� �����ϼ���: ");
}

void product_menu() {
	int choice = 0;
	while (choice != 5) {
		printf("1. �߰�\n");
		printf("2. ����\n");
		printf("3. ���\n");
		printf("4. ����\n");
		printf("5. ���ư���\n");
		printf("��ȣ�� �����ϼ���: ");
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
				printf("��ǰ ������ �����մϴ�.\n");
				break;
			default:
				printf("�߸��� �Է��Դϴ�.\n");
				break;
		}
	}
}

void customer_menu() {
	int choice = 0;
	while (choice != 5) {
		printf("1. �߰�\n");
		printf("2. ����\n");
		printf("3. ���\n");
		printf("4. ����\n");
		printf("5. ���ư���\n");
		printf("��ȣ�� �����ϼ���: ");
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
				printf("�� ������ �����մϴ�.\n");
				break;
			default:
				printf("�߸��� �Է��Դϴ�.\n");
				break;
		}
	}
}

void order_menu() {
	int choice = 0;
	while (choice != 5) {
		printf("1. �߰�\n");
		printf("2. ����\n");
		printf("3. ���\n");
		printf("4. ����\n");
		printf("5. ���ư���\n");
		printf("��ȣ�� �����ϼ���: ");
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
				printf("�ֹ� ������ �����մϴ�.\n");
				break;
			default:
				printf("�߸��� �Է��Դϴ�.\n");
				break;
		}
	}
}

void add_product() { 
	Product p; // product ����ü ���� p ����
	printf("��ǰ �̸��� �Է��ϼ���: ");
	scanf("%s", p.name); 
	printf("��ǰ ������ �Է��ϼ���: ");
	scanf("%d", &p.price);
	FILE *fp = fopen("product.txt", "a"); // product.txt ���� ����
	fprintf(fp, "%s %d\n", p.name, p.price); // product.txt ���Ͽ� ��ǰ �̸��� ���� ����
	fclose(fp); // ���� �ݱ�
}

void modify_product() {
	char name[MAX_NAME_LEN];
	printf("������ ��ǰ �̸��� �Է��ϼ���: ");
	scanf("%s", name); 
	FILE *fp = fopen("product.txt", "r"); // product.txt ���� �б� �������� ����
	FILE *temp = fopen("temp.txt", "w"); // temp.txt ���� ���� �������� ����
	Product p; // product ����ü ���� p ����
	while (fscanf(fp, "%s %d\n", p.name, &p.price) != EOF) { // product.txt ���Ͽ��� ��ǰ ���� �� �پ� ������ �б�
		if (strcmp(p.name, name) == 0) { // ������ ��ǰ �̸��� ����ڰ� �Է��� �̸��� ���Ͽ� ���� ���
			printf("���ο� ��ǰ �̸��� �Է��ϼ���: ");
			scanf("%s", p.name); // ���ο� ��ǰ �̸� �Է��Ͽ� ����ü p�� ����
			printf("���ο� ��ǰ ������ �Է��ϼ���: ");
			scanf("%d", &p.price); // ���ο� ��ǰ ������ �Է¹޾� ����ü p�� ����
		}
		fprintf(temp, "%s %d\n", p.name, p.price); // temp.txt ���Ͽ� ������ ��ǰ �̸��� ���� ����
	}
	fclose(fp); //product.txt ���� �ݱ�
	fclose(temp); //temp.txt ���� �ݱ�
	remove("product.txt"); // product.txt���� ����
	rename("temp.txt", "product.txt"); //temp.txt ���� product.txt �� �̸� ����
}

void print_product() {
	FILE *fp = fopen("product.txt", "r"); // product.txt ���� �б� �������� ����
	Product p; // product ����ü ���� p ����
	printf("��ǰ �̸�\t��ǰ ����\n");
	while (fscanf(fp, "%s %d\n", p.name, &p.price) != EOF) { // product.txt���� �� �پ� ������ �б�
		printf("%s\t\t%d\n", p.name, p.price); // ��ǰ �̸��� ���� ���
	}
	fclose(fp); //���� �ݱ�
}

void delete_product() {
	char name[MAX_NAME_LEN]; 
	printf("������ ��ǰ �̸��� �Է��ϼ���: "); 
	scanf("%s", name); //��ǰ �̸� �Է�
	FILE *fp = fopen("product.txt", "r"); // product.txt ���� �б� �������� ����
	FILE *temp = fopen("temp.txt", "w"); //temp.txt ���� �������� ����
	Product p; // product ����ü ���� p ����
	while (fscanf(fp, "%s %d\n", p.name, &p.price) != EOF) { // product.txt ���Ͽ��� ��ǰ ���� �� �پ� ������ �б�
		if (strcmp(p.name, name) != 0) { // �о�� ��ǰ �̸��� ����ڰ� �Է��� �̸��� �ٸ� ���
			fprintf(temp, "%s %d\n", p.name, p.price); //temp.txt���Ͽ� ������ ��ǰ�� ������ ������ ��ǰ ������ �Է�
		}
	}
	fclose(fp); // product.txt ���� �ݱ�
	fclose(temp); // temp.txt ���� �ݱ�
	remove("product.txt"); // product.txt���� ����
	rename("temp.txt", "product.txt"); // temp.txt ���� product.txt�� �̸� ����
}

void add_customer() {
	Customer c; // Customer ����ü ���� c ����
	printf("�� �̸��� �Է��ϼ���: "); 
	scanf("%s", c.name); //
	printf("�� ��ȣ���Է��ϼ���: ");
	scanf("%s", c.number);
	FILE *fp = fopen("customer.txt", "a"); // customer.txt ���� ����
	fprintf(fp, "%s %s\n", c.name, c.number); // customer.txt ���Ͽ� �� �̸��� ��ȣ ����
	fclose(fp); // ���� �ݱ�
}

void modify_customer() {
	char name[MAX_NAME_LEN];
	printf("������ �� �̸��� �Է��ϼ���: ");
	scanf("%s", name); // �̸� �Է¹ޱ�
	FILE *fp = fopen("customer.txt", "r"); // customer.txt �б� �������� ����
	FILE *temp = fopen("temp.txt", "w"); // temp.txt���� ���� �������� ����
	Customer c; // Customer ����ü ���� c ����
	while (fscanf(fp, "%s %s\n", c.name, c.number) != EOF) { // customer.txt ���� �� �پ� ������ �б�
		if (strcmp(c.name, name) == 0) { // ������ �� �̸��� ����ڰ� �Է��� �� �̸��� ���� ���
			printf("���ο� �� �̸��� �Է��ϼ���: ");
			scanf("%s", c.name); // �̸� �Է�
			printf("���ο� �� ��ȣ�� �Է��ϼ���: ");
			scanf("%s", c.number); // ��ȣ �Է�
		}
		fprintf(temp, "%s %s\n", c.name, c.number); // ������ �̸��� ��ȣ temp.txt ���Ͽ� ����
	}
	fclose(fp); // ���� �ݱ�
	fclose(temp); // ���� �ݱ�
	remove("customer.txt"); // customer.txt ���� ����
	rename("temp.txt", "customer.txt"); // temp.txt ���� customer.txt�� �̸� ����
}

void print_customer() {
	FILE *fp = fopen("customer.txt", "r"); // customer.txt ���� �б��������� ����
	Customer c; // Customer ����ü ���� c ����
	printf("�� �̸�\t�� ��ȣ\n"); 
	while (fscanf(fp, "%s %s\n", c.name, c.number) != EOF) { // customer.txt ���� �� �پ� ������ �б�
		printf("%s\t\t%s\n", c.name, c.number); // �� �̸��� ��ȣ ���
	}
	fclose(fp); // ���� �ݱ�
}

void delete_customer() {
	char name[MAX_NAME_LEN];
	printf("������ �� �̸��� �Է��ϼ���: ");
	scanf("%s", name); // �̸� �Է¹ޱ�
	FILE *fp = fopen("customer.txt", "r"); // customer.txt ���� �б� �������� ����
	FILE *temp = fopen("temp.txt", "w"); // temp.txt ���� ���� �������� ����
	Customer c; // Customer ����ü ���� c ����
	while (fscanf(fp, "%s %s\n", c.name, c.number) != EOF) { // customer.txt ���� �� �پ� ������ �б�
		if (strcmp(c.name, name) != 0) { // ������ �̸��� ����ڰ� �Է¹��� �̸��� �ٸ� ���
			fprintf(temp, "%s %s\n", c.name, c.number); // temp.txt ���Ͽ� ������ �� ������ ������ ������ �� ���� �Է�
		}
	}
	fclose(fp); // ���� �ݱ�
	fclose(temp); // ���� �ݱ�
	remove("customer.txt"); // customer.txt ���� ����
	rename("temp.txt", "customer.txt"); // temp.txt ���� customer.txt�� �̸� ����
}

void add_order() {
	Order o; // Order ����ü ���� o ����
	printf("�ֹ��� �̸��� �Է��ϼ���: "); 
	scanf("%s", o.name); // �ֹ��� �̸� �Է�
	printf("��ǰ �̸��� �Է��ϼ��� :");
	scanf("%s",o.product); // ��ǰ �̸� �Է�
	printf("�ֹ� ��¥�� �Է��ϼ���(YYYYMMDD): "); 
	scanf("%s", o.date); // �ֹ� ��¥ �Է�
	FILE *fp = fopen("order.txt", "a"); // order.txt ���� ����
	fprintf(fp, "%s %s %s\n", o.name, o.product, o.date); // o ����ü ������ ����� ���� order.txt�� �Է�
	fclose(fp); // ���� �ݱ�
}

void modify_order() {
	char name[MAX_NAME_LEN];
	printf("������ �ֹ��� �̸��� �Է��ϼ���: ");
	scanf("%s", name); // �ֹ��� �̸� �Է�
	FILE *fp = fopen("order.txt", "r"); // order.txt �б� �������� ����
	FILE *temp = fopen("temp.txt", "w"); // temp.txt ���� ���� �������� �б�
	Order o; // Order ����ü ���� o ����
	while (fscanf(fp, "%s %s %s\n", o.name, o.product, o.date) != EOF) { // order.txt ���� ������ �� �پ� �б�
		if (strcmp(o.name, name) == 0) { // ���Ͽ� ����� �̸��� ����ڰ� �Է��� �̸��� ���� ���
			printf("���ο� �ֹ��� �̸��� �Է��ϼ��� :");
			scanf("%s", o.name); // �ֹ��� �̸� �Է�
			printf("���ο� ��ǰ �̸��� �Է��ϼ��� :");
			scanf("%s", o.product); // ��ǰ �̸� �Է�
			printf("���ο� �ֹ� ��¥�� �Է��ϼ���(YYYYMMDD): ");
			scanf("%s", o.date); // �ֹ� ��¥ �Է�
		}
		fprintf(temp, "%s %s %s\n", o.name, o.product, o.date); // ������ ���� temp.txt ���Ͽ� ����
	}
	fclose(fp); // ���� �ݱ�
	fclose(temp); // ���� �ݱ�
	remove("order.txt"); // order.txt ����
	rename("temp.txt", "order.txt"); // temp.txt ���� order.txt�� �̸� ����
}

void print_order() {
	FILE *fp = fopen("order.txt", "r"); // order.txt �б� ���� ���� ����
	Order o; // Order ����ü ���� o ����
	printf("�ֹ��� �̸�\t�ֹ��� ��ǰ\t�ֹ� ��¥\n");
	while (fscanf(fp, "%s %s %s\n", o.name, o.product, o.date) != EOF) { // order.txt ���� �� �پ� ������ �б�
		printf("%s\t\t%s\t\t%s\n", o.name, o.product, o.date); // �ֹ��� �̸�, ��ǰ �̸�, �ֹ� ��¥ ���
	}
	fclose(fp); // ���� �ݱ�
}

void delete_order() {
	char name[MAX_NAME_LEN];
	printf("������ �ֹ��� �̸��� �Է��ϼ���: ");
	scanf("%s", name); // �ֹ��� �̸� �Է�
	FILE *fp = fopen("order.txt", "r"); // order.txt �б� ���� ���� ����
	FILE *temp = fopen("temp.txt", "w"); // temp.txt ���� ���� ���� ����
	Order o; // Order ����ü ���� o ����
	while (fscanf(fp, "%s %s %s\n", o.name, o.product, o.date) != EOF) { // order.txt ���� �� �پ� ������ �б�
		if (strcmp(o.name, name) != 0) { //�ֹ��� �̸��� �Է¹��� �̸��� ���� ������
			fprintf(temp, "%s %s %s\n", o.name, o.product, o.date); // tempt.txt ���Ͽ� ������ �ֹ� ������ ������ ������ ����
		}
	}
	fclose(fp); // ���� �ݱ�
	fclose(temp); // ���� �ݱ�
	remove("order.txt"); // order.txt ���� ����
	rename("temp.txt", "order.txt"); // temp.txt ���� order.txt�� �̸� ����
}

