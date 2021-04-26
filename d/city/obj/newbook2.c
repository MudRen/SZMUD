// Code of ShenZhou
#include <ansi.h>
inherit ITEM;

int help(object me);

void create()
{
        set_name("�հ׵���", ({"book"}));
        set_weight(10);
        set_weight(1);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ���Ѿ�д�õ��飬����ö�(read)�����������ݡ�\n");
                set("unit", "��");
                set("material", "paper");
                set("value", 2000);
                set("no_sell", 1);
        }
}

int init()
{
    add_action("do_read", "read");   
}

int do_read(string arg)
{
        string msg, this_page;
		int page_no;
		object me, this_book;
        mapping new_book;

        me = this_player();
		this_book = this_object();

        if( !arg || sscanf(arg, "%s %d", msg, page_no)!=2 ) return help(me);

        if (msg != "page") 
             return  notify_fail("������ (read page #) ��\n");
    	if (page_no > 20 || page_no < 1) 
              return  notify_fail("���� 1 �� 20 ҳ֮�䡣\n");

		new_book = this_book->query("new_book");

        if(!(this_page = new_book["text"][page_no]))
             return  notify_fail("��һҳ��ûд����ô����\n");;

        printf("��%s����\n�����ߡ���%s\n\n",
		new_book["title"],new_book["arthur"]);
        this_player()->start_more(this_page);

        return 1;
}

int help(object me)
{
	write("ָ���ʽ��\n
	������ (read page #) ��\n");
	return 1;
}
