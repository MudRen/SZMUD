//Cracked by Roath
// Room: /d/beijing/zijincheng/yujingting.c

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
���ǽ��ڶ���ɽ�ϵ�����ͤ,����ɽ�����еŵ�����,��԰�п�
�Ե��ٵ���ߵ�.���ϴ�ɽԭ��,��ɽ����;���,�Ͻ��Ǿ����۵ף�
�ž�����֮��,�ʵ��ڶ���ɽ�Ǹ�.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"yuhuayuan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
