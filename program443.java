class node
{
    public int data;
    public node next;

    public node(int no)
    {
        this.data = no;
        this.next = null;
    }
}

class SinglyLL
{
    public node first;
    public int iCount;

    public SinglyLL()
    {
        System.out.println("Object of singlyLL gets created...");

        this.first = null;
        this.iCount = 0;
    }

    public void InsertFirst(int no)
    {
        node newn = null;

        //change code
        newn = new node(no);

        newn.next = this.first;
        this.first = newn;

        this.iCount++;
    }

    public void InsertLast(int no)
    {
        node newn = null;
        node temp = null;

        newn = new node(no);

        if(first == null)
        {
            this.first = newn;
        }
        else if(first.next == null)
        {
            this.first.next = newn;
        }
        else
        {
            temp = first;

            while(temp.next != null)
            {
                temp = temp.next;
            }

            temp.next = newn;
        }

        this.iCount++;
    }

    public void InsertAtPos(int no, int pos)
    {}

    public void DeleteFirst()
    {}

    public void DeleteLast()
    {}

    public void DeleteAtPos(int pos)
    {}

    public void Display()
    {
        node temp = null;

        temp = first;

        while(temp != null)
        {
            System.out.print("| "+temp.data+"| ->");
            temp = temp.next;
        }

        System.out.println("null");
    }

    public int Count()
    {
        return iCount;
    }
}

class program443
{
    public static void main(String A[])
    {
        SinglyLL obj = null;
        int iRet = 0;

        obj = new SinglyLL();

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
    }
}