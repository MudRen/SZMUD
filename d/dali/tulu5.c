// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
�����Ǵ����ڣ�������һ������·�ϣ����˶��Ǳ��صİ������ˡ�
Ҳ�����Щ��ԭ���������߶�����·������ͨ��ٵ�����������·ͨ
������ǵ����š�
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"tulu4.c",
		"southwest" : __DIR__"tulu6.c",
	]));

	set("cost", 2);
	set("outdoors", "dali");
	setup();
}
