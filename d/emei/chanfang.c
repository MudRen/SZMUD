// Code of ShenZhou
// chanfang.c ����

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
������һ�䰲�������������������е��Ӵ�������֮������������
����ط���������š���λ����ʦ̫���׼�Ů�����������붨��
LONG
	);
	set("exits", ([
		"west" : __DIR__"fushou1",
	]));

	set("jingzuo_room", 1);
	set("no_fight", 1);

	set("cost", 0);
	setup();
	replace_program(ROOM);

}
