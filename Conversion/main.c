//
// Created by x5021 on 2026/10/24.
//

#include <stdint.h>
#include <stdio.h>

typedef enum : int32_t {
    Height = 1,
    Quality = 2,
    Time = 3
} Type;

typedef struct {
    int32_t itemOne;
    float itemThree;
    double itemTwo;
} ConversionResults;

static ConversionResults conversionCMToINAndFT(const double cm) {
    constexpr double CMPerIN = 2.54;
    constexpr double INPerFT = 12.00;
    const auto in = cm / CMPerIN;
    const auto ft = (int32_t)(in / INPerFT);
    const auto otherIn = in - ft * INPerFT;
    return (ConversionResults){.itemOne = ft, .itemTwo = otherIn};
}

static ConversionResults conversionKGToLB(const double kg) {
    constexpr double KGPerLB = 0.45359237;
    const auto lb = kg / KGPerLB;
    return (ConversionResults){.itemTwo = lb};
}

static ConversionResults conversionMINToSECAndHOUR(const float min) {
    constexpr int32_t ConversionFactor = 60;
    auto sec = min * ConversionFactor;
    auto hour = (double)min / ConversionFactor;
    return (ConversionResults){.itemThree = sec, .itemTwo = hour};
}

int main() {
    int32_t index;
    printf("Please enter the index of the number you want to conversion: \n");
    printf("1. Height\n");
    printf("2. Quality\n");
    printf("3. Time\n");
    printf("Enter:");
    scanf("%d", &index);
    switch ((Type)index) {
        case Height: {
            double cm;
            printf("Enter the value of height(cm):");
            scanf("%lf", &cm);
            const auto result = conversionCMToINAndFT(cm);
            printf("===ConversionResult===\n");
            char ftin[64];
            snprintf(ftin, sizeof ftin, "%d feet, %.2f inches", result.itemOne, result.itemTwo);
            printf("%-12s | %12s\n","Centimeter", "Feet and inches");
            printf("%-12.2f | %-20s",cm,ftin);
            break;
        }
        case Quality: {
            double kg;
            printf("Enter the value of quality(kg): ");
            scanf("%lf", &kg);
            const auto result = conversionKGToLB(kg);
            printf("===ConversionResult===\n");
            printf("%-12s | %-12s\n", "Kilogram", "Pound");
            printf("%-12.2f | %-12.2f\n", kg, result.itemTwo);
            break;
        }
        case Time: {
            double min;
            printf("Enter the value of time(min):");
            scanf("%lf", &min);
            const auto result = conversionMINToSECAndHOUR(min);
            printf("===ConversionResult===\n");
            printf("%-12s | %-12s | %-12s\n", "Minute", "Hour", "Second");
            printf("%-12.2f | %-12.2f | %-12.2f\n", min, result.itemTwo, result.itemThree);
            break;
        }
        default: {
            printf("Invalid index\n");
            return 1;
        }
    }
}
