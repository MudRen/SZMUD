//Cracked by Roath
// Room: /d/beijing/zijincheng/maoqindian.c

inherit ROOM;

void create()
{
	set("short", "��ڵ�");
	set("long", @LONG
    �����ں��ֹٵ�ֵ�ദ,����ͼ��,�ľߴ���
�˴�.�����ʵ����ڴ˶��顣
    ÿ���＾,�ʵ��������Ĳö�һЩ�̲������
�ش󰸼�Ҳ���������.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"pibenchu",
  "eastup" : __DIR__"qianqinggong",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
