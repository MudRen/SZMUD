// Code of ShenZhou
// Room: tiyf.c

inherit ROOM;

#include "/d/changbai/caishen.h";

void create()
{
	set("short", "���Ʒ�");
	set("long", @LONG
�˷�λ������ϲ࣬��ʯ��¶����״���ݡ�ɽͷ�����������ƣ���ʹ��
����Ҳ�������嶥����������˵�˷�ֱͨ�칬������ͥ���˼����������ݣ�
��˽����Ʒ塣
LONG	);
	set("exits", ([ 
              "northdown" : __DIR__"tianchi",
              "northwest" : __DIR__"yuzf",
              "northeast" : __DIR__"longmf",
        ]));
	
        set("outdoors", "changbai");

        set("count", random(3)+1);

	setup();
}
