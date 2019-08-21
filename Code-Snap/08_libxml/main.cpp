#include <iostream>
#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

using namespace std;
int main()
{
    xmlDocPtr pDoc = xmlParseFile("CreatedXml.xml");
    if (NULL == pDoc)
    {
        cout << "pDoc = Null";
        return 1;
    }
    xmlNodePtr root = xmlDocGetRootElement(pDoc);

    if(NULL == root) return 1;

    return 0;
}