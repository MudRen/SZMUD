// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "��ɽ���");
        set("long", @LONG
��ɽ�Թ������ɡ����¡����ڲ��������Ĵ��򣬶�������︷������
������һ����ֺ�ب������·��һ������������Ĵ��¥��������д��
��Ӣ��¥������������֣����߳��Ŵ����������������������
LONG
        );
        set("exits", ([
		"north" : __DIR__"ngate",
		"south" : __DIR__"yxlou",
		"east" : __DIR__"street3",
		"west" : __DIR__"street1",
	]));

	set("objects", ([
		__DIR__"npc/sisao" : 1,
	]));
	set("cost",1);
	set("outdoors", "wudang");
	setup();
        replace_program(ROOM);
}
