#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function Declarations
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(double a, double b); 
long long factorial(int a);        

// Trigonometric Functions
double sine(double degree);
double cosine(double degree);
double tangent(double degree);
double secant(double degree);
double cosecant(double degree);
double cotangent(double degree);

int main() {
    int a,b;//declaration moved here so a,b variables are not accessed in whole program thus increasing readability
    int select;
    
        printf("--- ADVANCED CALCULATOR ---\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("5. Factorial\n");
    printf("6. Sine\n");
    printf("7. Cosine\n");
    printf("8. Tangent\n");
    printf("9. Secant\n");
    printf("10. Cosecant\n");
    printf("11. Cotangent\n");
    printf("Enter choice (1-11): ");
    scanf("%d", &select);
;

    switch(select) {
        case 1:
            printf("Enter Number 1: ");
            scanf("%d", &a);
            printf("Enter Number 2: ");
            scanf("%d", &b);
            printf("Addition is: %d\n", add(a, b));
            break;
            
        case 2:
            printf("Enter Number 1: ");
            scanf("%d", &a);
            printf("Enter Number 2: ");
            scanf("%d", &b);
            printf("Subtraction is: %d\n", subtract(a, b));
            break;
            
        case 3:
            printf("Enter Number 1: ");
            scanf("%d", &a);
            printf("Enter Number 2: ");
            scanf("%d", &b);
            printf("Multiplication is: %d\n", multiply(a, b));
            break;
        
        case 4: {
            double num1, num2;
            printf("Enter Dividend: ");
            scanf("%lf", &num1);
            printf("Enter Divisor: ");
            scanf("%lf", &num2);
            if (num2 == 0) {
                printf("Error: Division by zero!\n");
            } else {
                printf("Division is: %.2f\n", divide(num1, num2));
            }
            break;
        }
            
        case 5: {
            int num;
            printf("Enter integer: ");
            scanf("%d", &num);
            if (num < 0) {
                printf("Factorial of negative numbers doesn't exist.\n");
            } else {
                printf("Factorial of %d is: %lld\n", num, factorial(num));
            }
            break;
        }
            
        case 6: {
            double deg;
            printf("Enter angle in degrees: ");
            scanf("%lf", &deg);
            printf("Sine(%.2f) = %.4f\n", deg, sine(deg));
            break;
        }

        case 7: {
            double deg;
            printf("Enter angle in degrees: ");
            scanf("%lf", &deg);
            printf("Cosine(%.2f) = %.4f\n", deg, cosine(deg));
            break;
        }

        case 8: {
            double deg;
            printf("Enter angle in degrees: ");
            scanf("%lf", &deg);
            // Quick check to avoid tan(90) crash / huge values
            if (fmod(deg - 90, 180) == 0) {
                printf("Tangent is undefined for this angle.\n");
            } else {
                printf("Tangent(%.2f) = %.4f\n", deg, tangent(deg));
            }
            break;
        }
        
        default:
            printf("Invalid selection!\n");
    }
    
    return 0;
}

// Basic Math Operations
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

// Factorial function using recursion
long long factorial(int a) {
    if (a == 0 || a == 1) {
        return 1; 
    }
    return a * factorial(a - 1);//changed n to a to increase readability
}

// Trigonometric Implementations
double sine(double degree) {
    double radian = degree * (PI / 180.0);
    return sin(radian);
}

double cosine(double degree) {
    double radian = degree * (PI / 180.0);
    return cos(radian);
}

double tangent(double degree) {
    double radian = degree * (PI / 180.0);
    return tan(radian);
}

double cosecant(double degree) {
    return 1.0 / sine(degree);
}

double secant(double degree) {
    return 1.0 / cosine(degree);
}

double cotangent(double degree) {
    return 1.0 / tangent(degree);
}