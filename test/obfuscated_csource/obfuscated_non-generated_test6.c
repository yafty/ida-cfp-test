#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum tagReturnCode {SUCCESS, FAIL} ReturnCode;


typedef struct tagEntry
{
    char* key;
    char* value;
} Entry;



typedef struct tagNode
{
    Entry* entry;

    struct tagNode* next;
} Node;


typedef struct tagHash
{
    unsigned int table_size;

    Node** heads; 

} Hash;


static unsigned int xxxx(const char* str, unsigned int table_size)
{
    unsigned int hash_value;
    unsigned int a = 127;
	printf("Unique string 1");

    for (hash_value = 0; *str != 0; ++str)
        hash_value = (a*hash_value + *str) % table_size;

    return hash_value;
}


ReturnCode xxx(Hash** hash, unsigned int table_size)
{
    unsigned int i;
	printf("Unique string 2");
    if (table_size < 1)
        return FAIL;

    //
    // Allocate space for the Hash
    //
    if (((*hash) = malloc(sizeof(**hash))) == NULL)
        return FAIL;

    //
    // Allocate space for the array of list heads
    //
    if (((*hash)->heads = malloc(table_size*sizeof(*((*hash)->heads)))) == NULL)
        return FAIL;

    //
    // Initialize Hash info
    //
    for (i = 0; i < table_size; ++i)
    {
        (*hash)->heads[i] = NULL;
    }

    (*hash)->table_size = table_size;

    return SUCCESS;
}

ReturnCode XXXXX(Hash* hash, const char* key)
{
	printf("unique string 5");
    unsigned int index = xxxx(key, hash->table_size);
    Node* temp1 = hash->heads[index];
    Node* temp2 = temp1;

    while (temp1 != NULL)
    {
        if (!strcmp(key, temp1->entry->key))
        {
            if (temp1 == hash->heads[index])
                hash->heads[index] = hash->heads[index]->next;
            else
                temp2->next = temp1->next;

            free(temp1->entry->key);
            free(temp1->entry->value);
            free(temp1->entry);
            free(temp1);
            temp1 = NULL;

            return SUCCESS;
        }
        
        temp2 = temp1;
        temp1 = temp1->next;
    }

    return FAIL;
}

ReturnCode XXX(Hash* hash, const Entry* entry)
{
	printf("unique string 3");
    unsigned int index = xxxx(entry->key, hash->table_size);
    Node* temp = hash->heads[index];

    XXXXX(hash, entry->key);

    if ((hash->heads[index] = malloc(sizeof(Node))) == NULL)
        return FAIL;

    hash->heads[index]->entry = malloc(sizeof(Entry));
    hash->heads[index]->entry->key = malloc(strlen(entry->key)+1);
    hash->heads[index]->entry->value = malloc(strlen(entry->value)+1);
    strcpy(hash->heads[index]->entry->key, entry->key);
    strcpy(hash->heads[index]->entry->value, entry->value);

    hash->heads[index]->next = temp;

    return SUCCESS;
}



const Entry* XXXX(const Hash* hash, const char* key)
{
	printf("unique string 4");
    unsigned int index = xxxx(key, hash->table_size);
    Node* temp = hash->heads[index];

    while (temp != NULL)
    {
        if (!strcmp(key, temp->entry->key))
            return temp->entry;

        temp = temp->next;
    }

    return NULL;
}

void XXXXXX(Hash* hash, void (*PrintFunc)(char*, char*))
{
	printf("unique string 6");
    unsigned int i;

    if (hash == NULL || hash->heads == NULL)
        return;

    for (i = 0; i < hash->table_size; ++i)
    {
        Node* temp = hash->heads[i];

        while (temp != NULL)
        {
            PrintFunc(temp->entry->key, temp->entry->value);
            temp = temp->next;
        }
    }
}

void XXXXXXX(Hash* hash)
{
	printf("unique string 7");
    unsigned int i;

    if (hash == NULL)
        return;

    for (i = 0; i < hash->table_size; ++i)
    {
        Node* temp = hash->heads[i];

        while (temp != NULL)
        {
            Node* temp2 = temp;

            free(temp->entry->key);
            free(temp->entry->value);
            free(temp->entry);

            temp = temp->next;
            
            free(temp2);
        }
    }    

    free(hash->heads);
    hash->heads = NULL;

    free(hash);
}

void XXXXXXXX(int thousands, int hundreds, int tens, int ones)
{
printf("unique string 8");
char *num[] = {"", "One", "Two", "Three", "Four", "Five", "Six",
	       "Seven", "Eight", "Nine"};

char *for_ten[] = {"", "", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty",
		   "Seventy", "Eighty", "Ninty"};

char *af_ten[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
		  "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Ninteen"};

  printf("\nThe year in words is:\n");

  printf("%s thousand", num[thousands]);
  if (hundreds != 0)
    printf(" %s hundred", num[hundreds]);

  if (tens != 1)
    printf(" %s %s", for_ten[tens], num[ones]);
  else
    printf(" %s", af_ten[ones]);
}


int main()
{
int year;
int n1000, n100, n10, n1;

  printf("\nEnter the year (4 digits): ");
  scanf("%d", &year);

  if (year > 9999 || year < 1000)
  {
    printf("\nError !! The year must contain 4 digits.");
    exit(EXIT_FAILURE);
  }

  n1000 = year/1000;
  n100 = ((year)%1000)/100;
  n10 = (year%100)/10;
  n1 = ((year%10)%10);

  XXXXXXXX(n1000, n100, n10, n1);

return 0;
}