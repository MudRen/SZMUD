// Code of ShenZhou
// Room: didao.c �ص����
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "�ص����");
	set("long", @LONG
�����Ǻ������ڵĵص���ڣ�һ��С���ѵĺ��棬��һ��������Ķ�
Ѩͨ�����¡�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"down": __DIR__"didao1",
		"northeast" : "/d/kunlun/shanqiu",
]));
	set("no_clean_up", 1);
	set("cost", 1);

	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if ((!me->query("family") || me->query("family/family_name")!="����") &&
		dir == "down")
		return notify_fail("����������׳����ס�㣬˵�������˲��ý���ص���\n");
	
	return ::valid_leave(me,dir);
}