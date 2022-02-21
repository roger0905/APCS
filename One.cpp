#include <iostream>

using namespace std;

int main()
{
	int i = 0, Title_Number = 0;
	int People_Input = 0, Number_Input = 0, Number_Input_Reg[20] = { 0 }, Number_Reg[20] = { 0 };

	while (1) {

		// INPUT Title
		cout << "範例" << Title_Number + 1 << " : 輸入\n";

		// Input People Number
		cin >> People_Input;

		// Protection Whole Program
		if (People_Input > 20 || People_Input <= 0) {
			break;
		}

		// Input Number TO People's Array
		while (cin >> Number_Input) {
			Number_Input_Reg[i++] = Number_Input;
			char Key_Reg = getchar();

			if (Key_Reg == '\n')
				break;
		}

		// Change TO Inside Number_Reg Array
		for (int i = 0; i < People_Input; i++) {
			Number_Reg[i] = Number_Input_Reg[i];
		}

		// Calculate min TO Max Array
		for (int i = 0; i < People_Input; i++) {
			for (int j = i + 1; j < People_Input; j++) {
				if (Number_Reg[i] > Number_Reg[j]) {
					int Move_Number_Reg = Number_Reg[i];
					Number_Reg[i] = Number_Reg[j];
					Number_Reg[j] = Move_Number_Reg;
				}
			}
		}

		// OUTPUT Title
		cout << "範例" << Title_Number + 1 << " : 正確輸出\n";

		// Output min TO Max Array
		for (int i = 0; i < People_Input; i++)
			cout << Number_Reg[i] << " ";

		cout << "\n";

		int Best_Number_Move[20] = { 0 }, Worst_Number_Move[20] = { 0 }, Best_Array_Reg = 0, Worst_Array_Reg = 0;

		// Calculate (Number_Reg Array) TO [ (Best_Number_Move Array) AND (Worst_Number_Move Array) ]
		for (int i = 0; i < People_Input; i++) {
			if (Number_Reg[i] >= 60) {
				Best_Number_Move[Best_Array_Reg] = Number_Reg[i];
				Best_Array_Reg++;
			}
			if (Number_Reg[i] < 60) {
				Worst_Number_Move[Worst_Array_Reg] = Number_Reg[i];
				Worst_Array_Reg++;
			}
		}

		// Output (Worst Number) AND (Best Number)  
		if ((Best_Array_Reg < People_Input) && (Worst_Array_Reg < People_Input)) {
			cout << Worst_Number_Move[Worst_Array_Reg - 1] << "\n";
			cout << Best_Number_Move[0];
		}
		// Output (Worst Number) AND "worst case"
		else if (Worst_Array_Reg == People_Input) {
			cout << Worst_Number_Move[Worst_Array_Reg - 1] << "\nworst case";
		}
		// Output "best case" AND (Best number)
		else if (Best_Array_Reg == People_Input) {
			cout << "best case\n" << Best_Number_Move[0];
		}

		// Reset TO Origin
		int Num[20] = { 0 };
		i = 0;
		Title_Number++;
		cout << "\n" << endl;
	}
	// Output Program Error TO Close Whole Program
	cout << "\nSystem Error\n";
	system("pause");
}