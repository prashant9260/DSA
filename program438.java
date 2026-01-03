class node
{
    public int data;
    public node next;
}

class SinglyLL
{
    public node first;
    public int iCount;

    SinglyLL()
    {
        System.out.println("Object of SinglyLL gets created...");
        this.first = null;
        this.iCount = 0;
    }
}

class program438
{
    public static void main(String A[])
    {
        SinglyLL obj = null;

        obj = new SinglyLL();
    }
}