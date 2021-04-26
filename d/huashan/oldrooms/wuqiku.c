// Code of ShenZhou
// wuqiku.c ��ɽ������
// qfy July 7, 1996

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ǻ�ɽ�ɵı�������ǽ�ϸ���������೤�����̽����񽣡�
LONG
	);

	set("exits", ([
		"east" : __DIR__"square",
	]));

	set("objects", ([
		__DIR__"obj/changjian" : 2,
		__DIR__"obj/duanjian" : 2,
		__DIR__"obj/zhujian" : 3,
	]));

	set("cost", 0);
	setup();
	//replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	object *inv;
	int i, j=0;

	inv = all_inventory(me);

	for (i=0; i<sizeof(inv); i++) {
		if ((string)inv[i]->query("skill_type")=="sword") j++;
        }
	
	if ( j == 1 ) me->set_temp("marks/��", 1);
	if ( j > 1 ) return notify_fail("����ô��˽���㲻�ܴ��߳���һ�ѱ�����\n");

	return ::valid_leave(me, dir);
}

