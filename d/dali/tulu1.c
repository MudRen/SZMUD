// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
�����Ǵ����ڣ�������һ������·�ϣ����˶��Ǳ��صİ������ˡ�
Ҳ�����Щ��ԭ���������߶�����·����ͨ��ٵ���������·ͨ����
��ǵ����š�
LONG
	);

	set("exits", ([
		"north" : __DIR__"guandao5",
		"south" : __DIR__"tulu2.c",
	]));

	set("cost", 2);
	set("outdoors", "dali");
	setup();
}
