// Code of ShenZhou
// Room: longmf.c

inherit ROOM;

#include "/d/changbai/caishen.h";

void create()
{
	set("short", "���ŷ�");
	set("long", @LONG
�˷�Ϊ��������֮һ���ڳ�鶺������������ַ���ԣ�����״���ţ���
�����š��ݴ���������ˮʱ����������Ա��������ʯ������Ϊ�񱮡���
�˿���鶺�����һ����ɫ��������ֱ���ɽ����֮�䡣
LONG	);
	set("exits", ([ 
              "westdown" : __DIR__"tianchi",
              "northwest" : __DIR__"baiyf",
              "southwest" : __DIR__"tiyf",
        ]));
	
        set("outdoors", "changbai");

        set("count", random(3)+1);

	setup();
}
