//Cracked by Roath
// Room: /d/beijing/west/quanjude.c

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
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"quanjude2",
  "south" : __DIR__"tianqiao1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
