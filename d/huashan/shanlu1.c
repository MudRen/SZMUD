// Code of ShenZhou
// ��ɽ��Ů��ɽ·
// qfy 26/6/1996

inherit ROOM;

void create()
{
	set("short", "��Ů��ɽ·");
	set("long", @LONG
����һ��ͨ����Ů�������Σ�µ�ɽ·��һ·��������ľԽ��Խ�٣�
�뻪ɽ��ľ�廪����ɫ���ĵ���ɫ�ɶԱȡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"southdown" : __DIR__"yunu",
		"northup":__DIR__"shanlu2",
	]));

	set("objects", ([
		CLASS_D("huashan") + "/genming" : 1, 
	]));

	set("outdoors", "huashan");

	set("cost", 3);
	setup();
}


 
