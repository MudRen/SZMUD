// Code of ShenZhou
// ���� to huashan
// qfy August 17, 1996

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ϸ�����Ȫ�������Ե�һ���ƾɵ�������ƽʱ���̺�����
����ؤ��ѡ��Ϊ���ݵ�֮һ��
LONG
	);

	set("exits", ([
		"up" : "/d/quanzhou/tudi",
		"north":__DIR__"qzandao2",	
	]));

	set("objects",([
		CLASS_D("gaibang") + "/kuaihuo-san" : 1,
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}
