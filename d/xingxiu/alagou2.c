// Code of ShenZhou
// Ryu, 5/10/97

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
ɽ����խ��������к��ˮ���������а����ܴ����������С��
ũ����裬�������࣬����һ�ٶ��������ˮ��Ȼ�ѳ�����СϪ��
��ȴ�����峺������һ�������Ų�ɫ��ȹ�������«���չ޵�������
Ů����������԰ӱ߼�ˮ��ˮ�е�ӳ��������ȵ���Ӱ��
LONG
	);
	set("exits", ([
		"northup" : __DIR__"lake",
		"south" : __DIR__"alagou1",
	]));
	set("objects", ([
		__DIR__"npc/xbgirl": 2,
	]));
	set("cost", 2);
	set("resource/water",1);
	set("outdoors", "tianshan");

	setup();
	replace_program(ROOM);
}
