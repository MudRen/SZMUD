// Code of ShenZhou
// Room: tianchi.c

inherit ROOM;

#include "/d/changbai/caishen.h";

void create()
{
	set("short", "���");
	set("long", @LONG
������ǳ��׵�ʥ��������ء��������¶ˮ�����Ҷ������Բ�Σ���
խ������ΧȺ�廷�У����簨��ѩ�廳���е�һ�������񾵡��ο��д�
˵��������ʥ�أ�ʱ���������ʣ������������ɫ�쳣������ʱ������Х
����ɳ��ʯ�����������ɷһ�㡣�����������Ĳοͣ��Ի����Ǳع��ؾ�
���������Ҹ������
LONG	);
	set("exits", ([ 
              "westup" : __DIR__"yuzf",
              "eastup" : __DIR__"longmf",
              "northup" : __DIR__"baiyf",
              "southup" : __DIR__"tiyf",
        ]));
	
        set("outdoors", "changbai");
        set("fjing", 1);

        set("count", random(3)+1);

	setup();
}
