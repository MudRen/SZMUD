//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","���������");
	set("long",@LONG
���ڴ�ʯ����ϣ������ı��ֱȽ����壬·�ϵ����˽��١����紵��������ë���Ȼ��
һ����������˴�����Ľ������ɽ�����������������С·�����������˻������
LONG
	);
	set("exits",([
		"east" : __DIR__"xiaolu",
                "west" : __DIR__"qlbfd",
		"south" : __DIR__"nroad1",
		"north" : __DIR__"nroad3",
	]));
set("outdoors", "changan");
set("fanhua", 2);
	setup();
}
