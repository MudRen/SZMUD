// Code of ShenZhou
// Room: jiglz.c

inherit ROOM;

#include "/d/changbai/caishen.h";

void create()
{
	set("short", "��������");
	set("long", @LONG
������һƬ���������ɽ�룬Զ�����缦����һ���������Ѿ��ӽ�����
�ˡ���Ŀ������ȥ����ɫ��ɽ��������£���鶺���һ����ɫ�����������
�����С�����ķ��Ƹ����ˣ�������վ��ס���ӡ�
LONG	);
	set("exits", ([ 
              "westdown" : __DIR__"tieby",
              "eastup" : __DIR__"lumf",
        ]));
	
	set("objects", ([
	    "/d/xingxiu/npc/spider3" : 1
	]));
        set("outdoors", "changbai");

        set("count", random(3)+1);

	setup();
}
