// Code of ShenZhou
// room: /d/mingjiao/shijie1.c
// Zhangchi 3/00

#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "ʯ��");
    set("long",@LONG
����һ����������ʯ�ף�����վ�ż������̻�����ÿ�˵������϶���
��һѪ��Ļ��档��ʯ�׵ľ�ͷ��������������ʮ�ɵļ�¥���������˴�
�������¥�ϵĹ����ֽ��ᷢ��������
LONG
	);

 	set("exits",([
		      "north" : __DIR__"yongdao",	
		      "southeast" : __DIR__"shanmentongdao",	
		      	]));
	set("outdoors", "mingjiao");
	set("cost", 1);

	setup();
	replace_program(ROOM);
}

