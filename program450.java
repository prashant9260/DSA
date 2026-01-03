// Doubly Linear

class node
{
    public int data;
    public node next;
    public node prev;

    public node(int no)
    {
        this.data = no;
        this.next = null;
        this.prev = null;
    }
}

class DoublyLL
{
    private node first;
    private node last;
    
    private int iCount;

    public DoublyLL()
    {
        System.out.println("Object of DoublyLL gets created.");
        
        this.first = null;
        this.last = null;
        
        this.iCount = 0;
    }

    public void InsertFirst(int no)
    {
        node newn = null;

        newn = new node(no);

        if(this.first == null && this.last == null)
        {
            this.first = newn;
            this.last = newn;
        }
        else
        {
            this.first.prev = newn;
            newn.next = this.first;

            this.first = newn;
        }

        this.iCount++;
    }

    public void InsertLast(int no)
    {
        node newn = null;

        newn = new node(no);

        if(this.first == null && this.last == null)
        {
            this.first = newn;
            this.last = newn;
        }
        else 
        {
            newn.prev = this.last;
            this.last.next = newn;
            this.last = newn;

            newn.next = null;            
        }

        this.iCount++;
    }

    public void DeleteFirst()
    {
        if(this.first == null && this.last == null)
        {
            return;
        }
        else if(this.first == this.last)
        {
           this.first = this.last = null;  
        }
        else
        {
            this.first = this.first.next;
            this.first.prev = null;
        }

        this.iCount--;
    }
    
    public void DeleteLast()
    {

        if(this.first == null && this.last == null)
        {
            return;
        }
        else if(this.first == this.last)
        {
           this.first = this.last = null;  
        }
        else
        {
            this.last = this.last.prev;
            this.last.next = null;
        }

        this.iCount--; 
    }
    
    
    public void InsertAtPos(int no, int pos)
    {
        node newn = null;
        node temp = null;
        int iCnt = 0;

        newn = new node(no);

        if(pos < 1 || pos > iCount+1)
        {
            System.out.println("Invalid position...");
            return;
        }

        if(pos == 1)
        {
            this.InsertFirst(no);
        }
        else if(pos == iCount+1)
        {
            this.InsertLast(no);
        }
        else
        {
            temp = this.first;

            for(iCnt = 1; iCnt < pos-1; iCnt++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            newn.prev = temp;
            temp.next = newn;
            newn.next.prev = newn;

            this.iCount++;
        }
    }

    public void DeleteAtPos(int pos)
    {
        node temp = null;
        int iCnt = 0;

        if(pos < 1 || pos > iCount)
        {
            System.out.println("Invalid position...");
            return;
        }

        if(pos == 1)
        {
            this.DeleteFirst();
        }
        else if(pos == iCount)
        {
            this.DeleteLast();
        }
        else
        {
            temp = this.first;

            for(iCnt = 1; iCnt < pos-1; iCnt++)
            {
                temp = temp.next;
            }

            temp.next = temp.next.next;
            temp.next.prev = temp;

            System.gc();

            this.iCount--;
        }
    }
    
    public void Display()
    {
        node temp = null;

        temp = this.first;

        while(temp != null)
        {
            System.out.print("| "+temp.data+"| <=>");
            temp = temp.next;
        }

        System.out.println("null");
    }

    public int Count()
    {
        return this.iCount;
    }
}

class program450
{
    public static void main(String A[])
    {
        DoublyLL obj = null;
        int iRet = 0;

        obj = new DoublyLL();

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);
        
        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);

        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);
        
        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);

        obj.DeleteFirst();

        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);

        obj.DeleteLast();

        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);
       
        obj.InsertAtPos(105,4);

        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);
       
        obj.DeleteAtPos(4);
        
        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);
    
        // Important for memory deallocation 
        obj = null;
        System.gc();
    }
}