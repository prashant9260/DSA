class node
{
    public int data;
    public node next;
}

class SinglyLL
{
    public node first;
    public int iCount;

    public SinglyLL()
    {
        System.out.println("Object of SinglyLL gets created...");
        this.first = null;
        this.iCount = 0;
    }

    public void InsertFirst(int no)
    {
        node newn = null;

        newn = new node();

        newn.data = no;
        newn.next = null;

        newn.next = this.first;
        this.first = newn;

        this.iCount++;
    }

    public void InsertLast(int no)
    {}

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

       temp = this.first;

       while(temp != null)
       {
            System.out.print("| "+temp.data+" | ->");
            temp = temp.next;
       }

       System.out.println("null");
    }

    public int Count()
    {
        return this.iCount;
    }

}

class program441
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
        System.out.println("Numbers of Nodes are : "+iRet);

        // Important for memory deallocation
        obj = null;
        System.gc();

    }
}