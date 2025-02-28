#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono> 
using namespace std;

void clearScreen(){
    std::cout << "\033[2J\033[1;1H";
}
class Hive {
    private:
        int bee_count;
        int hive_cordinate_x;
        int hive_cordinate_y;
        string hive_name;
        string hive_owner;

    public:
    // Constructor ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    Hive(int b=0, int x=0, int y=0, string n="Nie podano nazwy pasieki\n", string w="Nie podano właściciela\n"){
        if (b<0){
            cout<<"Liczba pszczół nie może być ujemna"<<endl;
            bee_count=0;
            std::this_thread::sleep_for(std::chrono::seconds(2));}
        else {    
            bee_count=b;}
        hive_cordinate_x=x;
        hive_cordinate_y=y;
        hive_name=n;
        hive_owner=w;
    }
    // Setters ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    void setBeeCount(int x){
        if (x<-100 || x>100){
            cout<<"Podano liczbę spoza zakresu <-100,100>"<<endl;
        }
        else if (bee_count+x<0){
            cout<<"Liczba pszczół spadłaby poniżej 0"<<endl;
        }
        else {
            cout<<"Zmieniono liczbę pszczół"<<endl;
            bee_count+=x;
        }
    }
    void setHiveName(string n){
        if (isupper(n[0])) {
            cout<<"Zmieniono nazwę pasieki"<<endl;
            hive_name=n;        
        }
        else {
            cout<<"Nazwa pasieki musi zaczynać się z dużej litery!"<<endl;
        }
    }
    void setHiveOwner(string w){
        cout<<"Zmieniono właściciela pasieki"<<endl;
        hive_owner=w;
    }    
    void setHiveCordinates(int x, int y){
        if (x>90 || x<-90){
        cout<<"Podano złą wartość x"<<endl;
        }
        if (y>180 || y<-180){
        cout<<"Podano złą wartość y"<<endl;
        }
        else {
        cout<<"Zmieniono współrzędne geograficzne"<<endl;
        hive_cordinate_x = x;
        hive_cordinate_y = y;
        }
    }
    // Getters ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    int getBeeCount() {
        return bee_count;
    }
    std::pair<int, int> getCordinates() {
        return std::make_pair(hive_cordinate_x, hive_cordinate_y);
    }
    string getHiveName() {
        return hive_name;
    }
    string getOwnerName() {
        return hive_owner;
    }
    // Functions ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    void hiveMenu() {
        int num=0;
        clearScreen();
        while (num!=3){
        clearScreen();
        cout<<"Witaj użytkowniku w swoim ulu!\nCo chciałbyś zrobić?\n 1. Odczytać informacje o ulu\n 2. Zmienić informacje o ulu\n 3. Wyjść"<<endl;
        cin>>num;
        if (num==1){
        clearScreen();  
        cout<<"Co chciałbyś odczytać?\n 1. Liczbę pszczół w ulu\n 2. Nazwę pasieki\n 3. Położenie pasieki\n 4. Nazwę właściciela\n 5. Wrócić do menu"<<endl;
        int num1;
        cin>>num1;
        clearScreen();  
        switch (num1) {
            case 1:
                cout<<"Liczba pszczół wynosi: "<<getBeeCount()<<endl;
                break;
            case 2:
                cout<<"Pasieka nazywa się: "<<getHiveName()<<endl;
                break;
            case 3:
                cout << "Współrzędne geograficzne pasieki to X: " << getCordinates().first << " Y: " << getCordinates().second << endl;
                break;
            case 4:
                cout<<"Obecny właściciel to: "<<getOwnerName()<<endl;
                break;
            case 5:
                cout<<"Wracam do menu\n";
                break;
            default:
                cout << "Podano liczbę spoza menu" << endl;
                break;
                }
        }
        if (num==2){
        clearScreen();
        cout<<"Co chciałbyś zmienić?\n 1. Zmienić liczbę pszczół w ulu\n 2. Zmienić nazwę pasieki\n 3. Zmienić położenie pasieki\n 4. Zmienić właściciela\n 5. Wrócić do menu"<<endl;
        int num2,b,x,y;
        string n,w;
        cin>>num2;
        clearScreen();  
        switch (num2) {
            case 1:
                cout<<"Podaj o ile chciałbyś zmienić liczbę pszczół"<<endl;
                cin>>b;
                setBeeCount(b);
                break;
            case 2:
                cout<<"Podaj nową nazwę pasieki"<<endl;
                cin>>n;
                setHiveName(n);
                break;
            case 3:
                cout<<"Podaj nowe współrzędne geograficzne pasieki (x,y)"<<endl;
                cout<<"X: ";
                cin>>x;
                cout<<"\nY: ";
                cin>>y;
                setHiveCordinates(x,y);
                break;
            case 4:
                cout<<"Podaj nazwę nowego właściciela"<<endl;
                cin>>w;
                setHiveOwner(w);
                break;
            case 5:
                cout<<"Wracam do menu"<<endl;
                break;
            default:
                cout << "Podano liczbę spoza menu" << endl;
                break;
            }
        }
    std::this_thread::sleep_for(std::chrono::seconds(3));
    }
    }
  
};

int main() {
  clearScreen();
  int b;
  cout<<"Witaj, podaj liczbę pszczół w pasiece: ";
  cin>>b;
  Hive ul(b);
  ul.hiveMenu();
}