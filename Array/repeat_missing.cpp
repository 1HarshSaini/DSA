int *findTwoElement(int *arr, int n) {
        // code here
        int a;//repeating
        int b;//missing
        
        for(int i=0;i<n;i++){
            if(arr[abs(arr[i])-1]>=0){
                arr[abs(arr[i])-1]=-arr[abs(arr[i])-1];//if index ho - mean vissited krdo
            }
            // if that ele is( - )alrady it means that there is same ele apear before
            else if(arr[abs(arr[i])-1]<0){
                a=abs(arr[i]);
               
            }
        }
        
        for(int i=0;i<n;i++){
            // if any elemnt in array is +ve it means that this index element is missing
            if(arr[i]>=0){
                b=i+1;
                break;
            }
        }
        
       int* v = new int[2];
       v[0]=a;
       v[1]=b;
       return v;
    }