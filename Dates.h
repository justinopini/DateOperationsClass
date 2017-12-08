class Date{
    public:
    //Constructors
        Date();//Default constructor
        Date(int Day, int Month, int Year);//Non-defaulft constructor
    //Transformers
        Date AddDays(int Number) const;
        Date RemoveDays(int Number) const;
        void SetMonth();
        void SetDay() ;
        void SetYear();
    //Observers
        void PrintDate() const;
        bool IsLeapYear() const;
        int GetMonth() const;
        int GetDay() const;
        int GetYear() const;
    private:
    //Variables
        int Day;
        int Month;
        int Year;
};
