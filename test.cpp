    #include <iostream>

    // Templated dynamically growing array Interface
    template <typename T>
    class growingArrayInterface{
    public:
        // Pure Virtual Functions
        virtual void push_back(T x) = 0;
        virtual void remove_if(bool(*fun)(T)) = 0;
        virtual T &operator[](int idx)const = 0;
        virtual int getSize()const=0;
    };

    // Implementing the interface
    template <typename T>
    class growingArray : public growingArrayInterface<T>{
    private:
        T* arr;
        int curSize,mxSize;
        void resize();
    public:
        growingArray();
        growingArray(int size,T initialValue);
        ~growingArray();
        void push_back(T x);
        void remove_if(bool(*fun)(T));
        T &operator[](int idx)const;
        int getSize()const;
    };

    int main()
    {
        
        growingArray<int> myGrowingArray;
        int arr[]={13, 12, 4, 29, 30};  //This for input

        //Pushing input to growing array
        for(int i=0;i<5;i++)myGrowingArray.push_back(arr[i]); 

        //If the predicate is x<12 then the array will be [13, 12, 29, 30] not like the test.
        myGrowingArray.remove_if([](int value){return value<12;});

        // Printing the growingArray.
        for(int i=0;i<myGrowingArray.getSize();i++)std::cout<<myGrowingArray[i]<<" ";
        std::cout<<std::endl;
    


    }

    //Defination functions for growingArray class

    template <typename T>
    growingArray<T>::growingArray() :arr(new T[1]),curSize(0),mxSize(1) {}

    template <typename T>
    growingArray<T>::growingArray(int size,T initialValue) :arr(new T[size<<1]),curSize(size),mxSize(size<<1) {
        for(int i=0;i<curSize;i++)arr[i]=initialValue;
    }

    template <typename T>
    int growingArray<T>::getSize()const{return curSize;}

    template <typename T>
    growingArray<T>::~growingArray(){
        delete[] arr;
        arr = nullptr;
    }

    template <typename T>
    void growingArray<T>::resize(){
        T*tmpArr=new T[mxSize<<1];
        for(int i=0;i<curSize;i++)
            tmpArr[i]=arr[i];
        delete[] arr;
        arr=tmpArr;
        tmpArr=nullptr;
        mxSize<<=1;
    }
    template <typename T>
    void growingArray<T>::push_back(T x){
        if(curSize==mxSize)resize();
        arr[curSize++]=x;
    }

    template <typename T>
    void growingArray<T>::remove_if(bool(*fun)(T)){
        int newSize=0;
        for(int i=0;i<getSize();i++)
            if(!fun(arr[i]))arr[newSize++]=arr[i];
        curSize=newSize;
    }


    template <typename T>
    T& growingArray<T>::operator[](int idx)const{
        if(idx>=curSize){
            std::cout<< "Out of memory index"<<std::endl;
            exit(0);
        }
        return arr[idx];
    }