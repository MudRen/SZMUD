//Cracked by Roath
// Room: /d/beijing/zijincheng/qianqinggong.c

inherit ROOM;

void create()
{
	set("short", "Ǭ�幬");
	set("long", @LONG
���ǻʵ۵��޹����ʺ��ڴ˾�ס���������ɿ��԰��ջʵ۵��ٻ�
�����������ʵ�Ҳ��ʱ�ڴ��ټ��������ٳ��������������ţ��Ӽ���
��ʹ���Լ�����ѧϰ�������µȡ�
�ڹ��ŵ����Ϸ�������һ�����(bian).
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yard1",
  "north" : __DIR__"jiaotaidian",
  "westdown" : __DIR__"maoqindian",
  "eastdown" : __DIR__"yuchafang",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "bian" : "����д�š�����������ĸ����֡��峯�ʵ۽��̳��˵�
������д���ݣ�һ�ݴ�����ߣ�һ�ݷ��ڽ���ϻ�ڣ��ŵ�
Ǭ�幬������������ҵĺ��棬�ʵ������ɹ����󳼹�ͬ
������ܲص�һ�ݺͽ���ϻ����ͬ͢��������λ���ӡ�
",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
