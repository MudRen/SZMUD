// by Jiuer 
// Room: /d/gaibang/bjandao1.c  ��������
// Date:  03/15/2002

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ؤ�� �������ܵĵ���ͨ��������ؤ�Ｘ����֮��Ѫ��ɡ� 
LONG
	);

	set("exits", ([
			"north" : __DIR__"bjandao2",
			"southwest" : __DIR__"undertre",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

