// Code of ShenZhou
// Room: xuedi2.c 

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "ѩ��");
	set("long", @LONG
������һƬ��ãã��ѩ�أ�һ���������߼ʡ�����һ����ӰҲû�У���
��Ļ�ѩ������������֨�����������������һ���¶��Ľ�ӡ������ı���
��Х��������������ʹ��������̫����������ߣ��Ե���ô�԰ס�
LONG
	);

	set("exits", ([
		"southwest" : __DIR__"xuedi1",
                "east" : __DIR__"xuedi3",
	]));

        set("outdoors", "changbai");
        set("cost", 5);

	setup();
	
}

#include "/d/changbai/xuedi.h";
