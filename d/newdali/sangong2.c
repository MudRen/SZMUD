// Code of ShenZhou
// Room: /d/dali/sangong2.c

inherit ROOM;

void create()
{
	set("short", "˾����");
	set("long", @LONG
�����ÿ����������ڸ���һ�б����ܣ���ǹ��ꪽ�ȫ���鰸֮����б�
�����ڼ��ϣ����л�Ƥ��Ƥ�̵أ�һ����֮����ٹ��á��������Ǵ����˾��
�ǵ�˾����˾���������񣬴����ľ�������Ϊ������ı�����Ҫ����߾�������
�ΰ����ѡ�
LONG);
	set("objects", ([
		__DIR__"npc/fan-ye" : 1,
		]));
	set("exits", ([
		"south" : __DIR__"sangong",
		]));
	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	setup();
	replace_program(ROOM);
}
