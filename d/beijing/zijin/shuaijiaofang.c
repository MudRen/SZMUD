//Cracked by Roath
// Room: /d/beijing/zijincheng/shuaijiaofang.c

inherit ROOM;

void create()
{
	set("short", "ˤ�ӷ�");
	set("long", @LONG
������տն�����ǽ�ڱ����ż���ţƤ�Ƶ����Σ����ϴ�������
ֻ�󲼴��������ƺ�װ���������ɳ��������һ�����ӣ��������ʮ
�������ġ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"neizuomen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
