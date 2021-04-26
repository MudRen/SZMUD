// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
������ɽ����һ�߷壬ֱ�����ƣ���·��Ѱ��ֻ��ɽǰһ���ʯ(stone)��
����ɽ����������ʱ�к��������˳����ɽ���е��� ��������ɽ֮̽����δ
������
LONG
        );
        set("exits", ([
                "eastdown" : __DIR__"zibai",
                "westdown" : __DIR__"tanglang",
        ]));

	set("item_desc", ([
                "stone" : "һ����Ĵ�ʯ�����Ĳ��ֺܹ⻬����������ʱ��Ħ����\n",
        ]));
	set("outdoors" , "qilian-shan");
	set("insect_cont", 5);
	set("cost", 3);
	setup();
}

void init()
{
	add_action("do_move","move");
}

int do_move(string arg)
{
	object me = this_player();

	set("exits/enter", __DIR__"rukou");

	write("��ʹ��Ų����ʯ���ֳ�һ��ɽ��������ͻȻ���ִ�ʯ������Щ�ּ���\n"
          "����д�š��Ǳ������ˣ���������Ȼȫƾָ���̳�������ʯ���֣���\n"
          "�߻�ӡ��һ����ӡ����ʯ������࣬�ɼ������˹���֮���Ѵﾪ����\n"
          "�׵ĵز���\n", me);

       remove_call_out("close");
       call_out("close", 5, this_object());
 
	
   return 1;
}

void close(object room)
{
        message("vision","Ƭ��֮�󣬴�ʯ�ֹ���ԭ�ء�\n", room);
        room->delete("exits/enter");
}


