//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","���������");
	set("long",@LONG
�����ǳ����ǵ���Ѱ���ĺõط������ϵ����������е����ţ�·��ż����
������������������Ũױ��Ĩ��Ů�����ڽ�ͷ����֬��һ����֪�����������
¥Ů�ӣ������˵���������컨����ȥ�������ǳ��������Ľ���¥���ڶ൱��
�Ĺ��������������֡�
LONG
	);
	set("exits",([
		"east" : __DIR__"dongmen",
		"west" : __DIR__"eroad2",
		"south" : __DIR__"honghuage",
		"northwest" : __DIR__"jinyulou",
		"north" : "/p/fystreet/street0",
	]));
	set("outdoors", "changan");
	setup();
}
