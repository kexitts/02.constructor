#include <iostream>
using namespace std;

struct Coord
{
    int X;
    int Y;
};

class Rectangle
{
private:
    int width;
    int height;
    char symbol;
    Coord position;

public:
   
    Rectangle()
    {
        width = 5;
        height = 3;
        symbol = '*';
        position.X = 0;
        position.Y = 0;
    }

   
    Rectangle(int size)
    {
        if (size > 0)
        {
            width = size;
            height = size;
        }
        else
        {
            width = 5;
            height = 3;
        }

        symbol = '*';
        position.X = 0;
        position.Y = 0;
    }

    
    Rectangle(int w, int h)
    {
        width = (w > 0) ? w : 5;
        height = (h > 0) ? h : 3;
        symbol = '*';
        position.X = 0;
        position.Y = 0;
    }

    
    void Show()
    {
        if (position.X < 0 || position.Y < 0)
        {
            cout << "Помилка координат!" << endl;
            return;
        }

        for (int i = 0; i < position.Y; i++)
            cout << endl;

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < position.X; j++)
                cout << ' ';

            for (int j = 0; j < width; j++)
                cout << symbol;

            cout << endl;
        }
    }

    
    void ChangeSize(int dh, int dw)
    {
        if (height + dh <= 0 || width + dw <= 0)
        {
            cout << "Помилка! Розміри мають бути більшими за 0."
                << endl;
            return;
        }

        height += dh;
        width += dw;
    }

    
    void Move(int dx, int dy)
    {
        if (position.X + dx < 0 || position.Y + dy < 0)
        {
            cout << "Помилка! Координати не можуть бути від'ємними."
                << endl;
            return;
        }

        position.X += dx;
        position.Y += dy;
    }

    
    void SetSymbol(char ch)
    {
        symbol = ch;
    }
};

int main()
{
    
    Rectangle r1;
    Rectangle r2(4);
    Rectangle r3(8, 4);

    cout << "Прямокутник за замовчуванням:" << endl;
    r1.Show();

    cout << "\nПрямокутник з одним параметром:" << endl;
    r2.Show();

    cout << "\nПрямокутник з двома параметрами:" << endl;
    r3.Show();

    cout << "\nЗміна розміру прямокутника:" << endl;
    r3.ChangeSize(2, 3);
    r3.Show();

    cout << "\nПереміщення прямокутника:" << endl;
    r3.Move(5, 2);
    r3.Show();

    cout << "\nЗміна символу:" << endl;
    r3.SetSymbol('#');
    r3.Show();

    cout << "\nПеревірка некоректних даних:" << endl;
    r3.ChangeSize(-100, 0);
    r3.Move(-100, 0);

    return 0;
}