// Code of ShenZhou

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
  	set("short", HIY"���"NOR);
    set("long", @LONG
����ڹ��߻谵���������ƣ���Լ�ɼ������������ϣ������ϣ�
�����϶����˺��һ�����͡�����������ͽ�Ƕ��Ŵ��СС�ķ���
ߵ�ݣ����������͡����ڹ��������Ĳ�����ഫ���ĳɹ����¼�ʱ
�����ģ��������ʧ�ޣ����ϵĽ����԰�������࣬�߲߰����ġ�
LONG
        );

    set("exits", ([
		"south" : __DIR__"changlang",
    ]));

    set("time", time());

    set("objects", ([
				__DIR__"obj/xiang" : 1,
                __DIR__"npc/zhirilama" : 1,
    ]));

    setup();
  
}

void  init()
{
        return;
}

