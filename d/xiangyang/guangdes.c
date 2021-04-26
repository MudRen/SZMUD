// Code of ShenZhou
// Room: /d/xiangyang/guangdeshi.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����ԭ���ƾ��£�����������䡣���ܵ�ͤԺ��Ϊשʯ��ľ�ṹ������
Ϊ�ƾɡ���һ������ӳ���ۿ�������ǰ���۵��������֡������ײ�����Ϊ�˷���
���������һʯ��ȯ�ţ��ơ��˷����š��������Ϸ�ʯ��̡��౦���������֡�
���������������꣬����һ��(tree)������׳��֦Ҷïʢ��
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"qilidian",
  "enter" : __DIR__"duofota",
  "west" : __DIR__"milin",
]));
set("item_desc", ([
		"tree" : "��˵�������һ���к��ܵĵ����Ϻ��У�һ�����ᣬ�������������������Ҫ
�������ˡ�����Ҫ���£�ͽ�ܲ��á���˵������֮���Ҹ��顣�����ᣬ��������
�ձ���ʹ�ޣ���ˮʪ͸���������괺�����ַ�ѿ�����ܹ��¡�\n",
	]));
	setup();
	replace_program(ROOM);
}
