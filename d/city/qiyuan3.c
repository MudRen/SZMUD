// Code of ShenZhou
// qiyuan3.c


#include <ansi.h>
#include <room.h>
#include "/d/city/chess_room.h"

inherit ROOM;
string look_book();
void do_back(object ob);
int do_knock(object ob);

void create()
{
	set("short", "���Ұ");
	set("long", @LONG
�����ǲ���е�����֮һ����������֪����̸���ۣ�Ʒ����ȵĺõط�����     
�ڲ��ü򵥵�Ҳ���¡�ǽ�Ϲ���һ������ (duilian)��ľ����������������̺�
���ӣ���ʱ���Կ�ʼ(start)���壬����(table)��������⣬������һ��С���� 
(book)��
LONG
	);
	set("exits", ([
		"east" : "/d/city/chaguan",
        ]));
        set("no_fight", 1);
        set("no_sleep_room",1);
	set("item_desc", ([
		"book" : (:look_book:),
		"table": "һ�ŵ��ŵ���ľС��������������̺��������ߡ�\n",
		"duilian" : HIC"
	****** ******
	* ܱ * * �� *
	* �� * * ̸ *
	* �� * * �� *
	* �� * * �� *
	* һ * * �� *
	* �� * * Ҹ *
	* �� * * �� *
	* ů * * �� *
	****** ******\n\n"NOR,
 	
	]));
	set("no_clean_up", 0);
        setup();
        set("no_user", 1);
}


int do_knock(string arg)
{       
        object me = this_player();
	object waiter;

        if ( (!arg )|| (arg != "table"))
	  {       
	        write("��ʲôѽ��(knock table)\n");
                return 1;
	  }
        if( (arg == "table") )
	  {     
                if(!(waiter = find_living("chaguan xiaoer")))
                  {
		        waiter = new("/d/city/npc/c_waiter");
		        waiter->move(environment(me));
                  }

                waiter->move(environment(me));
                message_vision("$N�������ָͷ�������������ӣ����С�����˹�����\n", me);
		remove_call_out("do_back");
	        call_out("do_back", 20 + random(10), waiter);
                return 1;
	  }
        return 1;
}

void do_back(object ob)
{
  message("vision", 
	  "�͹������ã�С���������ˡ�\n", 
	  environment(ob), ({ob}));
  ob->move("/d/city/chaguan");
}
void reset()
{
        ::reset();
        set("no_clean_up", 1);
}
