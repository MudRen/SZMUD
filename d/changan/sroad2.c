//Created by RoomEditer on 02-1-3
//by bravo
inherit ROOM;

void create()
{
	set("short","�����ϴ��");
	set("long",@LONG
������һ����ʯ����ϣ��������ɨ���˴������Ƶ�Ҷ�ӵ�������������
�ĵ������ͷң������ϣ�����������λ����Ҫ���š����洫��һ���������
��������һ����֪����һȺС�������汳ʫ��
LONG
	);
	set("exits",([
		"east" : __DIR__"moshouju",
                "west" : __DIR__"wuguan",
		"south" : __DIR__"sroad3",
		"north" : __DIR__"sroad1",
	]));
set("outdoors", "changan");
	setup();
}
