//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","���������");
	set("long",@LONG
���ڴ�ʯ����ϣ������ı��ֱȽ����壬·�ϵ����˽��١����紵������
��ë���Ȼ��һ����������˴ӱ���Ľ�������������
LONG
	);
	set("exits",([

		"southeast" : __DIR__"xfroad4",
		"southwest" : __DIR__"xfroad3",
		"north" : __DIR__"nroad2",
	]));
set("outdoors", "changan");
	setup();
}
