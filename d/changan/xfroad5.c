//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","�Ҹ����");
	set("long",@LONG
������Щ��Ҷ��һ��紵�������˲��������������Ǹ���ǣ�һЩ������
ʿ�����������������Ϸ����ǳ���������ĵض��ˣ�һЩ���˿첽��ǰ�ߣ�
����һ��ɳ����Ϣ��·�ϳ�ˮ�����������˳����ϡ�
LONG
	);
	set("exits",([
		"east" : __DIR__"majiu",
		"southwest" : __DIR__"center",
                "southeast" : __DIR__"xfroad6",
		"northwest" : __DIR__"xfroad4",
	]));
set("outdoors", "changan");
set("fanhua", 3);
	setup();
}
