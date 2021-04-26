// Code of ShenZhou
// Room: /d/xiangyang/xiaoshitai.c

inherit ROOM;

void create()
{
	set("short", "Уʿ��");
	set("long", @LONG
��վ���ı���У���ϣ�����һ�Ӷӱ�����̨�²�����ÿһӪ��һ���ܱ�ͳ����
�������ݣ���Ȼ�ǿ������������۲��ã�������죬��ꪲεأ�����˷�������
���飻���βʣ������ڿա�
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"lianwuc",
  "eastup" : __DIR__"guloud",
  "north" : __DIR__"xijie2",
  "southeast" : __DIR__"djtai",
]));

	setup();
	replace_program(ROOM);
}
