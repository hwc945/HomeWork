#include "Operate.h"
int main(){
		printf("请输入中缀表达式，末尾以‘#’结束:\n");
		SElemType2 result = calculate();
		printf("该中缀表达式结果为：%.3lf",result);
		return 0;
}


