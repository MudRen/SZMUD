// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
�����Ǵ����ڣ�������һ������·�ϣ����˶��Ǳ��صİ������ˡ�
Ҳ�����Щ��ԭ���������߶�����·����ͨ���ٵ�������ͨ�������
�����š�
LONG );

	set("exits", ([
		"east" : __DIR__"tulu6.c",
		"west" : __DIR__"tulu8.c",
	]));

	set("objects", ([
		__DIR__"npc/wujian": 1,
	]));

	set("cost", 2);
	set("outdoors", "dali");
	setup();
}
