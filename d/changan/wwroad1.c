//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","�����·");
	set("long",@LONG
һȺ�ٱ��������������һ�Ż�����Ū�ý��ϵ��������������������Ŀ�
������ǰ���������ǵİ����ѡ����ϲ�ʱ����һЩ��ܶ�Ź���¼�������һЩ
���ḾŮ����һ��Ѱ�����ǵ��ɷ�
LONG
	);
	set("exits",([
		"northwest" : __DIR__"wroad1",
		"southeast" : __DIR__"wwroad2",
	]));
set("outdoors", "changan");
	setup();
}
