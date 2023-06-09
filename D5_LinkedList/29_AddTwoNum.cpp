// (1) add the two digits and check for carry
// (2) remember numbers can be unequal in digits.
// (3) at last if carry remains, create a node for it.

Node *addTwoNumbers(Node *num1, Node *num2){
    int carry = 0;
    Node *dummy = new Node(-1);
    Node *res = dummy;
    while(num1 != NULL && num2 != NULL){    // (1)
        int dig1 = num1->data;
        int dig2 = num2->data;

        int sum = dig1 + dig2 + carry;
        carry = sum / 10;
        sum = sum % 10;

        Node *newnode = new Node(sum);
        dummy->next = newnode;
        dummy = dummy->next;

        num1 = num1->next;
        num2 = num2->next;
    }
    if(num1 != NULL){   // (2)
        while(num1 != NULL){
            int sum = carry + num1->data;
            carry = sum / 10;
            sum = sum % 10;

            Node *newnode = new Node(sum);
            dummy->next = newnode;
            dummy = dummy->next;

            num1 = num1->next;
        }
    }
    if(num2 != NULL){     // (2)
        while(num2 != NULL){
            int sum = carry + num2->data;
            carry = sum / 10;
            sum = sum % 10;

            Node *newnode = new Node(sum);
            dummy->next = newnode;
            dummy = dummy->next;

            num2 = num2->next;
        }
    }
    if(carry){      // (3)
        Node *newnode = new Node(carry);
        dummy->next = newnode;
        dummy = dummy->next;
    }

    return res->next;
}