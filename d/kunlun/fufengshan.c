// fufengshan.c (kunlun)

#include <ansi.h>
#include <room.h>
inherit ROOM;

int do_climb();

void create()
{
		  set("short", "����ɽ");
		  set("long", @LONG
����ɽ������ʮ�ֶ��ͣ�ɽ�����Ͼ�û��ãã�ƺ����嶥�����ѩ��ɽ��
����ȴ�������Բԣ���ľï�ܣ����Ž��أ���������
LONG
		  );
		  set("outdoors", "kunlun");

		  set("exits", ([
					 "enter" : __DIR__"houyuan.c",
					 "northeast" : __DIR__"bainiushan.c",
                                         "up" : __DIR__"sanshengao.c",
		  ]));


		  set("no_clean_up",0);
create_door("enter", "С��", "out", DOOR_CLOSED);
                  
                  set("cost", 3);
                  setup();
}

/*
int valid_leave(object me, string dir)
{
        
        if( random((int)me->query_skill("dodge")) <= 30) 
        {
                me->receive_damage("qi", 50, "��ɽ�Ϲ�������ˤ����");
                me->receive_wound("qi",  50, "��ɽ�Ϲ�������ˤ����");
                message_vision(HIR"$Nһ��С�Ľ���̤�˸��գ�... ��...��\n"NOR, me);
                me->move(__DIR__"shanlin1");
                message("vision", HIR"ֻ��" + me->query("name") + "��ɽ�Ϲ�µµ�ع������������ڵ��ϰ�������������\n"NOR, environment(me), me);
        return notify_fail(HIR"���ɽ�Ϲ���������ֻ���û����޴����ۣ������˼����ˡ�\n"NOR);
        }
        return ::valid_leave(me, dir);
}

*/
