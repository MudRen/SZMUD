// Code of ShenZhou
// Room: /shaolin/jiulou2.c
// YZC 1995/12/04 

inherit ROOM;
inherit F_DEALER;

void create()
{
	set("name", "ӭ��¥");
	set("short", "ӭ��¥��¥");
	set("long", @LONG
����¥�ϵ�������������ѧʿ������������ʫ��������������Ҳ��
����߳Ժȱ������ס����ﾭ���ٰ����ȫϯ������Ҳ������������
�����ߺ�������ش���һ�����˰������棬��������Ʈ��������Ҳ
����ʳָ�󶯣�����վ��¥������������ԶԶ��������ĺ�����ǽ�Ϲ�
�Ÿ�����(paizi)��
LONG
	);

	set("item_desc", ([
		"paizi" : "����ר���ϵȰ����硣\n",
	]));

	set("exits", ([
		"down" : __DIR__"jiulou1",
	]));

	set("objects",([
		CLASS_D("gaibang") + "/qiu-wanjia" : 1,
//		"/d/shenlong/npc/qing" : 1,
	]));

	set("cost", 2);
	setup();
}
