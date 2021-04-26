// Code of ShenZhou
// /d/wanshou/shulin.c
// snowbird July 1999
// 1.1.1.1

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��������ɽׯ��ѱ����Ұ����Ϣ�����ӡ����ϱ���ɽׯѱ�޳���
����ͨ��ɽׯ������ͱڡ�
LONG
        );
        set("exits", ([
		        "north" : __DIR__"juebi",
				"south" : __DIR__"xunshouchang",
        ]));

        set("outdoors", "wanshou-shanzhuang");

	    set("cost", 1);
        setup();

}

void init()
{
        add_action("do_howl", "howl");
}

int do_howl(string arg) 
{
   object me = this_player();
   object animal, *animals;
   object here = environment(me);
   string file = "/u/snowbird/wanshou/npc/animal2";
   int i, num;

   animals = filter_array(children(file), (: clonep :));

   num = sizeof(animals);

   if (num > 0) {
       for (i=0; i<num; i++) {
		  if(animals[i]->query_lord() == me)
              return notify_fail("��������Х�����˺�һ��������������ɾ����ĵĺ��޶�����\n");

       }
   }
   animal=new(file);
   animal->animal_special_init(me);
   message_vision(HIG"$N��Хһ����һֻ$n����������˳������ԹԵط���$N�Ľűߡ�\n"NOR, me, animal);
   animal->move(here);

   return 1;
}
