//Cracked by Roath
// Room: /d/beijing/zijincheng/tihedian.c

inherit ROOM;

void create()
{
	set("short", "��͵�");
	set("long", @LONG
   ����̫��ס���㹬ʱ,�ڴ�����,"���ŷ�"ÿ��Ҫ������ʮ������.ÿ����
��ʳʮ����,���ȶ�.��ʮ��,���и�ʽ�˵�.����ʮ����(1887)����̫���ڴ�
Ϊ�����ʵ�����ѡ�ʺ�����ӵ���ʽ.

LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"yikungong",
  "north" : __DIR__"chuxiugong",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
