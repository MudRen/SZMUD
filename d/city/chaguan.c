// Code of ShenZhou
// Room: /city/chaguan.c
// xQin 6/00

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
��һ�߽��������ŵ�һ�ɲ���������Ƣ������Ϊ֮һˬ�����Ű�����һ����
���������˿��ˣ������̸Ц����ͷ�Ӷ�����˵��������ò�������ԭ�򲻵�
����Ϊ����Ĳ裬��Ϊϲ����������Ŀ����ṩ��һ�������д�ĺ�ȥ��������
��̫���Ʒ��֮�����Ϳ���(help tea)�ɡ�
LONG 
	);
	
//	set("no_clean_up", 0);
//	set("no_fight", 1);
	set("day_shop", 1);
	set("exits", ([
		"south" : __DIR__"xidajie1",
		"north" : __DIR__"qiyuan2",
		"west" : __DIR__"qiyuan3",
		"east" : __DIR__"qiyuan4",
 
	]));
	set("objects", ([
		"/d/city/npc/wang_lifa" : 1
	]));
	setup();

}

