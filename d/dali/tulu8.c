// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
�����Ǵ����ڣ�������һ������·�ϣ����˶��Ǳ��صİ������ˡ�
Ҳ�����Щ��ԭ���������߶�����·���߾��Ǵ���ǵ������ˣ���
��·ͨ��ȥ��ԭ�Ĺٵ���
LONG
	);

	set("exits", ([
		"east" : __DIR__"tulu7.c",
		"west" : __DIR__"southgate.c",
		"north" : __DIR__"droad4.c",
	]));

	set("cost", 2);
	set("outdoors", "dali");
	setup();
}
