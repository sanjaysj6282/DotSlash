#include <bits/stdc++.h>
using namespace std;

#define FAST {ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);}

#define ll long long int
#define ld long double

#define pb push_back 
#define pi pair<ll, ll>
#define ff first
#define ss second
#define vi vector<ll> 
#define vb vector<bool>
#define vii vector<pi>
#define vvi vector<vi> 
#define mii map<ll, ll>
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define srt(v) sort(v.begin(), v.end())
#define setcnt(n) __builtin_popcount(n) // no of ones(set bits)
#define bitcnt(n) (int)log2(n) // no of bits

#define yy cout<<"YES\n"
#define nn cout<<"NO\n"
#define pre(a) {cout << fixed << setprecision(a);}
#define vect(v, n) {rep(i, 0, n){ll x; cin>>x; v.pb(x);}}

const int M=1e4+3, MOD=1e9+7;

ll gcd(ll a,ll b) {if(b==0) return a; return gcd(b,a%b); }
ll lcm(ll a,ll b) {return a/gcd(a,b)*b; }


class node{
    public:
        int data;
        node* next;
    
        node(int val){
            data = val;
            next=NULL;
        }
};

void insertatHead(node* &head,int val){
    node* n= new node(val);

    if(head==NULL){
        n->next=n;
        head = n;
        return;
    }

    node* temp = head;        
    while(temp->next!=head){  
        temp = temp->next;    
    }
    temp->next=n;
    n->next=head;
    head=n;
}

void insertAtTail(node* &head,int val){

    if(head == NULL){
        insertatHead(head,val);
        return;
    }

    node* n= new node(val);
    node* temp = head;        
    while(temp->next!=head){  
        temp = temp->next;    
    }
    temp->next=n;
    n->next=head;
}

void display(node* head){
    node* temp=head;
    // Do while is used to check condition after execution
    // 1st it executes then checks the condition
    // It executes once more than while
    do{
        cout << temp->data <<" ";
        temp=temp->next;
    }while(temp!=head);
    cout << "\n";
}

void deleteAtHead(node* &head){
    node* todelete = head;
    node* temp=head;
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next=head->next;
    head= head->next;

    delete todelete;

}

void deletion(node* &head, int pos){
    if(pos==1){
        deleteAtHead(head);
        return;
    }

    node* temp = head;
    int count = 1;

    while(count!=pos-1){
        temp=temp->next;
        count++;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;    // Deletion is  a must to prevent memory leak
}

void deleteNode(node** head, ll key){   
    // If linked list is empty
    if (*head == NULL)
        return;
         
    // If the list contains only a single node
    if((*head)->data==key && (*head)->next==*head)
    {
        free(*head);
        *head=NULL;
        return;
    }
     
    node *last=*head,*d;
     
    // If head is to be deleted
    if((*head)->data==key)
    {
         
        // Find the last node of the list
        while(last->next!=*head)
            last=last->next;
             
        // Point last node to the next of head i.e.
        // the second node of the list
        last->next=(*head)->next;
        free(*head);
        *head=last->next;
      return;
    }
     
    // Either the node to be deleted is not found
    // or the end of list is not reached
    while(last->next!=*head&&last->next->data!=key)
    {
        last=last->next;
    }
     
    // If node to be deleted was found
    if(last->next->data==key)
    {
        d=last->next;
        last->next=d->next;
        free(d);
    }
    else
        cout<<"no such keyfound";
}


// Declaring variables
ll n, m, k, t;
string s, s1, s2;

// 1 2 3 4 5 6
// 1   3   5 
//     3

// Terminated due to timeout
void solve(){
    cin >> n;
    node* head =NULL;
    rep(i, 1, n+1){
        insertAtTail(head,i);
    }

    // display(head);

    node* temp=head;
    while(head->next!=head){
        deleteNode(&head, temp->next->data);
        temp=temp->next;
    }

    cout << head->data << endl;
}

int32_t main() {
    FAST;

    t=1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}