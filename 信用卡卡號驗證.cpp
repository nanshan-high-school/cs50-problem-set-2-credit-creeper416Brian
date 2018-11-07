#include <iostream>
using namespace std;
int main() {

  long int number ;
  cout << "你的信用卡卡號為何?";
  cin >> number ;

  long int i = number / 10;
  long int k = number * 10;
  long int count;
  int total = 0;
  int code;


//乘2區

  for(long int count = 1;count <= 99999999999999999;count = count * 100){
    int sentence = i % count % 10;
    total = total + sentence * 2 / 10 + sentence * 2 % 10 ;
    i = number / count / 10;
  }


//乘1區

  for(long int count = 1;count <= 99999999999999999;count = count * 100){
    int sentence = k % count % 10;
    total = total + sentence / 10 + sentence % 10;
    k = number * 10 / count / 10;
  }
  

 total = total - number % 10;
 

//判斷信用卡種類區

  if (number / 1000000000000000 == 4)
    cout << "你的信用卡為Visa Card";

  else if (number / 100000000000000 >= 51 && number / 100000000000000 <= 55)
    cout << "你的信用卡為Master Card";

  else if (number >=1000000000000 && number <=9999999999999)
    cout << "你的信用卡為Visa Card";

  else if (number / 10000000000 >= 222100 && number / 10000000000 <= 272099)
    cout << "你的信用卡為Master Card";

  else
    cout << "你的信用卡非 Master Card 亦非 Visa Card";


  //驗證碼區

  if (total % 10 == 0)
    code = total % 10;

  else
    code = 10 - total % 10;


  if (code == number % 10)
    cout << "\n這張信用卡合法";

  else    
    cout << "\n這張信用卡不合法";
}
