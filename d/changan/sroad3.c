//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","�����ϴ��");
	set("long",@LONG
������һ����ʯ����ϣ��������ɨ���˴������Ƶ�Ҷ�ӵ�������������
�ĵ������ͷң������ϡ�
LONG
	);
	set("exits",([

                "east" : __DIR__"zahuodian",
                "west" : __DIR__"bydamen",
                "south" : __DIR__"sroad6",
		"north" : __DIR__"sroad2",
	]));
set("outdoors", "changan");
	setup();
}
