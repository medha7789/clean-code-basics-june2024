class Subtype {
    int subtype;
public:
    public Subtype(int value)
    {
        subtype = value; 
    }
    public getSubtype() {
        return subtype;
    }
    public setSubtype(int value) {
        subtype = value;
    }
    virtual void spin() = 0;
    virtual void hop() = 0;
    virtual void slide() = 0;
};
class hopper : public Subtype {
    bool visible; // need for hopper
    int xcoord, ycoord; // need for hopper
public:
    void hop();
    void slide();//FAT interface
    void spin();//FAT interface
};
class slider : public Subtype {
    bool vertical; // need for slider
    int distance; // need for slider
public:
    void hop(){}//FAT interface
    void slide(){}
    void spin(){}//FAT interface
};
class spinner : public Subtype {
    bool clockwise; // need for spinner
    bool expand; // need for spinner
public:
    void hop(){}//FAT interface
    void slide(){}//FAT interface
    void spin(){}
};
class Icon
{
    float speed, glow, energy;
    int x, y;
    subtype IconSubtype;

public:
    // constructor must set subtype: client must pass value
    void Icon(int value)
    {
        IconSubtype.subtype = value; // use enum for readability
        // and then use conditional to set associated fields
    }

    void move()
    {
        if (IconSubtype.subtype == 1) 
        { 
          IconSubtype.spin(); 
        }
        else if (subtype == 2)
        {
            IconSubtype.slide();
        }
        else
        {
            IconSubtype.hop();
        }
    }
    // tedious subtype checking: subtype drives flair details
    void flair()
    {
        if (subtype == 1) { IconSubtype.spin(); }
        else if (subtype == 2)
        {
            IconSubtype.slide();
        }
        else
        {
            IconSubtype.hop();
        }
    }
}
int main()
{
  //I want the icon to move while spinning
  Icon iconObj(1);//1 for spin, 2 for slide and 3 for hop
  iconObj.move();
  return 0;
}
