//Cracked by Roath
// Room: /d/beijing/quanjude.c

inherit ROOM;

void create()
{
	set("short", "ȫ�۵�");
	set("long", @LONG
���Ǳ����Ƕ���������ȫ�۵¿�Ѽ�꣬���������������Ī��Ҫ
����������ȫ�۵¿�Ѽ���������ʶ��������ϱ�������ȫ�۵�Ҳ����
��ķָ�ġ����ﳣ�����ӯ�ţ������ﲻ���ǵ����Ŀ��ˣ�¥������
�����۸��¥��Ҳ�ߵöࡣ
LONG
	);
	set("exits", ([
  "south" : __DIR__"tianqiao",
]));
	set("no_clean_up", 0);
	set("objects", ([
	__DIR__"npc/quanjude_xiaoer":1,
]));
	setup();
	replace_program(ROOM);
}
