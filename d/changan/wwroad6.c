//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","�����·");
	set("long",@LONG
һȺ�ٱ���������������һ�Ż�����Ū�ý��ϵ��������������������Ŀ�
������ǰ�����������ǵİ����ѡ����ϲ�ʱ����һЩ��ܶ�Ź���¼�������һ
Щ���ḾŮ����һ��Ѱ�����ǵ��ɷ�
LONG
	);
	set("exits",([
		"northeast" : __DIR__"eroad1",
		"southwest" : __DIR__"wwroad5",
	]));
set("outdoors", "changan");
	setup();
}