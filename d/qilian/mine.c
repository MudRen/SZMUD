// Code of Shenzhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;
int do_dig();
void create()
{
        set("short", "���ﶴ");
        set("long", @LONG
һ���յ����Ĵ�ɽ�����ıںܹ⻬���㿴�����ű��Ϻ�����ʲ�ᶫ
�����������⡣
LONG
        );
        set("exits", ([
                "out" : __DIR__"danfeng",
        ]));
	set("gold_count", 20);

	set("cost", 2);
        setup();
}
void init()
{
        add_action("do_dig","dig");
}

int do_dig()
{
    object ob, me = this_player();

    if (present("tie qiao", me))  
    { message_vision("$N��������������������ϣ�ﬣ�ﬣ� һͨ���ڡ�\n", me);
   
	if ( random(10) == 5 && query("gold_count") >= 1) {
      write("һ���������Ķ���һ�������������������ڵ�һ���ƽ�\n");
	   me->add("jingli", -10);
           ob = new("clone/money/gold");
           ob->move("/d/qilian/mine");
	   add("gold_count", -1);
	if (query("gold_count") < 1)
	log_file("MONEY", sprintf("%s(%s)��%s�ڵ��ﶴ�����������ƽ�\n",
		me->query("name"), getuid(me), ctime(time())));
         }    
   }
      else {
		write("û�к��ʵļһ�ڲ����ɣ�");
        }
 	return 1;
}
