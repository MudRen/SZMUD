//Created by RoomEditer on 02-1-3.
inherit ROOM;

void create()
{
	set("short","�Ҹ����");
	set("long",@LONG
��������ͨ�����ŵıؾ�֮·�����ϱȽ����壬�⼸���ΰ����ã���ѹ��
�յ��¼��Ѿ������ˣ�����ȥ���ź�ԩ��Ҳ���ˡ�������Щ��Ҷ��һ��紵����
���˲���������
LONG
	);
	set("exits",([

		"northwest" : __DIR__"nroad1",
		"southeast" : __DIR__"xfroad5",
	]));
set("outdoors", "changan");
	setup();
}
